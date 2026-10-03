#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "inventario.h"

#define MAX_PERSONAGENS 20

typedef enum
{
    SUCESSO,
    CADASTRO_CHEIO,
    ID_DUPLICADO,
    NAO_ENCONTRADO,
    DADOS_INVALIDOS,
    CANCELADO

} RESULTADO;

typedef enum
{
    ELFO,
    ANAO,
    HUMANO,
    HALFING,
    VAMPIRO,
    DRACONICO,
    DEMIHUMANO,
    ORC,
    ANJO,
    DEMONIO,

} RACA;


typedef enum
{
    GUERREIRO,
    MAGO,
    LADINO,
    CLERIGO,
    ARQUEIRO,
    BERSERKER,
    ALQUIMISTA,
    BEASTMASTER,
    MESTRE_EM_ARMADILHAS,
    SUMMONER,

} CLASSE;


typedef struct
{
    int id;
    char nome[50];

    RACA raca;
    CLASSE classe;

    int nivel;
    int vidaMaxima;
    int vidaAtual;
    int ataque;
    int defesa;
    int iniciativa;
    int poder;

    INVENTARIO inventario;

    item equipamentos[10];
    int equipamentosOcupados[10];

} PERSONAGEM;


typedef struct
{
    PERSONAGEM personagens[MAX_PERSONAGENS];
    int quantidade;

} CadastroPersonagens;

void inicializarCadastro(CadastroPersonagens *cadastro);
void preencherPersonagem(PERSONAGEM *novo);
RESULTADO cadastrarPersonagem(PERSONAGEM *novo, CadastroPersonagens *cadastro);
void mostrarPersonagem(PERSONAGEM *p);
void listarPersonagens(CadastroPersonagens *cadastro);
RESULTADO alterarPersonagem(CadastroPersonagens *cadastro);
RESULTADO excluirPersonagem(CadastroPersonagens *cadastro, int id);
void listarEquipamentos(PERSONAGEM *personagem);
RESULTADO equiparItem(PERSONAGEM *personagem, int idItem);
RESULTADO desequiparItem(PERSONAGEM *personagem, int slot);
void exibirAtributosTotais(PERSONAGEM *personagem);
void liberarCadastro(CadastroPersonagens *cadastro);

PERSONAGEM *buscarPersonagemPorId(CadastroPersonagens *cadastro, int id);
int lerInteiroPersonagem();
int obterQuantidadePersonagens(CadastroPersonagens *cadastro);
int validarPersonagem(PERSONAGEM *personagem);

#endif // PERSONAGEM_H