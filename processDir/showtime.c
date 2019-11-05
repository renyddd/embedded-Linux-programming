#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
    time_t timep;
    time (&timep);
    printf("\n%s\n", ctime(&timep));
    return 0;
}
