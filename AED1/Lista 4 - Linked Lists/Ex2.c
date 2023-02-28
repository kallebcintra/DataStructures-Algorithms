/* AED1 Lista 4 Ex.2 (A COPA do mundo é nossa...) - 2022/1 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node node;
typedef struct list list;

struct node{
    int value;
    node *next;
};

struct list{
    node *first;
    node *last;
    int size;
};

list newList();

bool addList(list *fila, int value);

bool removeList(list *l, int n);

void printList(list *fila);

void cleanUp(list *fila);

int main()
{
    int i;
    int n;
    int senha;
    int m;
    int exSenha;

    list fila = newList();

    scanf("%d", &n);
    if(n < 1 || n > 60000){
        printf("ERRO\n");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        scanf("%d", &senha);
        addList(&fila, senha);
    }

    scanf("%d", &m);
    if(m > n){
        printf("ERRO\n");
        return 0;
    }

    for(i = 0; i < m; i++)
    {
        scanf("%d", &exSenha);
        removeList(&fila, exSenha);
    }

    printList(&fila);

    cleanUp(&fila);

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

bool addList(list *fila, int value)
{
    node *new = NULL;
    new = (node *) malloc(sizeof(node)*1);

    new -> value = value;
    new -> next = NULL;

    if(fila -> first == NULL){
        fila -> first = new;
    }
    else{
        fila -> last -> next = new;
    }
    fila -> last = new;
    fila -> size++;

    return true;
}

bool removeList(list *l, int n)
{
    node * currnode = NULL;
    node * prevnode = NULL;

    for(currnode = l -> first; currnode != NULL; prevnode = currnode, currnode = currnode -> next)
    {
        if(currnode -> value == n)
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

void printList(list *fila)
{
    node *new = NULL;

    for(new = fila -> first; new != NULL; new = new -> next)
    {
        printf("%d ", new -> value);
    }
    printf("\n");
}

void cleanUp(list *fila)
{
    node *currnode = NULL;
    node *temp = NULL;

    for(currnode = fila -> first; currnode != NULL; currnode = temp)
    {
        temp = currnode -> next;
        free(currnode);
    }

    fila -> first = NULL;
    fila -> last = NULL;
    fila -> size = 0;
}