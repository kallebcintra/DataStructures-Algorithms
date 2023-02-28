//==============================================================================
// Arquivo Conjunto.h
//==============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define CRESCENTE 0
#define DECRESCENTE 1

typedef int Ordem;
typedef struct conjunto Conjunto;

struct conjunto{
    unsigned int * vet;
    unsigned int size;
};

bool criaConjunto(Conjunto * c);

bool conjuntoVazio(Conjunto * c);

bool insereElementoConjunto(Conjunto * c, unsigned int value);

bool excluirElementoConjunto(Conjunto * c, unsigned int value);

unsigned int tamanhoConjunto(Conjunto * c);

int maior(Conjunto * c, unsigned int value);

int menor(Conjunto * c, unsigned int value);

bool pertenceConjunto(Conjunto * c, unsigned int value);

bool conjuntosIdenticos(Conjunto * c1, Conjunto * c2);

bool subconjunto(Conjunto * c1, Conjunto * c2);

Conjunto complemento(Conjunto * c1, Conjunto * c2);

Conjunto uniao(Conjunto * c1, Conjunto * c2);

Conjunto interseccao(Conjunto * c1, Conjunto * c2);

Conjunto diferenca(Conjunto * c1, Conjunto * c2);

Conjunto * conjuntoPartes(Conjunto * c);

void criaParte(Conjunto * CP, Conjunto * c, bool * regra, unsigned int parte);

void mudaCombinacao(bool * regra, unsigned int size);

void mostraConjunto(Conjunto * c, Ordem o);

void ordenaConjunto(Conjunto * c, Ordem o);

bool copiarConjunto(Conjunto * c1, Conjunto * c2);

bool destroiConjunto(Conjunto * c);

void Menu();

