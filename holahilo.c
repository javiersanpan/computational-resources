#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 20

int saldo;

// no olvidar el -lpthread al compilar

void *printHola(void *arg){
    // este recibe el void que como establecimos abajo realmente es un char no un void
    char * p = (char *)arg;

    printf("Hola desde este hilo %s\n",p);

    // dentro de un hilo le indica al hilo principal que ya terminó
    pthread_exit(NULL);
}

// Se tiene que poner ese valor como inicializador para que el primer
// valor pueda pasar y no sea un 'deadlock'
pthread_mutex_t lockSaldo = PTHREAD_MUTEX_INITIALIZER;

void * suma100(void *arg){
// Con esta función hacemos que en cada hilo le sume 100
    int lsaldo = saldo;
    // aquí le pasamos el candado de mutex
    pthread_mutex_lock(&lockSaldo);
    lsaldo += 100;
    saldo = lsaldo;

    // aquí se desbloquea
    pthread_mutex_unlock(&lockSaldo);

    pthread_exit(NULL);
// Este código utiliza variables globales, por lo tanto es una región crítica
// Cuando hay una región crítica para que no falle al ejecutrase al mismo tiempo
// se tiene que usar un race condition
// En este caso se va a utilizar lock/mutex
}

int main(){
    // sea hace un arreglo de todos los hilos
    pthread_t threads[NUM_THREADS];

    saldo = 0;
    
    // esta es una cadena de caracteres que se pasará en la función
    char *s = "Soy un hilo";

    for(int i = 0; i < NUM_THREADS; i++){
        //(id del hilo, modificador, función, argumento para función)
        // el (void *) es para que pase el argumetno como un void
        pthread_create(&threads[i],NULL,suma100,(void *)s);

    }

    for(int i = 0;i < NUM_THREADS;i -= -1){
        pthread_join(threads[i],NULL);
    }

    // Se tiene que hacer el print del saldo una vez que ya hayan corrido todos los hilos
    // entonces se tiene que hacer el print una vez que haya terminado, así que tenemos que
    // hacer una función que haga el join, tiene que esperar a que el hilo que se pase como argumento
    // termine, y una vez que se termine, continua
    // Recordemos que en este ejemplo hicimos 20 hilos
    

    printf("Saldo final es %d\n",saldo);

    // esto espera a que terminen todos los hilos
    pthread_exit(NULL);

    return 0;
}