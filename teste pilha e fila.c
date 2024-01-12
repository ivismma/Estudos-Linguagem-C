#include <stdio.h>
#include <stdlib.h>

#define Fila Pilha // Mesma estrutura.

typedef struct node{
	int valor;
	struct node *prox;
} Pilha;

Pilha *empilhar(Pilha *topo, int valor);  // pop()
Pilha *desempilhar(Pilha *topo);          // push()

Fila *enfileirar(Fila *topo, int valor);
Fila *liberar(Fila *topo);

void exibirLista(Pilha *topo); // Exibi��o Lista encadeada

int main(void){
	
	Pilha *pilha = NULL;     // LIFO

	printf("Pilha:\n");
	pilha = empilhar(pilha, 3);
	pilha = empilhar(pilha, 5);
	pilha = empilhar(pilha, 10);
	pilha = empilhar(pilha, 4);
	pilha = desempilhar(pilha); // Desempilhar elem. 4.
	exibirLista(pilha);
	
	
	Fila *fila = NULL;        // FIFO
	printf("\n\nFila:\n");
	fila = enfileirar(fila, 5); 
	fila = enfileirar(fila, 3);
	fila = enfileirar(fila, 2);
	fila = enfileirar(fila, 1);
	fila = liberar(fila);       // Liberar elem. 5.
	exibirLista(fila);
	
	return 0;
}

Pilha *empilhar(Pilha *topo, int valor){
	Pilha *novo = (Pilha*) calloc(1,sizeof(Pilha));
	novo->valor = valor;
	
	if(topo == NULL) return novo;
	else{
		Pilha *aux = topo;
		topo = novo;
		novo->prox = aux;
		novo->valor = valor;
		return topo;
	}
}

Pilha *desempilhar(Pilha *topo){
	if(topo == NULL) return NULL;
	else{
		Pilha *novo = topo->prox;
		free(topo);
		topo = novo;
		return topo;
	}
}

Fila *enfileirar(Fila *topo, int valor){
	Fila *novo = (Fila*) calloc(1,sizeof(Fila));
	novo->valor = valor;
	
	if(topo == NULL) return novo;
	else if(topo->prox == NULL){
		topo->prox = novo;
		return topo;
	}
	else{
		Fila *atual = topo;
	
	// Percorre at� o �ltimo n�.
	while(atual->prox != NULL)
		atual = atual->prox;
	
	// Chegou no �ltimo n�.
	atual->prox = novo;
	
	return topo;
	}
}

Fila *liberar(Fila *topo){
	if(topo == NULL) return NULL;
	else{
		Fila *aux = topo->prox;
		free(topo);
		return aux;
	}
}

void exibirLista(Pilha *topo){
	if(topo == NULL) return;
	else{
		Pilha *atual = topo;
		
		while(atual != NULL){
			printf("%d\n", atual->valor);
			atual = atual->prox;
		}
		return;
	}
}