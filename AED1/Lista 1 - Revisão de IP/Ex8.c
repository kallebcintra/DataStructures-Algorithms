/*programa na linguagem C para ler dois números inteiros e calcular o máximo divisor comum desses números*/

#include <stdio.h>

int main()
{
    int n1, n2;
    int mdc;
    int i;

    //Imput dos dois números inteiros
    scanf("%d %d", &n1, &n2);

    for(i = 1; i <= n1 && i <= n2; i++)
    {
        // checa se i é fator de ambos os números
        if(n1 % i == 0 && n2 % i == 0) mdc = i;
    }

    printf("%d\n", mdc);

    return 0;
}