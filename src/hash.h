#ifndef _HASH_
#define _HASH_
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
typedef struct hashTable{
     uintptr_t * table;
     unsigned int atualSize;
     unsigned int size;
     uintptr_t deleted;
     unsigned int (*get_key)(int, void*);  
     bool (*compara)(void*, void*);
     int (*passos) (int, void*);
}hash;
bool primo(int num); //feito, testado
int acharPrimoProx(int num); //feito, testado

bool checksize(hash* t); //feito, sem testar
void * search(hash* t, void* dado); //feito, sem testar

void reSize(hash* t); //em andamento
void insert(hash* t, void* dado); //feito, testado
void genHash(hash* t, int size, unsigned int (*getKey)(int, void*), bool (*compara)(void*, void*), int (*passos) (int, void*)); //feito, testado
//void deleteHash(hash* t, void* dado);//, não iniciado
void encerrarHash(hash* t);//, não iniciado
#endif//
