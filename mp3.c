#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() { /*indica lo que devuelve el programa principal*/
  pid_t pid, pid_hijo, pid2; /*Zona de declaración de variables, se definen 2 variables tipo pid_t para almacenar los pids de los procesos */
  
  pid = fork(); 
  
    if ( pid == 0){

        printf("Soy el hijo1 y mi pid es: %d \n",getpid());
        printf("El pid de mi padre es: %d \n" , getppid());
       
    }
    
    else{

        pid = wait(NULL);
        printf("Soy el padre y mi pid es: %d \n",getpid());
        printf("El pid de mi hijo1 es: %d \n" , pid);
        pid2 = fork();

        if(pid2 == 0){

             printf("Soy el hijo2 y mi pid es: %d \n",getpid());
             printf("El pid de mi padre es: %d \n" , getppid());
        }
        else{  
        pid2 = wait(NULL);
        printf("El pid de mi hijo2 es: %d \n" , pid2);

        }
    
    }
    
exit(0);
}
