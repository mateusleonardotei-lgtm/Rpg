#ifndef ITEM_H
#define ITEM_H

typedef enum
{
    ELMO,
    PEITORAL,
    MANOPLAS,
    CALCA,
    BOTAS,
    ANEL,
    COLAR,
    CINTO,
    ARMA_UMA_MAO,
    ARMA_DUAS_MAOS
} TIPO_ITEM;


typedef struct
{
    int id;
    char nome[50];

    TIPO_ITEM tipo;

    int espacos;

    int bonusAtaque;
    int bonusDefesa;
    int bonusVida;
    int bonusIniciativa;

    int poder;

} item;


void cadastrarItem(item *novo);

void mostrarItem(item *i);

#endif // ITEM.H