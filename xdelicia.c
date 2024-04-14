#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#define TAMANHO 10
#define PRODUTOS 30
#define INGREDIENTES 30
#define SENHA "admin"

//------------STRUCTS-----------------

struct Compras
{
    int idProduto, quantidade;
};
struct Carrinho
{
    struct Compras compras[TAMANHO];
    float preco;
};
struct endereco
{
    char rua[50], bairro[20], cep[20];
    int numero, id;
};
struct Usuario
{
    int id, idade;
    char login[20], senha[20], nome[20], sobrenome[20], email[30], telefone[20];
    struct Carrinho carrinho;
    struct endereco enderecos[10];
};
struct Fornecedor
{
    int id;
    struct endereco enderecos[10];
    char nome[20];
};

struct Ingrediente
{
    int id, quantidade;
    char nome[30];
    float preco;
};
struct valorReceber
{
    float valor;
    char nome[20];
    bool ativo;
};
struct valorPagar
{
    float valor;
    char nome[20];
    bool ativo;
};
struct Financeiro
{
    struct valorReceber receber[20];
    struct valorPagar pagar[20];
    float totalReceber;
    float totalPagar;
};

struct IngredienteProduto
{
    int idIngrediente;
    int quantidade;
};

struct Produto
{
    int id;
    char nome[30], tipo[20];
    struct IngredienteProduto ingredientes[TAMANHO];
    float preco;
};

//----------Variaveis Globais---------

struct Usuario usuarios[TAMANHO];
int usuarioLogado;
struct Ingrediente listaIngredientes[INGREDIENTES];
struct Produto listaProdutos[PRODUTOS];
struct Financeiro financeiro;
struct Fornecedor listaFornecedores[TAMANHO];

// Inicializar

void inicializarFornecedor()
{
    int i, j;
    for (i = 0; i < TAMANHO; i++)
    {
        listaFornecedores[i].id = -1;

        for (j = 0; j < 10; j++)
        {
            listaFornecedores[i].enderecos[j].id = -1;
        }
    }
}

void inicializarFinanceiro()
{
    int i;
    financeiro.totalReceber = 0;
    financeiro.totalPagar = 0;
    for (i = 0; i < 20; i++)
    {
        financeiro.receber[i].ativo = false;
        financeiro.pagar[i].ativo = false;
    }
}

void inicializarIngredientes()
{
    int i;
    for (i = 0; i < INGREDIENTES; i++)
    {
        listaIngredientes[i].id = -1;
    }

    listaIngredientes[0].id = 1;
    listaIngredientes[0].quantidade = 10;
    strcpy(listaIngredientes[0].nome, "Pão");
    listaIngredientes[0].preco = 1.50;

    listaIngredientes[1].id = 2;
    listaIngredientes[1].quantidade = 10;
    strcpy(listaIngredientes[1].nome, "Tomate");
    listaIngredientes[1].preco = 0.50;

    listaIngredientes[2].id = 3;
    listaIngredientes[2].quantidade = 10;
    strcpy(listaIngredientes[2].nome, "Carne");
    listaIngredientes[2].preco = 8;

    listaIngredientes[3].id = 4;
    listaIngredientes[3].quantidade = 10;
    strcpy(listaIngredientes[3].nome, "Queijo");
    listaIngredientes[3].preco = 1.50;

    listaIngredientes[4].id = 5;
    listaIngredientes[4].quantidade = 10;
    strcpy(listaIngredientes[4].nome, "Alface");
    listaIngredientes[4].preco = 1.50;

    listaIngredientes[5].id = 6;
    listaIngredientes[5].quantidade = 0;
    strcpy(listaIngredientes[5].nome, "Bacon");
    listaIngredientes[5].preco = 1.50;

    listaIngredientes[6].id = 7;
    listaIngredientes[6].quantidade = 10;
    strcpy(listaIngredientes[6].nome, "Ketchup");
    listaIngredientes[6].preco = 1;

    listaIngredientes[7].id = 8;
    listaIngredientes[7].quantidade = 10;
    strcpy(listaIngredientes[7].nome, "Ovo");
    listaIngredientes[7].preco = 2.50;

    listaIngredientes[8].id = 9;
    listaIngredientes[8].quantidade = 10;
    strcpy(listaIngredientes[8].nome, "Cebola");
    listaIngredientes[8].preco = 1.50;

    listaIngredientes[9].id = 10;
    listaIngredientes[9].quantidade = 10;
    strcpy(listaIngredientes[9].nome, "Batata");
    listaIngredientes[9].preco = 2.50;

    listaIngredientes[10].id = 11;
    listaIngredientes[10].quantidade = 10;
    strcpy(listaIngredientes[10].nome, "Coca-Cola");
    listaIngredientes[10].preco = 2.50;

    listaIngredientes[11].id = 12;
    listaIngredientes[11].quantidade = 10;
    strcpy(listaIngredientes[11].nome, "Coca-Cola Zero");
    listaIngredientes[11].preco = 1.99;

    listaIngredientes[12].id = 13;
    listaIngredientes[12].quantidade = 10;
    strcpy(listaIngredientes[12].nome, "Fanta Laranja");
    listaIngredientes[12].preco = 1.99;

    listaIngredientes[13].id = 14;
    listaIngredientes[13].quantidade = 0;
    strcpy(listaIngredientes[13].nome, "Fanta Uva");
    listaIngredientes[13].preco = 1.99;

    listaIngredientes[14].id = 15;
    listaIngredientes[14].quantidade = 0;
    strcpy(listaIngredientes[14].nome, "Guaraná Antártica");
    listaIngredientes[14].preco = 2.50;

    listaIngredientes[15].id = 16;
    listaIngredientes[15].quantidade = 10;
    strcpy(listaIngredientes[15].nome, "Guaraná Antártica Zero");
    listaIngredientes[15].preco = 1.99;

    listaIngredientes[16].id = 17;
    listaIngredientes[16].quantidade = 0;
    strcpy(listaIngredientes[16].nome, "Sprite");
    listaIngredientes[16].preco = 1.50;

    listaIngredientes[17].id = 18;
    listaIngredientes[17].quantidade = 10;
    strcpy(listaIngredientes[17].nome, "Água com gás");
    listaIngredientes[17].preco = 0.99;

    listaIngredientes[18].id = 19;
    listaIngredientes[18].quantidade = 0;
    strcpy(listaIngredientes[18].nome, "Água");
    listaIngredientes[18].preco = 0.65;

    listaIngredientes[19].id = 20;
    listaIngredientes[19].quantidade = 10;
    strcpy(listaIngredientes[19].nome, "Ice Tea Limão");
    listaIngredientes[19].preco = 2.50;

    listaIngredientes[20].id = 21;
    listaIngredientes[20].quantidade = 10;
    strcpy(listaIngredientes[20].nome, "Ice Tea Pêssego");
    listaIngredientes[20].preco = 2.50;
}

