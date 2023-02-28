/*receber a quantidade de semanas em que a fábrica pretende produzir e calcular e mostrar a quantidade mínima e máxima 
de unidades de produto que serão produzidas.*/

#include <stdio.h>

int main()
{
    int Weeks;
    int ProdMax, ProdMin;

    //Quantidade de Semanas
    scanf("%d", &Weeks);
    if(Weeks < 1){
        printf("erro\n");
        return 0;
    }

    // Cálculo das produções mínimas e máximas
    ProdMax = ((Weeks*5)*8)*5 + ((Weeks*2)*8)*3;
    ProdMin = ((Weeks*5)*8)*4 + ((Weeks*2)*8)*3;

    printf("%d\n", ProdMin);
    printf("%d\n", ProdMax);

    return 0;
}