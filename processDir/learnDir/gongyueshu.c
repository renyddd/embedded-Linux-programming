#include<stdio.h>


//求两个数的最大公约数


int main()
{
	int a, b, c;
	printf("请输入两个数:");
	scanf("%d%d", &a, &b);
	if (a < b){
		a = a + b;									//大的值放在a中，小的值放在b中
		b = a - b;
		a = a - b;
	}
	for (c = b; c > 0; c--){					//for循环，重复进行取余操作
		if ((a%c == 0) && (b%c == 0)){			//当第一次同时为0时，便是最大公约数，跳出循环
			break;
		}
	}
	printf("最大公约数是%d\n", c);
    return 0;
}

