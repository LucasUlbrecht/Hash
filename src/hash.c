#include "hash.h"
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
        if (isPrime(menor)) {
            return menor;
        }
        
        if (isPrime(maior)) {
            return maior;
        }
        
        menor--;
        maior++;
    }
}
void genHash(hash** t, int size, uintptr_t (*getKey)(hash, void*), bool (*compara)(void*, void*)){
    *t=(hash*)calloc(size,sizeof(hash));
    (*t)->table=(uintptr_t)calloc(size,sizeof(uintptr_t));
    (*t)->get_key=getKey;
    (*t)->deleted='*';
    (*t)->compara=compara;
}
void insert(hash** t, void* dado){
    if(t==NULL||dado==NULL) return;
    uintptr_t pos = (*t)->get_key(**t, dado);
    while((*t)->table[pos] !=0 && (*t)->table[pos] != (*t)->deleted) pos = (pos + 1) % (*t)->size;
    (*t)->table[pos] = (uintptr_t)dado;
    (*t)->atualSize++;
    if(!checksize(*t)){
        reSize(t);
    }
}
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
}//