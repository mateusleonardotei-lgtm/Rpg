#include <stdio.h>
#include <stdlib.h>
#include "inventario.h"

// Função para inicializar o inventário
void inicializarInventario(INVENTARIO *inventario)
{         
    inventario->quantidade = 0;                     // o inventario começa com 0 itens
    inventario->capacidade = CAPACIDADE_INVENTARIO; // capacidade máxima do inventário de 50
    
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Função para calcular a ocupação do inventário em termos de espaços ocupados pelos itens

int calcularOcupacaoInventario(const INVENTARIO *inventario)
{
    int ocupacao = 0;

    for (int i = 0; i < inventario->quantidade; i++)
    {
        ocupacao += inventario->itens[i].espacos;
    }

    return ocupacao;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Função para adicionar um item ao inventário

RESULTADO_INVENTARIO adicionarItem(INVENTARIO *inventario, item *novo)
{
    if (buscarItem(inventario, novo->id) != NULL)
    {
        return ITEM_DUPLICADO;
    }

    if (inventario->quantidade >= inventario->capacidade)
    {
        return INVENTARIO_CHEIO;
    }

   if (calcularOcupacaoInventario(inventario) + novo->espacos > CAPACIDADE_INVENTARIO)
{
    return INVENTARIO_CHEIO;
}

    inventario->itens[inventario->quantidade] = *novo;
    inventario->quantidade++;

    return INVENTARIO_SUCESSO;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Função para buscar um item no inventário pelo ID

item *buscarItem(INVENTARIO *inventario, int id)
{
    for (int i = 0; i < inventario->quantidade; i++)
    {
        if (inventario->itens[i].id == id)
        {
            return &inventario->itens[i]; // retorna o ponteiro para o item encontrado
        }
    }

    return NULL; // retorna NULL se o item não for encontrado
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Função para remover um item do inventário pelo ID

RESULTADO_INVENTARIO removerItem(INVENTARIO *inventario, int id)
{
    int posicao = -1;

    for (int i = 0; i < inventario->quantidade; i++)
    {
        if (inventario->itens[i].id == id)
        {
            posicao = i;
            break;
        }
    }

    if (posicao == -1)
    {
        return ITEM_NAO_ENCONTRADO;
    }


    for (int i = posicao; i < inventario->quantidade - 1; i++)
    {
        inventario->itens[i] = inventario->itens[i + 1];
    }

    inventario->quantidade--;

    return INVENTARIO_SUCESSO;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Função para listar todos os itens do inventário

void listarInventario(INVENTARIO *inventario)
{
    if (inventario->quantidade == 0)
    {
        printf("\nO inventario esta vazio!\n");
        return;
    }

    printf("\n---- INVENTARIO ----\n");

    for (int i = 0; i < inventario->quantidade; i++)
    {
        printf("\n--- Item %d ---\n", i + 1);
        mostrarItem(&inventario->itens[i]);
    }

    int ocupacao = calcularOcupacaoInventario(inventario);

    printf("Espacos ocupados: %d/%d\n", ocupacao,CAPACIDADE_INVENTARIO);

    printf("Espacos livres: %d\n", CAPACIDADE_INVENTARIO - ocupacao);
}
