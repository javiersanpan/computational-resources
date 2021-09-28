#include <stdio.h>
#include <unistd.h>

int main(){
    // este bucle infiníto crea procesos infinitos, y como se llenan los ID
    // ya no se pueden usar los demás programas
    // while(true){


    int pid = fork();
    /* A partir de esta línea, van a haber dos procesos que van a ser idénticos
    van a tener el mismo código, excepto que pid en el hijo va a ser 0, y en el padre 
    va a ser diferente a 0 */

    if(pid == 0){
        printf("Soy el proceso hijo\n");
    } else {
        printf("Soy el proceso padre\n");
    }
    //}
    return 0;
}