void inicializarprodutos()
{

    int i, j;
    for (i = 0; i < PRODUTOS; i++)
    {
        listaProdutos[i].id = -1;
        for (j = 0; j < TAMANHO; j++)
        {
            listaProdutos[i].ingredientes[j].idIngrediente = -1;
        }
    }

    strcpy(listaProdutos[0].tipo, "hamburguer");
    listaProdutos[0].id = 1;
    strcpy(listaProdutos[0].nome, "X-Salada");
    listaProdutos[0].ingredientes[0].idIngrediente = 1;
    listaProdutos[0].ingredientes[0].quantidade = 1;
    listaProdutos[0].ingredientes[1].idIngrediente = 3;
    listaProdutos[0].ingredientes[1].quantidade = 1;
    listaProdutos[0].ingredientes[2].idIngrediente = 4;
    listaProdutos[0].ingredientes[2].quantidade = 1;
    listaProdutos[0].ingredientes[3].idIngrediente = 2;
    listaProdutos[0].ingredientes[3].quantidade = 1;
    listaProdutos[0].ingredientes[4].idIngrediente = 5;
    listaProdutos[0].ingredientes[4].quantidade = 1;
    listaProdutos[0].ingredientes[5].idIngrediente = 9;
    listaProdutos[0].ingredientes[5].quantidade = 1;
    listaProdutos[0].preco = 18;

    strcpy(listaProdutos[1].tipo, "hamburguer");
    listaProdutos[1].id = 2;
    strcpy(listaProdutos[1].nome, "X-Egg");
    listaProdutos[1].ingredientes[0].idIngrediente = 1;
    listaProdutos[1].ingredientes[0].quantidade = 1;
    listaProdutos[1].ingredientes[1].idIngrediente = 3;
    listaProdutos[1].ingredientes[1].quantidade = 1;
    listaProdutos[1].ingredientes[2].idIngrediente = 8;
    listaProdutos[1].ingredientes[2].quantidade = 1;
    listaProdutos[1].ingredientes[3].idIngrediente = 4;
    listaProdutos[1].ingredientes[3].quantidade = 1;
    listaProdutos[1].ingredientes[4].idIngrediente = 5;
    listaProdutos[1].ingredientes[4].quantidade = 1;
    listaProdutos[1].ingredientes[5].idIngrediente = 2;
    listaProdutos[1].ingredientes[5].quantidade = 1;
    listaProdutos[1].ingredientes[6].idIngrediente = 9;
    listaProdutos[1].ingredientes[6].quantidade = 1;
    listaProdutos[1].ingredientes[7].idIngrediente = 7;
    listaProdutos[1].ingredientes[7].quantidade = 1;
    listaProdutos[1].preco = 25;

    strcpy(listaProdutos[2].tipo, "hamburguer");
    listaProdutos[2].id = 3;
    strcpy(listaProdutos[2].nome, "X-tudo");
    listaProdutos[2].ingredientes[0].idIngrediente = 1;
    listaProdutos[2].ingredientes[0].quantidade = 1;
    listaProdutos[2].ingredientes[1].idIngrediente = 2;
    listaProdutos[2].ingredientes[1].quantidade = 1;
    listaProdutos[2].ingredientes[2].idIngrediente = 3;
    listaProdutos[2].ingredientes[2].quantidade = 1;
    listaProdutos[2].ingredientes[3].idIngrediente = 4;
    listaProdutos[2].ingredientes[3].quantidade = 1;
    listaProdutos[2].ingredientes[4].idIngrediente = 5;
    listaProdutos[2].ingredientes[4].quantidade = 1;
    listaProdutos[2].ingredientes[5].idIngrediente = 6;
    listaProdutos[2].ingredientes[5].quantidade = 1;
    listaProdutos[2].ingredientes[6].idIngrediente = 7;
    listaProdutos[2].ingredientes[6].quantidade = 1;
    listaProdutos[2].ingredientes[7].idIngrediente = 8;
    listaProdutos[2].ingredientes[7].quantidade = 1;
    listaProdutos[2].ingredientes[8].idIngrediente = 9;
    listaProdutos[2].ingredientes[8].quantidade = 1;
    listaProdutos[2].preco = 22;

    strcpy(listaProdutos[3].tipo, "hamburguer");
    listaProdutos[3].id = 4;
    strcpy(listaProdutos[3].nome, "Duplo X-Burguer");
    listaProdutos[3].ingredientes[0].idIngrediente = 1;
    listaProdutos[3].ingredientes[0].quantidade = 1;
    listaProdutos[3].ingredientes[1].idIngrediente = 3;
    listaProdutos[3].ingredientes[1].quantidade = 2;
    listaProdutos[3].ingredientes[2].idIngrediente = 4;
    listaProdutos[3].ingredientes[2].quantidade = 2;
    listaProdutos[3].ingredientes[3].idIngrediente = 5;
    listaProdutos[3].ingredientes[3].quantidade = 1;
    listaProdutos[3].ingredientes[4].idIngrediente = 2;
    listaProdutos[3].ingredientes[4].quantidade = 1;
    listaProdutos[3].ingredientes[5].idIngrediente = 9;
    listaProdutos[3].ingredientes[5].quantidade = 1;
    listaProdutos[3].ingredientes[6].idIngrediente = 7;
    listaProdutos[3].ingredientes[6].quantidade = 1;
    listaProdutos[3].preco = 25;

    strcpy(listaProdutos[4].tipo, "hamburguer");
    listaProdutos[4].id = 5;
    strcpy(listaProdutos[4].nome, "X-Egg-Bacon");
    listaProdutos[4].ingredientes[0].idIngrediente = 1;
    listaProdutos[4].ingredientes[0].quantidade = 1;
    listaProdutos[4].ingredientes[1].idIngrediente = 3;
    listaProdutos[4].ingredientes[1].quantidade = 1;
    listaProdutos[4].ingredientes[2].idIngrediente = 4;
    listaProdutos[4].ingredientes[2].quantidade = 1;
    listaProdutos[4].ingredientes[3].idIngrediente = 8;
    listaProdutos[4].ingredientes[3].quantidade = 1;
    listaProdutos[4].ingredientes[4].idIngrediente = 6;
    listaProdutos[4].ingredientes[4].quantidade = 1;
    listaProdutos[4].ingredientes[5].idIngrediente = 5;
    listaProdutos[4].ingredientes[5].quantidade = 1;
    listaProdutos[4].ingredientes[6].idIngrediente = 2;
    listaProdutos[4].ingredientes[6].quantidade = 1;
    listaProdutos[4].ingredientes[7].idIngrediente = 9;
    listaProdutos[4].ingredientes[7].quantidade = 1;
    listaProdutos[4].ingredientes[8].idIngrediente = 7;
    listaProdutos[4].ingredientes[8].quantidade = 1;
    listaProdutos[4].preco = 21.40;

    strcpy(listaProdutos[5].tipo, "hamburguer");
    listaProdutos[5].id = 6;
    strcpy(listaProdutos[5].nome, "Duplo X-salada");
    listaProdutos[5].ingredientes[0].idIngrediente = 1;
    listaProdutos[5].ingredientes[0].quantidade = 2;
    listaProdutos[5].ingredientes[1].idIngrediente = 3;
    listaProdutos[5].ingredientes[1].quantidade = 2;
    listaProdutos[5].ingredientes[2].idIngrediente = 4;
    listaProdutos[5].ingredientes[2].quantidade = 2;
    listaProdutos[5].ingredientes[3].idIngrediente = 2;
    listaProdutos[5].ingredientes[3].quantidade = 2;
    listaProdutos[5].ingredientes[4].idIngrediente = 5;
    listaProdutos[5].ingredientes[4].quantidade = 1;
    listaProdutos[5].ingredientes[5].idIngrediente = 9;
    listaProdutos[5].ingredientes[5].quantidade = 2;
    listaProdutos[5].preco = 28.99;

    strcpy(listaProdutos[6].tipo, "hamburguer");
    listaProdutos[6].id = 7;
    strcpy(listaProdutos[6].nome, "X-bacon");
    listaProdutos[6].ingredientes[0].idIngrediente = 1;
    listaProdutos[6].ingredientes[0].quantidade = 1;
    listaProdutos[6].ingredientes[1].idIngrediente = 3;
    listaProdutos[6].ingredientes[1].quantidade = 1;
    listaProdutos[6].ingredientes[2].idIngrediente = 4;
    listaProdutos[6].ingredientes[2].quantidade = 1;
    listaProdutos[6].ingredientes[3].idIngrediente = 6;
    listaProdutos[6].ingredientes[3].quantidade = 1;
    listaProdutos[6].ingredientes[4].idIngrediente = 7;
    listaProdutos[6].ingredientes[4].quantidade = 1;
    listaProdutos[6].preco = 21.99;

    strcpy(listaProdutos[7].tipo, "hamburguer");
    listaProdutos[7].id = 8;
    strcpy(listaProdutos[7].nome, "X-burguer");
    listaProdutos[7].ingredientes[0].idIngrediente = 1;
    listaProdutos[7].ingredientes[0].quantidade = 1;
    listaProdutos[7].ingredientes[1].idIngrediente = 3;
    listaProdutos[7].ingredientes[1].quantidade = 1;
    listaProdutos[7].ingredientes[2].idIngrediente = 4;
    listaProdutos[7].ingredientes[2].quantidade = 1;
    listaProdutos[7].ingredientes[3].idIngrediente = 5;
    listaProdutos[7].ingredientes[3].quantidade = 1;
    listaProdutos[7].ingredientes[4].idIngrediente = 2;
    listaProdutos[7].ingredientes[4].quantidade = 1;
    listaProdutos[7].ingredientes[5].idIngrediente = 9;
    listaProdutos[7].ingredientes[5].quantidade = 1;
    listaProdutos[7].ingredientes[6].idIngrediente = 7;
    listaProdutos[7].ingredientes[6].quantidade = 1;
    listaProdutos[7].preco = 15.30;

    strcpy(listaProdutos[8].tipo, "hamburguer");
    listaProdutos[8].id = 9;
    strcpy(listaProdutos[8].nome, "Duplo X-Bacon");
    listaProdutos[8].ingredientes[0].idIngrediente = 1;
    listaProdutos[8].ingredientes[0].quantidade = 1;
    listaProdutos[8].ingredientes[1].idIngrediente = 3;
    listaProdutos[8].ingredientes[1].quantidade = 2;
    listaProdutos[8].ingredientes[2].idIngrediente = 4;
    listaProdutos[8].ingredientes[2].quantidade = 2;
    listaProdutos[8].ingredientes[3].idIngrediente = 6;
    listaProdutos[8].ingredientes[3].quantidade = 1;
    listaProdutos[8].ingredientes[4].idIngrediente = 5;
    listaProdutos[8].ingredientes[4].quantidade = 1;
    listaProdutos[8].ingredientes[5].idIngrediente = 2;
    listaProdutos[8].ingredientes[5].quantidade = 1;
    listaProdutos[8].ingredientes[6].idIngrediente = 9;
    listaProdutos[8].ingredientes[6].quantidade = 1;
    listaProdutos[8].ingredientes[6].idIngrediente = 7;
    listaProdutos[8].ingredientes[6].quantidade = 1;
    listaProdutos[8].preco = 29.99;

    strcpy(listaProdutos[9].tipo, "hamburguer");
    listaProdutos[9].id = 10;
    strcpy(listaProdutos[9].nome, "Duplo X-tudo");
    listaProdutos[9].ingredientes[0].idIngrediente = 1;
    listaProdutos[9].ingredientes[0].quantidade = 2;
    listaProdutos[9].ingredientes[1].idIngrediente = 2;
    listaProdutos[9].ingredientes[1].quantidade = 2;
    listaProdutos[9].ingredientes[2].idIngrediente = 3;
    listaProdutos[9].ingredientes[2].quantidade = 2;
    listaProdutos[9].ingredientes[3].idIngrediente = 4;
    listaProdutos[9].ingredientes[3].quantidade = 2;
    listaProdutos[9].ingredientes[4].idIngrediente = 5;
    listaProdutos[9].ingredientes[4].quantidade = 1;
    listaProdutos[9].ingredientes[5].idIngrediente = 6;
    listaProdutos[9].ingredientes[5].quantidade = 2;
    listaProdutos[9].ingredientes[6].idIngrediente = 7;
    listaProdutos[9].ingredientes[6].quantidade = 1;
    listaProdutos[9].ingredientes[7].idIngrediente = 8;
    listaProdutos[9].ingredientes[7].quantidade = 2;
    listaProdutos[9].ingredientes[8].idIngrediente = 9;
    listaProdutos[9].ingredientes[8].quantidade = 2;
    listaProdutos[9].preco = 32.50;

    strcpy(listaProdutos[10].tipo, "acompanhamento");
    listaProdutos[10].id = 11;
    strcpy(listaProdutos[10].nome, "Batata frita");
    listaProdutos[10].ingredientes[0].idIngrediente = 10;
    listaProdutos[10].ingredientes[0].quantidade = 1;
    listaProdutos[10].preco = 5.25;

    strcpy(listaProdutos[11].tipo, "acompanhamento");
    listaProdutos[11].id = 12;
    strcpy(listaProdutos[11].nome, "Batata frita com queijo");
    listaProdutos[11].ingredientes[0].idIngrediente = 10;
    listaProdutos[11].ingredientes[0].quantidade = 1;
    listaProdutos[11].ingredientes[1].idIngrediente = 4;
    listaProdutos[11].ingredientes[1].quantidade = 1;
    listaProdutos[11].preco = 7.42;

    strcpy(listaProdutos[12].tipo, "acompanhamento");
    listaProdutos[12].id = 13;
    strcpy(listaProdutos[12].nome, "Batata frita com queijo e bacon");
    listaProdutos[12].ingredientes[0].idIngrediente = 10;
    listaProdutos[12].ingredientes[0].quantidade = 1;
    listaProdutos[12].ingredientes[1].idIngrediente = 4;
    listaProdutos[12].ingredientes[1].quantidade = 1;
    listaProdutos[12].ingredientes[2].idIngrediente = 6;
    listaProdutos[12].ingredientes[2].quantidade = 1;
    listaProdutos[12].preco = 10.30;

    strcpy(listaProdutos[13].tipo, "acompanhamento");
    listaProdutos[13].id = 14;
    strcpy(listaProdutos[13].nome, "Cebola empanada");
    listaProdutos[13].ingredientes[0].idIngrediente = 9;
    listaProdutos[13].ingredientes[0].quantidade = 1;
    listaProdutos[13].preco = 3;

    strcpy(listaProdutos[14].tipo, "Bebidas");
    listaProdutos[14].id = 15;
    strcpy(listaProdutos[14].nome, "Coca-Cola");
    listaProdutos[14].ingredientes[0].idIngrediente = 11;
    listaProdutos[14].ingredientes[0].quantidade = 1;
    listaProdutos[14].preco = 9.99;

    strcpy(listaProdutos[15].tipo, "Bebidas");
    listaProdutos[15].id = 16;
    strcpy(listaProdutos[15].nome, "Coca-Cola Zero");
    listaProdutos[15].ingredientes[0].idIngrediente = 12;
    listaProdutos[15].ingredientes[0].quantidade = 1;
    listaProdutos[15].preco = 8.99;

    strcpy(listaProdutos[16].tipo, "Bebidas");
    listaProdutos[16].id = 17;
    strcpy(listaProdutos[16].nome, "Fanta Laranja");
    listaProdutos[16].ingredientes[0].idIngrediente = 13;
    listaProdutos[16].ingredientes[0].quantidade = 1;
    listaProdutos[16].preco = 9.50;

    strcpy(listaProdutos[17].tipo, "Bebidas");
    listaProdutos[17].id = 18;
    strcpy(listaProdutos[17].nome, "Fanta Uva");
    listaProdutos[17].ingredientes[0].idIngrediente = 14;
    listaProdutos[17].ingredientes[0].quantidade = 1;
    listaProdutos[17].preco = 9.50;

    strcpy(listaProdutos[18].tipo, "Bebidas");
    listaProdutos[18].id = 19;
    strcpy(listaProdutos[18].nome, "Guaraná Antártica");
    listaProdutos[18].ingredientes[0].idIngrediente = 15;
    listaProdutos[18].ingredientes[0].quantidade = 1;
    listaProdutos[18].preco = 8.50;

    strcpy(listaProdutos[19].tipo, "Bebidas");
    listaProdutos[19].id = 20;
    strcpy(listaProdutos[19].nome, "Guaraná Antártica Zero");
    listaProdutos[19].ingredientes[0].idIngrediente = 16;
    listaProdutos[19].ingredientes[0].quantidade = 1;
    listaProdutos[19].preco = 9.50;

    strcpy(listaProdutos[20].tipo, "Bebidas");
    listaProdutos[20].id = 21;
    strcpy(listaProdutos[20].nome, "Sprite");
    listaProdutos[20].ingredientes[0].idIngrediente = 17;
    listaProdutos[20].ingredientes[0].quantidade = 1;
    listaProdutos[20].preco = 6.99;

    strcpy(listaProdutos[21].tipo, "Bebidas");
    listaProdutos[21].id = 22;
    strcpy(listaProdutos[21].nome, "Água com gás");
    listaProdutos[21].ingredientes[0].idIngrediente = 18;
    listaProdutos[21].ingredientes[0].quantidade = 1;
    listaProdutos[21].preco = 3;

    strcpy(listaProdutos[22].tipo, "Bebidas");
    listaProdutos[22].id = 23;
    strcpy(listaProdutos[22].nome, "Água sem gás");
    listaProdutos[22].ingredientes[0].idIngrediente = 19;
    listaProdutos[22].ingredientes[0].quantidade = 1;
    listaProdutos[22].preco = 2.50;

    strcpy(listaProdutos[23].tipo, "Bebidas");
    listaProdutos[23].id = 24;
    strcpy(listaProdutos[23].nome, "Ice Tea Limão");
    listaProdutos[23].ingredientes[0].idIngrediente = 20;
    listaProdutos[23].ingredientes[0].quantidade = 1;
    listaProdutos[23].preco = 9.99;

    strcpy(listaProdutos[24].tipo, "Bebidas");
    listaProdutos[24].id = 25;
    strcpy(listaProdutos[24].nome, "Ice Tea Pêssego");
    listaProdutos[24].ingredientes[0].idIngrediente = 21;
    listaProdutos[24].ingredientes[0].quantidade = 1;
    listaProdutos[24].preco = 9.99;
}

