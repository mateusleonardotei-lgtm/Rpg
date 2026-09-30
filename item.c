#include <stdio.h>
#include <string.h>
#include "item.h"

int lerInteiroItem()
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


int lerNomeItem(char nome[])
{
    int c;
    int i = 0;
    int excedeu = 0;

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


void cadastrarItem(item *novo)
{
    int tempTipo;
    int nomeInvalido;

    do
    {
        printf("\nDigite o id do item: ");
        novo->id = lerInteiroItem();

        while (getchar() != '\n');

        if (novo->id <= 0)
        {
            printf("Erro: o ID deve ser maior que zero!\n");
        }

    } while (novo->id <= 0);

    do
    {
        printf("\nDigite o nome do item: ");

        nomeInvalido = lerNomeItem(novo->nome);

        if (strlen(novo->nome) == 0)
        {
            printf("Erro: o nome nao pode ser vazio!\n");
        }
        else if (nomeInvalido)
        {
            printf("Erro: o nome nao pode ter mais de 49 caracteres!\n");
        }

    } while (strlen(novo->nome) == 0 || nomeInvalido);

    do
{
    printf("\nDigite o tipo do item:\n");
    printf("0 - ELMO\n");
    printf("1 - PEITORAL\n");
    printf("2 - MANOPLAS\n");
    printf("3 - CALCA\n");
    printf("4 - BOTAS\n");
    printf("5 - ANEL\n");
    printf("6 - COLAR\n");
    printf("7 - CINTO\n");
    printf("8 - ARMA_UMA_MAO\n");
    printf("9 - ARMA_DUAS_MAOS\n");
    printf("Opcao: ");

    tempTipo = lerInteiroItem();

    if (tempTipo < 0 || tempTipo > 9)
    {
        printf("Erro: tipo invalido!\n");
    }

} while (tempTipo < 0 || tempTipo > 9);

    novo->tipo = (TIPO_ITEM)tempTipo;

    do
    {
        printf("\nDigite a quantidade de espacos que o item ocupa (1 a 50): ");

        novo->espacos = lerInteiroItem();

        while (getchar() != '\n');

        if (novo->espacos < 1 || novo->espacos > 50)
        {
            printf("Erro: a quantidade deve estar entre 1 e 50!\n");
        }

    } while (novo->espacos < 1 || novo->espacos > 50);

    do
    {
        printf("\nDigite o bonus de ataque do item: ");

        novo->bonusAtaque = lerInteiroItem();

        while (getchar() != '\n');

        if (novo->bonusAtaque < 0)
        {
            printf("Erro: o bonus nao pode ser negativo!\n");
        }

    } while (novo->bonusAtaque < 0);

    do
    {
        printf("\nDigite o bonus de defesa do item: ");

        novo->bonusDefesa = lerInteiroItem();

        while (getchar() != '\n');

        if (novo->bonusDefesa < 0)
        {
            printf("Erro: o bonus nao pode ser negativo!\n");
        }

    } while (novo->bonusDefesa < 0);

    do
    {
        printf("\nDigite o bonus de vida do item: ");

        novo->bonusVida = lerInteiroItem();

        while (getchar() != '\n');

        if (novo->bonusVida < 0)
        {
            printf("Erro: o bonus nao pode ser negativo!\n");
        }

    } while (novo->bonusVida < 0);

    do
    {
        printf("\nDigite o bonus de iniciativa do item: ");

        novo->bonusIniciativa = lerInteiroItem();

        while (getchar() != '\n');

        if (novo->bonusIniciativa < 0)
        {
            printf("Erro: o bonus nao pode ser negativo!\n");
        }

    } while (novo->bonusIniciativa < 0);

    do
    {
        printf("\nDigite o poder do item: ");

        novo->poder = lerInteiroItem();

        while (getchar() != '\n');

        if (novo->poder < 0)
        {
            printf("Erro: o poder nao pode ser negativo!\n");
        }

    } while (novo->poder < 0);


    printf("\nItem preenchido com sucesso!\n");
}

void mostrarItem(item *i)
{
    printf("ID: %d\n", i->id);
    printf("Nome: %s\n", i->nome);

    printf("Tipo: ");

    switch (i->tipo)
{
    case ELMO:
        printf("ELMO");
        break;

    case PEITORAL:
        printf("PEITORAL");
        break;

    case MANOPLAS:
        printf("MANOPLAS");
        break;

    case CALCA:
        printf("CALCA");
        break;

    case BOTAS:
        printf("BOTAS");
        break;

    case ANEL:
        printf("ANEL");
        break;

    case COLAR:
        printf("COLAR");
        break;

    case CINTO:
        printf("CINTO");
        break;

    case ARMA_UMA_MAO:
        printf("ARMA_UMA_MAO");
        break;

    case ARMA_DUAS_MAOS:
        printf("ARMA_DUAS_MAOS");
        break;
}

    printf("\nEspacos: %d\n", i->espacos);
    printf("Bonus de ataque: %d\n", i->bonusAtaque);
    printf("Bonus de defesa: %d\n", i->bonusDefesa);
    printf("Bonus de vida: %d\n", i->bonusVida);
    printf("Bonus de iniciativa: %d\n", i->bonusIniciativa);
    printf("Poder: %d\n", i->poder);
}