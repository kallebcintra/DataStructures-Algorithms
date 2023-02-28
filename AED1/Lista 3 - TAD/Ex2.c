//==============================================================================
// Arquivo data.h
//==============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

typedef struct data Data;

struct data{
    unsigned int Dia;
    unsigned int Mes;
    unsigned int Ano;
};

Data * criaData (unsigned int dia, unsigned int mes, unsigned int ano);

Data * copiaData (Data *d);

void liberaData (Data *d);

Data * somaDiasData (Data *d, unsigned int dias); 

Data * subtrairDiasData (Data *d, unsigned int dias);

void atribuirData (Data * d, unsigned int dia, unsigned int mes, unsigned int ano); 

unsigned int obtemDiaData (Data *d);

unsigned int obtemMesData (Data *d);

unsigned int obtemAnoData (Data *d);

unsigned int bissextoData (Data *d);

int comparaData (Data *d1, Data *d2);

unsigned int numeroDiasDatas (Data *d1, Data *d2);

unsigned int numeroMesesDatas (Data *d1, Data *d2);

unsigned int numeroAnosDatas (Data *d1, Data *d2);

unsigned int obtemDiaSemanaData (Data *d);

char * imprimeData (Data *d, char * formato);

void leData(Data *d);

void erro(char *erro_msg);

bool dataValida(int dia, int mes, int ano);

int ultimoDiaMes(Data *d);

void printData(Data *d, char *formato);

void Menu();

//==============================================================================
// Arquivo data.c
//==============================================================================
int main()
{
    int n;
    Data *a = criaData(1, 1, 1900), *b = criaData(1, 1, 1900);
    char *str = str = (char *) malloc(20*sizeof(char));;
    int entrada;
    int x;

    while(n != 0)
    {
        Menu();
        strcpy(str, "ddmmaaaa");
        scanf("%d", &n);

        switch(n)
        {
            case 1:
                leData(a);

                printf("Digite uma quantidade de dias\n");
                scanf("%d", &entrada);

                liberaData(b);

                b = somaDiasData(a, entrada);
                printf("Data apos %d dias:\n", entrada);
                printData(b, str);

                break;
            case 2:
                leData(a);

                printf("Digite uma quantidade de dias\n");
                scanf("%d", &entrada);

                liberaData(b);

                b = subtrairDiasData(a, entrada);
                printf("Data %d dias antes:\n", entrada);
                printData(b, str);

                break;
            case 3:
                leData(a);

                x = obtemDiaData(a);

                printf("Dia: %d\n", x);

                break;
            case 4:
                leData(a);

                x = obtemMesData(a);

                printf("Mes: %d\n", x);

                break;
            case 5:
                leData(a);

                x = obtemAnoData(a);

                printf("Ano: %d\n", x);

                break;
            case 6:
                leData(a);

                if(bissextoData(a)) printf("Ano bissexto\n");
                else printf("Ano bissexto\n");

                break;
            case 7:
                leData(a);
                leData(b);

                if(comparaData(a, b) == 0) printf("Datas iguais\n");
                else if(comparaData(a, b) == -1) printf("Primeira Data e mais recente\n");
                else printf("Primeira Data e mais antiga\n");

                break;
            case 8:
                printf("Digite Data mais 'recente'\n");
                leData(a);
                printf("Digite Data mais 'antiga'\n");
                leData(b);

                if(comparaData(a, b) == 1)
                {
                    printf("A primeira data deve ser mais 'recente'\n");
                    break;
                }

                printf("Diferenca de dias entre as Datas: %d\n", numeroDiasDatas(a, b));

                break;
            case 9:
                printf("Digite Data mais 'recente'\n");
                leData(a);
                printf("Digite Data mais 'antiga'\n");
                leData(b);

                if(comparaData(a, b) == 1)
                {
                    printf("A primeira data deve ser mais 'recente'\n");
                    break;
                }

                printf("Diferenca de meses entre as Datas: %d\n", numeroMesesDatas(a, b));

                break;
            case 10:
                printf("Digite Data mais 'recente'\n");
                leData(a);
                printf("Digite Data mais 'antiga'\n");
                leData(b);

                if(comparaData(a, b) == 1)
                {
                    printf("A primeira data deve ser mais 'recente'\n");
                    break;
                }

                printf("Diferenca de anos entre as Datas: %d\n", numeroAnosDatas(a, b));

                break;
            case 11:
                leData(a);

                entrada = obtemDiaSemanaData(a);

                if(entrada == 1) printf("Domingo\n");
                else if(entrada == 2) printf("Segunda-feira\n");
                else if(entrada == 3) printf("Terça-feira\n");
                else if(entrada == 4) printf("Quarta-feira\n");
                else if(entrada == 5) printf("Quinta-feira\n");
                else if(entrada == 6) printf("Sexta-feira\n");
                else printf("Sabado\n");
    
                break;
            case 12:
                leData(a);

                printf("Digite o formato desejado\n");
                printf("aaaammdd\n");
                printf("ddmmaaaa\n");
                printf("dd\n");
                printf("mm\n");
                printf("aaaa\n");
                printf("ddmm\n");

                scanf("%s", str);

                printData(a, str);
    
                break;
        }
    }

    return 0;
}

