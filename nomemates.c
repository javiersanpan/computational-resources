#include <signal.h>
#include <stdio.h>
#include <unistd.h>

// Sobrescribir control C

void handle(int numsignal){
    // imprime el número de la señal
    printf("No se ejecutó: %d\n",numsignal);
}

int main(){
    // señal dos se cambia por la función handle
    // como no es handle() no se está ejecutando
    // señal 2 es SIGINT control C que causa que se termine inmediatamente
    // la unica que no peude sobrescsribir es 9
    signal(2,handle);

        while(1){
            printf("Trabajando\n");
            sleep(1);
        }
    
    return 0;
}