#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 20

// no olvidar el -lpthread al compilar

void *printHola(void *arg){
    // este recibe el void que como establecimos abajo realmente es un char no un void
    char * p = (char *)arg;

    printf("Hola desde este hilo %s\n",p);

    // dentro de un hilo le indica al hilo principal que ya terminó
    pthread_exit(NULL);
}

int main(){
    // sea hace un arreglo de todos los hilos
    pthread_t threads[NUM_THREADS];
    
    // esta es una cadena de caracteres que se pasará en la función
    char *s = "Soy un hilo";

    for(int i = 0; i < NUM_THREADS; i++){
        //(id del hilo, modificador, función, argumento para función)
        // el (void *) es para que pase el argumetno como un void
        pthread_create(&threads[i],NULL,printHola,(void *)s);

    }

    // esto espera a que terminen todos los hilos
    pthread_exit(NULL);

    return 0;
}