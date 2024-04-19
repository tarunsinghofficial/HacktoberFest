#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[30];
  int codigo_produto;
  int quantidade_disponivel;
  int n_vendas;
  int n_compras;
  float preco;
  int status;
} Produto;

void inserir(Produto produtos[], int *n_produtos) {
  // inserindo o nome, codigo, preço e quantidade

  int codigo;
  printf("Digite o nome do produto e o código: ");
  scanf("%s %i", produtos[*n_produtos].nome, &codigo);

  getchar();

  printf("\nDigite a quantidade disponivel: ");
  scanf("%i", &produtos[*n_produtos].quantidade_disponivel);

  getchar();

  printf("\nDigite o preço do %s: ", produtos[*n_produtos].nome);
  scanf("%f", &produtos[*n_produtos].preco);

  produtos[*n_produtos].codigo_produto = codigo;

  produtos[*n_produtos].status = 1;
  (*n_produtos)++;
}

int remover(Produto produtos[], int n_produtos, char nome[]) {
  int res = buscar(produtos, n_produtos, nome);
  if (res == -1) {
    printf("O produto que vc deseja remover nao existe!\n");
  } else {
    produtos[res].status = 0;
    printf("%s Removido com sucesso!!", nome);
  }
}

int buscar(Produto produtos[], int n_produtos, char nome[]) {
  for (int i = 0; i < n_produtos; i++) {
    if (strcmp(produtos[i].nome, nome) == 0) {
      return i;
    }
  }

  return -1;
}

int comprar(Produto produtos[], int n_produtos, int codigo_produto) {
  for (int i = 0; i < n_produtos; i++) {
    if (produtos[i].codigo_produto == codigo_produto) {
      produtos[i].quantidade_disponivel++;
      produtos[i].n_compras++;
      printf("Nova quantidade disponivel: %d",
             produtos[i].quantidade_disponivel);
      return 1;
    }
  }
  return 0;
}

void imprimir(Produto produtos[], int n_produtos) {
  for (int i = 0; i < n_produtos; i++) {
    printf("\n\n %s codigo %i vendas %i compras %i qtd %i", produtos[i].nome,
           produtos[i].codigo_produto, produtos[i].n_vendas,
           produtos[i].n_compras, produtos[i].quantidade_disponivel);
  }
}

int vender(Produto produtos[], int n_produtos, int codigo_produto) {
  for (int i = 0; i <= n_produtos; i++) {
    if (produtos[i].codigo_produto == codigo_produto) {
      if (produtos[i].quantidade_disponivel > 0) {
        produtos[i].quantidade_disponivel--;
        produtos[i].n_vendas++;
        printf("Nova quantidade disponivel: %d",
               produtos[i].quantidade_disponivel);
        return 1;
      }
    }
  }
  return 0;
}

int estoque(Produto produtos[], int n_produtos) {
  for (int i = 0; i < n_produtos; i++) {
    if (produtos[i].status == 1) {
      printf("%i unidades de %s \n", produtos[i].quantidade_disponivel,
             produtos[i].nome);
    }
  }
}

// ** Lista ordenada dos produtos mais vendidos **
void lista_vendidos(Produto produtos[], int n_produtos) {

  Produto temp;

  Produto produtos_ordenados[n_produtos];
  // Copia a lista de produtos para a lista em que vai ser ordenado
  for (int i = 0; i < n_produtos; i++) {
    produtos_ordenados[i] = produtos[i];
  }

  for (int u = 0; u < n_produtos - 1; u++) {
    for (int j = 0; j < n_produtos - 1 - u; j++) {
      if (produtos[j].n_vendas > produtos[j + 1].n_vendas) {
        temp = produtos_ordenados[j];
        produtos_ordenados[j] = produtos_ordenados[j + 1];
        produtos_ordenados[j + 1] = temp;
      }
    }
  }

  printf("\n\n lista vendas:");
  for (int i = n_produtos - 1; i >= 0; i--) {
    printf("\n %s - %i", produtos_ordenados[i].nome,
           produtos_ordenados[i].n_vendas);
  }
}

void lista_compras(Produto produtos[], int n_produtos) {

  Produto temp;

  Produto produtos_ordenados[n_produtos];
  // Copia a lista de produtos para a lista em que vai ser ordenado
  for (int i = 0; i < n_produtos; i++) {
    produtos_ordenados[i] = produtos[i];
  }

  for (int u = 0; u < n_produtos - 1; u++) {
    for (int j = 0; j < n_produtos - 1 - u; j++) {
      if (produtos[j].n_compras > produtos[j + 1].n_compras) {
        temp = produtos_ordenados[j];
        produtos_ordenados[j] = produtos_ordenados[j + 1];
        produtos_ordenados[j + 1] = temp;
      }
    }
  }

  printf("\n\n lista compras:");
  for (int i = n_produtos - 1; i >= 0; i--) {
    printf("\n %s - %i", produtos_ordenados[i].nome,
           produtos_ordenados[i].n_compras);
  }
}

void extrato(Produto produtos[], int n_produtos) {
  printf("\nNome - vendas - preço - total:\n");
  for (int i = 0; i < n_produtos; i++) {
    printf("\n%s - %i - %f - %f ", produtos[i].nome, produtos[i].n_vendas,
           produtos[i].preco, produtos[i].preco * produtos[i].n_vendas);
  }
}

int main(void) {
  Produto produtos[100];
  int n_produtos = 0;

  do {
    imprimir(produtos, n_produtos);

    printf("\n\n**PADARIA**\n\n");
    printf("(1) Inserir\n(2) Remover\n(3) Buscar\n(4) Comprar\n(5) Vender\n(6) "
           "Estoque\n(7) Lista ordenada vendas\n(8) Lista ordenada "
           "compras\n(9) Extrato\n");

    int escolha;
    printf("Digite o que deseja fazer > ");
    scanf("%i", &escolha);
    getchar();

    switch (escolha) {
    case 1:
      inserir(produtos, &n_produtos);
      break;

    case 2:

      printf("Qual produto deseja remover: ");
      char nome[30];
      scanf("%s", nome);

      remover(produtos, n_produtos, nome);

      break;

    case 3:
      printf("Qual produto deseja buscar? ");

      scanf("%s", nome);
      getchar();

      int possui = buscar(produtos, n_produtos, nome);

      if (possui == -1) {
        printf("%s não está cadastrado no sistema\n", nome);
      } else {
        printf("%s está no sistema \n", nome);
      }
      break;

    case 4:
      printf("Digite o codigo do produto que deseja comprar:");
      int codigo;
      scanf("%d", &codigo);
      int existe = comprar(produtos, n_produtos, codigo);
      break;

    case 5:
      printf("Digite o codigo do produto que deseja vender:");

      scanf("%d", &codigo);
      existe = vender(produtos, n_produtos, codigo);
      break;

    case 6:
      estoque(produtos, n_produtos);
      break;

    case 7:
      lista_vendidos(produtos, n_produtos);
      break;

    case 8:
      lista_compras(produtos, n_produtos);
      break;

    case 9:
      extrato(produtos, n_produtos);
      break;
    }

    getchar();
    system("clear");

  } while (1);

  return 0;
}
