#include <linux/input.h> //输入子系统 的 标准头文件
// /usr/include/
/**
	函数功能： 获取 xy 的触摸值
	参数1： 保存x触摸值
	参数2： 保存y触摸值
	返回值：void

**/
void  get_xy(int *x, int *y){

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
			if(ts.code==0){
				*x = ts.value; //保存x触摸值
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
