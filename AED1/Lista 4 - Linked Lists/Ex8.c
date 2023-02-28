/* AED1 Lista 4 Ex.8 (Micalateia) - 2022/1 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Person person;
typedef struct Node node;
typedef struct List list;

struct Person
{
    char *name;
    char *phone;
    int v;
};

struct Node
{
    person p;
    node *next;
    node *prev;
};

struct List
{
    node *first;
    node *last;
    int size;
};
    
void stringCopy(char **dest, char *src);
    
void freePerson(person *p);
    
void freeNode(node *n);
    
list newList();
    
void printPhoneBook(list *l);
    
void insertPhoneBook(list *l, char *name, char *phoneNumber, int v);
    
void cleanUp(list *l);
    
bool removePhoneBook(list *l, char *name);
    
node *runList(list *l, char *name);
    
int main()
{
    char operacao;
    char name[10001];
    char phoneNumber[10001];
    int v;
    
    list phoneBook;
    phoneBook = newList();

    node *n = NULL;
    node *tmp, *tmp2, *tmp3;
    
    insertPhoneBook(&phoneBook, "Hermanoteu", "4523-2248", 300);
    insertPhoneBook(&phoneBook, "Ooloneia", "4523-4887", 299);
    
    while(true)
    {
        scanf("%c%*c", &operacao);
    
        switch (operacao)
        {
        case 'I':
            scanf("%s %s %d%*c", name, phoneNumber, &v);
            insertPhoneBook(&phoneBook, name, phoneNumber, v);
            break;
        case 'R':
            scanf("%s%*c", name);
            removePhoneBook(&phoneBook, name);
            break;
        case 'L':
            scanf("%s%*c", name);
            n = runList(&phoneBook, name);

            if(n != NULL) n->p.v++;
            if(n->prev == NULL) break;

            while(n->p.v > n->prev->p.v)
            {
                tmp = n->prev;
                tmp2 = n->next;
                tmp3 = tmp->prev;
    
                n->next = tmp;
                n->prev = tmp3;
    
                tmp->prev = n;
                tmp->next = tmp2;
    
                if(tmp2 != NULL) tmp2->prev = tmp;
                if(tmp3 != NULL) tmp3->next = n;
                   
                if(tmp->next == NULL) phoneBook.last = tmp;
                if(n->prev == NULL)
                {
                    phoneBook.first = n;
                    break;
                }
            }

            break;
        case 'F':    
            printPhoneBook(&phoneBook);
            cleanUp(&phoneBook);
            return 0;
        }
    }
}

//
//
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
//
//
void cleanUp(list *l)
{
    node * currnode = NULL;
    node * tmp = NULL;
    
    for(currnode = l -> first; currnode != NULL; currnode = tmp)
    {
        tmp = currnode -> next;
        freeNode(currnode);
    }
    
    l -> first = NULL;
    l -> last = NULL;
    l -> size = 0;
}

//
//
//
void freePerson(person *p)
{
    free(p->phone);
    free(p->name);
}

//
//
//
void freeNode(node *n)
{
    freePerson(&n->p);
    free(n);
}

//
//
//
void insertPhoneBook(list *l, char *name, char *phoneNumber, int v)
{
    node *new = NULL;
    node *p = NULL;
    
    new = (node *) malloc(sizeof(node)*1);
    stringCopy(&new -> p.name, name);
    stringCopy(&new -> p.phone, phoneNumber);
    new -> p.v = v;
    
    
    for(p = l -> first; true; p = p -> next)
    {
        if(l->size == 0)
        {
            l->first = new;
            l->last = new;
            new->next = NULL;
            new->prev = NULL;
            break;
        } 
    
        if(v > p->p.v)
        {
            new->prev = p->prev;
            new->next = p;
            if(p->prev != NULL) p->prev->next = new;
            p->prev = new;
            if(new->prev == NULL) l->first = new;
            if(new->next == NULL) l->last = new;
            break;
        }
    
        if(p == l->last)
        {
            p->next = new;
            new->prev = p;
            new->next = NULL;
            l->last = new;
            break;
        }
    
    }
    
    l->size++;
}

//
//
//
bool removePhoneBook(list *l, char *name)
{
    node * p = NULL;

    for(p = l->first; p != NULL; p = p->next)
    {
        if(strcmp(p->p.name, name) == 0)
        {
            if(l->size == 1)
            {
                cleanUp(l);
                return true;
            }

            if(p == l->first) l->first = p->next;
            else if(p == l->last) l->last = p->prev;
            else {
                p->prev->next = p->next;
                p->next->prev = p->prev;
            } 

            l->first->prev = NULL;
            l->last->next = NULL;
            l->size--;

            free(p);


            return true;
        }
    }

    return false;
}

//
//
//
void stringCopy(char **dest, char *src)
{
    int size;
    
    *dest = NULL;
    size = strlen(src) + 1;
    
    *dest = (char *) malloc(size * sizeof(char));
    strcpy(*dest, src);
}

//
//
//
void printPhoneBook(list *l)
{
    node *currnode = NULL;
    
    for(currnode = l->first; currnode != NULL; currnode = currnode->next) {
        printf("%s - %s %d\n", currnode->p.name, currnode->p.phone, currnode->p.v);
    }
}

//
//
//
node *runList(list *l, char *name)
{
    node * p = NULL;
    
    for(p = l->first; p != NULL; p = p->next)
    {
        if(strcmp(p->p.name, name) == 0) return p;
    }
    
    return NULL;
}