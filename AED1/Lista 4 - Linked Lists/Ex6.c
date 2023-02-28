/* AED1 Lista 4 Ex.6 (Notação polonesa inversa) - 2022/1 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct Node node;
typedef struct List list;

struct Node{
    char n;
    node *next;
};

struct List{
    node *first;
    int size;
    node *last;
};

list newList();

void cleanUp(list *l);

bool empilhar(list *l, char value);

char desempilhar(list *l);

bool ordemDePrioridade(char c, char t);

bool Operador(char c);

void posFixo(char *infixo, char *posfixo);

bool check(char *s);

int main()
{
    int n;
    int i, j;
    char operacao[1001];
    char saida[1001];

    scanf("%d%*c", &n);

    for(j = 0; j < n; j++) //while(n--)
    {
        scanf("%[^\n]%*c", operacao);

        if(!check(operacao)){
            printf("mal-formada\n");
            continue;
        }

        posFixo(operacao, saida);

        i = 0;
        while(saida[i] != '\0')
        {
            if(saida[i+1] == '\n') printf("\n%c", saida[i]);
            else printf("%c ", saida[i]);
            i++;
        }
        printf("\n");
    }

    return 0;
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
// Função "empilha" uma lista
//
bool empilhar(list *l, char value)
{
    node *new = NULL;

    new = (node *) malloc(sizeof(node)*1);

    new -> n = value;
    new -> next = NULL;
    
    if(l -> first == NULL){
        l -> first = new;
    }
    if(l -> last != NULL){
        l -> last -> next = new; 
    }

    l -> last = new;
    l -> size++;

    return true;
}

//
// Função "desempilha" uma lista
//
char desempilhar(list *l)
{
    node *currnode = NULL;
    int last;

    if(l -> size == 0) return -1;

    if(l -> size == 1)
    {
        last = l -> first -> n;
        cleanUp(l);
        return last;
    }

    for(currnode = l -> first; currnode -> next != l -> last; currnode = currnode -> next);

    currnode -> next = NULL;
    last = l -> last -> n;

    free(l -> last);

    l -> last = currnode;
    l -> size--;

    return last;
}

//
// Função define a ordem de prioridade dos operadores
//
bool ordemDePrioridade(char c, char t)
{
    int pc, pt;

    if(c == '^') pc = 4;
    else if(c == '*' || c == '/') pc = 2;
    else if(c == '+' || c == '-') pc = 1;
    else if(c == '(') pc = 4;

    if(t == '^') pt = 3;
    else if(t == '*' || t == '/') pt = 2;
    else if(t == '+' || t == '-') pt = 1;
    else if(t == '(') pt = 0;

    return (pc > pt);
}

//
// Função define quais são os operadores
//
bool Operador(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' ) return true;
    return false;
}

//
//
//
void posFixo(char *infixo, char *posfixo)
{
    list tempList;
    int i = 0, j = 0;
    char c, t;

    memset(posfixo, '\0', 1000);
    tempList = newList();

    empilhar(&tempList, '(');

    //i = 0;
    //j = 0;
    do
    {
        c = infixo[i];
        i++;
        if(isalnum(c))
        {
            posfixo[j] = c;
            j++;
        }
        else if(c == '(')
        {
            empilhar(&tempList, '(');
        }
        else if(c == ')' || c == '\0')
        {
            do
            {
                t = desempilhar(&tempList);
                if(t != '('){
                    posfixo[j] = t;
                    j++;
                }
            } while(t != '(');
        }
        else if(Operador(c))
        {
            while(true)
            {
                t = desempilhar(&tempList);

                if(ordemDePrioridade(c, t))
                {
                    empilhar(&tempList, t);
                    empilhar(&tempList, c);
                    break;
                }

                posfixo[j] = t;
                j++;
            }
        }
    } while(c != '\0');

    cleanUp(&tempList);
}

//
//
//
bool check(char *s)
{
    int i = 0;
    char last;
    list pilha;
    bool correct;

    pilha = newList();
    correct = true;

    while(s[i] != '\0')
    {
        if(s[i] == '(') empilhar(&pilha, s[i]);

        if(s[i] == ')')
        {
            last = desempilhar(&pilha);
            if(last != '(')
            {
                correct = false;
                break;
            }
        }

        i++;
    }

    if(pilha.size != 0) correct = false;
    cleanUp(&pilha);

    return correct;
}