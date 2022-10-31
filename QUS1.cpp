 #include <stdio.h>
 #include <unistd. h>
 #include <stdlib. h>

 int main (int argc , char *argv[])
 {
 printf("pid of sample4.c is = %d\n"
,, getpid());
" C "
 char *args[ ] = {"sample4copy"
"programe" , NULL};

 execv (" . / sample4copy" , args);
 printf ( "Now back to sample4.c");
  return 0;
 }
