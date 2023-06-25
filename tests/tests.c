#include "../src/ex.h"
#include <assert.h>
void testGen(hash* t){
    genHash(t, 13, doubleHashFunction, compara, passos);
    assert(t->size==13);
    assert(t->get_key!=NULL);
}
void testHashfy(hash t){

    munic aux;
    aux.CodSiafi=8;
    int pos;
    pos=getKey(t.size, aux.CodSiafi);
    assert(pos==8);
    munic aux1;
    aux1.CodSiafi=14;
    int pos1;
    pos1=getKey(t.size, aux1.CodSiafi);
    assert(pos1==1);
    assert(t.size==13);
    
    //Status: Funciona;


}
void testHashfy2(hash t){
    munic aux;
    aux.CodSiafi=8;
    int pos;
    pos=t.get_key(t.size, &aux);
    assert(pos==8);
    munic aux1;
    aux1.CodSiafi=58;
    int pos1;
    pos1=t.get_key(t.size, &aux1);
    assert(pos1==6);
}
void testInsert(hash t){
    munic munic1;
    munic munic2;
    munic munic3;
    munic1.CodSiafi=8;
    munic2.CodSiafi=13;
    munic3.CodSiafi=60;
    insert(&t, &munic1);
    insert(&t, &munic2);
    insert(&t, &munic3);
    munic* test= (munic*)t.table[8];
    assert(test==&munic1);
    munic* test1= (munic*)t.table[0];
    assert(test1==&munic2);
    munic* test2= (munic*)t.table[9];
    assert(test2==&munic3);
}
int main (void){
    hash t;
    testGen(&t);
    testHashfy(t);
    testHashfy2(t);
    testInsert(t);
}