//==============================================================================
// Arquivo Conjunto.c
//==============================================================================
int main()
{
    int i;
    int operacao;
    int x;
    long long int NC;

    Conjunto a, b, c;
    Conjunto * CP;

    criaConjunto(&a);
    criaConjunto(&b);
    
    printf("Digite os elementos do conjunto A\n");
    printf("Digite -1 para finalizar\n");

    while(true){
        scanf("%d", &operacao);
        if(operacao == -1) break;
        insereElementoConjunto(&a, operacao);
    }

    printf("\n");

    printf("Digite os elementos do conjunto B\n");
    printf("Digite -1 para terminar\n");

    while(true){
        scanf("%d", &operacao);
        if(operacao == -1) break;
        insereElementoConjunto(&b, operacao);
    }

    printf("\n");

    mostraConjunto(&a, CRESCENTE);
    mostraConjunto(&b, CRESCENTE);

    while(true)
    {
        Menu();
        scanf("%d", &operacao);

        switch (operacao)
        {
            case 1:
                scanf("%d", &x);
                if(insereElementoConjunto(&a, x)) printf("SUCESSO\n");
                else printf("FALHA");
                break;
            case 2:
                if(insereElementoConjunto(&b, x)) printf("SUCESSO\n");
                else printf("FALHA");
                break;
            case 3:
                scanf("%d", &x);
                if(excluirElementoConjunto(&a, x)) printf("SUCESSO\n");
                else printf("FALHA");
                break;
            case 4:
                scanf("%d", &x);
                if(excluirElementoConjunto(&b, x)) printf("SUCESSO\n");
                else printf("FALHA");
                break;
            case 5:
                printf("%d\n", tamanhoConjunto(&a));
                break;
            case 6:
                printf("%d\n", tamanhoConjunto(&b));
                break;
            case 7:
                scanf("%d", &x);
                printf("%d\n", maior(&a, x));
                break;
            case 8:
                scanf("%d", &x);
                printf("%d\n", maior(&b, x));
                break;
            case 9:
                scanf("%d", &x);
                printf("%d\n", menor(&a, x));
                break;
            case 10:
                scanf("%d", &x);
                printf("%d\n", menor(&b, x));
                break;
            case 11:
                scanf("%d", &x);
                if(pertenceConjunto(&a, x)) printf("PERTENCE\n");
                else printf("NAO PERTENCE\n");
                break;
            case 12:
                scanf("%d", &x);
                if(pertenceConjunto(&b, x)) printf("PERTENCE\n");
                else printf("NAO PERTENCE\n");
                break;
            case 13:
                if(conjuntosIdenticos(&a, &b)) printf("CONJUNTOS IDENTICOS\n");
                else printf("CONJUNTOS NAO IDENTICOS\n");
                break;
            case 14:
                if(subconjunto(&a, &b)) printf("E SUBCONJUNTO\n");
                else printf("NAO E SUBCONJUNTO\n");
                break;
            case 15:
                if(subconjunto(&b, &a)) printf("E SUBCONJUNTO\n");
                else printf("NAO E SUBCONJUNTO\n");
                break;
            case 16:
                criaConjunto(&c);
                c = complemento(&a, &b);

                mostraConjunto(&c, CRESCENTE);
                destroiConjunto(&c);
                break;
            case 17:
                criaConjunto(&c);
                c = complemento(&b, &a);

                mostraConjunto(&c, CRESCENTE);
                destroiConjunto(&c);
                break;
            case 18:
                criaConjunto(&c);
                c = uniao(&a, &b);

                mostraConjunto(&c, CRESCENTE);
                destroiConjunto(&c);
                break;
            case 19:
                criaConjunto(&c);
                c = interseccao(&a, &b);

                mostraConjunto(&c, CRESCENTE);
                destroiConjunto(&c);
                break;
            case 20:
                criaConjunto(&c);
                c = diferenca(&a, &b);

                mostraConjunto(&c, CRESCENTE);
                destroiConjunto(&c);
                break;
            case 21:
                criaConjunto(&c);
                c = diferenca(&b, &a);

                mostraConjunto(&c, CRESCENTE);
                destroiConjunto(&c);
                break;
            case 22:
                NC = pow(2, a.size);
                CP = conjuntoPartes(&a);

                for(i = 0; i < NC; i++)
                {
                    mostraConjunto(&CP[i], CRESCENTE);
                }

                for(i = 0; i < NC; i++)
                {
                    destroiConjunto(&CP[i]);
                }
                free(CP);

                break;
            case 23:
                NC = pow(2, b.size);
                CP = conjuntoPartes(&b);

                for(i = 0; i < NC; i++)
                {
                    mostraConjunto(&CP[i], CRESCENTE);
                }

                for(i = 0; i < NC; i++)
                {
                    destroiConjunto(&CP[i]);
                }
                free(CP);

                break;
            case 24:
                printf("0 - CRESCENTE\n");
                printf("1 - DECRESCENTE\n");
                printf("Insira a ordem desejada\n");

                scanf("%d", &x);
                mostraConjunto(&a, x);
                break;
            case 25:
                printf("0 - CRESCENTE\n");
                printf("1 - DECRESCENTE\n");
                printf("Insira a ordem desejada\n");

                scanf("%d", &x);
                mostraConjunto(&b, x);
                break;
            case 0:
                destroiConjunto(&a);
                destroiConjunto(&b);
                return 0;
        }
    }

    return 0;
}

//
// Imprime as operações possíveis em forma de Menu
//
void Menu()
{
    printf("\n");
    printf("Conjuntos de Numeros Naturais (Menu):\n");
    printf("\n");
    printf("\t1. Inserir novo elemento no conjunto A\n");
    printf("\t2. Inserir novo elemento no conjunto B\n");
    printf("\t3. Excluir elemento do conjunto A\n");
    printf("\t4. Excluir elemento do conjunto B\n");
    printf("\t5. Cardinalidade do conjunto A\n");
    printf("\t6. Cardinalidade do conjunto B\n");
    printf("\t7. Elementos do conjunto A que sao maiores que x\n");
    printf("\t8. Elementos do conjunto B que sao maiores que x\n");
    printf("\t9. Elementos no conjunto A que sao menores que x\n");
    printf("\t10. Elementos no conjunto B que sao menores que x\n");
    printf("\t11. Verifica se x pertence ao conjunto A\n");
    printf("\t12. Verifica se x pertence ao conjunto B\n");
    printf("\t13. Verifica se os conjuntos A e B sao identicos\n");
    printf("\t14. Verifica se A e subconjunto de B\n");
    printf("\t15. Verifica se B e subconjunto de A\n");
    printf("\t16. Complemento de A em relacao a B\n");
    printf("\t17. Complemento de B em relacao a A\n");
    printf("\t18. Uniao entre A e B\n");
    printf("\t19. Interseccao entre A e B\n");
    printf("\t20. Diferenca entre A e B\n");
    printf("\t21. Diferenca entre B e A\n");
    printf("\t22. Conjunto das partes de A\n");
    printf("\t23. Conjunto das partes de B\n");
    printf("\t24. Mostrar o conjunto A\n");
    printf("\t25. Mostrar o conjunto B\n");
    printf("\t0. Destruir o Conjunto e Finalizar o programa\n");
    printf("\n");
    printf("Escolha uma das operacoes: ");
}

