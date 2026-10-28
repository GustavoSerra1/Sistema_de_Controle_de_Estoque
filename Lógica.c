#include <stdio.h>
#include <string.h>

char nomes[10][50];
float precos[10];
int quantidades[10];
int total = 0;

int cadastrar(char nome[], float preco, int qtd) {
    if (total >= 10 || preco < 0 || qtd < 0) {
        return 0;
    }
    strcpy(nomes[total], nome);
    precos[total] = preco;
    quantidades[total] = qtd;
    total++;
    return 1;
}
void consultar() {
    int i;
    if (total == 0) {
        printf("Nenhum produto cadastrado.\n");
    }
    for (i = 0; i < total; i++) {
        printf("\nCodigo: %d\n", i + 1);
        printf("Nome: %s\n", nomes[i]);
        printf("Preco: R$ %.2f\n", precos[i]);
        printf("Quantidade: %d\n", quantidades[i]);
    }
}
int vender(int codigo, int qtd) {
    codigo--;
    if (codigo < 0 || codigo >= total || qtd <= 0) {
        return 0;
    }
    if (qtd > quantidades[codigo]) {
        return 0;
    }
    quantidades[codigo] = quantidades[codigo] - qtd;
    return 1;
}
float valorVenda(int codigo, int qtd) {
    return precos[codigo - 1] * qtd;
}
void reposicao() {
    int i;
    int encontrou = 0;
    for (i = 0; i < total; i++) {
        if (quantidades[i] < 5) {
            printf("\nProduto: %s\n", nomes[i]);
            printf("Quantidade: %d\n", quantidades[i]);
            encontrou = 1;
        }
    }
    if (encontrou == 0) {
        printf("Nenhum produto precisa de reposicao.\n");
    }
}
int entrada(int codigo, int qtd) {
    codigo--;
    if (codigo < 0 || codigo >= total || qtd <= 0) {
        return 0;
    }
    quantidades[codigo] = quantidades[codigo] + qtd;
    return 1;
}
float valorEstoque() {
    float valor = 0;
    int i;
    for (i = 0; i < total; i++) {
        valor = valor + precos[i] * quantidades[i];
    }
    return valor;
}