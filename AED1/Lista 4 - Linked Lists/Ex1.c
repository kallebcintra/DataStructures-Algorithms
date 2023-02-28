/* AED1 Lista 4 Ex.1 (Fila do SUS) - 2022/1 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Paciente paciente;
typedef struct Node node;
typedef struct List list;

struct Paciente{
    int horaEntrada;
    int horaLimite;
};

struct Node{
    paciente p;
    node *next;
};

struct List{
    node *first;
    node *last;
    int size;
};

list newList();

void cleanUp(list *l);

void lePaciente(paciente *p);

bool addList(list *l, paciente p);

paciente freeFirstList(list *l);

int main()
{
    int n;
    int tempoAtual;
    int vaiMorrer = 0; // Brincadeira
    int i;

    paciente p;
    list fila;
    fila = newList();

    scanf("%d", &n);
    if(n < 1 || n > 50){
        printf("ERRO\n");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        lePaciente(&p);
        addList(&fila, p);
    }

    p = freeFirstList(&fila);

    tempoAtual = p.horaEntrada + 30;

    while(fila.size > 0)
    {
        p = freeFirstList(&fila);

        if(p.horaEntrada > tempoAtual)
        {
            tempoAtual = p.horaEntrada + 30;      
            continue;
        }
        
        if(tempoAtual > p.horaEntrada + p.horaLimite){
            vaiMorrer++;
        }
        tempoAtual += 30;
    }

    printf("%d\n", vaiMorrer);
    cleanUp(&fila);

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

    for(currnode = l -> first; currnode != NULL; currnode = temp)
    {
        temp = currnode -> next;
        free(currnode);
    }

    l -> first = NULL;
    l -> last = NULL;
    l -> size = 0;
}

void lePaciente(paciente *p)
{
    int h, m, c;

    scanf("%d %d %d%*c", &h, &m, &p -> horaLimite);

    c = h * 60;
    c += m;

    p -> horaEntrada = c;
}

bool addList(list *fila, paciente p)
{
    node *new = NULL;
    new = (node *) malloc(sizeof(node)*1);

    new -> p = p;
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

paciente freeFirstList(list *l)
{
    paciente p;
    node *temp;

    temp = l -> first;
    l -> first = l -> first -> next;
    p = temp -> p;

    free(temp);
    l -> size--;

    return p;
}