#include <stdio.h>
#include <string.h>
#include "personagem.h"

// Função para ler o nome do personagem, garantindo que não exceda o tamanho máximo permitido
int lerNome(char nome[])
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

int lerInteiro()
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

/* Função para cadastrar um novo personagem */
void preencherPersonagem(PERSONAGEM *novo)
{
    int tempRaca, tempClasse;
    int nomeInvalido;

    // ID
    do
    {
        printf("\nDigite o id do personagem: ");
        novo->id = lerInteiro();
        while (getchar() != '\n')
            ;

        if (novo->id <= 0)
        {
            printf("Erro: o ID deve ser maior que zero!\n");
        }

    } while (novo->id <= 0);

    // Nome
    do
    {
        printf("Digite o nome do personagem: ");
        nomeInvalido = lerNome(novo->nome);

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
        printf("\nDigite a raca do personagem (0 - ELFO, 1 - ANAO, 2 - HUMANO, 3 - HALFING): ");
        tempRaca = lerInteiro();

        while (getchar() != '\n')
            ;

        if (tempRaca < 0 || tempRaca > 3)
        {
            printf("Erro: raca invalida! Digite um valor entre 0 e 3.\n");
        }
    } while (tempRaca < 0 || tempRaca > 3);

    novo->raca = (RACA)tempRaca;

    // Classe
    do
    {
        printf("\nDigite a classe do personagem (0 - GUERREIRO, 1 - MAGO, 2 - LADINO, 3 - CLERIGO): ");
        tempClasse = lerInteiro();

        while (getchar() != '\n');

        if (tempClasse < 0 || tempClasse > 3)
        {
            printf("Erro: classe invalida! Digite um valor entre 0 e 3.\n");
        }
    } while (tempClasse < 0 || tempClasse > 3);

    novo->classe = (CLASSE)tempClasse;

    // Nivel
    do
    {
        printf("\nDigite o nivel do personagem (entre 1 e 20): ");
        novo->nivel = lerInteiro();

        while (getchar() != '\n');

        if (novo->nivel < 1)
        {
            printf("Erro: o nivel deve ser maior que zero!\n");
        }
    } while (novo->nivel < 1 || novo->nivel > 20);

    // Vida máxima
    do
    {
        printf("\nDigite a vida maxima do personagem (entre 1 e 999): ");
        novo->vidaMaxima = lerInteiro();

        while (getchar() != '\n')
            ;

        if (novo->vidaMaxima < 1)
        {
            printf("Erro: a vida maxima deve ser maior que zero!\n");
        }
    } while (novo->vidaMaxima < 1 || novo->vidaMaxima > 999);

    // Vida atual
    do
    {
        printf("\nDigite a vida atual do personagem (entre 0 e %d): ", novo->vidaMaxima);
        novo->vidaAtual = lerInteiro();

        while (getchar() != '\n')
            ;

        if (novo->vidaAtual < 0 || novo->vidaAtual > novo->vidaMaxima)
        {
            printf("Erro: a vida atual deve ser entre 0 e a vida maxima!\n");
        }
    } while (novo->vidaAtual < 0 || novo->vidaAtual > novo->vidaMaxima);

    // Ataque
    do
    {
        printf("\nDigite o ataque do personagem (entre 0 e 30): ");
        novo->ataque = lerInteiro();

        while (getchar() != '\n')
            ;

        if (novo->ataque < 0)
        {
            printf("Erro: o ataque nao pode ser negativo!\n");
        }
    } while (novo->ataque < 0 || novo->ataque > 30);

    // Defesa
    do
    {
        printf("\nDigite a defesa do personagem (entre 0 e 30): ");
        novo->defesa = lerInteiro();

        while (getchar() != '\n')
            ;

        if (novo->defesa < 0)
        {
            printf("Erro: a defesa nao pode ser negativa!\n");
        }
    } while (novo->defesa < 0 || novo->defesa > 30);

    // Iniciativa
    do
    {
        printf("\nDigite a iniciativa do personagem (entre -5 e 20): ");
        novo->iniciativa = lerInteiro();

        while (getchar() != '\n')
            ;

        if (novo->iniciativa < -5)
        {
            printf("Erro: a iniciativa nao pode ser menor que -5!\n");
        }
    } while (novo->iniciativa < -5 || novo->iniciativa > 20);

    // Poder
    do
    {
        printf("\nDigite o poder do personagem (entre 1 e 100): ");
        novo->poder = lerInteiro();

        while (getchar() != '\n')
            ;

        if (novo->poder < 1)
        {
            printf("Erro: o poder nao pode ser menor que 1!\n");
        }
    } while (novo->poder < 1 || novo->poder > 100);
}

