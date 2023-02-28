/* AED1 Lista 4 Ex.7 (A lista de Arya (série “Game of Thrones”)) - 2022/1 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node node;
typedef struct List list;

struct Node{
    int value;
    node *next;
};

struct List{
    node *first;
    node *last;
    int size;
};

list newList();

void cleanUp(list *l);

bool createList(list *l, int p);

bool insertAfterList(list *l, int p, int e); // I (p e)

bool removeList(list *l, int p); // R (p)

int betweenList(list *l, int a, int b); // C (a b)

void printList(list *l); // M

//void endList(list *l); // F

int main()
{
    // Declaração das variáveis (separadas para melhor compreenção)
    int n;
    int i;
    int inimigo;
    char operacao;
    list lista = newList();

    int p, e;
    int a, b;
    int x;

    // Imput do número de "Inimigos"
    scanf("%d", &n);
    if(n < 1 || n > 1000){
        printf("ERRO\n");
        return 0;
    }

    // Criação da lista com cada "Inimigo" de Arya
    for(i = 0; i < n; i++)
    {
        scanf("%d", &inimigo);
        createList(&lista, inimigo);
    }

    // Escolha das operações desejadas e Switch Case
    while(true)
    {
        scanf("%c", &operacao);
        p = 0;

        switch(operacao)
        {
            case 'I':
                scanf("%d %d", &p, &e);
                insertAfterList(&lista, p, e);
                printf("inserido %d\n", p);
                break;
            case 'R':
                scanf("%d", &p);
                removeList(&lista, p);
                printf("removido %d\n", p);
                break;
            case 'C':
                scanf("%d %d", &a, &b);
                x = betweenList(&lista, a, b);
                printf("quantidade %d\n", x);
                break;
            case 'M':
                printList(&lista);
                break;
            case 'F':
                printf("fim\n");
                cleanUp(&lista);
                return 0;
        }
    }

    //return 0;
}

//
// Função inicializa uma Lista
//
list newList()
{
    list new;

    new.first = NULL;
    new.last = NULL;
    new.size = 0;

    return new;
}

//
// Função "Limpa" uma Lista
//
void cleanUp(list *l)
{
    node *currnode = NULL;
    node *temp = NULL;

    for(currnode = l -> first; currnode != NULL; currnode = temp)
    {
        temp = currnode -> next;
        free(currnode);
    }

    l -> first = NULL;
    l -> last = NULL;
    l -> size = 0;
}

//
// Função adiciona valores a uma lista inicializada
//
bool createList(list *l, int p)
{
    node *new = NULL;
    new = (node *) malloc(sizeof(node)*1);

    new -> value = p;
    new -> next = NULL;

    if(l -> first == NULL){
        //new -> value = value;
        l -> first = new;
    }
    else{
        //new -> value = value;
        l -> last -> next = new;
    }
    l -> last = new;
    l -> size++;

    return true;
}

//
// Função que adiciona um número "p" logo após o número "e" em uma lista
//
bool insertAfterList(list *l, int p, int e)
{
    node *new = NULL;
    node *currnode = NULL;

    new = (node *)malloc(sizeof(node)*1);

    new -> value = p;

    for(currnode = l -> first; currnode != NULL; currnode = currnode -> next)
    {
        if(currnode -> value == e)
        {
            new -> next = currnode -> next;
            //currnode = new;
            currnode -> next = new;

            if(new -> next == NULL) l -> last = new;
            return true;
        }
    }

    free(new);
    return false;
}

//
// Função que remove um número "p" da lista
//
bool removeList(list *l, int p)
{
    node * currnode = NULL;
    node * prevnode = NULL;

    for(currnode = l -> first; currnode != NULL; prevnode = currnode, currnode = currnode -> next)
    {
        if(currnode -> value == p)
        {
            if(l -> size == 1)
            {
                l -> first = NULL;
                l -> last = NULL;
            }
            else if(currnode == l -> first)
            {
                l -> first = currnode -> next;
            }
            else if(currnode == l -> last)
            {
                l -> last = prevnode;
                l -> last -> next = NULL;
            }
            else
            {
                prevnode -> next = currnode -> next;
            } 


            free(currnode);
            return true;
        }
    }

    return false;
}

//
// Função que conta a quantidade de números entre o número "a" e "b" em uma lista
//
int betweenList(list *l, int a, int b) // Peguei código da função emprestado
{
    int i = 0;
    node *currnode = NULL;

    bool foundFirst, first1, first2;

    foundFirst = false;
    first1 = false;
    first2 = false;

    for(currnode = l -> first; currnode != NULL; currnode = currnode -> next)
    {
        if(foundFirst)
        {
            if(first1)
            {
                if(currnode -> value == b) return i;
            }
            else if(first2)
            {
                if(currnode -> value == a) return i;
            }
            i++;
        }
        else
        {
            if(currnode -> value == a)
            {
                foundFirst = true;
                first1 = true;
            }
            else if(currnode -> value == b)
            {
                foundFirst = true;
                first2 = true;
            }
        }
    }
}


//
// Função que "printa" uma lista no terminal
//
void printList(list *l)
{
    node *currnode = NULL;

    printf("lista ");

    for(currnode = l -> first; currnode != NULL; currnode = currnode -> next)
    {
        printf("%d ", currnode -> value);
    }
    printf("\n");
}