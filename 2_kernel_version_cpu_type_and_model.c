#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    printf("\n Kernel version is : \n");
    system("cat /proc/sys/kernel/osrelease\n");
    printf("\n CPU information is: \n");
    system("cat /proc/cpuinfo\n");
    return 0;
}