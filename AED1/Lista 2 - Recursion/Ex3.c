/*Programa em C para converter número decimal em binário, usando recursividade*/

#include <stdio.h>
 
int find(int decimal_number);

int main()
{
    int n;
    int num;
    int i;

    scanf("%d", &n);
    if(n < 1 || n > 1000){
        printf("erro\n");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        scanf("%d", &num);
        if(num < 0 || num > 1000000){
            printf("erro\n");
            return 0;
        }
        printf("%d\n", find(num));
    }

    return 0;
}

int find(int decimal_number)
{
    if (decimal_number == 0) return 0;
    else return (decimal_number % 2 + 10 * find(decimal_number / 2));
}