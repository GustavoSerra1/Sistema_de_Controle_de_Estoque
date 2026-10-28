#include <stdio.h>

int cadastrar(char nome[], float preco, int qtd);
void consultar();
int vender(int codigo, int qtd);
void reposicao();
int entrada(int codigo, int qtd);
float valorEstoque();
float valorVenda(int codigo, int qtd);

int main() {
    int opcao = 0;
    int codigo, qtd, resultado;
    char nome[50];
    float preco, valor;

    while (opcao != 6) {
        printf("\n=== CONTROLE DE ESTOQUE ===\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Consultar estoque\n");
        printf("3 - Registrar venda\n");
        printf("4 - Ver reposicao\n");
        printf("5 - Entrada de mercadorias\n");
        printf("6 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Nome: ");
            scanf(" %49[^\n]", nome);
            printf("Preco: ");
            scanf("%f", &preco);
            printf("Quantidade: ");
            scanf("%d", &qtd);
            resultado = cadastrar(nome, preco, qtd);
            if (resultado == 1) {
                printf("Produto cadastrado!\n");
            }
            else {
                printf("Erro no cadastro!\n");
            }
        }
        else if (opcao == 2) {
            consultar();
        }
        else if (opcao == 3) {
            printf("Codigo do produto: ");
            scanf("%d", &codigo);
            printf("Quantidade: ");
            scanf("%d", &qtd);
            resultado = vender(codigo, qtd);
            if (resultado == 1) {
                valor = valorVenda(codigo, qtd);
                printf("Venda realizada!\n");
                printf("Total: R$ %.2f\n", valor);
            }
            else {
                printf("Venda nao realizada!\n");
            }
        }
        else if (opcao == 4) {
            reposicao();
        }
        else if (opcao == 5) {
            printf("Codigo do produto: ");
            scanf("%d", &codigo);
            printf("Quantidade recebida: ");
            scanf("%d", &qtd);
            resultado = entrada(codigo, qtd);
            if (resultado == 1) {
                printf("Estoque atualizado!\n");
            }
            else {
                printf("Entrada invalida!\n");
            }
        }
        else if (opcao == 6) {
            printf("\nValor do estoque: R$ %.2f\n", valorEstoque());
            printf("Programa encerrado!\n");
        }
        else {
            printf("Opcao invalida!\n");
        }
    }
    return 0;
}
