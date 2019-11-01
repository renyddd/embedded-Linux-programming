#include<stdio.h>
int main()
{
	int a, b, c;

	printf("请输入两个数:");
	scanf("%d%d", &a, &b);
	if (a < b)
    {
		a = a + b;									
		b = a - b;
		a = a - b;
	}
	for (c = b; c > 0; c--)
    {
		if ((a%c == 0) && (b%c == 0))
        {			
			break;
		}
	}
	printf("最大公约数是%d\n", c);

    return 0;
}
