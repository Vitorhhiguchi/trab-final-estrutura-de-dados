#include <stdbool.h>

typedef struct Lista{
    int info;
    struct Lista* prox;
} Lista;

// Cria uma lista
Lista* createList();

// Adiciona um elemento na lista
void add(Lista** set, int elem);

// Confere se a lista está vazia
bool isEmpty(Lista* set);

// Retorna o tamanho da lista
int len(Lista* set);

// Retorna T se o elemento estiver no conjunto, retorna F caso não estiver
bool isIn(Lista* set, int elem);

// Retorna T se o elemento nao estiver no conjunto, retorna F caso estiver no conjunto
bool isNotIn(Lista* set, int elem);

// Retorna T se a intersecção entre os conjuntos for vazia, F caso contrario
bool isDisjoint(Lista* set1, Lista* set2);