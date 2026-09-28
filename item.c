#include <stdio.h>
#include <string.h>
#include "item.h"


int lerNome(char nome[])
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
        scanf("%d", &novo->id);

        while (getchar() != '\n');

        if (novo->id <= 0)
        {
            printf("Erro: o ID deve ser maior que zero!\n");
        }

    } while (novo->id <= 0);

    do
    {
        printf("\nDigite o nome do item: ");

        nomeInvalido = lerNome(novo->nome);

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
        printf("\nDigite o tipo do item ");
        printf("(0 - Arma, 1 - Armadura, 2 - Consumivel, 3 - Acessorio): ");

        scanf("%d", &tempTipo);

        while (getchar() != '\n');

        if (tempTipo < 0 || tempTipo > 3)
        {
            printf("Erro: tipo invalido!\n");
        }

    } while (tempTipo < 0 || tempTipo > 3);

    novo->tipo = (tipoItem)tempTipo;

    do
    {
        printf("\nDigite a quantidade de espacos que o item ocupa (1 a 50): ");

        scanf("%d", &novo->espacos);

        while (getchar() != '\n');

        if (novo->espacos < 1 || novo->espacos > 50)
        {
            printf("Erro: a quantidade deve estar entre 1 e 50!\n");
        }

    } while (novo->espacos < 1 || novo->espacos > 50);

    do
    {
        printf("\nDigite o bonus de ataque do item: ");

        scanf("%d", &novo->bonusAtaque);

        while (getchar() != '\n');

        if (novo->bonusAtaque < 0)
        {
            printf("Erro: o bonus nao pode ser negativo!\n");
        }

    } while (novo->bonusAtaque < 0);

    do
    {
        printf("\nDigite o bonus de defesa do item: ");

        scanf("%d", &novo->bonusDefesa);

        while (getchar() != '\n');

        if (novo->bonusDefesa < 0)
        {
            printf("Erro: o bonus nao pode ser negativo!\n");
        }

    } while (novo->bonusDefesa < 0);

    do
    {
        printf("\nDigite o bonus de vida do item: ");

        scanf("%d", &novo->bonusVida);

        while (getchar() != '\n');

        if (novo->bonusVida < 0)
        {
            printf("Erro: o bonus nao pode ser negativo!\n");
        }

    } while (novo->bonusVida < 0);

    do
    {
        printf("\nDigite o bonus de iniciativa do item: ");

        scanf("%d", &novo->bonusIniciativa);

        while (getchar() != '\n');

        if (novo->bonusIniciativa < 0)
        {
            printf("Erro: o bonus nao pode ser negativo!\n");
        }

    } while (novo->bonusIniciativa < 0);

    do
    {
        printf("\nDigite o poder do item: ");

        scanf("%d", &novo->poder);

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

    switch(i->tipo)
    {
        case ARMA:
            printf("Arma");
            break;

        case ARMADURA:
            printf("Armadura");
            break;

        case CONSUMIVEL:
            printf("Consumivel");
            break;

        case ACESSORIO:
            printf("Acessorio");
            break;
    }

    printf("\nEspacos: %d\n", i->espacos);
    printf("Bonus de ataque: %d\n", i->bonusAtaque);
    printf("Bonus de defesa: %d\n", i->bonusDefesa);
    printf("Bonus de vida: %d\n", i->bonusVida);
    printf("Bonus de iniciativa: %d\n", i->bonusIniciativa);
    printf("Poder: %d\n", i->poder);
}