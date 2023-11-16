#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct ItemCompra {
 char nome[50];
 struct ItemCompra *prox;
};

struct ItemCompra *criarItemCompra(const char *nome) {
 struct ItemCompra *novoItem = (struct ItemCompra *)malloc(sizeof(struct ItemCompra));
 strcpy(novoItem->nome, nome);
 novoItem->prox = NULL;
 return novoItem;
}

void inserirListaOrdenada(struct ItemCompra **head, const char *nome) {
	
 struct ItemCompra *novoItem = criarItemCompra(nome);
 struct ItemCompra *atual = *head;
 struct ItemCompra *anterior = NULL;
 
 while (atual != NULL && strcmp(atual->nome, nome) < 0) {
 anterior = atual;
 atual = atual->prox;
 }
 
 if (anterior == NULL) {
 novoItem->prox = *head;
 *head = novoItem;
 } else {
 	
 anterior->prox = novoItem;
 novoItem->prox = atual;
 }
}

void imprimirLista(struct ItemCompra *head) {
	
 struct ItemCompra *atual = head;
 printf("Lista de compras:\n");
 while (atual != NULL) {
 printf("%s\n", atual->nome);
 atual = atual->prox;
 
	 }
	}

void liberarLista(struct ItemCompra *head) {
	
 struct ItemCompra *atual = head;
 while (atual != NULL) {
 struct ItemCompra *temp = atual;
 atual = atual->prox;
 free(temp);
 }
}

int main() {
	setlocale(LC_ALL, "Portuguese");
 struct ItemCompra *listaCompras = NULL;
 int tamanho; 
 char nome[50];
 int i; 
 
 printf("Informe o número de itens na lista de compras: ");
 scanf("%d", &tamanho);
 
 for (i = 0; i < tamanho; i++) {
	
	 printf("Escreva o nome do item %d: ", i + 1);
	 scanf("%s", nome);
	 inserirListaOrdenada(&listaCompras, nome);
	 }
	
	 
	 imprimirLista(listaCompras);
	 liberarLista(listaCompras);
	 
 return 0;
}
