// Librerias
#include <stdio.h>
#include <pthread.h>

// Declaracion de Mutex
pthread_mutex_t mutex;
// Declaracion de variables para condicion
pthread_cond_t cond_id;
// Variable global
int hello_written = 0;

// Funcion que ejecuta la primera parte del mensaje "Hello"
void* hello(void* arg) 
{
    // Aquí va el código para escribir "Hello " y tratar la región crítica
    pthread_mutex_lock(&mutex);
    printf("Hello ");
    hello_written = 1;
    pthread_cond_signal(&cond_id); 
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

// Funcion que ejecuta la segunda parte del mensaje "world!\n"
void* world(void* arg) 
{
    // Aquí va el código para el mutex
    pthread_mutex_lock(&mutex);

    while(hello_written == 0)
    {
        // Aquí va el código para la variable de condición
        pthread_cond_wait(&cond_id, &mutex);
    }
    // Aquí va el código para escribir "world!\n" y liberar la región crítica
    printf("world!\n");
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

// Funcion principal
int main(void) 
{
    // Declaracion de hilos
    pthread_t thread1, thread2;
    // Creacion de Mutex y variable condicion
    pthread_mutex_init(&mutex, 0);
    pthread_cond_init(&cond_id, 0);
    // Crear los hijos
    pthread_create(&thread1, NULL, hello, NULL);
    pthread_create(&thread2, NULL, world, NULL);
    // Espera a los hilos en orden
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    // Destruir mutex y las variables de condición
    pthread_cond_destroy( &cond_id );
    pthread_mutex_destroy( &mutex );
    
    return 0;
}