//
// Cria um Conjunto Vazio
//
bool criaConjunto(Conjunto * c)
{
    c -> size = 0;
    c -> vet = NULL;

    return true;
}

//
// Verifica se o Conjunto c é vazio
//
bool conjuntoVazio(Conjunto * c)
{
    if(c -> size == 0){
        return true;
    }
    return false;
}

//
// Inclui o elemento x no Conjunto c
//
bool insereElementoConjunto(Conjunto * c, unsigned int x)
{
    unsigned int * temp = NULL;
    
    if(pertenceConjunto(c, x)) return false;

    temp = (unsigned int *) realloc(c -> vet, (c -> size + 1) * (sizeof(unsigned int)));
    if(temp == NULL) return false;

    c -> vet = temp;
    c -> size++;
    c -> vet[c -> size - 1] = x;

    return true;
}

//
// Exclui o elemento x do Conjunto C
//
bool excluirElementoConjunto(Conjunto * c, unsigned int x)
{
    int i, j;
    Conjunto new;
    
    if(!pertenceConjunto(c, x)) return false;

    criaConjunto(&new);
    new.vet = (unsigned int *) malloc((c->size - 1) * sizeof(unsigned int));
    if(new.vet == NULL) return false;

    new.size = c->size - 1;
    
    for(i = 0, j = 0; j < new.size; i++)
    {
        if(c -> vet[i] == x) continue;

        new.vet[j] = c -> vet[i];
        j++;
    }

    free(c -> vet);
    c -> vet = new.vet;
    c -> size = new.size;

    return true;
}

//
// Calcula a Cardinalidade do conjunto c
//
unsigned int tamanhoConjunto(Conjunto * c)
{
    return c -> size;
}

//
// Determinar a quantidade de elementos do conjunto C que são maiores que x
//
int maior(Conjunto * c, unsigned int x)
{
    int i, cont;

    for(i = 0, cont = 0; i < c -> size; i++)
    {
        if(c -> vet[i] > x) cont++;
    }

    if(cont == 0){
        return -1;
    }
    else if(cont == c -> size){
        return 0;
    }

    return cont;
}

//
// Determinar a quantidade de elementos do conjunto C que são menores que x
//
int menor(Conjunto * c, unsigned int x)
{
    int i, cont;

    for(i = 0, cont = 0; i < c -> size; i++)
    {
        if(c -> vet[i] < x) cont++;
    }

    if(cont == 0){
        return -1;
    }
    else if(cont == c -> size){
        return 0;
    }

    return cont;
}

//
// Verifica se o elemento x pertence ao conjunto C
//
bool pertenceConjunto(Conjunto * c, unsigned int x)
{
    int i;

    for(i = 0; i < c -> size; i++){
        if(c -> vet[i] == x){
            return true;
        }
    }

    return false;
}

//
// Compara se dois conjuntos C1 e C2 são idênticos 
//
bool conjuntosIdenticos(Conjunto * c1, Conjunto * c2)
{
    int i;

    if(c1 -> size != c2 -> size) return false;

    for(i = 0; i < c1 -> size; i++){
        if(c1 -> vet[i] != c2 -> vet[i]){
            return false;
        }
    }

    return true;
}

//
// Identifica se o conjunto C1 é subconjunto do conjunto C2
//
bool subconjunto(Conjunto * c1, Conjunto * c2)
{
    int i;

    for(i = 0; i < c1 -> size; i++){
        if(!pertenceConjunto(c2, c1 -> vet[i])){
            return false;
        }
    }

    return true;
}

