#include <stdio.h>
#include <unistd.h>

int main(){

    int pid = fork();
    /* A partir de esta línea, van a haber dos procesos que van a ser idénticos
    van a tener el mismo código, excepto que pid en el hijo va a ser 0, y en el padre 
    va a ser diferente a 0 */

    if(pid == 0){
        printf("Soy el proceso hijo = pid: %d\n",pid);
    } else {
        printf("Soy el proceso padre = pid: %d\n",pid);
    }

    return 0;
}