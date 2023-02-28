/*programa em C para calcular o rendimento obtido em uma aplicação financeira pré-fixada após um certo número de anos*/

#include <stdio.h>

int main()
{
    float p;
    float t, c;
    int n, i;
    double valAno;

    scanf("%f", &p);
    if(p <= 0){
        printf("erro\n");
        return 0;
    }

    scanf("%d", &n);
    if(n <= 0){
        printf("erro\n");
        return 0;
    }

    scanf("%f", &t);
    if(t <= 0){
        printf("erro\n");
        return 0;
    }

    scanf("%f", &c);
    if(c <= 0 || c > 100){
        printf("erro\n");
        return 0;
    }

    //Cálculo e output do capital resultante ao final de cada ano
    for(i = 0; i < n; i++)
    {
        valAno = p+(p*(t/100)) - (p*(t/100))*(c/100);
        printf("%.2lf", valAno);
        printf("\n");
        p = valAno;
    }

    return 0;
}