void inicializarIngredienteProduto()
{

    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < TAMANHO; j++)
        {
            listaProdutos[i].ingredientes[j].idIngrediente = -1;
        }
    }
    printf("\ninicializou");
}

void inicializarUsuarios()
{
    int i, j;
    for (i = 0; i < TAMANHO; i++)
    {
        usuarios[i].id = -1;
        usuarios[i].carrinho.preco = 0;

        for (j = 0; j < 10; j++)
        {
            usuarios[i].carrinho.compras[j].idProduto = -1;
            usuarios[i].enderecos[j].id = -1;
        }
    }
}

bool verificaDisponibilidade(struct Produto produto, int quantidade)
{
    int i, j;

    for (i = 0; i < TAMANHO; i++)
    {
        if (produto.ingredientes[i].idIngrediente != -1)
        {
            for (j = 0; j < INGREDIENTES; j++)
            {
                if (produto.ingredientes[i].idIngrediente == listaIngredientes[j].id)
                {
                    if (produto.ingredientes[i].quantidade * quantidade > listaIngredientes[j].quantidade)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void removeQuantidade(struct Produto produto, int quantidade)
{
    int i;
    for (i = 0; i < TAMANHO; i++)
    {
        if (produto.ingredientes[i].idIngrediente != -1)
        {
            int quantIngrediente = produto.ingredientes[i].quantidade * quantidade;
            int id = produto.ingredientes[i].idIngrediente;
            int j;
            for (j = 0; j < INGREDIENTES; j++)
            {
                if (id == listaIngredientes[j].id)
                {
                    listaIngredientes[j].quantidade -= quantIngrediente;
                }
            }
        }
    }
}

void adicionaQuantidade(struct Produto produto, int quantidade)
{
    int i;
    for (i = 0; i < TAMANHO; i++)
    {
        if (produto.ingredientes[i].idIngrediente != -1)
        {
            int quantIngrediente = produto.ingredientes[i].quantidade * quantidade;
            int id = produto.ingredientes[i].idIngrediente;
            int j;
            for (j = 0; j < INGREDIENTES; j++)
            {
                if (id == listaIngredientes[j].id)
                {
                    listaIngredientes[j].quantidade += quantIngrediente;
                }
            }
        }
    }
}

void cardapioHamburguer()
{
    int i;
    int opcao;
    int quantidade;
    for (i = 0; i < PRODUTOS; i++)
    {
        if (verificaDisponibilidade(listaProdutos[i], 1) && !strcmp(listaProdutos[i].tipo, "hamburguer"))
        {
            printf("\nNº%d) %s: R$ %.2f.\n", i + 1, listaProdutos[i].nome, listaProdutos[i].preco);
        }
        else if (!strcmp(listaProdutos[i].tipo, "hamburguer"))
        {
            printf("\nNº %d %s: INSDISPONIVEL.\n", i + 1, listaProdutos[i].nome);
        }
    }

    printf("\nDigite o Nº do produto que voce deseja adicionar no carrinho: ");
    scanf("%d", &opcao);
    printf("\nDigite a quantidade que deseja adicionar: ");
    scanf("%d", &quantidade);

    opcao--;

    if (verificaDisponibilidade(listaProdutos[opcao], quantidade))
    {
        int posicao = -1;
        for (i = 0; i < TAMANHO; i++)
        {
            if (usuarios[usuarioLogado].carrinho.compras[i].idProduto == -1)
            {
                posicao = i;
                break;
            }
        }

        if (posicao != -1)
        {
            usuarios[usuarioLogado].carrinho.compras[posicao].idProduto = listaProdutos[opcao].id;
            usuarios[usuarioLogado].carrinho.preco += listaProdutos[opcao].preco * quantidade;
            usuarios[usuarioLogado].carrinho.compras[posicao].quantidade = quantidade;
            removeQuantidade(listaProdutos[opcao], quantidade);
            printf("\nItem adicionado com sucesso!");
        }
        else
        {
            printf("\nERRO!!\n");
        }
    }
    else
    {
        printf("\nIngredientes no stock indisponiveis para a quantidade selecionada");
    }
}

void cardapioBebida()
{
    int i;
    int opcao;
    int quantidade;
    for (i = 0; i < PRODUTOS; i++)
    {
        if (verificaDisponibilidade(listaProdutos[i], 1) && !strcmp(listaProdutos[i].tipo, "Bebidas"))
        {
            printf("\nNº %d %s: R$ %.2f.\n", i + 1, listaProdutos[i].nome, listaProdutos[i].preco);
        }
        else if (!strcmp(listaProdutos[i].tipo, "Bedidas"))
        {
            printf("\nNº %d %s: INSDISPONIVEL.\n", i + 1, listaProdutos[i].nome);
        }
    }

    printf("\nDigite o Nº do produto que voce deseja adicionar no carrinho: ");
    scanf("%d", &opcao);
    printf("\nDigite a quantidade que deseja adicionar: ");
    scanf("%d", &quantidade);

    opcao--;

    if (verificaDisponibilidade(listaProdutos[opcao], quantidade))
    {
        int posicao = -1;
        for (i = 0; i < TAMANHO; i++)
        {
            if (usuarios[usuarioLogado].carrinho.compras[i].idProduto == -1)
            {
                posicao = i;
                break;
            }
        }

        if (posicao != -1)
        {
            usuarios[usuarioLogado].carrinho.compras[posicao].idProduto = listaProdutos[opcao].id;
            usuarios[usuarioLogado].carrinho.preco += listaProdutos[opcao].preco * quantidade;
            usuarios[usuarioLogado].carrinho.compras[posicao].quantidade = quantidade;
            removeQuantidade(listaProdutos[opcao], quantidade);
            printf("\nItem adicionado com sucesso!");
        }
        else
        {
            printf("\nERRO!!\n");
        }
    }
    else
    {
        printf("\nIngredientes no stock indisponiveis para a quantidade selecionada");
    }
}

void cardapioAcompanhamento()
{
    int i;
    int opcao;
    int quantidade;
    for (i = 0; i < PRODUTOS; i++)
    {
        if (verificaDisponibilidade(listaProdutos[i], 1) && !strcmp(listaProdutos[i].tipo, "acompanhamento"))
        {
            printf("\nNº %d %s: R$ %.2f.\n", i + 1, listaProdutos[i].nome, listaProdutos[i].preco);
        }
        else if (!strcmp(listaProdutos[i].tipo, "acompanhamento"))
        {
            printf("\nNº %d %s: INSDISPONIVEL.\n", i + 1, listaProdutos[i].nome);
        }
    }

    printf("\nDigite o Nº do produto que voce deseja adicionar no carrinho: ");
    scanf("%d", &opcao);
    printf("\nDigite a quantidade que deseja adicionar: ");
    scanf("%d", &quantidade);

    opcao--;

    if (verificaDisponibilidade(listaProdutos[opcao], quantidade))
    {
        int posicao = -1;
        for (i = 0; i < TAMANHO; i++)
        {
            if (usuarios[usuarioLogado].carrinho.compras[i].idProduto == -1)
            {
                posicao = i;
                break;
            }
        }

        if (posicao != -1)
        {
            usuarios[usuarioLogado].carrinho.compras[posicao].idProduto = listaProdutos[opcao].id;
            usuarios[usuarioLogado].carrinho.preco += listaProdutos[opcao].preco * quantidade;
            usuarios[usuarioLogado].carrinho.compras[posicao].quantidade = quantidade;
            removeQuantidade(listaProdutos[opcao], quantidade);
            printf("\nItem adicionado com sucesso!");
        }
        else
        {
            printf("\nERRO!!\n");
        }
    }
    else
    {
        printf("\nIngredientes no stock indisponiveis para a quantidade selecionada");
    }
}

void cardapio()
{
    printf("\nCARDAPIO\n");

    int op;
    bool continua = true;

    while (continua)
    {
        printf("\n\n===============================\n");
        printf("\n\t(0)-Sair");
        printf("\n\t(1)-Hamburgueres");
        printf("\n\t(2)-Acompanhamentos");
        printf("\n\t(3)-Bebidas");
        printf("\n\tEscolha uma opção");
        printf("\n\n===============================\n\n");
        printf("opção: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            cardapioHamburguer();
            break;
        case 2:
            cardapioAcompanhamento();
            break;
        case 3:
            cardapioBebida();
            break;
        case 0:
            continua = false;
            break;
        default:
            printf("\nDigite uma opção válida!\n");
            break;
        }
    }
}

char *achaNomeProduto(int id)
{
    int i;
    for (i = 0; i < PRODUTOS; i++)
    {
        if (id == listaProdutos[i].id)
        {
            return listaProdutos[i].nome;
            break;
        }
    }
    return "";
}

void removeDoCarrinho()
{
    int produto, quantidade;

    printf("\nDigite o Nº do produto que deseja remover:");
    scanf("%d", &produto);
    printf("\nDigite a quantidade que deseja remover:");
    scanf("%d", &quantidade);

    produto--;

    if ((usuarios[usuarioLogado].carrinho.compras[produto].quantidade - quantidade) > 0)
    {

        int i;
        for (i = 0; i < PRODUTOS; i++)
        {
            if (listaProdutos[i].id == usuarios[usuarioLogado].carrinho.compras[produto].idProduto)
            {
                usuarios[usuarioLogado].carrinho.compras[produto].quantidade -= quantidade;
                usuarios[usuarioLogado].carrinho.preco -= listaProdutos[i].preco * quantidade;
                adicionaQuantidade(listaProdutos[i], quantidade);
                printf("\nItem removido com sucesso!");
                break;
            }
        }
    }
    else
    {
        int i;
        for (i = 0; i < PRODUTOS; i++)
        {
            if (listaProdutos[i].id == usuarios[usuarioLogado].carrinho.compras[produto].idProduto)
            {
                adicionaQuantidade(listaProdutos[i], usuarios[usuarioLogado].carrinho.compras[produto].quantidade);
                usuarios[usuarioLogado].carrinho.compras[produto].idProduto = -1;
                usuarios[usuarioLogado].carrinho.preco -= listaProdutos[i].preco * quantidade;
                printf("\nItem removido com sucesso!");
                break;
            }
        }
    }
}

void finalizarCompra()
{

    int i;
    int posicao = -1;
    for (i = 0; i < 20; i++)
    {
        if (!financeiro.receber[i].ativo)
        {
            posicao = i;
            break;
        }
    }

    if (posicao != -1)
    {
        financeiro.receber[posicao].ativo = true;
        financeiro.receber[posicao].valor = usuarios[usuarioLogado].carrinho.preco;
        strcpy(financeiro.receber[posicao].nome, usuarios[usuarioLogado].nome);
    }
    else
    {
        printf("\nERRO!!\n");
    }

    usuarios[usuarioLogado].carrinho.preco = 0;

    for (i = 0; i < TAMANHO; i++)
    {
        usuarios[usuarioLogado].carrinho.compras[i].idProduto = -1;
    }

    printf("\nPedido Realizado com Sucesso!\n");
}

void verCarrinho()
{
    int i;
    for (i = 0; i < TAMANHO; i++)
    {
        if (usuarios[usuarioLogado].carrinho.compras[i].idProduto != -1)
        {
            printf("\nNº %d) %s  %dx", i + 1, achaNomeProduto(usuarios[usuarioLogado].carrinho.compras[i].idProduto), usuarios[usuarioLogado].carrinho.compras[i].quantidade);
        }
    }
    printf("\nPreço total: R$ %.2f.", usuarios[usuarioLogado].carrinho.preco);

    int opcao;
    bool continua = true;
    while (continua)
    {
        printf("\n\n============================\n");
        printf("\n(1)-Finalizar o pedido");
        printf("\n(2)-Remover um item");
        printf("\n(0)-Voltar para o menu");
        printf("\n\n============================\n\n");
        printf("opção: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            finalizarCompra();
            continua = false;
            break;
        case 2:
            removeDoCarrinho();
            break;
        case 0:
            continua = false;
            break;
        default:
            printf("\nDigite uma opção válida!\n");
            break;
        }
    }
}

void cadastroUsuario()
{
    int i;
    int posicao = -1;
    for (i = 0; i < TAMANHO; i++)
    {
        if (usuarios[i].id == -1)
        {
            posicao = i;
            break;
        }
    }

    if (posicao != -1)
    {
        usuarios[posicao].id = posicao;
        printf("\nLogin: ");
        scanf("%s", usuarios[posicao].login);
        printf("Senha: ");
        scanf("%s", usuarios[posicao].senha);
        printf("Digite seu nome: ");
        scanf("%s", usuarios[posicao].nome);
        printf("Digite seu sobrenome: ");
        scanf("%s", usuarios[posicao].sobrenome);
        printf("Digite sua idade: ");
        scanf("%d", &usuarios[posicao].idade);
        printf("Digite seu número telefonico: ");
        scanf("%s", usuarios[posicao].telefone);
        printf("digite seu email: ");
        scanf("%s", usuarios[posicao].email);
        printf("Rua utilizando _: ");
        scanf("%s", usuarios[posicao].enderecos[0].rua);
        printf("Bairro: ");
        scanf("%s", usuarios[posicao].enderecos[0].bairro);
        printf("CEP: ");
        scanf("%s", usuarios[posicao].enderecos[0].cep);
        printf("Número: ");
        scanf("%d", &usuarios[posicao].enderecos[0].numero);
        usuarios[usuarioLogado].enderecos[0].id = 0;

        printf("\nUsuario cadastrado com sucesso!\n");
    }
    else
    {
        printf("\nERRO!!\n");
    }
}

void adicionarEndereco()
{

    int i;
    int posicao = -1;
    for (i = 0; i < TAMANHO; i++)
    {
        if (usuarios[usuarioLogado].enderecos[i].id == -1)
        {
            posicao = i;
            break;
        }
    }

    if (i != -1)
    {
        printf("\nDigite as informações do novo endereço: \n");
        printf("Rua utilizando _: ");
        scanf("%s", usuarios[usuarioLogado].enderecos[posicao].rua);
        printf("Bairro: ");
        scanf("%s", usuarios[usuarioLogado].enderecos[posicao].bairro);
        printf("CEP: ");
        scanf("%s", usuarios[usuarioLogado].enderecos[posicao].cep);
        printf("Número: ");
        scanf("%d", &usuarios[usuarioLogado].enderecos[posicao].numero);
        usuarios[usuarioLogado].enderecos[i].id = posicao;
    }
}

void subMenuTrocadeDados()
{
    int opcao;
    bool continua = true;
    char senha[20];

    while (continua)
    {
        printf("\n\n===============================\n");
        printf("\n\t(0)-Sair");
        printf("\n\t(1)-Troca de senha");
        printf("\n\t(2)-novo endereço");
        printf("\n\n===============================\n");
        printf("\n Escolha uma das opções: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("\n Digite sua senha atual: ");
            scanf("%s", senha);

            if (strcmp(usuarios[usuarioLogado].senha, senha))
            {
               printf("senha incorreta");
            }
            else
            {
               printf("\n Digite a nova senha: ");
                scanf("%s", usuarios[usuarioLogado].senha);
                printf("\nsenha alterada com sucesso");
            }

            break;
        case 2:
            adicionarEndereco();
            break;
        case 0:
            continua = false;
            break;

        default:
            break;
        }
    }
}

void verDados()
{
    printf("\n\n========Meus Dados=============\n");

    printf("\nNome: %s %s", usuarios[usuarioLogado].nome, usuarios[usuarioLogado].sobrenome);
    printf("\nTelefone: %s", usuarios[usuarioLogado].telefone);
    printf("\nEmail: %s", usuarios[usuarioLogado].email);
    printf("\nIdade: %d", usuarios[usuarioLogado].idade);
    int j;
    for (j = 0; j < 10; j++)
    {
        if (usuarios[usuarioLogado].enderecos[j].id != -1)
        {
            printf("\nEndereço %d) \tCEP: %s \tBairro: %s \tRua: %s \tNumero: %d", j + 1, usuarios[usuarioLogado].enderecos[j].cep, usuarios[usuarioLogado].enderecos[j].bairro, usuarios[usuarioLogado].enderecos[j].rua, usuarios[usuarioLogado].enderecos[j].numero);
        }
    }
}

void sistemaClientes()
{
    int opcao;
    bool continua = true;

    while (continua)
    {
        printf("\n=============Menu!=============\n");
        printf("\n\t(0)-Sair");
        printf("\n\t(1)-Cardapio");
        printf("\n\t(2)-Ver Carrinho");
        printf("\n\t(3)-Alterar dados");
        printf("\n\t(4)-Ver dados");
        printf("\n\n===============================\n");
        printf("\n Escolha uma opção: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            cardapio();
            break;
        case 2:
            verCarrinho();
            break;
        case 3:
            subMenuTrocadeDados();
            break;
        case 4:
            verDados();
            break;
        case 0:
            continua = false;
            break;
        default:
            printf("\nDigite uma opção válida!\n");
            break;
        }
    }
}

void encomendarIngrediente()
{

    int i, ingrediente, fornecedor, quantidade;

    printf("\n\n==========Fornecedores============\n\n");
    for (i = 0; i < TAMANHO; i++)
    {
        if (listaFornecedores[i].id != -1)
        {
            printf("\nNº%d) %s", listaFornecedores[i].id, listaFornecedores[i].nome);
        }
    }
    printf("\n\nDe qual fornecedor voce deseja encomendar?");
    scanf("%d", &fornecedor);

    printf("\n\n==========Ingredientes============\n\n");
    for (i = 0; i < INGREDIENTES; i++)
    {
        if (listaIngredientes[i].id != -1)
        {
            printf("\nNº%d) %s R$ %.2f", listaIngredientes[i].id, listaIngredientes[i].nome, listaIngredientes[i].preco);
        }
    }

    printf("\nQual ingrediente deseja encomendar? ");
    scanf("%d", &ingrediente);
    printf("\nDigite a quantidade que deseja encomendar: ");
    scanf("%d", &quantidade);

    ingrediente--;
    fornecedor--;

    listaIngredientes[ingrediente].quantidade += quantidade;

    int j;
    int posicao = -1;
    for (j = 0; j < 20; j++)
    {
        if (!financeiro.pagar[j].ativo)
        {
            posicao = j;
            break;
        }
    }

    if (posicao != -1)
    {
        financeiro.pagar[posicao].ativo = true;
        financeiro.pagar[posicao].valor = listaIngredientes[ingrediente].preco * quantidade;
        strcpy(financeiro.pagar[posicao].nome, listaFornecedores[fornecedor].nome);
    }

    printf("\n\nItem encomendado com sucesso!");
}

void adicionarFornecedor()
{
    int i;
    int posicao = -1;
    for (i = 0; i < TAMANHO; i++)
    {
        if (listaFornecedores[i].id == -1)
        {
            posicao = i;
            break;
        }
    }

    if (posicao != -1)
    {
        int qntEnderecos;
        listaFornecedores[posicao].id = posicao + 1;
        printf("\nNome do fornecedor: ");
        scanf("%s", listaFornecedores[posicao].nome);
        printf("\nQuantos endereços o fornecedor tem:?");
        scanf("%d", &qntEnderecos);

        for (i = 0; i < qntEnderecos; i++)
        {
            printf("\n\nDados do %dº endereço: \n\n", i + 1);
            printf("Rua utilizando _: ");
            scanf("%s", listaFornecedores[posicao].enderecos[i].rua);
            printf("Bairro: ");
            scanf("%s", listaFornecedores[posicao].enderecos[i].bairro);
            printf("CEP: ");
            scanf("%s", listaFornecedores[posicao].enderecos[i].cep);
            printf("Número: ");
            scanf("%d", &listaFornecedores[posicao].enderecos[i].numero);
            listaFornecedores[posicao].enderecos[i].id = posicao + 1;
        }

        printf("\nFornecedor cadastrado com sucesso!\n");
    }
    else
    {
        printf("\nERRO");
    }
}

void extratoReceber()
{
    printf("\n\n=======Valor a receber======\n\n");

    int i;

    for (i = 0; i < 20; i++)
    {
        if (financeiro.receber[i].ativo)
        {
            printf("\n\n%d) \nNome do cliente: %s \nValor da compra: R$ %.2f", i + 1, financeiro.receber[i].nome, financeiro.receber[i].valor);
            financeiro.totalReceber += financeiro.receber[i].valor;
        }
    }
    printf("\n\n\nTotal a receber: R$ %.2f", financeiro.totalReceber);
}

void extratoPagar()
{
    printf("\n\n=======Valor a pagar======\n\n");

    int i;

    for (i = 0; i < 20; i++)
    {
        if (financeiro.pagar[i].ativo)
        {
            printf("\n\n%d) \nNome do fornecedor: %s \nValor da compra: R$ %.2f", i + 1, financeiro.pagar[i].nome, financeiro.pagar[i].valor);
            financeiro.totalPagar += financeiro.pagar[i].valor;
        }
    }
    printf("\n\n\nTotal a pagar: R$ %.2f", financeiro.totalPagar);
}

void menuFinanceiro()
{
    int opcao;
    printf("\n\n===============================\n");
    printf("\n(1)-Contas a receber");
    printf("\n(2)-Contas a pagar");
    printf("\n\n===============================\n\n");
    printf("Escolha uma das opções: ");

    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        extratoReceber();
        break;
    case 2:
        extratoPagar();
        break;
    default:
        printf("\nDigite uma opção válida!\n");
        break;
    }
}

void addprodutos()
{
    int qntIngredientes, i, posicao;
    posicao = -1;

    for (i = 0; i < PRODUTOS; i++)
    {
        if (listaProdutos[i].id == -1)
        {
            posicao = i;
            break;
        }
    }

    if (posicao != -1)
    {
        printf("Qual tipo do produto: ");
        scanf("%s", listaProdutos[posicao].tipo);
        printf("Qual o nome do produto: ");
        scanf("%s", listaProdutos[posicao].nome);
        printf("\nQuantos ingredientes:?");
        scanf("%d", &qntIngredientes);
    }
    for (i = 0; i < qntIngredientes; i++)
    {
        printf("\nDados do %dº ingrediente: \n", i + 1);
        printf("ID ingrediente: ");
        scanf("%d", &listaProdutos[posicao].ingredientes[i].idIngrediente);
        printf("\nQuantidade do ingrediente: ");
        scanf("%d", &listaProdutos[posicao].ingredientes[i].quantidade);
    }
}

void addingrediente()
{
    int posicao, i;
    posicao = -1;
    for (i = 0; i < INGREDIENTES; i++)
    {
        if (listaIngredientes[i].id == -1)
        {
            posicao = i;
            break;
        }
    }

    if (posicao != -1)
    {
        printf("Escreva o nome do novo ingrediente: ");
        scanf("%s", listaIngredientes[posicao].nome);
        printf("Coloque o valor de compra do fornecedor");
        scanf("%f", &listaIngredientes[posicao].preco);
        listaIngredientes[posicao].id = posicao + 1;
        listaIngredientes[posicao].quantidade = 0;
    }
    else
    {
        printf("erro");
    }
}

void stockIngredientes()
{
    printf("\n=======Stock de ingredientes========\n");
    int i;
    for (i = 0; i < INGREDIENTES; i++)
    {
        if (listaIngredientes[i].id != -1)
        {
            printf("\n\nNome: %s \nQuantidade: %d", listaIngredientes[i].nome, listaIngredientes[i].quantidade);
        }
    }
}

void dadosClientes()
{
    printf("\n=======CLientes cadastrados========\n");
    int i;
    for (i = 0; i < TAMANHO; i++)
    {
        if (usuarios[i].id != -1)
        {
            printf("\n\n%d)", i + 1);
            printf("\nNome: %s %s", usuarios[i].nome, usuarios[i].sobrenome);
            printf("\nTelefone: %s", usuarios[i].telefone);
            printf("\nEmail: %s", usuarios[i].email);
            printf("\nIdade: %d", usuarios[i].idade);
            int j;
            for (j = 0; j < 10; j++)
            {
                if (usuarios[i].enderecos[j].id != -1)
                {
                    printf("\nEndereço %d) \tCEP: %s \tBairro: %s \tRua: %s \tNumero: %d", j + 1, usuarios[i].enderecos[j].cep, usuarios[i].enderecos[j].bairro, usuarios[i].enderecos[j].rua, usuarios[i].enderecos[j].numero);
                }
            }
        }
    }
}

void sistemaFuncionario()
{
    int opcao;
    bool continua = true;

    while (continua)
    {
        printf("\n\n============================\n");
        printf("\n(0)-sair");
        printf("\n(1)-Novo ingrediente");
        printf("\n(2)-Adicionar produto");
        printf("\n(3)-Adicionar novo fornecedor");
        printf("\n(4)-Comprar ingredientes");
        printf("\n(5)-Financeiro");
        printf("\n(6)-Stock de ingredientes");
        printf("\n(7)-Dados dos clientes");
        printf("\n\n============================\n\n");
        printf("Escolha uma das opções: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            addingrediente();
            break;
        case 2:
            addprodutos();
            break;
        case 3:
            adicionarFornecedor();
            break;
        case 4:
            encomendarIngrediente();
            break;
        case 5:
            menuFinanceiro();
            break;
        case 6:
            stockIngredientes();
            break;
        case 7:
            dadosClientes();
            break;
        case 0:
            continua = false;
            break;
        default:
            printf("\nDigite uma opção válida!\n");
            break;
        }
    }
}

void login()
{
    char login[20], senha[20];
    bool encontrou = false;
    int i;

    printf("\nDigite o seu login: ");
    scanf("%s", login);
    printf("\nDigite sua senha: ");
    scanf("%s", senha);

    for (i = 0; i < TAMANHO; i++)
    {
        if (strcmp(usuarios[i].login, login) == 0 && strcmp(usuarios[i].senha, senha) == 0 && usuarios[i].id > -1)
        {
            encontrou = true;
            usuarioLogado = i;
            break;
        }
    }

    if (encontrou)
    {
        sistemaClientes();
    }
    else
    {
        printf("\nLogin ou senha incorretos!!!\n");
    }
}

void loginfuncionario()
{

    char senhafuncionario[6] = "admin";
    char senhafuncionario1[6];

    printf("Digite sua senha de funcionário: ");
    scanf("%s", senhafuncionario1);
    if (strcmp(senhafuncionario, senhafuncionario1) == 0)
    {
        sistemaFuncionario();
    }
    else
    {
        printf("\nSenha incorreta");
        bool continua = true;
        int opcao;
        while (continua)
        {
            printf("Deseja tentar novamente?");
            printf("\n\n(1)-Sim");
            printf("\n(2)-Não");
            scanf("%d", &opcao);
            switch (opcao)
            {
            case 1:
                loginfuncionario();
                continua = false;
                break;
            case 2:
                continua = false;
                break;
            default:
                printf("\nDigite uma opção válida!\n");
                break;
            }
        }
    }
}
//------------MENUS-------------------
void subMenuFuncionario()
{
    loginfuncionario();
}

void subMenuCliente()
{
    int opcao;
    bool continua = true;

    while (continua)
    {
        printf("\n==============================\n");
        printf("\nVocê já possui cadastro?");
        printf("\n\n\t(0)-Voltar");
        printf("\n\t(1)-Sim");
        printf("\n\t(2)-Não");
        printf("\n\n============================\n\n");
        printf("Escolha a opção desejada: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            login();
            break;
        case 2:
            cadastroUsuario();
            break;
        case 0:
            continua = false;
            break;
        default:
            printf("\nDigite uma opção válida!\n");
            break;
        }
    }
}

int main()
{
    bool continua = true;
    int opcao;

    

    while (continua)
    {
        printf("\n\n=======MENU PRINCIPAL=======\n");
        printf("\n\t(0)-Sair");
        printf("\n\t(1)-Funcionário");
        printf("\n\t(2)-Cliente");
        printf("\n\n============================\n\n");
        printf("\nEscolha a opção desejada: ");

        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            subMenuFuncionario();
            break;
        case 2:
            subMenuCliente();
            break;
        case 0:
            continua = false;
            break;
        default:
            printf("\nDigite uma opção válida!!\n");
            break;
        }
    }
    return 0;
}