// Função para inicializar o cadastro de personagens
void inicializarCadastro(CadastroPersonagens *cadastro)
{
    cadastro->quantidade = 0;
}

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
    cadastro->quantidade++;

    printf("Personagem cadastrado com sucesso!\n");
}

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
    id = lerInteiro();

    while (getchar() != '\n')
        ;

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
    opcao = lerInteiro();
    while (getchar() != '\n')
        ;

    switch (opcao)
    {
    case 1:;
        printf("Digite o novo nome: ");
        lerNome(personagem->nome);

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
            printf("0 - ELFO\n");
            printf("1 - ANAO\n");
            printf("2 - HUMANO\n");
            printf("3 - HALFING\n");
            printf("Opcao: ");
            tempRaca = lerInteiro();

            while (getchar() != '\n')
                ;

            if (tempRaca < 0 || tempRaca > 3)
            {
                printf("Erro: raca invalida! Digite um valor entre 0 e 3.\n");
            }
        } while (tempRaca < 0 || tempRaca > 3);
        personagem->raca = (RACA)tempRaca;

        printf("Raca alterada com sucesso!\n");
        break;

    case 3:;
        int tempClasse;
        do
        {
            printf("\nDigite a nova classe: \n");
            printf("0 - GUERREIRO\n");
            printf("1 - MAGO\n");
            printf("2 - LADINO\n");
            printf("3 - CLERIGO\n");
            printf("Opcao: ");
            tempClasse = lerInteiro();

            while (getchar() != '\n')
                ;

            if (tempClasse < 0 || tempClasse > 3)
            {
                printf("Erro: classe invalida! Digite um valor entre 0 e 3.\n");
            }
        } while (tempClasse < 0 || tempClasse > 3);
        personagem->classe = (CLASSE)tempClasse;

        printf("Classe alterada com sucesso!\n");
        break;

    case 4:;

        int novoNivel;
        do
        {
            printf("\nDigite o novo nivel do personagem (entre 1 e 20): ");
            novoNivel = lerInteiro();  

            while (getchar() != '\n')
                ;

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
            printf("\nDigite a nova vida maxima: ");
            novaVidaMaxima = lerInteiro();
            while (getchar() != '\n')
                ;

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
            printf("\nDigite a nova vida atual do personagem (entre 0 e %d): ", personagem->vidaMaxima);
            novaVidaAtual = lerInteiro();

            while (getchar() != '\n')
                ;

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
            printf("\nDigite o novo ataque do personagem (entre 0 e 30): ");
            novoAtaque = lerInteiro();

            while (getchar() != '\n')
                ;

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
            printf("\nDigite a nova defesa do personagem (entre 0 e 30): ");
            novaDefesa = lerInteiro();

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
            printf("\nDigite a nova iniciativa do personagem (entre -5 e 20): ");
            novaIniciativa = lerInteiro();

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
            printf("\nDigite o novo poder do personagem (entre 1 e 100): ");
            novoPoder = lerInteiro();

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

// Função para excluir um personagem do cadastro
void excluirPersonagem(CadastroPersonagens *cadastro){
    int id;
    int index = -1;

    printf("Digite o ID do personagem que deseja excluir: ");
    id = lerInteiro();

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