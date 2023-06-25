#ifndef _HASH_
#define _HASH_
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define SEED    0x12345678
typedef struct hashTable{
     uintptr_t * table;
     unsigned int atualSize;
     unsigned int size;
     uintptr_t deleted;
     uintptr_t (*get_key)(hash, void*);
     bool (*compara)(void*, void*);
}hash;
bool primo(int num); //feito, sem testar
int acharPrimoProx(int num); //feito, sem testar

bool checksize(hash* t); //feito, sem testar
void * search(hash* t, void* dado); //feito, sem testar

void reSize(hash** t); //em andamento
void insert(hash** t, void* dado); //feito, sem testar
void genHash(hash** t, int size, uintptr_t (*getKey)(hash, void*), bool (*compara)(void*, void*)); //feito, sem testar
//void deleteHash(hash** t, void* dado), não iniciado
//void encerrarHash(hash** t,), não iniciado
#endif//