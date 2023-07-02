#ifndef _HASH_
#define _HASH_
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
typedef struct hashTable{
     uintptr_t * table;
     unsigned int atualSize;
     unsigned int size;
     uintptr_t deleted;
     unsigned int (*get_key)(int, void*);  
     bool (*compara)(void*, void*);
     int (*passos) (int, void*);
     void (*delet) (void*);
     bool (*checkDel) (void*);
}hash;
bool primo(int num); //feito, testado
int acharPrimoProx(int num); //feito, testado

bool checksize(hash* t); //feito, sem testar
void * search(hash* t, void* dado); //feito, sem testar

void reSize(hash** t); //feito, testado
void insert(hash** t, void* dado); //feito, testado
void genHash(hash* t, int size, unsigned int (*getKey)(int, void*), bool (*compara)(void*, void*), int (*passos) (int, void*)); //feito, testado
void deleteHash(hash* t, void* dado);//, não iniciado
void hash_apaga(hash *h);
void encerrarHash(hash* t);//, não iniciado
#endif//
