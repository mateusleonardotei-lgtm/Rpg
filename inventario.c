#include <stdio.h>
#include <stdlib.h>
#include "inventario.h"

// Função para inicializar o inventário
void inicializarInventario(INVENTARIO *inventario)
{
    inventario->itens = malloc(inventario->capacidade * sizeof(item)); // aloca dinamicamente a memória para o array de itens

    inventario->espacosOcupados = 0;                // o inventario começa com 0 espaços ocupados
    inventario->quantidade = 0;                     // o inventario começa com 0 itens
    inventario->capacidade = CAPACIDADE_INVENTARIO; // capacidade máxima do inventário de 50
}

// Função para adicionar um item ao inventário
void adicionarItem(INVENTARIO *inventario, item *novo)
{
    if (inventario->quantidade >= inventario->capacidade) // verifica se o inventário está cheio
    {
        printf("Erro: inventario cheio!\n");
        return;
    }

    if (inventario->espacosOcupados + novo->espacos > inventario->capacidade) // verifica se há espaço suficiente no inventário para o novo item
    {
        printf("Erro: nao ha espaco suficiente no inventario para este item!\n");
        return;
    }

    inventario->itens[inventario->quantidade] = *novo; // adiciona o item ao array de itens
    inventario->quantidade++;                          // incrementa a quantidade de itens
    inventario->espacosOcupados += novo->espacos;      // incrementa os espaços ocupados

    printf("Item adicionado ao inventario com sucesso!\n");
}

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



// Função para remover um item do inventário pelo ID
void removerItem(INVENTARIO *inventario, int id)
{
    int posicao = -1;

    for (int i = 0; i < inventario->quantidade; i++) // procura o item pelo ID e armazena a posição do item encontrado
    {
        if (inventario->itens[i].id == id)
        {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) // verifica se o item foi encontrado
    {
        printf("Erro: item nao encontrado no inventario!\n");
        return;
    }

    int espacosRemovidos = inventario->itens[posicao].espacos; // armazena a quantidade de espaços ocupados pelo item que será removido

    for (int i = posicao; i < inventario->quantidade - 1; i++)
    {
        inventario->itens[i] = inventario->itens[i + 1]; // move os itens restantes para preencher o espaço do item removido
    }

    inventario->quantidade--; // decrementa a quantidade de itens no inventário
    inventario->espacosOcupados -= espacosRemovidos; // decrementa a quantidade de espaços ocupados pelo item removido

    printf("Item removido do inventario com sucesso!\n");
}