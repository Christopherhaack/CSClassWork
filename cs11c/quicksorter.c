/* this program implements the quicksort algorithm using
the quicksort algorithm */




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memcheck.h"
#include "linked_list.h"

node *quicksort(node *list);

int main (int argc, char *argv[]) {
    int i;
    int quit;
    node *list = NULL;
    node *sorted_list;
    node *temp;

    for (i = 1; i < argc; i++) {
        if(strcmp(argv[i], "-q") == 0) {
            quit = 1;
        }
        else if(atoi(argv[i]) == 0 && strcmp(argv[i], "0") != 0) {
            fprintf(stderr, "arguments must be numbers or q \n");
        }
        else {
        temp = create_node(atoi(argv[i]), list);
        list = temp;
        }
    }
    sorted_list = quicksort(list);
    free_list(list);

    
    if(quit != 1) {
    print_list(sorted_list);
    }   

    if (is_sorted(list) == 1) {
        free_list(sorted_list);
        print_memory_leaks();
        return 1;
    }
    else{
        free_list(sorted_list);
        print_memory_leaks();
        return 0;
    }
}


node *quicksort(node *list) {
    node *list_copy;
    node *first;
    node *greater_than = NULL;
    node *greater_temp;
    node *less_than = NULL;
    node *less_temp;
    node *temp;
    node *appended_first;
    if(list == NULL || (list -> next) == NULL) {
        list_copy = copy_list(list);
        return list_copy;
    }
    else {
        first = create_node(list -> data, NULL);
    }
    for(temp = list; temp != NULL; temp ++) {
        if ((list -> data) >  (first -> data)) {
        greater_temp = create_node(list -> data, greater_than);
        greater_than = greater_temp;
        }
        else {
        less_temp = create_node(list -> data, less_than);
        less_than = less_temp;
        }
    }
    less_temp = quicksort(less_than);
    free_list(less_than);
    less_than = less_temp;
    greater_temp = quicksort(greater_than);
    free_list(greater_than);
    greater_than = greater_temp;
    appended_first = append_lists(less_than, first);
    list_copy = append_lists(appended_first, greater_than);
    free_list(less_than);
    free_list(appended_first);
    free_list(greater_than);
    free_list(first);
    free_list(temp);
    return list_copy;
}