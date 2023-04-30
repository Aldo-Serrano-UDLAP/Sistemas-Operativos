// Librerias
#include <stdio.h>
#include <pthread.h>

// Declaracion de variable contador global
int count = 0;
// Declaracion de Mutex
pthread_mutex_t mutex;

// Funcion que incrementa el valor del contador
void* countUP(void* arg) 
{
    pthread_mutex_lock(&mutex); 
    // Inicio región crítica
    count++;
    // Fin región crítica
    pthread_mutex_unlock(&mutex);
    pthread_exit( NULL );
}

// Funcion principal
int main(void) 
{
    // Declaracion de hilos
    pthread_t thread1, thread2, thread3, thread4, thread5;
    
    // Crear el mutex
    pthread_mutex_init(&mutex, 0);
    
    // Creacion de los hilos
    pthread_create(&thread1, NULL, countUP, NULL);
    pthread_create(&thread2, NULL, countUP, NULL);
    pthread_create(&thread3, NULL, countUP, NULL);
    pthread_create(&thread4, NULL, countUP, NULL);
    pthread_create(&thread5, NULL, countUP, NULL);
    
    // Esperar hasta que terminen los hilos por orden
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    pthread_join(thread5, NULL);
    
    // Destruir Mutex
    pthread_mutex_destroy(&mutex);
    
    printf("Valor final de contador: %d\n", count);
    return 0;
}
