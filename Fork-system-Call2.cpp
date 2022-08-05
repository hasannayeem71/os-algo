#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(int argc, char **argv)
{
pid_t pid;
pid = fork();
pid = fork();
if(pid==0)
{
printf("It is the child process and pid is %d\n",getpid());
exit(0);
}
else if(pid > 0)
{
printf("It is the parent process and pid is %d\n",getpid());
}
else
{
printf("Error while forking\n");
exit(EXIT_FAILURE);
}
return 0;
}