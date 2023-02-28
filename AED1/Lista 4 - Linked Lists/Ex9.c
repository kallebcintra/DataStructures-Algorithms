/* AED1 Lista 4 Ex.9 (Brincadeira 1) - 2022/1 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node node;
typedef struct List list;

struct Node{
    char nome[101];
    node *next;
    node *prev;
};

struct List{
    node *first;
    int size;
    node *last;
};

list newList();

void cleanUp(list *l);

bool addList(list *l, char *nome);

bool removeList(list *l, char *nome);

int main()
{
    int i, j, l;
    int pontos = 0;
    char nome[101], sentido[101];

    list roda;
    roda = newList();

    node *p;

    addList(&roda, "Arlete");

    i = 0;
    while(true)
    {
        scanf("%s%*c", nome);
        if(strcmp(nome, "FIM") == 0) break;
        addList(&roda, nome);
        i++;
    }
    j = i;

    while(j > 0)
    {
        scanf("%s%*c", nome);
        scanf("%s%*c", sentido);

        l = 0;
        if(strcmp(sentido, "horario") == 0) 
        {
            for(p = roda.first -> next; l < 2 ; p = p -> next)
            {
                if(strcmp(p -> nome, nome) == 0)
                {
                    removeList(&roda, p -> nome);
                    pontos++;
                    break;
                }

                l++;
            }
        }
        else if(strcmp(sentido, "anti-horario") == 0)
        {
            for(p = roda.last; l < 2 ; p = p->prev)
            {
                if(strcmp(p -> nome, nome) == 0)
                {
                    removeList(&roda, p -> nome);
                    pontos++;
                    break;
                }

                l++;
            }
        }

        j--;
    }

    printf("%d\n", pontos);

    cleanUp(&roda);

    return 0;
}


list newList()
{
    list new;

    new.first = NULL;
    new.last = NULL;
    new.size = 0;

    return new;
}

bool addList(list *l, char *nome)
{
    node *new = NULL;

    new = (node *) malloc(sizeof(node)*1);
    if(new == NULL) return false;

    strcpy(new -> nome, nome);

    if(l -> size == 0)
    {
        l -> first = new;
        l -> last = new;

        new -> prev = l -> last;
        new -> next = l -> first;

        l -> size++;
        return true;
    }
    
    l -> last -> next = new;
    l -> first -> prev = new;

    new -> prev = l -> last;
    new -> next = l -> first;

    l -> last = new;
    l -> size++;

    return true;
}

bool removeList(list *l, char *nome)
{
    node *p;
    int i;

    if(l -> size == 1)
    {
        if(strcmp(l -> first -> nome, nome) == 0)
        {
            cleanUp(l);
            return true;
        }
    }

    for(p = l -> first, i = 0; i < l -> size; p = p -> next, i++)
    {
        if(strcmp(p -> nome, nome) == 0)
        {
            p -> prev -> next = p -> next;
            p -> next -> prev = p -> prev;

            if(p == l -> last) l -> last = p -> prev;
            if(p == l -> first) l -> first = p -> next;
            
            l -> size--;
            free(p);

            return true;
        }
    }

    return false;
}

void cleanUp(list *l)
{
    node *currnode = NULL;
    node *temp = NULL;
    int i, n;

    n = l -> size;

    for(currnode = l -> first, i = 0; i < n; currnode = temp, i++)
    {
        temp = currnode -> next;
        free(currnode);
    }

    l -> first = NULL;
    l -> last = NULL;
    l -> size = 0;
}