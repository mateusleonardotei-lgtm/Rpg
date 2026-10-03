#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "item.h"

#define CAPACIDADE_INVENTARIO 50

typedef struct
{
    item *itens;
    int quantidade;
    int capacidade;
    int espacosOcupados;
} INVENTARIO;

void inicializarInventario(INVENTARIO *inventario);
void removerItem(INVENTARIO *inventario, int id);
void listarInventario(INVENTARIO *inventario);

item *buscarItem(INVENTARIO *inventario, int id);
int adicionarItem(INVENTARIO *inventario, item *novo);

#endif // INVENTARIO_H