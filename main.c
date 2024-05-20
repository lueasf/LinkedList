#include "list.h"
#include <stdio.h>

int main(){

    //EX1
    List* liste = create_list(1,create_list(2,create_list(3,NULL)));
    printf("exercice 1: %d\n", value(liste));

    //EX2
    printf("exercice 2: ");
    print_list(liste);

    //EX2
    printf("exercice 2: ");
    printf("range(10) = ");
    List* rnge = range(10);
    print_list(rnge);

    //EX3
    printf("exercice 3: ");
    printf("append = ");
    List* new = append(11, rnge);
    print_list(new);

    //EX4
    printf("exercice 4: ");
    printf("reverse = ");
    List* new2 = reverse(new);
    print_list(new2);

    //EX5
    printf("exercice 5: ");
    printf("map (range(10, carre) = ");
    List* c = map(rnge, carre);
    print_list(c);
    return 0;

}
