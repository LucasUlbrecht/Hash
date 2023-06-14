#include "ex.h"
uintptr_t getKey(hash t, void* dado){
    munic* aux = (munic*) dado;
    uintptr_t auxCod=aux->CodSiafi;
    return (uintptr_t) auxCod%t.size;
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