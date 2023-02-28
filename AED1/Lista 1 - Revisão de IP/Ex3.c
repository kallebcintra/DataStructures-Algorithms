/*Programa em C para determinar a soma dos n primeiros números primos*/

#include <stdio.h>

//Função checa se um número é primo
int eprimo( int j );

int main()
{
    int n;
    int i = 0, j = 1;
    int sum = 0;

    //Imput da quantidade dos primeiros n primos a serem somados 
    scanf("%d", &n);
    if(n <= 0 || n > 1000){
      printf("erro\n");
      return 0;
    }

    while(1) 
    {
       j++;
       if(eprimo(j)){
          sum += j;
          i++;
       }

       if(i == n){
          break;
       }
    }

    printf("%d\n", sum);
    return 0;
}

int eprimo( int j )
{
    int Contador = 0;
    int i;

    for(i = 2; i <= j/2; i++) 
    {
       if(j % i == 0){
          Contador = 1;
       }
    }

    if(Contador == 0) return 1;
    else return 0;
}