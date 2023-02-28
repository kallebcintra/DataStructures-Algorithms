/* AED1 Lista 5 Ex.3 (Ordenação) - 2022/1 */
/* Complexidade de Tempo: O(n^2) */
/* Método de Ordenação escolhido: Insertion Sort */

#include <stdio.h>
#include <stdlib.h>

int nthSmallest(int arr[], int sizeArr, int n);

int main()
{
    int V[1001];
    int n, i;
    int l, k;
    int lSmallest;
    int kSmallest;

    scanf("%d", &n);
    if(n < 1 || n > 1000) return 0;

    for(i = 0; i < n; i++){
        scanf("%d", &V[i]);
        if(V[i] < 1 || V[i] > 10000) return 0;
    }

    scanf("%d %d", &l, &k);
    if(l > n || k > n) return 0;

    lSmallest = nthSmallest(V, n, l);
    kSmallest = nthSmallest(V, n, k);

    printf("%d\n", lSmallest + kSmallest);

    return 0;
}

int nthSmallest(int arr[], int sizeArr, int n)
{
    int i, key, j;
    int x;

    for (i = 1; i < sizeArr; i++)
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

    x = arr[n - 1];

    return x;
}