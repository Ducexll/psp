#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() { /*indica lo que devuelve el programa principal*/
  pid_t pid, pid_hijo; /*Zona de declaración de variables, se definen 2 variables tipo pid_t para almacenar los pids de los procesos */
  
  pid = fork(); 
  
    if ( pid == 0){
        
        pid_hijo = fork(); 

            if(pid_hijo ==0){
                printf("Soy el nieto y mi pid es: %d \n",getpid());
                printf("El pid de mi padre es: %d \n" , getppid());
            } 
            else{
                wait(NULL);
                printf("Soy el hijo y mi pid es: %d \n",getpid());
                printf("El pid de mi padre es: %d \n" , getppid());
            }
    }
    
    else{
        pid_hijo = wait(NULL);
        printf("Soy el padre y mi pid es: %d \n",getpid());
        printf("El pid de mi hijo es: %d \n" , pid_hijo);
        
    }
    
exit(0);
}
