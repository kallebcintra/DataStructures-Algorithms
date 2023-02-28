/*Programa em C para achar o fatorial duplo de um número n, usando recursividade*/

// Incompleto
#include <stdio.h>

int fatorialDuplo( int n );

int main()
{
    int num; 
    unsigned long long int r;

    scanf("%d", &num);
    if(num < 1 || num > 100){
        printf("erro\n");
        return 0;
    }

    r = fatorialDuplo(num);
    printf("%lld\n", r);

    return 0;
}

int fatorialDuplo( int n )
{
    if (n == 0 || n==1) return 1;
    else return n * fatorialDuplo(n-2);
}