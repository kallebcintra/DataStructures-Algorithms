/*Programa em C para imprimir até o n-ésimo termo da “Série de Fibonacci”, usando o conceito de recursividade*/

#include <stdio.h>

int Fibonacci(int);
 
int main()
{
   int n, j;
   int i = 0;
 
   scanf("%d",&n);
   if(n < 0 || n > 1000){
        printf("erro\n");
        return 0;
   }
 
   for (j = 1; j <= n+1; j++)
   {
      printf("%d ", Fibonacci(i));
      i++; 
   }
 
   return 0;
}
 
int Fibonacci(int n)
{
   if ( n == 0 ) return 0;
   else if ( n == 1 ) return 1;
   else return ( Fibonacci(n-1) + Fibonacci(n-2) );
}