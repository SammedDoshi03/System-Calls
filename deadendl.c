#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


void forkcall() {
    printf("WANDA\t");
    int id = fork();
    if (id == 0)
        printf("WE are in Child Process\t");
    else
        printf("WE are in Parent Process\n");
    fork();
    printf("VISION\n");
}

void waitcall() {
    int id = fork();
    if (id == 0)
        printf("WE are in Child Process\t");
    else{
        printf("Waiting Right Now...\n");
        wait(NULL);
        printf("It's a parent process\n");
    }
}

void idcall() {
    pid_t f;
    f = fork();
    if (f == 0){
        printf("CHILD PROCESS: Id = %d\n", getpid());
        printf("PARENT PROCESS: Id is = %d\n", getppid());
    } else {
        printf("CHILD PROCESS: Id = :%d\n", f);
        printf("PARENT PROCESS: Id = %d\n", getpid());
    }
}

void execcall(){
    printf("Process id in exec: %d\n",getpid());
    char *args[]={"LIGHT","KIRA","RYOUK",NULL};
    execv("./deadnok",args); 
}

int main() {
       int choice, Confirmation =0;
       printf("\t LOG :SYSTEM CALLS\n");
       printf("PROCESSES \t 1.Fork()\t 2.Wait()\t 3.Getpid() and Getppid ()");
       printf("4.Ps\t 5.Exec()\t 6.Exit\n");
    //    do {
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
                forkcall(); 
                break;
        case 2:
                waitcall();
                break;
        case 3:
                idcall();
                break;
        case 4:
                printf("Process status of currently running processes\n");
                system("ps");
                break;

        case 5:
                printf("Here new process is replaced with old process\n\n");
                printf("Pid of sys.c is %d\n", getpid());
                printf("Parent Pid of sys.c is %d\n\n", getppid());
                execcall();
                printf("Invalid choice");
            }
            // printf("APPLY ANOTHER PROCESS (1/0) ");
            // scanf("%d",&Confirmation); 
        // }while (Confirmation == 1);
}