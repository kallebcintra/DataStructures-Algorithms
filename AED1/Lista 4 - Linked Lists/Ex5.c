/* AED1 Lista 4 Ex.5 (Caminho) - 2022/1 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node node;
typedef struct list list;

struct node{
    char rua[21];
    node *next;
};

struct list{
    node *first;
    node *last;
    int size;
};

list newList(); //Função cria uma Lista duplamente encadeada

void cleanUp(list *l); //"Limpa" uma Lista duplamente encadeada

bool empilhar(list *l, char *W); //Insere as palavras informadas em nodes da lista

int desempilhar(list *l, char *last); //Realiza a troca das palavras

int main()
{
    char word[21];
    list pilha;

    pilha = newList();

    //Imput do user, cada palavra, até a palavra "ESCOLA", assim como a chamada da função empilhar
    while(true)
    {
        scanf("%s", word);
        if(strcmp(word, "ESCOLA") == 0) break;
        empilhar(&pilha, word);
    }

    //Chamadas da função desempilhar e série de condições para output desejado
    while(true)
    {
        desempilhar(&pilha, word);
        if(strcmp(word, "ESQUERDA") == 0) printf("Vire a DIREITA ");
        else printf("Vire a ESQUERDA ");

        if(pilha.size == 0)
        {
            printf("para chegar em CASA.\n");
            break;
        }

        desempilhar(&pilha, word);
        printf("na rua %s.\n", word);
    }

    return 0;
}

list newList()
{
    list p;

    p.first = NULL;
    p.last = NULL;
    p.size = 0;

    return p;
}

void cleanUp(list *l)
{
    node *currnode;
    node *temp;

    for(currnode = l -> first; currnode != NULL; currnode = temp)
    {
        temp = currnode -> next;
        free(currnode);
    }

    l -> first = NULL;
    l -> last = NULL;
    l -> size = 0;
}

bool empilhar(list *l, char *W)
{
    node *new;

    new = (node *) malloc(sizeof(node)*1);

    strcpy(new -> rua, W);
    new -> next = NULL;

    if(l -> first == NULL) l -> first = new;
    if(l -> last != NULL) (l -> last) -> next = new;

    l -> last = new;
    l -> size++;

    return true;
}

int desempilhar(list *l, char *last)
{
    node *p = NULL;

    if(l -> size == 0) return -1;

    if(l -> size == 1)
    {
        strcpy(last, l -> first -> rua);
        cleanUp(l);
        return 1;
    }

    for(p = l -> first; p -> next != l -> last; p = p -> next);

    p -> next = NULL;
    strcpy(last, l -> last -> rua);
    free(l -> last);
    l -> last = p;
    l -> size--;

    return 1;
}