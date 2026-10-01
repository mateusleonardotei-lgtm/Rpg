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

    int opcao;
    int idBusca;
    int opcaoInventario;

    inicializarCadastro(&cadastro);
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
        printf("6 - Administrar inventario\n");
        printf("7 - Consultar equipamentos \n");
        printf("8 - Equipar item \n");
        printf("9 - Desequipar item \n");
        printf("10 - Exibir atributos totais \n");
        printf("0 - Sair\n");
        printf("============================\n");

        printf("Digite uma opcao: ");
        opcao = lerInteiroPersonagem();
        while (getchar() != '\n');

        switch (opcao)
        {
        case 1:;
            printf("\n---- CADASTRO ----\n");

            preencherPersonagem(&novo);
            cadastrarPersonagem(&novo, &cadastro);

            break;

        case 2:;
            listarPersonagens(&cadastro);
            break;

        case 3:;
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

        case 4:;
            alterarPersonagem(&cadastro);
            break;

        case 5:;
            excluirPersonagem(&cadastro);
            break;

        case 6:
        {
            int idPersonagem;
            PERSONAGEM *personagem;

            printf("\nDigite o ID do personagem: ");
            idPersonagem = lerInteiroPersonagem();

            while (getchar() != '\n');

            personagem = buscarPersonagemPorId(&cadastro, idPersonagem);

            if (personagem == NULL)
            {
                printf("\nPersonagem nao encontrado!\n");
                break;
            }

            printf("\nAdministrando inventario de: %s\n", personagem->nome);

            do
            {
                printf("\n---- INVENTARIO DE %s ----\n", personagem->nome);
                printf("1 - Adicionar item\n");
                printf("2 - Buscar item por ID\n");
                printf("3 - Remover item\n");
                printf("4 - Listar itens\n");
                printf("5 - Informar ocupacao\n");
                printf("0 - Voltar\n");
                printf("Digite uma opcao: ");
                opcaoInventario = lerInteiroPersonagem();

                while (getchar() != '\n');

                switch (opcaoInventario)
                {
                case 1:
                {
                    item novoItem;

                    printf("\n---- ADICIONAR ITEM ----\n");

                    cadastrarItem(&novoItem);
                    adicionarItem(&personagem->inventario, &novoItem);

                    break;
                }

                case 2:
                {
                    int idItem;
                    item *itemEncontrado;

                    printf("\nDigite o ID do item: ");
                    idItem = lerInteiroPersonagem();

                    while (getchar() != '\n');

                    itemEncontrado = buscarItem(&personagem->inventario,idItem);

                    if (itemEncontrado != NULL)
                    {
                        mostrarItem(itemEncontrado);
                    }
                    else
                    {
                        printf("\nItem nao encontrado!\n");
                    }

                    break;
                }

                case 3:
                {
                    int idItem;

                    printf("\nDigite o ID do item que deseja remover: ");
                    idItem = lerInteiroPersonagem();

                    while (getchar() != '\n');

                    removerItem(&personagem->inventario, idItem);

                    break;
                }

                case 4:
                    listarInventario(&personagem->inventario);
                    break;

                case 5:
                    printf("\nEspacos ocupados: %d/%d\n", personagem->inventario.espacosOcupados,personagem->inventario.capacidade);

                    printf("Espacos livres: %d\n", personagem->inventario.capacidade -personagem->inventario.espacosOcupados);

                    break;

                case 0:
                    printf("\nVoltando ao menu principal...\n");
                    break;

                default:
                    printf("\nOpcao invalida!\n");
                    break;
                }

            } while (opcaoInventario != 0);

            break;
        }

        case 7:
        {
            int idPersonagem;
            PERSONAGEM *personagem;

            printf("\nDigite o ID do personagem: ");
            idPersonagem = lerInteiroPersonagem();

            while (getchar() != '\n');

            personagem = buscarPersonagemPorId(&cadastro, idPersonagem);

            if (personagem == NULL)
            {
                printf("\nPersonagem nao encontrado!\n");
                break;
            }

            listarEquipamentos(personagem);

            break;
        }

        case 8:
        {
            int idPersonagem;
            int idItem;
            PERSONAGEM *personagem;

            printf("\nDigite o ID do personagem: ");
            idPersonagem = lerInteiroPersonagem();

            while (getchar() != '\n');

            personagem = buscarPersonagemPorId(&cadastro, idPersonagem);

            if (personagem == NULL)
            {
                printf("\nPersonagem nao encontrado!\n");
                break;
            }

            printf("\nDigite o ID do item que deseja equipar: ");
            idItem = lerInteiroPersonagem();

            while (getchar() != '\n');

            equiparItem(personagem, idItem);

            break;
        }

        case 9:
        {
            int idPersonagem;
            int slot;
            PERSONAGEM *personagem;

            printf("\nDigite o ID do personagem: ");
            idPersonagem = lerInteiroPersonagem();

            while (getchar() != '\n');

            personagem = buscarPersonagemPorId(&cadastro, idPersonagem);

            if (personagem == NULL)
            {
                printf("\nPersonagem nao encontrado!\n");
                break;
            }

            printf("\n---- DESEQUIPAR ITEM ----\n");
            printf("0 - Elmo\n");
            printf("1 - Peitoral\n");
            printf("2 - Manoplas\n");
            printf("3 - Calca\n");
            printf("4 - Botas\n");
            printf("5 - Anel\n");
            printf("6 - Colar\n");
            printf("7 - Cinto\n");
            printf("8 - Mao direita\n");
            printf("9 - Mao esquerda\n");

            printf("\nEscolha o slot: ");
            slot = lerInteiroPersonagem();

            while (getchar() != '\n');

            desequiparItem(personagem, slot);

            break;
        }

        case 10:
        {
            int idPersonagem;
            PERSONAGEM *personagem;

            printf("\nDigite o ID do personagem: ");
            idPersonagem = lerInteiroPersonagem();

            personagem = buscarPersonagemPorId(&cadastro, idPersonagem);

            if (personagem == NULL)
            {
                printf("\nPersonagem nao encontrado!\n");
                break;
            }

            exibirAtributosTotais(personagem);

            break;
        }

        case 0:
            printf("\nSaindo do programa...\n");
            break;

        default:
            printf("\nOpcao invalida!\n");
            break;
        }

    } while (opcao != 0);

    return 0;
}