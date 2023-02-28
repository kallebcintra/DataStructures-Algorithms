/*Calculo da conta de água de contas residenciais(1), comerciais(2) ou industriais(3)*/

#include <stdio.h>

int main()
{
    int numConta;
    int tipoConta;
    double consumoConta;
    double valTotal;

    scanf("%d", &numConta);
    if(numConta < 1 || numConta > 999999999){
        printf("erro\n");
        return 0;
    }

    scanf("%d", &tipoConta);
    if(tipoConta != 1 && tipoConta != 2 && tipoConta != 3){
        printf("erro\n");
        return 0;
    }

    scanf("%lf", &consumoConta);
    if(consumoConta < 0){
        printf("erro");
        return 0;
    }

    if(tipoConta == 1)
    {
        valTotal = 5.00 + (0.05*consumoConta);
    }
    else if(tipoConta == 2)
    {
        if(consumoConta <= 80.00) valTotal = 500.00;
        else valTotal = 500.00 + (0.03*(consumoConta - 80.00));
    }
    else if(tipoConta == 3)
    {
        if(consumoConta <= 100.00) valTotal = 800.00;
        else valTotal = 800.00 + (0.04*(consumoConta - 100.00));
    }

    printf("%.2lf\n", valTotal);

    return 0;
}

