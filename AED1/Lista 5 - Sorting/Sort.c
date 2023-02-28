#include "Sort.h"


//==============================================================================
// Funções Auxiliares e de Execução
//==============================================================================

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

//
// swap
//
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//==============================================================================
// Selection Sort
//==============================================================================

//
// Função ordena um vetor usando Selection Sort (Crescente)
//
void selectionSort(int arr[], int n)
{
    int i, j, min;
 
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min]) min = j;
 
            if(min != i) swap(&arr[min], &arr[i]);
        }
    }
}

//
// Função ordena um vetor usando Selection Sort (Decrescente)
//
void selectionSortDecrescent(int arr[], int n)
{
    int i, j, max;
 
    for (i = 0; i < n - 1; i++)
    {
        max = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[max]) max = j;
 
            if(max != i) swap(&arr[max], &arr[i]);
        }
    }
}

//==============================================================================
// Insertion Sort
//==============================================================================

//
// Função ordena um vetor usando Insertion Sort (Crescente)
//
void insertionSort(int arr[], int n)
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

//==============================================================================
// Bubble Sort
//==============================================================================

//
// Função ordena um vetor usando Bubble Sort (Não Ideal) (Crescente)
//
void bubbleSortBeta(int arr[], int n)
{
    int i, j;

    for(i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);
        }
    }
}

//
// Função ordena um vetor usando Bubble Sort (ideal) (Crescente)
//
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;

    for(i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        break;
    }
}

//
// Função ordena um vetor usando Bubble Sort (Decrescente)
//
void bubbleSortDecrescent(int arr[], int n)
{
    int i, j;
    bool swapped;

    for(i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        break;
    }
}

//==============================================================================
// Merge Sort
//==============================================================================

//
// Função que "Merge" os Vetores do MergeSort
//
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    int L[n1], R[n2];
  
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }
  

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
  
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

//
// Função que ordena, em conjunto com a função "Merge" um vetor Usando Merge Sort (Crescente) 
//
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
  
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
    }
}

//==============================================================================
// Quick Sort
//==============================================================================

/* Esta função toma o último elemento como pivô, coloca o elemento pivô em sua posição correta em 
array, e coloca tudo menor (menor que pivô) à esquerda do pivô e todos os elementos maiores à direita de pivô */
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];
    int i = (low - 1);
    int j;
  
    for (j = low; j <= high - 1; j++) 
    {  
        if (arr[j] < pivot) 
        { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
//
// Função principal que ordena um vetor usando Quick Sort (Crescente)
//
void quickSort(int arr[], int low, int high) 
{
    int pi;

    if (low < high) 
    { 
        pi = partition(arr, low, high); 

        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 