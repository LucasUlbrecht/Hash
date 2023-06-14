#include "ex.h"
void testInsert(hash* t){
    munic* munic1;
    munic* munic2;
    munic* munic3;
    munic1->CodSiafi=1;
    munic2->CodSiafi=2;
    munic3->CodSiafi=3;
    genHash(&t, 13, getKey);
    insert(&t, munic1);
    insert(&t, munic2);
    insert(&t, munic3);
}
int main (void){
    hash *t;
    testInsert(t);
}