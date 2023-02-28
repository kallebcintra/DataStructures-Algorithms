/*programa na linguagem C para verificar se um número inteiro é perfeito, ou seja, se a soma dos seus divisores 
(exceto o próprio número) é igual a ele mesmo. Por exemplo, o número 28 é perfeito porque 28 = 1+2+4+7+14*/ 

#include <stdio.h>

int main()
{
    int n;
    int sumDiv = 0;
    int i;

    //Imput do número inteiro a ser verificado
    scanf("%d", &n);
    if(n <= 0){
        printf("erro\n");
        return 0;
    }

    //Obtendo a soma dos divisores
    for(i = 1; i < n; i++)
    {
        if(n % i == 0) sumDiv += i;
    }

    if(sumDiv == n) printf("perfeito\n");
    else printf("imperfeito\n");

    return 0;
}
