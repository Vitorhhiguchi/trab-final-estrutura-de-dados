#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "set.h"

int main() {
    // Inicializando os conjuntos
    Lista* set1 = createList();
    Lista* set2 = createList();

    add(&set1, 1);
    add(&set1, 2);
    add(&set1, 3);

    add(&set2, 3);
    add(&set2, 4);
    add(&set2, 5);

    printf("Set 1:\n");
    printSet(set1);
    printf("\n");

    printf("Set 2:\n");
    printSet(set2);
    printf("\n");

    // Testando unionSet
    Lista* unionResult = unionSet(set1, set2);
    printf("Uniao de Set 1 e Set 2:\n");
    printSet(unionResult);
    printf("\n");

    // Testando intersection
    Lista* intersectionResult = intersection(set1, set2);
    printf("Intersecao de Set 1 e Set 2:\n");
    printSet(intersectionResult);
    printf("\n");

    // Testando difference
    Lista* differenceResult = difference(set1, set2);
    printf("Diferenca de Set 1 e Set 2:\n");
    printSet(differenceResult);
    printf("\n");

    // Testando symmetric_difference
    Lista* symmetricDifferenceResult = symmetric_difference(set1, set2);
    printf("Diferenca simetrica de Set 1 e Set 2:\n");
    printSet(symmetricDifferenceResult);
    printf("\n");

    // Testando isSubSet
    printf("Set 1 eh um subconjunto de Set 2? %s\n", isSubSet(set1, set2) ? "Sim" : "Nao");

    // Testando isSuperSet
    printf("Set 2 eh um superconjunto de Set 1? %s\n", isSuperSet(set2, set1) ? "Sim" : "Nao");

    // Testando copy
    Lista* copiedSet;
    copy(set2, &copiedSet);
    printf("Copia de Set 2:\n");
    printSet(copiedSet);
    printf("\n");

    // Testando pop
    Lista* elem_pop = pop(&set1);
    if (elem_pop != NULL) {
        printf("Elemento removido de Set 1: %d\n", elem_pop->info);
        free(elem_pop); // Lembre-se de liberar a memória do nó removido
    } else {
        printf("Set 1 esta vazio, nenhum elemento removido.\n");
    }
    printf("Set 1 apos pop:\n");
    printSet(set1);
    printf("\n");

    // Re-adicionando elementos para testar isDisjoint
    add(&set1, 6);
    add(&set1, 7);

    // Testando isDisjoint
    printf("Set 1 e Set 2 sao disjuntos? %s\n", isDisjoint(set1, set2) ? "Sim" : "Nao");

    // Liberando memória
    clearSet(set1);
    clearSet(set2);
    clearSet(unionResult);
    clearSet(intersectionResult);
    clearSet(differenceResult);
    clearSet(symmetricDifferenceResult);
    clearSet(copiedSet);

    return 0;
}
