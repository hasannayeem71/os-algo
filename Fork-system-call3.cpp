#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
main()
{
pid_t pid;
int x = 5;
pid = fork();
x++;
if (pid < 0)
{
printf("Process creation error");
exit(-1);
}
else if (pid == 0)
{
printf("Child process:");
printf("\nProcess id is %d", getpid());
printf("\nValue of x is %d", x);
printf("\nProcess id of parent is %d\n", getppid());
}
else
{
printf("\nParent process:");
printf("\nProcess id is %d", getpid());
printf("\nValue of x is %d", x);
printf("\nProcess id of shell is %d\n", getppid());
}
}