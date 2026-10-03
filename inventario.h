#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "item.h"

#define CAPACIDADE_INVENTARIO 50

typedef enum
{
    INVENTARIO_SUCESSO,
    INVENTARIO_CHEIO,
    ITEM_DUPLICADO,
    ITEM_NAO_ENCONTRADO
} RESULTADO_INVENTARIO;

typedef struct
{
    item itens[CAPACIDADE_INVENTARIO];
    int quantidade;
    int capacidade;
} INVENTARIO;

void inicializarInventario(INVENTARIO *inventario);
RESULTADO_INVENTARIO removerItem(INVENTARIO *inventario, int id);
void listarInventario(INVENTARIO *inventario);
item *buscarItem(INVENTARIO *inventario, int id);
RESULTADO_INVENTARIO adicionarItem(INVENTARIO *inventario, item *novo);
int calcularOcupacaoInventario(const INVENTARIO *inventario);

#endif // INVENTARIO_H