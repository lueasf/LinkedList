#include <stdlib.h>
#include "list.h"
#include <assert.h>


List *create_list(int value, List *next){
    List* liste = (List*)malloc(sizeof(List*));
    liste->value = value;
    liste->next = next;
    return liste;
}

int value(List *list){
    return list->value;
}

List *next(List *list){
    assert(list != NULL);
    return list->next;
}

void print_list(List* list){
    printf("[");
    while (next(list) != NULL){
        printf("%d,", value(list));
        list = list->next;
    }
    printf("%d", value(list));
    printf("]\n");
}

List *range(int n){
    List* liste = create_list(1, NULL);
    List* copie = liste;
    for (int i = 2; i<= n ; i++){
        liste->next = create_list(i, NULL);
        liste = liste->next;
    }
    return copie;
}



List * append(int val, List* list){
    // cas liste vide:
    if (list == NULL){
        List* uno = create_list(val, NULL);
        return uno;
    }
    List* copie = list;
    List* copie2 = copie; // pointeur vers le haut de la liste chaînée
    while (next(copie) != NULL){
        copie = copie->next;
    }
    copie->next = create_list(val, NULL);
    return copie2;
}

/* AUTRE MANIÈRE : 
List *range(int n){
    List* nb =  NULL;
    for (int i = n; i > 0; i --){
        nb = create_list(i, nb);
    }
    return nb;
}



List* append(int val, List *list){
    // on regarde si la liste est vide
    if (list == NULL){
        List * tmp = create_list(val, NULL);
        return tmp;
    }
    // on fait une coie de la première val de list
    List* copie = create_list(value(list), NULL);
    // on crée un pointeur vers le haut pour renvoyer la liste
    List* copie2 = copie;
    list = list->next;
    while (list != NULL){
        copie->next = create_list(value(list), NULL);
        list = list->next;
        copie = copie->next;
    }
    copie->next = create_list(val, NULL);
    return copie2;
}

*/


List *reverse(List *list){
    if (list == NULL){
        return list;
    }
    List* copie = create_list(value(list), NULL);
    list = list->next;
    while( list !=  NULL){
        copie = create_list(value(list), copie);
        list = list->next;
    }
    return copie;
}

List *map(List *list, int (*f)(int)){
    if (list == NULL){
        return list;
    }
    List* new = create_list(f(value(list)), NULL);
    List* copie = new; // pointeur sur le haut de la liste chaînée
    list = list->next;
    while (next(list) != NULL){
        new->next = create_list(f(value(list)), NULL);
        list = list->next;
        new = new->next;
    }
    return copie;
}

int carre(int x){
    return (x*x);
}
