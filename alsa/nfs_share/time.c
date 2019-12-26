/********std header**********/
#define  _PG_std
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <math.h>
#include <sys/mman.h>
#include <errno.h>
#include <stdarg.h>
#include <time.h>
#include <unistd.h>


int main(int argc,char **argv)
{
	while(1)
	{

		struct tm * mytime;
		time_t tmp;

		tmp = time(NULL);

		mytime = localtime(&tmp);

		printf("H:%d  M:%d   S:%d\n",mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
		
		sleep(1);
	}

	

	return 0;
}//end of te main


