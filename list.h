#include <stdio.h>
#include <stdlib.h>

struct List{
    int value;
    struct List * next;
};

typedef struct List List;

List *create_list(int value, List *next);

int value(List *list);

List *next(List *list);

void print_list(List* list);

List *range(int n);

List * append(int val, List* list);

List *reverse(List *list);

List *map(List *list, int (*f)(int));

int carre(int x);
