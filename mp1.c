#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() { /*indica lo que devuelve el programa principal*/
  pid_t pid, pid_hijo; /*Zona de declaración de variables, se definen 2 variables tipo pid_t para almacenar los pids de los procesos */
  
  pid = fork(); 
  
    if ( pid == 0){
        printf("julio");
    }
    
    else{
        pid_hijo = wait(NULL);
        printf("Soy el padre y mi pid es: %d \n",getpid());
        printf("El pid de mi hijo es: %d \n" , pid_hijo);
        
    }
    
exit(0);
}
