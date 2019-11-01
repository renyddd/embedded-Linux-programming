#include <stdio.h>
int main()
{
    int year,a;
    printf("请输人年份：\n");
    scanf("%d",&year);
    if(year%400==0)
        a=1;
    else
    {
        if(year%4==0&&year%100!=0)
            a=1;
        else
            a=0;
    }
    if(a==1)
    {
        printf("%d 此年是闰年\n",year);
    }
    else
    {
        printf("%d 此年非闰年\n",year);
    }
    return 0;
}
