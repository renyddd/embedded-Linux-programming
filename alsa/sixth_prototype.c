#include <sys/mman.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <linux/input.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>
#include <time.h>
#include <dirent.h>

void bmp_show(char *bmp_name)
{
    /**
      函数功能： bmp 图片全屏显示
      参数1： bmp图片路径
      返回值: void 
      备注: 此函数仅支持 800*480 分辨率图片

     **/

    //1. 打开 设备文件（LCD）
    int fd_lcd = open("/dev/fb0", O_RDWR);
	
	if(fd_lcd == -1){
		printf("open lcd err\n");
		return;
	}
	
	//2. fb0 映射
	unsigned char * fp = mmap(NULL, 800*480*4, PROT_READ|PROT_WRITE,\
				MAP_SHARED, fd_lcd, 0);
				
	if(fp == (void*)-1){
		printf("mmap err\n");
		return;
	}

	//3. 打开bmp图片-->读取图片颜色数据
	int fd_bmp = open(bmp_name,O_RDONLY);
	
	if(fd_bmp == -1){
		printf("open bmp err\n");
		close(fd_lcd);
		munmap(fp, 800*480*4);	
		return;
	}
	
	char bmp_buf[800*480*3];
	
	read(fd_bmp, bmp_buf, 54);
	read(fd_bmp, bmp_buf, 800*480*3);
	
	//4. 显示 bmp 颜色数据
	int i,j;
	
	for(j=0;j<480; j++){
		for(i=0; i<800; i++){
			// fp[i*4+800*4*j] = bmp_buf[i*3+800*3*(479-j)]; //B
			// fp[i*4+1+800*4*j] = bmp_buf[i*3+800*3*(479-j)+1]; //G
			// fp[i*4+2+800*4*j] = bmp_buf[i*3+800*3*(479-j)+2]; //R
			memcpy(fp+i*4+800*4*j, bmp_buf + i*3+800*3*(479-j), 3);
			fp[i*4+3+800*4*j] = 0;
		}
	}

	//5. 释放资源
	close(fd_lcd);
	close(fd_bmp);
	
	munmap(fp, 800*480*4);	
}

void get_xy(int *x, int *y)
{
    //输入子系统 的 标准头文件
    // /usr/include/
    /**
      函数功能： 获取 xy 的触摸值
      参数1： 保存x触摸值
      参数2： 保存y触摸值
      返回值：void

     **/

	//1. 打开 触摸屏的设备文件
	int fd_touch = open("/dev/input/event0", O_RDONLY);
	
	if(fd_touch == -1){
		printf("open touch screen err\n");
		return;
	}
	
	//2. 读取 触摸信息 结构体
	struct input_event ts;
	
	while(1){
		//此处读取的是设备驱动文件，如果没有数据不会立即返回，而会阻塞等待
		read(fd_touch, &ts , sizeof(ts) );
		
		//printf("type:%d    code:%d    value:%d\n",\
			ts.type, ts.code, ts.value);

		if(ts.type == 3){
			if(ts.code==0){ *x = ts.value; //保存x触摸值
			}else if(ts.code==1){
				*y = ts.value; //保存y触摸值
			}
		}

		if((ts.code==330) && (ts.value==0)){
			break;
		}
	}
	//printf("x:%d   y:%d\n",*x,*y);
	//3. 回收资源
	close(fd_touch);
}

void exec_arecord()
{
    // get time.
    struct tm * mytime;
    time_t tmp;

    char wav_file_dir[100] = {"./record_repository/test_\0"};

    char *p_wav_file_name = NULL;

    char wav_file_name[20];
    // child, do execvp job.
    // printf("coming into case 0.\n");

    time(&tmp);
    mytime = localtime(&tmp);
    // printf("mytime got the value. %s%d_%d_%d.wav\n", wav_file_dir, mytime->tm_hour,mytime->tm_min, mytime->tm_sec);

    // name process.
    sprintf(wav_file_name, "%d_%d_%d.wav", mytime->tm_hour,mytime->tm_min, mytime->tm_sec);
    // printf("going to show wav_file_name: ");
    // printf("%s\n", wav_file_name);

    p_wav_file_name = strcat(wav_file_dir, wav_file_name);

    char *tmp_list[] = {
        "arecord",
        "-r",
        "16000",
        "-t",
        "wav",
        "-f",
        "S16_LE",
        "--duration=5",
        p_wav_file_name,
        NULL
    };
    
    printf("\nYour record file is: %s\n", p_wav_file_name);
    printf("It will last for 5 seconds.\n");
    // printf("going to strcpy process.\n");
    // strcpy(*arg_list, *tmp_list);How to cpoy the array of the points?

    //printf("enter child process.\n");
    // printf("H:%d  M:%d   S:%d\n", mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
    execvp("arecord", tmp_list);
    printf("the exec (record) failed.\n");
}

int exec_aplay(int num)
{
    char wav_file_dir[100] = {"./record_repository"};
    DIR *dirp = opendir(wav_file_dir);
    struct dirent *dp;

    int i = 0;
    char dir_item[100][200];

    int cnt = 0;
    char s[50];

    // printf("going to while\n");
    while ( dp = readdir(dirp) ) {
        // printf("\n");
        // printf("aplay record_repository/%s\n", dp->d_name);
        sprintf(s, "aplay record_repository/%s", dp->d_name);
        printf("the s is: %s\n", s);
        // When the error [aplay: playback:2309: read error], these means '.' and '..'.
        strcpy(dir_item[i++], s);
    }

    cnt = i;
    i = 0;

    // printf("*******************************\n");
    /*
    while ( i < cnt ) {
        //printf("dir_item[%d] is: %s",i , dir_item[i++]);
        //printf("dir_item is: %s", dir_item[i++]);
        system(dir_item[i++]);
    }*/

    system(dir_item[num]);
    printf("aplay done.\n\n");
    closedir(dirp);

    return num + 1;
}

int main()
{
    int x = 400;
    int y = 240;
    
    pid_t childPid;
    
    char *arg_list[] = {NULL};

    int aplay_num = 0;
    //bmp_show("/mnt/m.bmp");
    bmp_show("/mnt/UI2.0.bmp");

    while(1) {

        get_xy(&x, &y);

        printf("x= %d, y= %d\n", x, y);

        /*
         * exit field
         * x = 0 - 300
         * y = 0 - 300
         */
        if ( x <= 300 && y <= 300 )
        {
            bmp_show("/mnt/m.bmp");
            break;
        }

        /*
         * arecord field (shell command)
         * x >= 722
         * y <= 300
         */
        else if ( x >= 722 && y <= 300)
        {
            printf("caught your touch!\n");

            switch ( childPid = fork() ) {
                case -1:
                    perror("fork");
                    exit(1);

                case 0:
                    bmp_show("/mnt/stopRecord.bmp");
                    exec_arecord();

                default:
                    // paretn, do wait job.
                    wait(NULL);
                    printf("\nRecord done, and the childPid: %d\n\n", childPid);
            }
        }

        /*
         * aplay field
         * x > 722
         * y > 300
         */
        else if ( x > 722 && y > 300 )
        {
            printf("come into aplay field.\n");
            bmp_show("/mnt/UI2.0.bmp");
            aplay_num = exec_aplay(aplay_num);
        }
    }
        
    return 0;
}
