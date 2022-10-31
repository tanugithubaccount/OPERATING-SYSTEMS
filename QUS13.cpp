#include<stdio.h>
#include<stdlib.h>
void display(int ,int [10]);
void firstfit(int ,int [10],int [10],int);
void bestfit(int ,int [10],int [10],int);
void worstfit(int,int [10],int [10],int);
int main()
{
 int npr,nh=0,i,j,k,pr[10],hol[10],ch,temp[10];

 printf("\n Enter the number of processes:");
 scanf("%d",&npr);
 printf("\nNumber of holes:");
 scanf("%d",&nh);
 for(i=0;i<npr;i++)
 {
  printf("\nProcess %d:",i+1);
  scanf("%d",&pr[i]);
 }
 for(i=0;i<nh;i++)
 {
  printf("\nHole %d:",i+1);
  scanf("%d",&hol[i]);
  temp[i]=hol[i];
 }
 do
 {
  printf("\n----------MENU------------"
  "\n1.FIRST-FIT \n2.BEST FIT"
  "\n3.WORST FIT\n4.EXIT\nENTER YOUR CHOICE:");
  scanf("%d",&ch);
  for(i=0;i<nh;i++)
  temp[i]=hol[i];
  switch(ch)
  {
   case 1: firstfit(npr,temp,pr,nh);
    break;
   case 2: bestfit(npr,temp,pr,nh);
    break;
   case 3:worstfit(npr,temp,pr,nh);
   break;
   case 4:exit (0);
   break;
   default:printf("\nWrong choice......!");
  }
 }
 while(ch!=4);
 return 0;
}
//First Fit
void firstfit(int npr,int hol[10],int pr[10],int nh)
{
 int i,j,k,flag=0;
 for(i=0;i<npr;i++)
 {
  flag=0;
  for(j=0;j<nh;j++)
  {
   if(pr[i]<hol[j])
   {
    hol[j]=hol[j]-pr[i];
    printf("\nMemory is Allocated to Process %d :(%d)",i+1,pr[i]);
    flag=1;
    break;
   }
   else if(pr[i]==hol[j])
   {
    flag=1;
    printf("\nMemory is Allocated to Process %d :(%d)",i+1,pr[i]);
    for(k=j;k<nh-1;k++)
    {
     hol[k]=hol[k+1];
    }
    nh--;
    break;
   }
  }
  if(flag==0)
  {
   printf("\n Hole is not Available.....");
   break;
  }
  display(nh,hol);
 }
}
//Best fit
void bestfit(int npr,int hol[10],int pr[10],int nh)
{
 int i,j,k,min,flag;
 for(i=0;i<npr;i++)
 {
  flag=0;
  for(j=0;j<nh;j++)
  {
   if(pr[i]<=hol[j])
   {
    flag=1;
    min=j;
    for(k=j;k<nh;k++)
    {
     if((hol[min]>hol[k])&&(pr[i]<=hol[k]))
     min=k;
    }
    if(pr[i]<hol[min])
    {
     printf("\nMemory is Allocated to Process %d :(%d)",i+1,pr[i]);
     hol[min]=hol[min]-pr[i];
     break;
    }
    else if(pr[i]==hol[min])
    {
     printf("\nMemory is Allocated to Process %d :(%d)",i+1,pr[i]);
     for(k=min;k<nh-1;k++)
     hol[k]=hol[k+1];
     nh--;
     break;
    }
   }
  }
  if(flag==0)
  {
   printf("\n Hole is not Available.....");
   break;
  }
  display(nh,hol);
 }
}
//worst fit
void worstfit(int npr,int hol[10],int pr[10],int nh)
{
 int i,j,k,max,flag;
 for(i=0;i<npr;i++)
 {
  flag=0;
  for(j=0;j<nh;j++)
  {
   if(pr[i]<=hol[j])
   {
    printf("\nMemory is Allocated to Process %d :(%d)",i+1,pr[i]);
    flag=1;
    max=j;
    for(k=j;k<nh;k++)
    {
     if((hol[max]<hol[k])&&(pr[i]<=hol[k]))
     max=k;
    }
    if(pr[i]<hol[max])
    {
     printf("\nCPU is Allocated for process %d",i+1);
     hol[max]=hol[max]-pr[i];
     break;
    }
    else if(pr[i]==hol[max])
    {
     printf("\nCPU is Allocated for process %d",i+1);
     for(k=max;k<nh-1;k++)
     hol[k]=hol[k+1];
     nh--;
     break;
    }
   }
  }
  if(flag==0)
  {
   printf("\n Hole is not Available.....");
   break;
  }
  display(nh,hol);
 }
}
void display(int nh,int hol[10])
{
 int i=0;
 printf("\nHoles:");
 for(i=0;i<nh;i++)
 {
  printf("%d\t",hol[i]);
 }
}

