#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
int sum;
void *run(void *param);
int main(int argc, char *argv[]).
{
pthread_t tid;
pthread_attr_t attr;
if(argc !=2)
{
printf("Error !");
return 1;
}
if(atoi(argv[1])<0)
{
printf("no. Should be +ive");
return 1;
}
pthread_attr_init(&attri
pthread_create(&tid,&attr.run.arguri):
pthread_join(tid, NULL);
printf("Sum = %d in", sum);
}
void *run(void *param)
{
int i,upper;
sum=0 ;
upper=atoi(param);
if(upper>0)
{
for(i=1;i<=upper; ++i)
SUM+=i:
pthread_exit(0);
}
}
