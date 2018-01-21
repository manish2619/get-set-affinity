#define _GNU_SOURCE
#include<sched.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#define CPU 0

void error(char *ptr)
{
    perror(ptr);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{   
      
    ssize_t setaffinity,getaffinity; 
    pid_t pid;                       /*variable for PID*/
    cpu_set_t my_set;                /*CPU_SET Structure*/


    pid=getpid();         
    CPU_ZERO(&my_set);  
    CPU_SET(CPU,&my_set);
                
              /**Set-Affinity**/
    setaffinity=sched_setaffinity(0,sizeof(cpu_set_t),&my_set);
    if(setaffinity ==-1)
    {
      error("sched_setaffinity");
    }
    printf("setaffinity for PID %d to CPU %d\n",pid,CPU);
              
              /**Get-Affinity**/
   
    getaffinity=sched_getaffinity(0,sizeof(cpu_set_t),&my_set);
    if(getaffinity ==-1)
    {
     error("sched_getaffinity");
    }
    return 0;
    
}
