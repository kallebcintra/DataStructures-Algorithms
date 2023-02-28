#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Crianca node;
typedef struct Circulo list;

struct Crianca{
    char name[31];
    int n;
    node *next;
    node *prev;
};

struct Circulo{
    node *first;
    node *last;
    int size;
};

list newList();

void cleanUp(list *l);

bool addList(list *l, char *name, int n);

bool removeList(list *l, char *name);

void runCircle(list *l);

int main()
{
    int n, i;
    char name[31];
    int num;
    list circle = newList();

    scanf("%d", &n);
    if(n < 1 || n > 100){
        printf("ERRO\n");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        scanf("%s%*c", name);
        scanf("%d", &num);
        addList(&circle, name, num);
    }

    runCircle(&circle);

    cleanUp(&circle);

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

bool addList(list *l, char *name, int n)
{
    node *new = NULL;

    new = (node *) malloc(sizeof(node)*1);
    if(new == NULL) return false;

    strcpy(new -> name, name);
    new -> n = n;

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

void runCircle(list *l)
{
    node *currnode = NULL;
    int temp;
    int i;

    temp = l -> first -> n;
    while(l -> size > 1)
    {
        i = 1;
        if(temp%2 != 0)
        {
            for(currnode = l -> first -> next; i < temp; currnode = currnode -> next){
                i++;
            }
        }
        else if(temp%2 == 0)
        {
            for(currnode = l -> last; i < temp; currnode = currnode -> prev){
                i++;
            }
        }
        temp = currnode -> n;
        removeList(l, currnode -> name);
    }

    printf("%s", l -> first -> name);
}

bool removeList(list *l, char *name)
{
    node *p;
    int i;

    if(l -> size == 1)
    {
        if(strcmp(l -> first -> name, name) == 0)
        {
            cleanUp(l);
            return true;
        }
    }

    for(p = l -> first, i = 0; i < l -> size; p = p -> next, i++)
    {
        if(strcmp(p -> name, name) == 0)
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