//
//Função que printa um menu na tela
//
void Menu()
{
    printf("Manipulando Datas (Menu):\n");
    printf("\n");
    printf("\t1. Soma dias a uma Data\n");
    printf("\t2. Subtrai dias a uma Data\n");
    printf("\t3. Obtem o dia de uma Data\n");
    printf("\t4. Obtem o mes de uma Data\n");
    printf("\t5. Obtem o ano de uma Data\n");
    printf("\t6. Verifica se uma Data pertence a um ano Bissexto\n");
    printf("\t7. Comparar duas Datas\n");
    printf("\t8. Numero de dias entre duas Datas\n");
    printf("\t9. Numero de meses entre duas Datas\n");
    printf("\t10. Numero de anos entre duas Datas\n");
    printf("\t11. Obtem o dia da semana de uma Data\n");
    printf("\t12. Imprime uma Data\n");
    printf("\t0. Finalizar o programa\n");
    printf("\n");
    printf("Escolha uma das operacoes: ");
}

//
//Função Cria uma Data
//
Data *criaData(unsigned int dia, unsigned int mes, unsigned int ano)
{
    Data *D = NULL;

    D = (Data *) malloc(sizeof(Data));
    if(D == NULL) erro("criaData");
    D -> Dia = dia;
    D -> Mes = mes;
    D -> Ano = ano;

    return D;
}

//
//Função que copia uma data
//
Data *copiaData(Data *d)
{
    Data *copia = criaData(d -> Dia, d -> Mes, d -> Ano);
    return copia;
}

//
//Função destroi data indicada por d
//
void liberaData(Data *d)
{
    if(d == NULL) erro("liberaData");
    free(d);
}

//
//Função soma dias a uma data
//
Data *somaDiasData(Data *d, unsigned int dias)
{
    Data *Novo = copiaData(d);
    Data *r = NULL;

    int mesLimite = ultimoDiaMes(d);

    if((d -> Dia + dias) <= mesLimite)
    {
        Novo -> Dia += dias;
        return Novo;
    }

    dias -= mesLimite - d -> Dia + 1;
    Novo -> Dia = 1;

    if(d -> Mes == 12)
    {
        Novo -> Mes = 1;
        Novo -> Ano++;
    }
    else Novo -> Mes++;

    r = somaDiasData(Novo, dias);

    liberaData(Novo);

    return r;
}

//
//Função descobre se um ano é bissexto
//
unsigned int bissextoData(Data *d)
{
    int r = 0;

    if(d -> Ano % 400 == 0) r = 1;
    else if(d -> Ano % 4 == 0 && d -> Ano % 100 != 0) r = 1;

    return r;
}

//
//Função subtrai dias a uma data
//
Data *subtrairDiasData(Data *d, unsigned int dias)
{
    Data *Novo = copiaData(d);
    Data *r = NULL;

    int mesLimite;

    if((d -> Dia - dias) >= 1)
    {
        Novo -> Dia -= dias;
        return Novo;
    }

    if(d -> Mes == 1)
    {
        Novo -> Mes = 12;
        Novo -> Ano--;
    }
    else Novo -> Mes--;

    mesLimite = ultimoDiaMes(Novo);

    dias -= d -> Dia;
    Novo -> Dia = mesLimite;

    r = subtrairDiasData(Novo, dias);
    liberaData(Novo);

    return r;
}

//
//Função que obtem os dias de uma Data
//
unsigned int obtemDiaData(Data *d)
{
    return d -> Dia;
}

//
//Função que obtem o Mês de uma Data
//
unsigned int obtemMesData(Data *d)
{
    return d -> Mes;
}

//
//Função que obtem o ano de uma Data
//
unsigned int obtemAnoData(Data *d)
{
    return d -> Ano;
}

//
//Função compara duas Datas
//
int comparaData(Data *d1, Data *d2)
{
    if(d1 -> Ano > d2 -> Ano) return -1;
    else if(d1 -> Ano < d2 -> Ano) return 1;

    if(d1 -> Mes > d2 -> Mes) return -1;
    else if(d1 -> Mes < d2 -> Mes) return 1;

    if(d1 -> Dia > d2 -> Dia) return -1;
    else if(d1 -> Dia < d2 -> Dia) return 1;

    return 0;
}

//
//Função retorna o número de dias que existe entre as datas d1 e d2
//
unsigned int numeroDiasDatas(Data *d1, Data *d2)
{
    Data *Novo = NULL;
    int dataDif = 0;

    if(comparaData(d1, d2) == 1) erro("numeroDiasDatas");

    if(d1 -> Mes == d2 -> Mes && d1 -> Ano == d2 -> Ano)
    {
        dataDif += d1 -> Dia - d2 -> Dia;
        return dataDif;
    }

    Novo = subtrairDiasData(d1, d1 -> Dia);

    dataDif += d1 -> Dia;
    dataDif += numeroDiasDatas(Novo, d2);

    liberaData(Novo);
     
    return dataDif;
}

