#include "../src/ex.h"

int interface(){
    int resposta;
    printf("Digite 1 para inserir na tabela hash gerada\n");
    printf("Digite 2 para realizar a busca de um dado na tabela hash (a partir de seu codigo)\n");
    printf("Digite 3 para remover um dado da tabela hash\n");
    printf("Digite 4 para criar um arquivo de saida\n");
    printf("Digite 5 para encerrar o programa\n");
    printf("Insira o dado: ");
    scanf("%d", &resposta);
    return resposta;
}

void encerrarPrograma(hash** t){
    encerrarHash(*t);
}

int main (void){
    int resposta;
    hash* t=(hash*)calloc(1,sizeof(hash));
    genHash(t, 13, doubleHashFunction, compara, passos);
    if(gerarLista(&t)!=0){
        printf("Ocorreu um erro\n");
        return;
    }
    printf("Bem Vindo ao Programa Jefferson Bombina V3.0\n");
    do{
        int resposta=interface();
        switch (resposta)
        {
        case 1:
            insercaoHash(&t);
            break;
        case 2:
            buscaHash(&t);
            break;
        case 3:
            remocaoHash(&t);
            break;
        case 4:
            FILE* arq;
            arq=fopen("resposta.txt", "w");
            for (int i = 0; i < (t)->size; i++) {
                if ((t)->table[i] != NULL && (t)->table[i] != (t)->deleted) {
                    munic* aux=(munic*)t->table[i];
                    fprintf(arq, "Cod: %d, nome: %s, lati: %f, long: %f, codUf: %d, codSifas: %d, ddd: %d, fuso: %s\n", aux->Cod, aux->NomeMuni, aux->Latitude, aux->Longitude, aux->CodUF, aux->CodSiafi, aux->DDD, aux->FusoHorario);
                }
            }
            fclose(arq);
            break;
        case 5:
            encerrarPrograma(&t);
            break;
        default:
            printf("Ops você selecionou uma opção errada, tente novamente, reveja as opções com cuidado\n");
        }
        
    }while(resposta!=5);
}