#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "set.h"

Lista* createList(){
    return NULL;
}

void add(Lista** set, int elem){
    Lista* novo = (Lista*) malloc(sizeof(Lista));

    novo->info = elem;
    novo->prox = *set;
    *set = novo;
}

bool isEmpty(Lista* set){
    return (set != NULL);
}

// int len(Lista* set){
//     int count = 0;

//     while(set != NULL){
//         printf("%d \n", set->info);
//         if(set->info != set->prox->info){
//             set = set->prox;
//             count++;
//         } else{
//             set = set->prox;
//             set = set->prox;

//             count++;
//         }
//     }

//     return count;
// }

int len(Lista* set) { 
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    int count = 0; 
    int seen[1000] = {0}; 
    while (set != NULL) { 
        novo->info = set->info;

        if (!seen[novo->info]) { 
            printf("%d \n", novo->info); 
            seen[novo->info] = 1; 
            count++; 
        } 
        novo = novo->prox;
        set = set->prox;
    } 
    return count; 
}

bool isIn(Lista* set, int elem){
    while(set != NULL){
        if(set->info == elem){
            return true;
        }
        set = set->prox;
    }
    return false;
}

bool isNotIn(Lista* set, int elem){
    while(set != NULL){
        if(set->info == elem){
            return false;
        }
        set = set->prox;
    }
    return true;
}

bool isDisjoint(Lista* set1, Lista* set2){
    Lista* ptr1 = set1;
    Lista* ptr2;

    while(ptr1 != NULL){
        ptr2 = set2;
        while(ptr2 != NULL){
            if(ptr1->info == ptr2->info){
                return false;
            }
            ptr2 = ptr2->prox;
        }
        ptr1 = ptr1->prox;
    }

    return true;
}