//
//Função retorna o número de meses que existe entre as datas d1 e d2
//
unsigned int numeroMesesDatas(Data *d1, Data *d2)
{
    Data *Novo = NULL;
    int dataDif = 0;

    if(comparaData(d1, d2) == 1) erro("numeroMesesDatas");

    if(d1 -> Ano == d2 -> Ano) {
        dataDif += d1 -> Mes - d2 -> Mes;
        return dataDif;
    }

    Novo = criaData(31, 12, d1 -> Ano - 1);

    dataDif += d1 -> Mes;
    dataDif += numeroMesesDatas(Novo, d2);
    
    liberaData(Novo);
    
    return dataDif;
}

//
//Função retorna o número de anos que existe entre as datas d1 e d2
//
unsigned int numeroAnosDatas(Data *d1, Data *d2)
{
    if(comparaData(d1, d2) == 1) erro("numeroAnosDatas");

    return d1 -> Ano - d2 -> Ano;
}

//
//Função atribui, à data d, a data dia/mes/ano especificada
//
void atribuirData(Data *d, unsigned int dia, unsigned int mes, unsigned int ano)
{
    if(!dataValida(dia, mes, ano))
    { 
        d = NULL;
        return;
    }

    d -> Dia = dia;
    d -> Mes = mes;
    d -> Ano = ano;
}

//
//Função determina se data informada, é válida
//
bool dataValida(int dia, int mes, int ano)
{
    Data *d = criaData(dia, mes, ano);;
    bool valida = true;
    
    if(ano < 0) valida = false;
    else if(mes < 1 || mes > 12) valida = false;
    else if(dia < 1 || dia > ultimoDiaMes(d)) valida = false;

    liberaData(d);

    return valida;
}

//
//Função retorna o dia da semana correspodente à data d
//
unsigned int obtemDiaSemanaData(Data *d)
{
    Data *temp = NULL;
    int i, r;
    int Dif;

    temp = criaData(1, 1, 1900);
    if(comparaData(d, temp) == 1) erro("obtemDiaSemanaData");

    Dif = numeroDiasDatas(d, temp);
    liberaData(temp);

    r = 2;
    for(i = 0; i < Dif; i++)
    {
        if(r == 7) r = 1;
        else r++;
    }

    return r;
}

//
//Função imprime data em formato padrão
//
char *imprimeData(Data *d, char *formato)
{
    char *str = NULL;

    str = (char *) malloc(20*sizeof(char));

    if(formato == NULL) erro("imprimeData");
    else if(strcmp(formato, "ddmmaaaa") == 0) sprintf(str, "%02d/%02d/%04d", d -> Dia, d -> Mes, d -> Ano);
    else if(strcmp(formato, "aaaammdd") == 0) sprintf(str, "%04d/%02d/%02d", d -> Ano, d -> Mes, d -> Dia);
    else if(strcmp(formato, "aaaa") == 0) sprintf(str, "%04d", d -> Ano);
    else if(strcmp(formato, "mm") == 0) sprintf(str, "%02d", d -> Mes);
    else if(strcmp(formato, "dd") == 0) sprintf(str, "%02d", d -> Dia);
    else if(strcmp(formato, "ddmm") == 0) sprintf(str, "%02d/%02d", d -> Dia, d -> Mes);
    else erro("imprimeData");

    return str;
}

//
// Função "printa" uma data na tela
//
void printData(Data *d, char *formato)
{
    char *str = NULL;

    str = imprimeData(d, formato);
    printf("%s\n", str);
    free(str);
}

//
//Função Lê uma Data
//
void leData(Data *d)
{
    Data n;

    printf("Digite uma data no formato padrao \"dd mm aaaa\"\n");
    scanf("%d%d%d", &n.Dia, &n.Mes, &n.Ano);

    if(!dataValida(n.Dia, n.Mes, n.Ano))
    {
        printf("ERRO\n");
        leData(d);
    }

    atribuirData(d, n.Dia, n.Mes, n.Ano);
}

//
//Função que imprime mensagem de erro
//
void erro(char *erro_msg)
{
    printf("Erro na função %s\n", erro_msg);
    exit(0);
}

//
//Função que "separa" os meses quanto ao numero de dias
//
int ultimoDiaMes(Data *d)
{
    if(d -> Mes == 1 || d -> Mes == 3 || d -> Mes == 5 || d -> Mes == 7 || d -> Mes == 8 || d -> Mes == 10 || d -> Mes == 12) return 31;
    else if(d -> Mes == 4 || d -> Mes == 6 || d -> Mes == 9 || d -> Mes == 11) return 30;
    else if(bissextoData(d)) return 29;
    else if(d -> Mes == 2) return 28;
}