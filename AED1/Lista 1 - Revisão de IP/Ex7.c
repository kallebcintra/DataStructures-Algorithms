/*Grau de pureza do aço produzido classificado de acordo com o resultado de três testes*/

#include <stdio.h>

int main()
{
    int CC;
    int DR;
    int RT;
    int grauPureza = 0;

    //Imput Conteúdo de Carbono
    scanf("%d", &CC);
    if(CC < 0 || CC > 50){
        printf("erro\n");
        return 0;
    }

    //Imput Dureza de Rockwell
    scanf("%d", &DR);
    if(DR < 0 || DR > 100){
        printf("erro\n");
        return 0;
    }

    //Imput Resistência à Tração
    scanf("%d", &RT);
    if(RT < 0 || RT > 100000){
        printf("erro\n");
        return 0;
    }

    if(CC < 7 && DR > 50 && RT > 80000) grauPureza = 10;
    else if(CC < 7 && DR > 50 && RT <= 80000) grauPureza = 9;
    else if(CC < 7 && DR <= 50 && RT <= 80000) grauPureza = 8;
    else if(CC >= 7 && DR <= 50 && RT <= 80000) grauPureza = 7;

    printf("%d\n", grauPureza);

    return 0;
}