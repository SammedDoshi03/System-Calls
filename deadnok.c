#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    printf("Pid of C_P is %d\n", getpid());
    printf("Parent Pid of C_P is %d\n\n", getppid());
    return 0;
}