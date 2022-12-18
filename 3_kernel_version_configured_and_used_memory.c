#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    printf("\n Kernel version: \n");
    system("cat /proc/sys/kernel/osrelease\n");
    printf("\n Configured free and used memory: \n");
    system("cat /proc/meminfo | awk 'NR == 1, NR == 2 {print}'");
    return 0;
}