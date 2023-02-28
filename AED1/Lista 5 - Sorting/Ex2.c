/* AED1 Lista 5 Ex.2 (Insertion - Selection) - 2022/1 */
/* Complexidade de Tempo: O(n^2) */
/* Métodos de Ordenação utilizados: Insertion Sort e Selection Sort */

#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n, int *changes);

void insertionSort(int arr[], int n, int value, int *changes);

int main()
{
    int n, i;

    scanf("%d", &n);
    if(n < 1 || n > 1000) return 0;

    int selection[n];
    int swapSS = 0;

    for(i = 0; i < n; i++){
        scanf("%d", &selection[i]);
    }

    int insertion[n];
    int swapIS = 0;

    for(i = 0; i < n; i++){
        insertionSort(insertion, i, selection[i], &swapIS);
    }

    selectionSort(selection, n, &swapSS);
    
    printf("%d\n", swapIS - swapSS - 1);

    return 0;
}

void selectionSort(int arr[], int n, int *changes)
{
    int i, j;
    int min;
    int temp;

    for(i = 0; i < n - 1; i++) {
        min = i;

        for(j = i + 1; j < n; j++){
            if(arr[j] < arr[min]) min = j;
        }

        if(min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
            (*changes)++;
        }
    }
}

void insertionSort(int arr[], int n, int value, int *changes)
{
    int i, j; 
    int temp1, temp2;

    for(i = 0; i < n; i++)
    {
        if(arr[i] > value)
        {
            for(j = n; j >= i; j--)
            {
                arr[j] = arr[j-1];
                (*changes)++;
            }
            arr[i] = value;

            return;
        }
    }

    arr[n] = value;
    (*changes)++;
}

//==============================================================================
// Código Anterior (Ignorar)
//==============================================================================

/*#include <stdio.h>
#include <stdlib.h>

long long int insertionSortSwaps(int ar[], int n, int value);
long long int selectionSortSwaps(int arr[], int n);
//void swap(int *xp, int *yp);
long int IS(int ar[], int n);

int main()
{
    int V[1001], V2[1001];
    int n;
    int i;
    int contIS = 0, contSS = 0;
    long long int r;

    // N° de Elementos a serem ordenados
    scanf("%d", &n);
    if(n < 1 || n > 1000) return 0;

    // Imput dos n elementos
    for(i = 0; i < n; i++)
    {
        scanf("%d", &V[i]);
        //V2[i] = V[i];
    }

    //contIS = insertionSortSwaps(V, n);
    //contIS = insertionSortSwaps(V, n);
    for(i = 0; i < n; i++) contIS = insertionSortSwaps(V2, i, V[i]);

    contSS = selectionSortSwaps(V, n);

    if(contIS > contSS){
        r = contIS - contSS;
    }
    else if(contIS < contSS){
        r = contSS - contIS;
    }

    //printf("%d\n", contIS);
    //printf("%d\n", contSS);
    printf("%lld\n", r);

    return 0;
}

//
// Função ordena um vetor usando Insertion Sort (Crescente)
//
long long int insertionSortSwaps(int ar[], int n, int value)
{
    int moveMe;
    int i, j;
    int tmp1, tmp2;
    long long int swaps = 0;

    if (n <= 1){
        return 0;
    }

    for (i = 1; i < n; i++)
    {
        moveMe = ar[i];
        j = i;
        while (j > 0 && moveMe < ar[j - 1])
        {
            ar[j] = ar[j - 1];
            j--;
            swaps++;
        }
        ar[j] = moveMe;
    }

    ar[n] = value;
    swaps++;

    return swaps;
}


//
// Função ordena um vetor usando Selection Sort (Crescente)
//
long long int selectionSortSwaps(int arr[], int n)
{
    long long int x = 0;
    int i, j, min;
    int temp;
 
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min]){
                min = j;
            }
 
            if(min != i){
                temp = arr[min];
                arr[min] = arr[i];
                arr[i] = temp;
                x++;
            }
        }
    }

    return x;
}*/