#include <stdio.h>

void intercambioVariables(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void cerosHastaLaIzquierda(int arreglo[], int n) 
{
    int i, j;
    for(i=0;i<n;i++)
    {
        if(arreglo[i]==0)
        {
            j = i;
            do
            {
                intercambioVariables(&arreglo[j],&arreglo[j-1]);
                j--;
            } while (j!=0);
        }
    }
    
}

int main(void) 
{
    int arreglo[] = {14, 2, 0, 7, 0, 8, 68, 1, 0};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    cerosHastaLaIzquierda(arreglo, n);

    printf("Lista ordenada con ceros al principio: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    return 0;
}