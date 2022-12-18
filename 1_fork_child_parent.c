/*
write a program (using fork() and / or exec() commands) where parent and child execute:
*/
//a) Same program, same code
//b) same program, different code
//c) before terminating, the parent waits for the child to finish its task

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    char choice = ' ';
    printf("a) Same program, same code\n");
    printf("b) same program, different code\n");
    printf("c) before terminating, the parent waits for the child to finish its task\n");
    printf("\nEnter your choice: ");
    scanf("%c", &choice);
    switch(choice)
    {
        case 'a':
        {
            pid_t pid, p;   // creating variable of type pid to store the pid of the process
            p = fork();     // fork command is used to create the child process
            pid = getpid(); // getpid command is used to get the pid of the process
            if (p < 0)      // pid value of a child process is 0(zero)
            {
                fprintf(stderr, "fork faild");
                return 1;
            }
            printf("Output of fork id: %d\n", p);
            printf("Process id is: %d\n", pid);
            return 0;
            break;
        }
        case 'b':
        {
            pid_t p;    // creating variable of type pid to store the pid of the process
            p = fork(); // fork command is used to create the child process
            if (p < 0)
            {
                fprintf(stderr, "fork faild");
                exit(1);
            }
            else if (p == 0) // pid value of a child process is 0(zero)
            {
                printf("\nI am child process.");
                printf("\nMy pid is: %d\n", getpid()); // getpid command is used to get the
                pid of the process
                    exit(0);
            }
            else
            {
                printf("\nI am parent process.");
                printf("\nMy pid is: %d\n", getpid());
                exit(0);
            }
            return 0;
            break;
        }
        case 'c':
        {
            pid_t p;    // creating variable of type pid to store the pid of the process
            p = fork(); // fork command is used to create the child process
            if (p < 0)
            {
                fprintf(stderr, "fork faild");
                exit(1);
            }
            else if (p == 0) // pid value of a child process is 0(zero)
            {
                printf("\nIn child process.");
                exit(0);
            }
            else
            {
                wait(NULL);
                printf("\nchild active pid is: %d\n", getpid()); // getpid command is used to
                get the pid of the process
                    printf("\nIn parent process.\n");
                exit(0);
            }
            return 0;
            break;
        }
        default:
        {
            printf("\nYou Enter worng choice\n")
        }
    }
}