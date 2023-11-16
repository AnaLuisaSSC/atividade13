#include <stdio.h>
#include <stdlib.h>

struct Node {
 int data;
 struct Node *next;
}; 

struct Node *criarNovoNo(int valor) {
 struct Node *novoNo = (struct Node *)malloc(sizeof(struct Node));
 novoNo->data = valor;
 novoNo->next = NULL;
 return novoNo;
 }
 
void inserirListaOrdenada(struct Node **head, int valor) {
 struct Node *novoNo = criarNovoNo(valor);
 struct Node *atual = *head;
 struct Node *anterior = NULL;
 
 while (atual != NULL && atual->data < valor) {
 anterior = atual;
 atual = atual->next;
 }
 
 if (anterior == NULL) {
 novoNo->next = *head;
 *head = novoNo;
 
 } else {
 
 anterior->next = novoNo;
 novoNo->next = atual;
 }
}

void imprimirLista(struct Node *head) {
 struct Node *atual = head;
 while (atual != NULL) {
 printf("%d -> ", atual->data);
 atual = atual->next;
 }
 printf("NULL\n");
}
// Função para liberar a memória alocada para a lista
void liberarLista(struct Node *head) {
 struct Node *atual = head;
 while (atual != NULL) {
 struct Node *temp = atual;
 atual = atual->next;
 free(temp);
 }
}
int main() {
	int i;
	int valor;
 struct Node *lista = NULL;
 int tamanho;
 printf("Digite o tamanho da lista: ");
 scanf("%d", &tamanho);
 for ( i = 0; i < tamanho; i++) {

 printf("Digite o valor %d: ", i + 1);
 scanf("%d", &valor);
 inserirListaOrdenada(&lista, valor);
 }
 printf("Lista ordenada: ");
 imprimirLista(lista);
 
 liberarLista(lista);
 return 0;
}