//
// Gera o complemento do conjunto C1 em relação ao conjunto C2
//
Conjunto complemento(Conjunto * c1, Conjunto * c2)
{
    return diferenca(c2, c1);
}

//
// Gera a união do conjunto C1 com o conjunto C2
//
Conjunto uniao(Conjunto * c1, Conjunto * c2)
{
    int i;
    unsigned int * temp = NULL;
    Conjunto U;

    criaConjunto(&U);

    U.vet = (unsigned int *) malloc((c1->size + c2->size) * sizeof(unsigned int));
    if(U.vet == NULL){
        printf("Erro ao alocar funcao uniao\n");
        exit(0);
    }

    for(i = 0; i < c1 -> size; i++){
        U.size++;
        U.vet[U.size - 1] = c1 -> vet[i];
    }

    for(i = 0; i < c2 -> size; i++){
        if(pertenceConjunto(&U, c2 -> vet[i])) continue;

        U.size++;
        U.vet[U.size - 1] = c2 -> vet[i];
    }

    if(U.size == 0){
        destroiConjunto(&U);
        return U;
    }

    temp = (unsigned int *) realloc(U.vet, U.size * sizeof(unsigned int));

    if(temp == NULL){
        printf("Erro ao realocar funcao uniao\n");
        exit(0);
    }

    U.vet = temp;

    return U;
}

//
// Gera a intersecção do conjunto C1 com o conjunto C2
//
Conjunto interseccao(Conjunto * c1, Conjunto * c2)
{
    int i;
    int menor;
    unsigned int * temp = NULL;
    Conjunto interseccao;
    bool c1Menor;

    criaConjunto(&interseccao);

    menor = c1 -> size;
    c1Menor = true;

    if(c2 -> size < menor){
        menor = c2 -> size;
        c1Menor = false;
    }

    interseccao.vet = (unsigned int *) malloc(menor * sizeof(unsigned int));
    if(interseccao.vet == NULL) {
        printf("Erro ao alocar funcao interseccao\n");
        exit(0);
    }
    
    if(c1Menor)
    {
        for(i = 0; i < c1 -> size; i++)
        {
            if(!pertenceConjunto(c2, c1 -> vet[i])) continue;

            interseccao.size++;
            interseccao.vet[interseccao.size - 1] = c1 -> vet[i];
        }
    }
    else
    {
        for(i = 0; i < c2 -> size; i++)
        {
            if(!pertenceConjunto(c1, c2 -> vet[i])) continue;

            interseccao.size++;
            interseccao.vet[interseccao.size - 1] = c2 -> vet[i];
        }
    }

    if(interseccao.size == 0){
        destroiConjunto(&interseccao);
        return interseccao;
    }

    temp = (unsigned int *) realloc(interseccao.vet, interseccao.size * sizeof(unsigned int));
    if(temp == NULL) {
        printf("Erro ao realocar, função interseccao\n");
        exit(0);
    }

    interseccao.vet = temp;

    return interseccao;
}

//
// Gera a diferença entre o conjunto C1 e o conjunto C2
//
Conjunto diferenca(Conjunto * c1, Conjunto * c2)
{
    int i;
    unsigned int * temp = NULL;
    Conjunto dif;

    criaConjunto(&dif);

    dif.vet = (unsigned int *) malloc(c1->size * sizeof(unsigned int));
    if(dif.vet == NULL){
        printf("Erro ao alocar funcao diferenca\n");
        exit(0);
    }

    for(i = 0; i < c1 -> size; i++)
    {
        if(pertenceConjunto(c2, c1 -> vet[i])) continue;

        dif.size++;
        dif.vet[dif.size - 1] = c1 -> vet[i];
    }

    if(dif.size == 0)
    {
        destroiConjunto(&dif);
        return dif;
    }

    temp = (unsigned int *) realloc(dif.vet, dif.size * sizeof(unsigned int));
    if(temp == NULL) {
        printf("Erro ao realocar funcao diferenca\n");
        exit(0);
    }

    dif.vet = temp;

    return dif;
}

