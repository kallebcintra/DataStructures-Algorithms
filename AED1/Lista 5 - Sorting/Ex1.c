/* AED1 Lista 5 Ex.1 (Separando Números Pares de Ímpares) - 2022/1 */
/* Complexidade de Tempo: O(n^2) */
/* Método de Ordenação escolhido: Insertion Sort */

#include <stdio.h>
#include <stdlib.h>

void insertionSortCrescent(int arr[], int n);
void insertionSortDecrescent(int arr[], int n);
void printArray(int arr[], int n);

int main()
{
    int Vus[101];
    int Vp[101], Vi[101];
    int n;
    int i;
    int contP = 0, contI = 0; 

    // N° de Elementos a serem ordenados
    scanf("%d", &n);
    if(n < 1 || n > 100) return 0;

    // Imput dos n elementos
    for(i = 0; i < n; i++)
    {
        scanf("%d", &Vus[i]); 
        if(Vus[i] %2 == 0) // Elementos Pares vão para o vetor Vp
        {
            Vp[contP] = Vus[i];
            contP++;
        }
        else // Elementos Ímpares vão para o vetor Vi
        {
            Vi[contI] = Vus[i];
            contI++;
        }
    }

    if(Vp != NULL){
        insertionSortCrescent(Vp, contP);
        printArray(Vp, contP);
    }

    if(Vi != NULL){
        insertionSortDecrescent(Vi, contI);
        printArray(Vi, contI);
    }



    return 0;
}

//
// Função ordena um vetor usando Insertion Sort (Crescente)
//
void insertionSortCrescent(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
  
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//
// Função ordena um vetor usando Insertion Sort (Decrescente)
//
void insertionSortDecrescent(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
  
        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//
// Função printa um vetor
//
void printArray(int arr[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}