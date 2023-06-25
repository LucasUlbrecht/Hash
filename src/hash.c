#include "hash.h"
/*
bool checksize(hash* t){
    if(t->atualSize%t->size<0.7){
        return true; //Tamanho aceitavel
    }else{
        return false; //Passou tamanho aceitavel
    }
}
void hash_apaga(hash *h){
    int pos;
    for(pos =0;pos< h->size;pos++){
        if (h->table[pos] != 0){
            if (h->table[pos]!=h->deleted){
                free((void *)h->table[pos]);
            }
        }
    }
    free(h->table);
}
*/
bool primo(int num) {
    if (num <= 1) {
        return false;
    }
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    
    return true;
}
int acharPrimoProx(int num) {
    if (primo(num)) {
        return num;
    }
    
    int menor = num - 1;
    int maior = num + 1;
    
    while (true) {
        if (primo(menor)) {
            return menor;
        }
        
        if (primo(maior)) {
            return maior;
        }
        
        menor--;
        maior++;
    }
}


void genHash(hash* t, int size, unsigned int (*getKey)(int, void*), bool (*compara)(void*, void*), int (*passos) (int, void*)){
    t->table=(uintptr_t*)calloc(size,sizeof(uintptr_t));
    if (t->table == NULL){
        return;
    }
    t->size=(unsigned int)size;
    t->get_key=getKey;
    t->deleted='*';
    t->compara=compara;
    t->passos=passos;
}

void insert(hash* t, void* dado){
    if(t==NULL||dado==NULL) return;
    uintptr_t pos = t->get_key(t->size, dado);
    while(t->table[pos] !=NULL && t->table[pos] != t->deleted) pos = (pos + t->passos(t->size, dado)) % t->size;
    t->table[pos] = (uintptr_t)dado;
    t->atualSize++;
    /*if(!checksize(*t)){
        reSize(t);
    }*/
}
/*
void * search(hash* t, void* dado){
    if(t==NULL||dado==NULL) return;
    uintptr_t pos = t->get_key(*t, dado);
    while(!(t->compara(t->table[pos],dado))) pos = (pos + 1) % t->size;
    return (void*) t->table[pos];
}
void reSize(hash** t){
    int tamanhoNovo=(*t)->size;
    tamanhoNovo=acharPrimoProx(tamanhoNovo*2);
    hash* nova;
    genHash(&nova, tamanhoNovo, (*t)->get_key, (*t)->compara);
    for(int i=0;i<(*t)->size;i++){
        insert(nova, (*t)->table[i]);
    };
    //encerra
    t=&nova;
}*/