//
// Gera o conjunto das partes do conjunto C
//
Conjunto * conjuntoPartes(Conjunto * c)
{
    int i;
    long long int numCombinacoes;

    Conjunto * CP = NULL;
    bool * regra = NULL;
    
    regra = (bool *) malloc(c -> size * sizeof(bool));
    if(regra == NULL) {
        printf("Erro ao alocar funcao conjuntoPartes\n");
        exit(0);
    }

    for(i = 0; i < c -> size; i++){
        regra[i] = false;
    }

    numCombinacoes = pow(2, c -> size);

    CP = (Conjunto *) malloc(numCombinacoes * sizeof(Conjunto));
    if(CP == NULL){
        printf("Erro ao alocar funcao conjuntoPartes\n");
        exit(0);
    }

    criaParte(CP, c, regra, 0);
    free(regra);

    return CP;
}

//
// Função auxiliar a função conjuntoPartes
//
void criaParte(Conjunto * CP, Conjunto * c, bool * regra, unsigned int parte)
{
    int i, j;
    Conjunto p;

    if(parte == pow(2, c -> size)) return;

    criaConjunto(&p);

    for(i = 0; i < c -> size; i++){
        if(regra[i]) p.size++;
    }

    if(p.size != 0)
    {
        p.vet = (unsigned int *) malloc(p.size * sizeof(unsigned int));
        if(p.vet == NULL){
            printf("Erro ao alocar funcao criaParte\n");
            exit(0);
        }

        for(i = 0, j = 0; j < p.size; i++)
        {
            if(regra[i])
            {
                p.vet[j] = c -> vet[i];
                j++;
            }
        }
    }

    CP[parte] = p;

    mudaCombinacao(regra, c -> size);
    criaParte(CP, c, regra, parte + 1);
}

//
// Função auxiliar a função criaParte
//
void mudaCombinacao(bool * regra, unsigned int size)
{
    int i;
    int ultimoInativo = 0;

    for(i = size-1; i >= 0; i--)
    {
        if(!regra[i])
        {
            ultimoInativo = i;
            break;
        }
    }

    regra[ultimoInativo] = true;

    for(i = ultimoInativo + 1; i < size; i++)
    {
        regra[i] = false;
    }
}

//
// Mostra os elementos presentes no conjunto C
//
void mostraConjunto(Conjunto * c, Ordem o)
{
    int i;
    ordenaConjunto(c, o);

    printf("{");

    for(i = 0; i < c -> size; i++)
    {
        if(i == c -> size - 1){
            printf("%d", c -> vet[i]);
        }
        else{
            printf("%d, ", c -> vet[i]);
        }
    }

    printf("}\n");
}

//
// Função auxiliar a função mostraConjunto
//
void ordenaConjunto(Conjunto * c, Ordem o)
{ 
    int i, j;
    int min, max;
    int temp;

    if(conjuntoVazio(c)) return;

    if(o == CRESCENTE)
    {
        for(i = 0; i < c -> size - 1; i++)
        {
            min = i;

            for(j = i + 1; j < c -> size; j++){
                if(c -> vet[j] < c -> vet[min]) min = j;
            }

            if(min != i)
            {
                temp = c -> vet[i];
                c -> vet[i] = c -> vet[min];
                c -> vet[min] = temp;
            }
        }
    }
    else if(o == DECRESCENTE)
    {
        for(i = 0; i < c -> size - 1; i++)
        {
            max = i;

            for(j = i + 1; j < c -> size; j++){
                if(c -> vet[j] > c -> vet[max]) max = j;
            }

            if(max != i)
            {
                temp = c -> vet[i];
                c -> vet[i] = c -> vet[max];
                c -> vet[max] = temp;
            }
        }
    }
}

//
// Copia o conjunto C1 para o conjunto C2
//
bool copiarConjunto(Conjunto * c1, Conjunto * c2)
{
    unsigned int * temp = NULL;
    criaConjunto(c2);

    temp = (unsigned int *) malloc(c1->size * sizeof(unsigned int));
    if(temp == NULL) return false;

    c2 -> vet = temp;
    for(c2 -> size = 1; c2 -> size <= c1 -> size; c2 -> size++)
    {
        c2 -> vet[c2 -> size - 1] = c1 -> vet[c2 -> size - 1];
    }
    
    c2 -> size--;
    temp = NULL;

    return true;
}

//
// Destroi o conjunto C
//
bool destroiConjunto(Conjunto * c)
{
    free(c -> vet);
    c -> vet = NULL;
    c -> size = 0;

    return true;
}
