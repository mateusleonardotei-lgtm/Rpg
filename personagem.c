#include <stdio.h>
#include <string.h>
#include "personagem.h"
#include "inventario.h"

// Função para ler o nome do personagem, garantindo que não exceda o tamanho máximo permitido
int lerNomePersonagem(char nome[])
{
    int c;
    int i = 0;
    int excedeu = 0;
    /* verifica se o nome excedeu o tamanho máximo permitido
    ou se o usuario digitou um nome vazio */
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (i < 49)
        {
            nome[i] = c;
            i++;
        }
        else
        {
            excedeu = 1;
        }
    }

    nome[i] = '\0';

    return excedeu;
}

int lerInteiroPersonagem()
{
    int valor;
    char c;

    while (1)
    {
        if (scanf("%d%c", &valor, &c) == 2 && c == '\n')
        {
            return valor;
        }

        printf("Erro: digite apenas um numero!\n");

        while (getchar() != '\n');
    }

}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
/* Função para verificar se o ID já existe no array de personagens */

int verificarId(PERSONAGEM *personagens, int numPersonagens, int id)
{
    for (int i = 0; i < numPersonagens; i++)
    {
        if (personagens[i].id == id)
        {
            return 1;
        }
    }

    return 0;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
/* Função para cadastrar um novo personagem */

void preencherPersonagem(PERSONAGEM *novo)
{
    int tempRaca, tempClasse;
    int nomeInvalido;
    int SIM_NAO;

    do{
        // ID
        do
        {
            printf("\nDigite o id do personagem:\n ");
            fflush(stdout);
            novo->id = lerInteiroPersonagem();

            if (novo->id <= 0)
            {
                printf("Erro: o ID deve ser maior que zero!\n");
            }

        } while (novo->id <= 0);

        // Nome
        do
        {
            printf("Digite o nome do personagem:\n ");
            fflush(stdout);
            nomeInvalido = lerNomePersonagem(novo->nome);

            if (strlen(novo->nome) == 0)
            {
                printf("Erro: o nome nao pode ser vazio!\n");
            }
            else if (nomeInvalido)
            {
                printf("Erro: o nome nao pode ter mais de 49 caracteres!\n");
            }

        } while (novo->nome[0] == '\0' || nomeInvalido);

        // Raça
        do
        {
            printf("\nDigite a raca do personagem (0- ELFO, 1- ANAO, 2- HUMANO, 3- HALFING, 4- DRUIDA, 5- DRACONICO, 6- DEMIHUMANOS, 7- ORC, 8- ANJO ou 9- DEMONIO):\n ");
            fflush(stdout);
            tempRaca = lerInteiroPersonagem();

            if (tempRaca < 0 || tempRaca > 9)
            {
                printf("Erro: raca invalida! Digite um valor entre 0 e 9.\n");
            }
        } while (tempRaca < 0 || tempRaca > 9);

        novo->raca = (RACA)tempRaca;

        // Classe
        do
        {
            printf("\nDigite a classe do personagem (0- GUERREIRO, 1- MAGO, 2- LADINO, 3- CLERIGO, 4- ARQUEIRO, 5- BERSERKER, 6- ALQUIMISTA, 7- BEASTMASTER, 8- MESTRE EM ARMADILHAS ou 9- SUMMONER):\n ");
            fflush(stdout);
            tempClasse = lerInteiroPersonagem();

            if (tempClasse < 0 || tempClasse > 9)
            {
                printf("Erro: classe invalida! Digite um valor entre 0 e 3.\n");
            }
        } while (tempClasse < 0 || tempClasse > 9);

        novo->classe = (CLASSE)tempClasse;

        // Nivel
        do
        {
            printf("\nDigite o nivel do personagem (entre 1 e 20):\n ");
            fflush(stdout);
            novo->nivel = lerInteiroPersonagem();

            if (novo->nivel < 1)
            {
                printf("Erro: o nivel deve ser maior que zero!\n");
            }
        } while (novo->nivel < 1 || novo->nivel > 20);

        // Vida máxima
        do
        {
            printf("\nDigite a vida maxima do personagem (entre 1 e 999):\n ");
            fflush(stdout);
            novo->vidaMaxima = lerInteiroPersonagem();

            if (novo->vidaMaxima < 1)
            {
                printf("Erro: a vida maxima deve ser maior que zero!\n");
            }
        } while (novo->vidaMaxima < 1 || novo->vidaMaxima > 999);

        // Vida atual
        do
        {
            printf("\nDigite a vida atual do personagem (entre 0 e %d):\n ", novo->vidaMaxima);
            fflush(stdout);
            novo->vidaAtual = lerInteiroPersonagem();

            if (novo->vidaAtual < 0 || novo->vidaAtual > novo->vidaMaxima)
            {
                printf("Erro: a vida atual deve ser entre 0 e a vida maxima!\n");
            }
        } while (novo->vidaAtual < 0 || novo->vidaAtual > novo->vidaMaxima);

        // Ataque
        do
        {
            printf("\nDigite o ataque do personagem (entre 0 e 30):\n ");
            fflush(stdout);
            novo->ataque = lerInteiroPersonagem();

            if (novo->ataque < 0)
            {
                printf("Erro: o ataque nao pode ser negativo!\n");
            }
        } while (novo->ataque < 0 || novo->ataque > 30);

        // Defesa
        do
        {
            printf("\nDigite a defesa do personagem (entre 0 e 30):\n ");
            fflush(stdout);
            novo->defesa = lerInteiroPersonagem();

            if (novo->defesa < 0)
            {
                printf("Erro: a defesa nao pode ser negativa!\n");
            }
        } while (novo->defesa < 0 || novo->defesa > 30);

        // Iniciativa
        do
        {
            printf("\nDigite a iniciativa do personagem (entre -5 e 20):\n ");
            fflush(stdout);
            novo->iniciativa = lerInteiroPersonagem();

            if (novo->iniciativa < -5)
            {
                printf("Erro: a iniciativa nao pode ser menor que -5!\n");
            }
        } while (novo->iniciativa < -5 || novo->iniciativa > 20);

        // Poder
        do
        {
            printf("\nDigite o poder do personagem (entre 1 e 100):\n ");
            fflush(stdout);
            novo->poder = lerInteiroPersonagem();

            if (novo->poder < 1)
            {
                printf("Erro: o poder nao pode ser menor que 1!\n");
            }
        } while (novo->poder < 1 || novo->poder > 100);

        //-------------ERRO-------------ERRO-------------ERRO-------------ERRO-------------ERRO-------------ERRO-------------ERRO-------------ERRO-------------
    /*Código deveria printar toda a ficha criada e perguntar se é essa mesmo e se não rodar o cadastro novamente*/

        //Mostra a prévia da ficha e espera uma confirmação para salvar a ficha novamente
        // Mostra a prévia e aguarda confirmação
        printf("\n======================================");
        printf("\n--- PREVIA DO PERSONAGEM ---");
        printf("\nID: %d | Nome: %s", novo->id, novo->nome);
        printf("\nNivel: %d | Vida: %d/%d", novo->nivel, novo->vidaAtual, novo->vidaMaxima);
        printf("\nAtaque: %d | Defesa: %d | Iniciativa: %d | Poder: %d", novo->ataque, novo->defesa, novo->iniciativa, novo->poder);
        printf("\n======================================");
        printf("\nEsta e a ficha que voce deseja criar?\n1- SIM\n0- NAO\nOpcao: ");
        do
        {
            printf("Esta e realmente a ficha que voce deseja criar?\n1- SIM\n0- NAO\n");
            fflush(stdout);

            SIM_NAO = lerInteiroPersonagem();

            if(SIM_NAO!=0 && SIM_NAO!=1){
                printf("Opcao invalida! Digite 1 ou 0 para SIM ou NAO, respectivamente.");
            }
        }while(SIM_NAO!=0 && SIM_NAO!=1);

        if(SIM_NAO==0){
            printf("\n--- Reiniciando o cadastro... ---\n");
        }
        //-------------ERRO-------------ERRO-------------ERRO-------------ERRO-------------ERRO-------------ERRO-------------ERRO-------------ERRO-------------

    }while(SIM_NAO==0);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Função para inicializar o cadastro de personagens

void inicializarCadastro(CadastroPersonagens *cadastro)
{
    cadastro->quantidade = 0;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Função para cadastrar um novo personagem no cadastro

void cadastrarPersonagem(PERSONAGEM *novo, CadastroPersonagens *cadastro)
{
    if (cadastro->quantidade >= MAX_PERSONAGENS)
    {
        printf("Erro: limite de personagens atingido!\n");
        return;
    }

    // Verifica se o ID já existe
    if (verificarId(cadastro->personagens, cadastro->quantidade, novo->id))
    {
        printf("Erro: ID ja existe! Escolha outro ID.\n");
        return;
    }

    cadastro->personagens[cadastro->quantidade] = *novo;
    inicializarInventario(&cadastro->personagens[cadastro->quantidade].inventario);
    for(int i = 0; i < 10; i++){
        cadastro->personagens[cadastro->quantidade].equipamentosOcupados[i] = 0;
    }
    cadastro->quantidade++;

    printf("Personagem cadastrado com sucesso!\n");
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Função para mostrar os detalhes de um personagem

void mostrarPersonagem(PERSONAGEM *p)
{
    printf("\n--- Detalhes do Personagem ---\n");
    printf("ID: %d\n", p->id);
    printf("Nome: %s\n", p->nome);
    switch (p->raca)
    {
    case ELFO:
        printf("Raca: ELFO\n");
        break;
    case ANAO:
        printf("Raca: ANAO\n");
        break;
    case HUMANO:
        printf("Raca: HUMANO\n");
        break;
    case HALFING:
        printf("Raca: HALFING\n");
        break;
    case DRUIDA:
        printf("Raca: DRUIDA\n");
        break;
    case DRACONICO:
        printf("Raca: DRACONICO\n");
        break;
    case DEMIHUMANO:
        printf("Raca: DEMIHUMANO\n");
        break;
    case ORC:
        printf("Raca: ORC\n");
        break;
    case ANJO:
        printf("Raca: ANJO\n");
        break;
    case DEMONIO:
        printf("Raca: DEMONIO\n");
        break;
    default:
        printf("Raca: Desconhecida\n");
        break;
    }

    switch (p->classe)
    {
    case GUERREIRO:
        printf("Classe: GUERREIRO\n");
        break;
    case MAGO:
        printf("Classe: MAGO\n");
        break;
    case LADINO:
        printf("Classe: LADINO\n");
        break;
    case CLERIGO:
        printf("Classe: CLERIGO\n");
        break;
    case ARQUEIRO:
        printf("Classe: ARQUEIRO\n");
        break;
    case BERSERKER:
        printf("Classe: BERSERKER\n");
        break;
    case ALQUIMISTA:
        printf("Classe: ALQUIMISTA\n");
        break;
    case BEASTMASTER:
        printf("Classe: BEASTMASTER\n");
        break;
    case MESTRE_EM_ARMADILHAS:
        printf("Classe: MESTRE_EM_ARMADILHAS\n");
        break;
    case SUMMONER:
        printf("Classe: SUMMONER\n");
        break;
    default:
        printf("Classe: Desconhecida\n");
        break;
    }
    printf("Nivel: %d\n", p->nivel);
    printf("Vida Maxima: %d\n", p->vidaMaxima);
    printf("Vida Atual: %d\n", p->vidaAtual);
    printf("Ataque: %d\n", p->ataque);
    printf("Defesa: %d\n", p->defesa);
    printf("Iniciativa: %d\n", p->iniciativa);
    printf("Poder: %d\n", p->poder);
    printf("-------------------------------\n");
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Função para listar todos os personagens cadastrados

void listarPersonagens(CadastroPersonagens *cadastro)
{
    if (cadastro->quantidade == 0)
    {
        printf("Nenhum personagem cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Personagens ---\n");
    for (int i = 0; i < cadastro->quantidade; i++)
    {
        mostrarPersonagem(&cadastro->personagens[i]);
    }
}

PERSONAGEM *buscarPersonagemPorId(CadastroPersonagens *cadastro, int id)
{
    for (int i = 0; i < cadastro->quantidade; i++)
    {
        if (cadastro->personagens[i].id == id)
        {
            return &cadastro->personagens[i];
        }
    }
    return NULL;
}

void alterarPersonagem(CadastroPersonagens *cadastro)
{

    int id;
    PERSONAGEM *personagem;

    printf("Digite o ID do personagem que deseja alterar: ");
    id = lerInteiroPersonagem();

    while (getchar() != '\n');

    personagem = buscarPersonagemPorId(cadastro, id);

    if (personagem == NULL)
    {
        printf("Personagem nao encontrado!\n");
        return;
    }

    printf("\nPersonagem encontrado!\n");
    mostrarPersonagem(personagem);

    int opcao;
    printf("\nDigite o campo que deseja alterar:\n");
    printf("1 - Nome\n");
    printf("2 - Raca\n");
    printf("3 - Classe\n");
    printf("4 - Nivel\n");
    printf("5 - Vida Maxima\n");
    printf("6 - Vida Atual\n");
    printf("7 - Ataque\n");
    printf("8 - Defesa\n");
    printf("9 - Iniciativa\n");
    printf("10 - Poder\n");
    printf("0 - Cancelar\n");

    printf("\nDigite uma opcao: ");
    opcao = lerInteiroPersonagem();
    while (getchar() != '\n');

    switch (opcao)
    {
    case 1:;
        printf("Digite o novo nome: ");
        lerNomePersonagem(personagem->nome);

        if (strlen(personagem->nome) == 0)
        {
            printf("Erro: o nome nao pode ser vazio!\n");
        }
        else
        {
            printf("Nome alterado com sucesso!\n");
        }
        break;

    case 2:;
        int tempRaca;
        do
        {
            printf("\nDigite a nova raca: \n");
            printf("0- ELFO\n");
            printf("1- ANAO\n");
            printf("2- HUMANO\n");
            printf("3- HALFING\n");
            printf("4- DRUIDA\n");
            printf("5- DRACONICO\n");
            printf("6- DEMIHUMANO\n");
            printf("7- ORC\n");
            printf("8- ANJO\n");
            printf("9- DEMONIO\n");
            printf("Opcao: ");
            tempRaca = lerInteiroPersonagem();

            while (getchar() != '\n');

            if (tempRaca < 0 || tempRaca > 9)
            {
                printf("Erro: raca invalida! Digite um valor entre 0 e 3.\n");
            }
        } while (tempRaca < 0 || tempRaca > 9);
        personagem->raca = (RACA)tempRaca;

        printf("Raca alterada com sucesso!\n");
        break;

    case 3:;
        int tempClasse;
        do
        {
            printf("\nDigite a nova classe:\n");
            printf("0 - GUERREIRO\n");
            printf("1 - MAGO\n");
            printf("2 - LADINO\n");
            printf("3 - CLERIGO\n");
            printf("4- ARQUEIRO\n");
            printf("5- BERSERKER\n");
            printf("6- ALQUIMISTA\n");
            printf("7- BEASTMASTER\n");
            printf("8- MESTRE EM ARMADILHAS\n");
            printf("9- SUMMONER\n");
            printf("Opcao: ");
            tempClasse = lerInteiroPersonagem();

            while (getchar() != '\n');

            if (tempClasse < 0 || tempClasse > 9)
            {
                printf("Erro: classe invalida! Digite um valor entre 0 e 3.\n");
            }
        } while (tempClasse < 0 || tempClasse > 9);
        personagem->classe = (CLASSE)tempClasse;

        printf("Classe alterada com sucesso!\n");
        break;

    case 4:;

        int novoNivel;
        do
        {
            printf("\nDigite o novo nivel do personagem (entre 1 e 20):\n ");
            novoNivel = lerInteiroPersonagem();  

            while (getchar() != '\n');

            if (novoNivel < 1 || novoNivel > 20)
            {
                printf("Erro: o nivel deve ser entre 1 e 20!\n");
            }
        } while (novoNivel < 1 || novoNivel > 20);
        personagem->nivel = novoNivel;

        printf("Nivel alterado com sucesso!\n");
        break;

    case 5:;
    {
        int novaVidaMaxima;

        do
        {
            printf("\nDigite a nova vida maxima:\n ");
            novaVidaMaxima = lerInteiroPersonagem();
            while (getchar() != '\n');

            if (novaVidaMaxima < personagem->vidaAtual || novaVidaMaxima > 999)
            {
                printf("Erro: a vida maxima nao pode ser menor que a vida atual (%d)!\n", personagem->vidaAtual);
            }

        } while (novaVidaMaxima < personagem->vidaAtual || novaVidaMaxima > 999);

        personagem->vidaMaxima = novaVidaMaxima;

        printf("Vida maxima alterada com sucesso!\n");
        break;
    }

    case 6:;
        int novaVidaAtual;
        do
        {
            printf("\nDigite a nova vida atual do personagem (entre 0 e %d):\n ", personagem->vidaMaxima);
            novaVidaAtual = lerInteiroPersonagem();

            while (getchar() != '\n');

            if (novaVidaAtual < 0 || novaVidaAtual > personagem->vidaMaxima)
            {
                printf("Erro: a vida atual deve ser entre 0 e %d!\n", personagem->vidaMaxima);
            }
        } while (novaVidaAtual < 0 || novaVidaAtual > personagem->vidaMaxima);
        personagem->vidaAtual = novaVidaAtual;

        printf("Vida atual alterada com sucesso!\n");
        break;

    case 7:;
        int novoAtaque;
        do
        {
            printf("\nDigite o novo ataque do personagem (entre 0 e 30):\n ");
            novoAtaque = lerInteiroPersonagem();

            while (getchar() != '\n');

            if (novoAtaque < 0 || novoAtaque > 30)
            {
                printf("Erro: o ataque deve ser entre 0 e 30!\n");
            }
        } while (novoAtaque < 0 || novoAtaque > 30);
        personagem->ataque = novoAtaque;

        printf("Ataque alterado com sucesso!\n");
        break;

        case 8:;
        int novaDefesa;
        do
        {
            printf("\nDigite a nova defesa do personagem (entre 0 e 30):\n ");
            novaDefesa = lerInteiroPersonagem();

            while (getchar() != '\n');

            if (novaDefesa < 0 || novaDefesa > 30)
            {
                printf("Erro: a defesa deve ser entre 0 e 30!\n");
            }
        } while (novaDefesa < 0 || novaDefesa > 30);
        personagem->defesa = novaDefesa;

        printf("Defesa alterada com sucesso!\n");
        break;

        case 9:;
        int novaIniciativa;
        do
        {
            printf("\nDigite a nova iniciativa do personagem (entre -5 e 20):\n ");
            novaIniciativa = lerInteiroPersonagem();

            while (getchar() != '\n');

            if (novaIniciativa < -5 || novaIniciativa > 20)
            {
                printf("Erro: a iniciativa deve ser entre -5 e 20!\n");
            }
        } while (novaIniciativa < -5 || novaIniciativa > 20);
        personagem->iniciativa = novaIniciativa;

        printf("Iniciativa alterada com sucesso!\n");
        break;

        case 10:;
        int novoPoder;
        do
        {
            printf("\nDigite o novo poder do personagem (entre 1 e 100):\n ");
            novoPoder = lerInteiroPersonagem();

            while (getchar() != '\n');

            if (novoPoder < 1 || novoPoder > 100)
            {
                printf("Erro: o poder deve ser entre 1 e 100!\n");
            }
        } while (novoPoder < 1 || novoPoder > 100);
        personagem->poder = novoPoder;

        printf("Poder alterado com sucesso!\n");
        break;

        case 0:;
        printf("Alteracao cancelada.\n");
        break;

        default:
        printf("Opcao invalida!\n");
        break;
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Função para excluir um personagem do cadastro

void excluirPersonagem(CadastroPersonagens *cadastro){
    int id;
    int index = -1;

    printf("Digite o ID do personagem que deseja excluir:\n ");
    id = lerInteiroPersonagem();

    while (getchar() != '\n');

    for(int i = 0; i < cadastro->quantidade; i++){
        if(cadastro->personagens[i].id == id){
            index = i;
            break;
        }
    }

    if(index == -1){
        printf("Personagem nao encontrado!\n");
        return;
    }

    for(int i = index; i < cadastro->quantidade - 1; i++){
        cadastro->personagens[i] = cadastro->personagens[i + 1]; // excluindo o personagem e movendo os demais para preencher o espaço
    }

    cadastro->quantidade--;

    printf("Personagem excluido com sucesso!\n");
}



void listarEquipamentos(PERSONAGEM *personagem)
{
    printf("\n---- EQUIPAMENTOS DE %s ----\n", personagem->nome);

    printf("\nElmo: ");
    if(personagem->equipamentosOcupados[0]){
        mostrarItem(&personagem->equipamentos[0]);
    }
    else{
        printf("Vazio\n");
    }

    printf("Peitoral: ");
    if (personagem->equipamentosOcupados[1]){
        mostrarItem(&personagem->equipamentos[1]);
    }
    else{
        printf("Vazio\n");
    }
    printf("Manoplas: ");
    if (personagem->equipamentosOcupados[2]){
        mostrarItem(&personagem->equipamentos[2]);
    }
    else{
        printf("Vazio\n");
    }

    printf("Calca: ");
    if (personagem->equipamentosOcupados[3]){
        mostrarItem(&personagem->equipamentos[3]);
    }
    else{
        printf("Vazio\n");
    }

    printf("Botas: ");
    if (personagem->equipamentosOcupados[4]){
        mostrarItem(&personagem->equipamentos[4]);
    }
    else{
        printf("Vazio\n");
    }

    printf("Anel: ");
    if (personagem->equipamentosOcupados[5]){
        mostrarItem(&personagem->equipamentos[5]);
    }
    else{
        printf("Vazio\n");
    }

    printf("Colar: ");
    if (personagem->equipamentosOcupados[6]){
        mostrarItem(&personagem->equipamentos[6]);
    }
    else{
        printf("Vazio\n");
    }

    printf("Cinto: ");
    if (personagem->equipamentosOcupados[7]){
        mostrarItem(&personagem->equipamentos[7]);
    }
    else{
        printf("Vazio\n");
    }

    printf("Mao direita: ");
    if (personagem->equipamentosOcupados[8]){
        mostrarItem(&personagem->equipamentos[8]);
    }
    else{
        printf("Vazio\n");
    }

    printf("Mao esquerda: ");
    if (personagem->equipamentosOcupados[9]){
        mostrarItem(&personagem->equipamentos[9]);
    }
    else{
        printf("Vazio\n");
    }
}

void equiparItem(PERSONAGEM *personagem, int idItem)
{
    item *item = buscarItem(&personagem->inventario, idItem);

    if (item == NULL)
    {
        printf("\nErro: item nao encontrado no inventario!\n");
        return;
    }

    switch (item->tipo)
    {
    case ELMO:
        if (personagem->equipamentosOcupados[0])
        {
            printf("\nErro: o slot de Elmo ja esta ocupado!\n");
            return;
        }

        personagem->equipamentos[0] = *item;
        personagem->equipamentosOcupados[0] = 1;
        removerItem(&personagem->inventario, idItem);

        printf("\nElmo equipado com sucesso!\n");
        break;

    case PEITORAL:
        if (personagem->equipamentosOcupados[1])
        {
            printf("\nErro: o slot de Peitoral ja esta ocupado!\n");
            return;
        }

        personagem->equipamentos[1] = *item;
        personagem->equipamentosOcupados[1] = 1;
        removerItem(&personagem->inventario, idItem);

        printf("\nPeitoral equipado com sucesso!\n");
        break;

    case MANOPLAS:
    if (personagem->equipamentosOcupados[2])
    {
        printf("\nErro: o slot de Manoplas ja esta ocupado!\n");
        return;
    }

    personagem->equipamentos[2] = *item;
    personagem->equipamentosOcupados[2] = 1;
    removerItem(&personagem->inventario, idItem);

    printf("\nManoplas equipadas com sucesso!\n");
    break;

    case CALCA:
        if (personagem->equipamentosOcupados[3])
        {
            printf("\nErro: o slot de Calca ja esta ocupado!\n");
            return;
        }

        personagem->equipamentos[3] = *item;
        personagem->equipamentosOcupados[3] = 1;
        removerItem(&personagem->inventario, idItem);

        printf("\nCalca equipada com sucesso!\n");
        break;

    case BOTAS:
        if (personagem->equipamentosOcupados[4])
        {
            printf("\nErro: o slot de Botas ja esta ocupado!\n");
            return;
        }

        personagem->equipamentos[4] = *item;
        personagem->equipamentosOcupados[4] = 1;
        removerItem(&personagem->inventario, idItem);

        printf("\nBotas equipadas com sucesso!\n");
        break;

    case ANEL:
        if (personagem->equipamentosOcupados[5])
        {
            printf("\nErro: o slot de Anel ja esta ocupado!\n");
            return;
        }

        personagem->equipamentos[5] = *item;
        personagem->equipamentosOcupados[5] = 1;
        removerItem(&personagem->inventario, idItem);

        printf("\nAnel equipado com sucesso!\n");
        break;

    case COLAR:
        if (personagem->equipamentosOcupados[6])
        {
            printf("\nErro: o slot de Colar ja esta ocupado!\n");
            return;
        }

        personagem->equipamentos[6] = *item;
        personagem->equipamentosOcupados[6] = 1;
        removerItem(&personagem->inventario, idItem);

        printf("\nColar equipado com sucesso!\n");
        break;

    case CINTO:
        if (personagem->equipamentosOcupados[7])
        {
            printf("\nErro: o slot de Cinto ja esta ocupado!\n");
            return;
        }

        personagem->equipamentos[7] = *item;
        personagem->equipamentosOcupados[7] = 1;
        removerItem(&personagem->inventario, idItem);

        printf("\nCinto equipado com sucesso!\n");
        break;

    case ARMA_UMA_MAO:
        if (!personagem->equipamentosOcupados[8])
        {
            personagem->equipamentos[8] = *item;
            personagem->equipamentosOcupados[8] = 1;

            removerItem(&personagem->inventario, idItem);

            printf("\nArma equipada na mao direita!\n");
        }
        else if (!personagem->equipamentosOcupados[9])
        {
            personagem->equipamentos[9] = *item;
            personagem->equipamentosOcupados[9] = 1;

            removerItem(&personagem->inventario, idItem);

            printf("\nArma equipada na mao esquerda!\n");
        }
        else
        {
            printf("\nErro: as duas maos estao ocupadas!\n");
        }
        break;

    case ARMA_DUAS_MAOS:
        if (!personagem->equipamentosOcupados[8] && !personagem->equipamentosOcupados[9])
        {
            personagem->equipamentos[8] = *item;
            personagem->equipamentos[9] = *item;

            personagem->equipamentosOcupados[8] = 1;
            personagem->equipamentosOcupados[9] = 1;

            removerItem(&personagem->inventario, idItem);

            printf("\nArma de duas maos equipada!\n");
        }
        else
        {
            printf("\nErro: e necessario ter as duas maos livres!\n");
        }
        break;
    }
}



void desequiparItem(PERSONAGEM *personagem, int slot)
{
    if (slot < 0 || slot > 9)
    {
        printf("\nSlot invalido!\n");
        return;
    }

    if (!personagem->equipamentosOcupados[slot])
    {
        printf("\nEsse slot esta vazio!\n");
        return;
    }

    item item = personagem->equipamentos[slot];

    adicionarItem(&personagem->inventario, &item);

    if (slot == 8 || slot == 9)
    {
        if (item.tipo == ARMA_DUAS_MAOS)
        {
            personagem->equipamentosOcupados[8] = 0;
            personagem->equipamentosOcupados[9] = 0;
        }
        else
        {
            personagem->equipamentosOcupados[slot] = 0;
        }
    }
    else
    {
        personagem->equipamentosOcupados[slot] = 0;
    }

    printf("\nItem desequipado com sucesso!\n");
}

void exibirAtributosTotais(PERSONAGEM *personagem)
{
    int bonusAtaque = 0;
    int bonusDefesa = 0;
    int bonusVida = 0;
    int bonusIniciativa = 0;
    int bonusPoder = 0;

    for (int i = 0; i < 10; i++)
    {
        if (personagem->equipamentosOcupados[i])
        {
            bonusAtaque += personagem->equipamentos[i].bonusAtaque;
            bonusDefesa += personagem->equipamentos[i].bonusDefesa;
            bonusVida += personagem->equipamentos[i].bonusVida;
            bonusIniciativa += personagem->equipamentos[i].bonusIniciativa;
            bonusPoder += personagem->equipamentos[i].poder;
        }
    }

    printf("\n---- ATRIBUTOS TOTAIS ----\n");

    printf("Ataque: %d + %d = %d\n", personagem->ataque, bonusAtaque, personagem->ataque + bonusAtaque);

    printf("Defesa: %d + %d = %d\n", personagem->defesa, bonusDefesa, personagem->defesa + bonusDefesa);

    printf("Vida maxima: %d + %d = %d\n", personagem->vidaMaxima, bonusVida, personagem->vidaMaxima + bonusVida);

    printf("Iniciativa: %d + %d = %d\n", personagem->iniciativa, bonusIniciativa, personagem->iniciativa + bonusIniciativa);

    printf("Poder: %d + %d = %d\n",personagem->poder, bonusPoder, personagem->poder + bonusPoder);
}