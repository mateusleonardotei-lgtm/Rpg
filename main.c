#include <stdio.h>
#include <stdlib.h>
#include "personagem.h"
#include "inventario.h"
#include "item.h"

int main()
{
    CadastroPersonagens cadastro;
    PERSONAGEM novo;
    PERSONAGEM *encontrado;
    INVENTARIO inventario;

    int opcao;
    int idBusca;

    inicializarCadastro(&cadastro);
    inicializarInventario(&inventario);

    do
    {
        printf("\n============================\n");
        printf("      MENU PRINCIPAL\n");
        printf("============================\n");
        printf("1 - Cadastrar personagem\n");
        printf("2 - Listar personagens\n");
        printf("3 - Buscar personagem\n");
        printf("4 - Alterar personagem\n");
        printf("5 - Excluir personagem\n");
        printf("0 - Sair\n");
        printf("============================\n");

        printf("Digite uma opcao: ");
        opcao = lerInteiroPersonagem();
        while (getchar() != '\n');

        switch (opcao)
        {
            case 1:
                printf("\n===== CADASTRO =====\n");

                preencherPersonagem(&novo);
                cadastrarPersonagem(&novo, &cadastro);

                break;

            case 2:
                listarPersonagens(&cadastro);
                break;

            case 3:
                printf("\nDigite o ID do personagem que deseja buscar: ");
                idBusca = lerInteiroPersonagem();
                while (getchar() != '\n');

                encontrado = buscarPersonagemPorId(&cadastro, idBusca);

                if (encontrado != NULL)
                {
                    printf("\nPersonagem encontrado!\n");
                    mostrarPersonagem(encontrado);
                }
                else
                {
                    printf("\nPersonagem nao encontrado!\n");
                }

                break;

            case 4:
                alterarPersonagem(&cadastro);
                break;
            
            case 5:
                excluirPersonagem(&cadastro);
                break;

            case 0:
                printf("\nSaindo do programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                break;
        }

    } while (opcao != 0);

    free(inventario.itens);

    return 0;
}