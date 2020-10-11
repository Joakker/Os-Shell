#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

/*
 * int main(int argc, char* argv[]){
 *
 *     int n = atoi(argv[1]);
 *
 *     for(int i=0; i < n; i++){
 *
 *         //Crea n procesos "defunct"
 *         if(fork() == 0) exit(0);
 *
 *     }
 *
 *     //Se obtiene el pid
 *     int pid = getpid();
 *
 *     printf("%d\n", pid);
 *
 *     char in[10];
 *
 *     while(1){
 *
 *         //si se escribe la palabra "kill" termina el programa,
 *         //acabando con los procesos defunct
 *         scanf("%s",in);
 *         if(strcmp(in,"kill")==0) kill(pid,3);
 *     };
 * }
 */
