#include "ex.h"

int getKey(int t, int cod){
    
    return cod%t;
}

unsigned int doubleHashFunction(int size, void* dado)
{
    munic* aux = (munic*) dado;
    unsigned int hash1 = getKey(size, aux->CodSiafi);
    unsigned int hash2 = 1 + (aux->CodSiafi % (size - 1));
    return (hash1 + acharPrimoProx(size) * hash2) % size;
}

bool compara(void* dadoTable, void* dadoComp){
    munic* auxTable = (munic*)dadoTable;
    munic* auxComp = (munic*)dadoComp;
    if(auxTable->CodSiafi==auxComp->CodSiafi){
        return true;
    }else{
        return false;
    }
}
int passos(int size, void* dado){
    
    munic* aux = (munic*) dado;
    return (1+(aux->CodSiafi % (size - 1)));
}
int gerarLista(hash** t){
    FILE* arq = fopen("municipios.txt","r");
    if(arq==NULL){
        printf("Erro gerar arquivo\n");
        return 1;
    }
    munic* municAux;
    int lixo;
    while(!feof(arq)){
        //printf("Gerando dado\n");
        municAux = (munic*)calloc(1, sizeof(munic));
        //printf("Dado gerado\n");
        fscanf(arq, "%d,", &municAux->Cod);
        fscanf(arq, "%[^,],", municAux->NomeMuni);
        fscanf(arq, "%f,", &municAux->Latitude);
        fscanf(arq, "%f,", &municAux->Longitude);
        fscanf(arq, "%d,", &lixo);
        fscanf(arq, "%d,", &municAux->CodUF);
        fscanf(arq, "%d,", &municAux->CodSiafi);
        fscanf(arq, "%d,", &municAux->DDD);
        fscanf(arq, "%[^\n]\n", municAux->FusoHorario);
        //printDado(municAux);
        insert(t, municAux);
    }
    return 0;
}
void insercaoHash(hash** t){
    munic* municAux = (munic*)calloc(1, sizeof(munic));
    int lixo;
    printf("Insira codigo\n");
    scanf( "%d,", &municAux->Cod);
    printf("Insira Nome\n");
    scanf( " %[^\n]", municAux->NomeMuni);
    printf("Insira Latitude\n");
    scanf( "%f,", &municAux->Latitude);
    printf("Insira Longitude\n");
    scanf( "%f,", &municAux->Longitude);
    printf("Insira Capital\n");
    scanf( " %[^\n]", municAux->Capital);
    printf("Insira Codigo UF\n");
    scanf( "%d,", &municAux->CodUF);
    printf("Insira CodigoSiafi\n");
    scanf( "%d,", &municAux->CodSiafi);
    printf("Insira ddd\n");
    scanf( "%d,", &municAux->DDD);
    printf("Insira Fuso Horario\n");
    scanf( " %[^\n]", municAux->FusoHorario);
    printf("Insirindo novo municipio\n");
    insert(t,municAux);
}
void buscaHash(hash** t){
    munic* dado=(munic*)calloc(1,sizeof(munic));
    printf("Insira codigo siafi do municipio que deseja encontrar\n");
    scanf("%d", &dado->CodSiafi);
    munic* resposta=search(*t, (void*)dado);
    printDado(resposta);
}
void remocaoHash(hash** t){
    munic* dado=(munic*)calloc(1,sizeof(munic));
    printf("Insira codigo siafi do municipio que deseja remover\n");
    scanf("%d", &dado->CodSiafi);
    deleteHash(*t, (void*)dado);
    printf("Removido\n");
}
void printDado(void* dado){
    munic* aux=(munic*) dado;
    printf("Cod: %d, nome: %s, lati: %f, long: %f, codUf: %d,codSifas: %d,ddd: %d,fuso: %s\n", aux->Cod, aux->NomeMuni, aux->Latitude, aux->Longitude, 
    aux->CodUF, aux->CodSiafi, aux->DDD, aux->FusoHorario);
}