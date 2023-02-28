#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node node;
typedef struct list list;

struct node{
    int value;
    node *next;
    node *prev;
};

struct list{
    node *first;
    node *last;
    int size;
};

list newList();

int listSize(list *l);

bool printNode(list *l, int value);

bool printNthNode(list *l, int value);

bool insertAfterList(list *l, int value, int nodeN);

bool insertBeforeList(list *l, int value, int nodeN);

bool insertFirstList(list *l, int value);

bool insertLastList(list *l, int value);

bool addList(list *l, int value);

void printList(list *l);

bool removeList(list *l, int value);

bool removeNthList(list *l, int n);

void printListOrdem(list *l, int ordem);

bool sortList(list *l, int value);

void cleanUp(list *l);