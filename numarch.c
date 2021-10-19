#include <unistd.h>

int main(){

    // Se crea el Pipe de dos procesos
    int fd[2];
    pipe(fd);

    // Se dividen los procesos de aquí en adelante con un fork
    int pid = fork();

    // Proceso hijo porque pid == 0
    if(pid == 0){
        //configurar pipe
        close(STDIN_FILENO);
        dup(fd[0]);
        close(fd[1]);
        // Ejecutar hijo que va a ejecutar wc
        execlp("wc","wc","-l",NULL);

    } else {
        // Proceso padre

        //Configurar el pipe
        //Salida estandar para el proceso padre
        close(STDOUT_FILENO);
        // Se conecta con la salida del pipe
        dup(fd[1]);
        //No se necesita leer la entrada del pipe
        close(fd[0]);

        // Ejecuta aquí ls
        // (nombre del archivo a ejecutar, como se llama el proceso, argumentos)
        execlp("ls","ls",NULL);

    }

    return 0;
}