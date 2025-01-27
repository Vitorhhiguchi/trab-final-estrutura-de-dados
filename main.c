#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "set.h"

int main(){
    Lista* lista;

    lista = createList();
    add(&lista, 25);
    add(&lista, 25);
    add(&lista, 50);
    add(&lista, 50);
    add(&lista, 51);
    add(&lista, 51);
    add(&lista, 51);


    if(lista == NULL){
        printf("Lista criada com sucesso! Ponteiro: %p\n", lista);
    }else {
        printf("Erro ao criar lista.\n");
    }

    Lista* atual = lista; 
    while (atual != NULL) { 
        printf("%d ", atual->info); 
        atual = atual->prox; 
    }

    printf("\n");

    if(isEmpty(lista)){
        printf("Lista nao esta vazia!\n");
    }else{
        printf("Lista esta vazia!\n");
    }

    int tamDaLista = len(lista);

    printf("Tamanho da lista: %d\n", tamDaLista);

    bool encontrado = isIn(lista, 25);

    printf("Resultado da verificacao na lista: %s\n", encontrado ? "true" : "false");

    if (encontrado) { 
        printf("O numero esta na lista!\n"); 
    } else { 
        printf("O numero NAO esta na lista!\n"); 
    }

    encontrado = isIn(lista, 123);

    printf("Resultado da verificacao na lista: %s\n", encontrado ? "true" : "false");

    if (encontrado) { 
        printf("O numero esta na lista!\n"); 
    } else { 
        printf("O numero NAO esta na lista!\n"); 
    }

    printf("\n\n");

    bool naoEstaNaLista = isNotIn(lista, 2);

    printf("Resultado da verificacao na lista: %s\n", naoEstaNaLista ? "true" : "false");

    if (naoEstaNaLista) { 
        printf("O numero NAO esta na lista!\n"); 
    } else { 
        printf("O numero esta na lista!\n"); 
    }

    naoEstaNaLista = isNotIn(lista, 51);

    printf("Resultado da verificacao na lista: %s\n", naoEstaNaLista ? "true" : "false");

    if (naoEstaNaLista) { 
        printf("O numero NAO esta na lista!\n"); 
    } else { 
        printf("O numero esta na lista!\n"); 
    }

    printf("\n\n");

    Lista* lista2;

    lista2 = createList();

    add(&lista2, 25);
    add(&lista2, 25);
    add(&lista2, 50);
    add(&lista2, 50);
    add(&lista2, 51);
    add(&lista2, 51);
    add(&lista2, 51);

    bool resultadoIntersec = isDisjoint(lista, lista2);

    if (resultadoIntersec) { 
        printf("Nao ha numeros em comum entre as listas passadas!\n"); 
    } else { 
        printf("Ha numeros em comum entre as listas passadas!\n"); 
    }

    return 0;
}