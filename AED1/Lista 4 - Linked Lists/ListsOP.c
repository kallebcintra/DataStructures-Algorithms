#include "ListsOP.h"

// Criar nova Lista Vazia
list newList()
{
    list new;

    new.first = NULL;
    new.last = NULL;
    new.size = 0;

    return new;
}

// Determinar o tamanho de uma lista
int listSize(list *l)
{
    node *currnode = NULL;
    int x;

    for(currnode = l -> first; currnode -> next != NULL; currnode = currnode -> next){
        x++;
    }

    return x;
} //Poderia apenas consultar list -> size também

// Printar a posição do node com chave = value
bool printNode(list *l, int value)
{
    node *currnode = NULL;
    int x = 0;

    for(currnode = l -> first; currnode -> value != value; currnode = currnode -> next){
        x++;
        if(currnode -> value == value){
            printf("Node com valor %d esta na posicao %d\n", value, x);
            return true;
        }
    }

    printf("Node com valor %d nao esta na lista\n", value);

    return false;
}

// Printar Node que está na posição n
bool printNthNode(list *l, int value)
{
    node *currnode = NULL;
    int x = 0;

    for(currnode = l -> first; currnode -> value != value; currnode = currnode -> next)
    {
        x++;
        if(x == value)
        {
            printf("%d\n", currnode -> value);
            return true;
        }
    }

    return false;
}

// Inserir Node imediatamente depois de determinado node -> value = nodeN
bool insertAfterList(list *l, int value, int nodeN)
{
    node *new = NULL;
    node *currnode = NULL;

    new = (node *)malloc(sizeof(node)*1);

    new -> value = value;

    for(currnode = l -> first; currnode != NULL; currnode = currnode -> next)
    {
        if(currnode -> value == nodeN)
        {
            new -> next = currnode -> next;
            currnode -> next = new;

            if(new -> next == NULL) l -> last = new;
            return true;
        }
    }

    free(new);
    return false;
}

// Inserir Node imediatamente antes de determinado node -> value = nodeN (A ser Testado)
bool insertBeforeList(list *l, int value, int nodeN)
{
    node *new = NULL;
    node *currnode = NULL;

    new = (node *)malloc(sizeof(node)*1);

    new -> value = value;

    for(currnode = l -> first; currnode != NULL; currnode = currnode -> next)
    {
        if(currnode -> next -> value == nodeN)
        {
            new -> next = currnode;
            currnode = new;

            if(currnode -> next == NULL) l -> last = currnode;
            return true;
        }
    }

    free(new);
    return false;
}

// inserir um Node no inicio da Lista
bool insertFirstList(list *l, int value)
{
    node *newNode = NULL;

    newNode = (node *)malloc(sizeof(node)*1);
    newNode -> value = value;

    newNode -> next = l -> first;

    if (l -> first == NULL)
    {
        l -> last = newNode;
    }

    l -> first = newNode;

    return true;
}

// inserir um Node no final da Lista (A ser testado)
bool insertLastList(list *l, int value)
{
    node *newNode = NULL;

    newNode = (node *)malloc(sizeof(node)*1);
    newNode -> value = value;
    newNode -> next = NULL;

    newNode -> prev = l -> last;

    if(l -> first == NULL)
    {
        l -> first = newNode;
    }

    l -> last = newNode;

    return true;
}

// Adicionar valores a uma Lista previamente vazia
bool addList(list *l, int value)
{
    node *new = NULL;
    new = (node *) malloc(sizeof(node)*1);

    new -> value = value;
    new -> next = NULL;

    if(l -> first == NULL){
        l -> first = new;
    }
    else{
        l -> last -> next = new;
    }
    l -> last = new;
    l -> size++;

    return true;
}

// Insere um certo valor em uma Lista
void insertList(list *l, int value)
{
    node *new = NULL;
    node *currnode = NULL;

    new = (node *) malloc(sizeof(node)*1);
    new -> value = value;

    for(currnode = l -> first; true; currnode = currnode -> next)
    {
        if(l->size == 0)
        {
            l->first = new;
            l->last = new;
            new->next = NULL;
            new->prev = NULL;
            break;
        } 

        if(value <= currnode -> value)
        {
            new -> prev = currnode -> prev;
            new -> next = currnode;
            if(currnode -> prev != NULL) currnode -> prev -> next = new;
            currnode -> prev = new;
            if(new -> prev == NULL) l -> first = new;
            if(new -> next == NULL) l -> last = new;
            break;
        }

        if(currnode == l -> last)
        {
            currnode -> next = new;
            new -> prev = currnode;
            new -> next = NULL;
            l -> last = new;
            break;
        }

    }
    
    l -> size++;
}


// Printar uma Lista na Tela
void printList(list *l)
{
    node *currnode = NULL;

    for(currnode = l -> first; currnode != NULL; currnode = currnode -> next)
    {
        printf("%d ", currnode -> value);
    }
    printf("\n");
}

// Remover Node que possui certo valor
bool removeList(list *l, int value)
{
    node * currnode = NULL;
    node * prevnode = NULL;

    for(currnode = l -> first; currnode != NULL; prevnode = currnode, currnode = currnode -> next)
    {
        if(currnode -> value == value)
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

// Remover Node que esta na posicao n (A ser testado)
bool removeNthList(list *l, int n)
{
    node * currnode = NULL;
    node * prevnode = NULL;
    int x = 0; // Valor de x a ser Revisado

    for(currnode = l -> first; currnode != NULL; prevnode = currnode, currnode = currnode -> next)
    {
        x++;
        if(x == n)
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

// Conta a quantidade de números entre os valores "a" e "b" em uma lista
int betweenList(list *l, int a, int b)
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

// Printa uma lista do 1° ao último caso 0 e do último ao 1° caso 1
void printListOrdem(list *l, int ordem)
{
    node *currnode = NULL;

    if(ordem == 0 /* CRESCENTE */)
    {
        for(currnode = l -> first; currnode != NULL; currnode = currnode -> next) 
        {
            printf("%d ", currnode -> value);
        }
    }
    else if(ordem == 1 /* DECRESCENTE */)
    {
        for(currnode = l -> last; currnode != NULL; currnode = currnode -> prev)
        {
            printf("%d ", currnode -> value);
        }
    }
    printf("\n");    
} 



// "Clean" a Linked List
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