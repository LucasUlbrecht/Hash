int main (void){
    //Hash hash;
    int resposta=interface();
    //Respostas: 0-Teste Funcionalidades, 1-Inserir Lista, 2-Buscar por, 3-Remover Elemento, 4-Ler Lista Gerada, 5-Encerrar Programa 
    switch (resposta)
    {
    case 1:
        insercaoHash();
        break;
    case 2:
        buscaHash();
        break;
    case 3:
        remocaoHash();
        break;
    case 4:
        gerarLista();
    case 5:
        encerrarPrograma();
    default:
        break;
    }
}