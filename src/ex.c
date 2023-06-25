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
    return 1 + (aux->CodSiafi % (size - 1));
}
