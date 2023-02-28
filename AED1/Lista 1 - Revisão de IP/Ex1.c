/*Programa em c que recebe a distância que separa as cidades, a velocidade do primeiro automóvel e a velocidade do segundo automóvel e
determinar o momento e o local em que os automóveis se encontram*/

#include <stdio.h>

int main()
{
    float distCity;
    int V1, V2;
    double Local, Momento;

    //Imput Distância entre as cidades
    scanf("%f", &distCity);
    if(distCity < 0){
        printf("erro\n");
        return 0;
    }

    //Imput das velocidades do carro 1(V1) e 2(V2)
    scanf("%d %d", &V1, &V2);
    if(V1 < 0 || V2 < 0){
        printf("erro\n");
        return 0;
    }

    Momento = distCity / (V1 + V2);
    Local = V1 * Momento;

    printf("%.2lf\n", Momento);
    printf("%.1lf\n", Local);

    return 0;
}