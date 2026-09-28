#ifndef ITEM_H
#define ITEM_H

typedef enum
{
    ARMA,
    ARMADURA,
    CONSUMIVEL,
    ACESSORIO

} tipoItem;


typedef struct
{
    int id;
    char nome[50];

    tipoItem tipo;

    int espacos;

    int bonusAtaque;
    int bonusDefesa;
    int bonusVida;
    int bonusIniciativa;

    int poder;

} item;


void cadastrarItem(item *novo);

void mostrarItem(item *i);

#endif // ITEM_H