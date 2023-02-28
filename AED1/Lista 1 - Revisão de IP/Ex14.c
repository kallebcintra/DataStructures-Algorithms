/*Programa em C que recebe o valor de n e calcule o Número de Fibonacci correspondente e a sua fatoração*/

#include <stdio.h>

int main()
{
    int n;
    int t1 = 0, t2 = 1, nextTerm = 0, i;

    scanf("%d", &n);
    if(n < 3 || n > 100){
        printf("O numero de ordem deve ser maior ou igual a 3 e menor ou igual a 100 - programa cancelado\n");
        return 0;
    }

    if(n == 0 || n == 1) printf("%d", n); 
    else nextTerm = t1 + t2;

    for (i = 3; i <= n; ++i)
    {
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }
    printf("%d", t2);

    return 0;
}