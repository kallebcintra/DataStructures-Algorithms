/*programa na linguagem C para verificar se um determinado número inteiro positivo é primo*/

#include <stdio.h>

int main()
{
    int n;
    int i;
    int Contador = 0;

    //Imput do número a ser testado primo
    scanf("%d", &n);
    if(n <= 0){
        printf("erro\n");
        return 0;
    }

    //Checa se o número possui apenas dois divisores
    for(i = 1; i < n+1; i++)
    {
        if(n % i == 0) Contador++;
    }

    if(Contador == 2) printf("primo\n");
    else printf("nao\n");

    return 0;
}