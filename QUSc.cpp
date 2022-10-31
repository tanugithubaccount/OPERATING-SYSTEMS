#include <stdio. h>
#include <sys/types. h>
#include <unistd. h>
int main(int argc, char *argv[])

printf("PID of sample1.c = %d\n" , getpid());
pid_t p;
D = fork( );
if (p==-1)
printf("there is an error while calling");

if(p==0)
printf("Child process is running\n");
printf("Now we will call sample2.c from child\n");
char *args[] = {"sample2" ,
"c" , "programming", NULL};
execv(" . /sample2" , args);

else
printf("Now parent process is running");
return 0;
