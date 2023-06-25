#ifndef _EX_
#define _EX_
#include"hash.h"
#define TAM_LIXO 70
#define MAX_NOME_MUNICIPIO 29
#define MAX_SIGLA_UF 2
#define MAX_NOME_ESTADO 17
#define MAX_NOME_CAPITAL 8
#define MAX_NOME_REGIAO 9
#define MAX_TAM_FUSO 30
#define NUM_ESTADOS 30
#define MAX_TAMADRRESS 50
#define MAX_TAMCITY 30
#define MAX_TAMCOUNTRY 2
#define MAX_TAMWEB 100
typedef struct MunicipiosBrasileiros
{
    int Cod;
    char NomeMuni[MAX_NOME_MUNICIPIO+1];
    char Estado[MAX_NOME_ESTADO+1];
    char Capital[MAX_NOME_CAPITAL+1];
    float	Latitude;
    float Longitude;
    int CodSiafi;
    int	DDD;
    char FusoHorario[MAX_TAM_FUSO+1];
    int	CodUF;
    char SiglaUF[MAX_SIGLA_UF+1];
    char Regiao[MAX_NOME_REGIAO+1];
}munic;
//void gerarLista(hash t);
//void printDado(hash t);
int passos(int size, void* dado);
int getKey(int t, int cod); //testado
bool compara(void* dadoTable, void* dadoComp); //testado
unsigned int doubleHashFunction(int size, void* dado);
#endif//