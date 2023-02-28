/*programa em C usando recursividade capaz de determinar o número reverso de um certo número natural estritamente positivo n 
fornecido como entrada*/

#include <stdio.h>

int numReverso( int , int );

int main()
{
    int n, resultado;

    scanf("%d", &n);
    if(n < 1 || n > 1000000){
        printf("erro\n");
        return 0;
    }

    resultado = numReverso(n, 0);

    printf("%d\n", resultado);
    return 0;
}

int numReverso(int num, int rev)
{
    if(num == 0) return rev;
    else return numReverso (num/10, rev*10 + num%10);
}