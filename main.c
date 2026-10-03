#include <stdio.h>
#include <stdlib.h>
#include "personagem.h"
#include "inventario.h"
#include "item.h"

int main()
{
    CadastroPersonagens cadastro;
    PERSONAGEM novo;
    RESULTADO resultado;

    int opcao;
    int opcaoInventario;
    int idItem;
    int slot;

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
        printf("11 - Quantidade de personagens cadastrados \n");
        printf("0 - Sair\n");
        printf("============================\n");

        printf("Digite uma opcao: ");
        opcao = lerInteiroPersonagem();

        switch (opcao)
        {
        case 1:;
            printf("\n---- CADASTRO ----\n");

            preencherPersonagem(&novo);
            resultado = cadastrarPersonagem(&novo, &cadastro);

            switch (resultado)
            {
            case SUCESSO:;
                printf("\nPersonagem cadastrado com sucesso!\n");
                break;
            case CADASTRO_CHEIO:;
                printf("\nErro: limite de personagens atingido!\n");
                break;
            case ID_DUPLICADO:;
                printf("\nErro: ID ja existe! Escolha outro ID.\n");
                break;
            case DADOS_INVALIDOS:;
                printf("\nErro: dados invalidos! Verifique os atributos do personagem.\n");
                break;
            default:;
                printf("\nErro desconhecido ao cadastrar personagem!\n");
                break;
            }

            break;

        case 2:;
            listarPersonagens(&cadastro);
            break;

        case 3:;
            int id;
            PERSONAGEM *personagem;

            printf("\nDigite o ID do personagem: ");
            id = lerInteiroPersonagem();

            personagem = buscarPersonagemPorId(&cadastro, id);

            if (personagem == NULL)
            {
                printf("\nPersonagem nao encontrado!\n");
            }
            else
            {
                mostrarPersonagem(personagem);
            }
            break;

        case 4:;
            resultado = alterarPersonagem(&cadastro);

            if (resultado == SUCESSO)
            {
                printf("\nAlteracao realizada com sucesso!\n");
            }
            else if (resultado == NAO_ENCONTRADO)
            {
                printf("\nPersonagem nao encontrado!\n");
            }
            else if (resultado == DADOS_INVALIDOS)
            {
                printf("\nDados invalidos!\n");
            }
            else if (resultado == CANCELADO)
            {
                printf("\nAlteracao cancelada.\n");
            }

            break;

        case 5:;

            printf("\nDigite o ID do personagem que deseja excluir: ");
            id = lerInteiroPersonagem();
            
            resultado = excluirPersonagem(&cadastro, id);

            if (resultado == SUCESSO)
            {
                printf("\nPersonagem excluido com sucesso!\n");
            }
            else if (resultado == NAO_ENCONTRADO)
            {
                printf("\nPersonagem nao encontrado!\n");
            }
            break;

        case 6:;
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

                switch (opcaoInventario)
                {
                case 1:;
                {
                    item novoItem;
                    RESULTADO_INVENTARIO resultadoInventario;

                    cadastrarItem(&novoItem);

                    resultadoInventario = adicionarItem(&personagem->inventario, &novoItem);

                    if (resultadoInventario == INVENTARIO_SUCESSO)
                    {
                        printf("\nItem adicionado ao inventario com sucesso!\n");
                    }
                    else if (resultadoInventario == ITEM_DUPLICADO)
                    {
                        printf("\nErro: ja existe um item com esse ID no inventario!\n");
                    }
                    else if (resultadoInventario == INVENTARIO_CHEIO)
                    {
                        printf("\nErro: nao ha espaco suficiente no inventario!\n");
                    }

                    break;
                }

                case 2:;
                {
                    int idItem;
                    item *itemEncontrado;

                    printf("\nDigite o ID do item: ");
                    idItem = lerInteiroPersonagem();

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

                case 3:;

                    int idItem;

                    printf("\nDigite o ID do item que deseja remover: ");
                    idItem = lerInteiroPersonagem();

                    RESULTADO_INVENTARIO resultadoInventario;

                    resultadoInventario = removerItem(&personagem->inventario, idItem);

                    if (resultadoInventario == INVENTARIO_SUCESSO)
                    {
                        printf("\nItem removido do inventario com sucesso!\n");
                    }
                    else if (resultadoInventario == ITEM_NAO_ENCONTRADO)
                    {
                        printf("\nItem nao encontrado no inventario!\n");
                    }

                    break;

                case 4:;
                    listarInventario(&personagem->inventario);
                    break;

                case 5:;
                    printf("\nEspacos ocupados: %d/%d\n", calcularOcupacaoInventario(&personagem->inventario), CAPACIDADE_INVENTARIO);

                    printf("Espacos livres: %d\n", CAPACIDADE_INVENTARIO - calcularOcupacaoInventario(&personagem->inventario));

                    break;

                case 0:;
                    printf("\nVoltando ao menu principal...\n");
                    break;

                default:
                    printf("\nOpcao invalida!\n");
                    break;
                }

            } while (opcaoInventario != 0);

            break;
        }

        case 7:;
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

            listarEquipamentos(personagem);

            break;
        }

        case 8:;
            printf("\nDigite o ID do personagem: ");
            id = lerInteiroPersonagem();

            personagem = buscarPersonagemPorId(&cadastro, id);

            if (personagem == NULL)
            {
                printf("\nPersonagem nao encontrado!\n");
                break;
            }

            printf("Digite o ID do item: ");
            idItem = lerInteiroPersonagem();

            resultado = equiparItem(personagem, idItem);

            if (resultado == SUCESSO)
            {
                printf("\nItem equipado com sucesso!\n");
            }
            else if (resultado == NAO_ENCONTRADO)
            {
                printf("\nItem nao encontrado no inventario!\n");
            }
            else if (resultado == DADOS_INVALIDOS)
            {
                printf("\nNao foi possivel equipar o item: slot ocupado ou maos ocupadas!\n");
            }

            break;

        case 9:;
            printf("\nDigite o ID do personagem: ");
            id = lerInteiroPersonagem();

            personagem = buscarPersonagemPorId(&cadastro, id);

            if (personagem == NULL)
            {
                printf("\nPersonagem nao encontrado!\n");
                break;
            }

            printf("\nDigite o slot que deseja desequipar:\n");
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
            printf("Opcao: ");

            slot = lerInteiroPersonagem();

            resultado = desequiparItem(personagem, slot);

            if (resultado == SUCESSO)
            {
                printf("\nItem desequipado com sucesso!\n");
            }
            else if (resultado == DADOS_INVALIDOS)
            {
                printf("\nSlot invalido!\n");
            }
            else if (resultado == NAO_ENCONTRADO)
            {
                printf("\nEsse slot esta vazio!\n");
            }
            else if (resultado == CADASTRO_CHEIO)
            {
                printf("\nNao foi possivel desequipar: inventario sem espaco suficiente!\n");
            }
            else if (resultado == ID_DUPLICADO)
            {
                printf("\nNao foi possivel desequipar: ja existe um item com esse ID no inventario!\n");
            }

            break;

        case 10:;
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

        case 11:;
            printf("\nQuantidade de personagens cadastrados: %d\n",
                   obterQuantidadePersonagens(&cadastro));
            break;

        case 0:;
            liberarCadastro(&cadastro);

            printf("\nSaindo do programa...\n");
            break;

        default:;
            printf("\nOpcao invalida!\n");
            break;
        }

    } while (opcao != 0);

    return 0;
}