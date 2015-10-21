#include <stdio.h>
#include "memcheck.h"
#include "linked_list.h"

node *quicksort(node *list);

int main (int argc, int argv[]) {
    int i;
    int quit;
    node *list;
    node *sorted_list;
    node *temp;
    for (i = 1; i < argc; i++) {
        if(strcmp(argv[i], "-q") == 0) {
            quit = 1;
        }
        else if(atoi(argv[i]) == 0 && strcmp(arg[v], i) == 0) {
            fprintf(stderr, "arguments must be numbers or q \n");
        }
        else {
        list = create_node(atoi(argv[i]), temp);
        list = temp;
        }
    }
    sorted_list = quicksort(list);
    free_list(list);
    list = reverse_list(sorted_list);
    print_memory_leaks();
    print_list(list);
    if (is_sorted(list) == 1) {
        free_list(list);
        return 1;
    }
    else{
        free_list(list);
        return 0;
    }
}


node *quicksort(node *list) {
    node *list_copy;
    node *first
    node *greater_temp;
    node *greater_than;
    node *less_temp;
    node *less_than;
    node *temp
    node *appended_first
    int i = 0;
    if(list == NULL || (list -> next) == NULL) {
        list_copy = *copy_list(list);
        return list_copy;
    }
    else {
        first = create_node(list -> data, NULL);
    }
    for(temp = list; temp != NULL; temp ++) {
        if ((list -> data) >  (first -> data)) {
        greater_than = create_node(list -> data, greater_temp);
        greater_than = greater_temp;
        }
        else {
        less_than = create_node(list -> data, less_temp);
        less_than = less_temp;
        }
    }
    less_temp = quicksort(less_than);
    free_list(less_than);
    less_than = less_temp;
    greater_temp = quicksort(greater_than);
    free_list(greater_than);
    greater_than = greater_temp;
    appended_first = append_list(less_than, first);
    list_copy = append_list(appended_first, greater_than);
    free_list(less_than);
    free_list(greater_than);
    free_list(first);
    free_list(temp);
    return list_copy;
}