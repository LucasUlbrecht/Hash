#include "../src/ex.h"
#include <assert.h>
void testGen(hash* t){
    genHash(t, 13, doubleHashFunction, compara, passos);
    assert(t->size==13);
    assert(t->get_key!=NULL);
    assert(t->atualSize==0);
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
    strcpy(munic1.Capital, "MS");
    munic2.CodSiafi=13;
    strcpy(munic2.Capital, "RJ");
    munic3.CodSiafi=60;
    strcpy(munic3.Capital, "SP");
    insert(&t, &munic1);
    insert(&t, &munic2);
    insert(&t, &munic3);
    munic* test= (munic*)t.table[8];
    assert(test==&munic1);
    munic* test1= (munic*)t.table[0];
    assert(test1==&munic2);
    munic* test2= (munic*)t.table[9];
    assert(t.atualSize==3);
}
void testBusca(hash t){
    munic dado;
    dado.CodSiafi=8;
    munic dado1;
    dado1.CodSiafi=13;
    munic dado2;
    dado2.CodSiafi=60;
    munic* test = search(&t,&dado);
    munic* test1 = search(&t, &dado1);
    munic* test2 = search(&t, &dado2);
    assert(test!=NULL);
    assert(strcmp(test->Capital, "MS")==0);
    assert(test1!=NULL);
    assert(strcmp(test1->Capital, "RJ")==0);
    assert(test2!=NULL);
    assert(strcmp(test2->Capital, "SP")==0);
}

void testReSize(hash t){
    munic munic1;
    munic munic2;
    munic munic3;
    munic munic4;
    munic munic5;
    munic munic6;
    munic1.CodSiafi=1;
    munic2.CodSiafi=2;
    munic3.CodSiafi=3;
    munic4.CodSiafi=4;
    munic5.CodSiafi=5;
    munic6.CodSiafi=6;
    insert(&t, &munic1);
    insert(&t, &munic2);
    insert(&t, &munic3);
    insert(&t, &munic4);
    insert(&t, &munic5);
    insert(&t, &munic6);
    assert(t.size==29);
}
int main (void){
    hash t;
    testGen(&t);
    testHashfy(t);
    testHashfy2(t);
    testInsert(t);
    testBusca(t);
    testReSize(t);
}