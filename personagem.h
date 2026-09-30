#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#define MAX_PERSONAGENS 20

typedef enum
{
    ELFO,
    ANAO,
    HUMANO,
    HALFING

} RACA;


typedef enum
{
    GUERREIRO,
    MAGO,
    LADINO,
    CLERIGO

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

} PERSONAGEM;


typedef struct
{
    PERSONAGEM personagens[MAX_PERSONAGENS];
    int quantidade;

} CadastroPersonagens;

void inicializarCadastro(CadastroPersonagens *cadastro);
void preencherPersonagem(PERSONAGEM *novo);
void cadastrarPersonagem(PERSONAGEM *novo, CadastroPersonagens *cadastro);
void mostrarPersonagem(PERSONAGEM *p);
void listarPersonagens(CadastroPersonagens *cadastro);
void alterarPersonagem(CadastroPersonagens *cadastro);
void excluirPersonagem(CadastroPersonagens *cadastro);

PERSONAGEM *buscarPersonagemPorId(CadastroPersonagens *cadastro, int id);
int lerInteiroPersonagem();

#endif // PERSONAGEM_H