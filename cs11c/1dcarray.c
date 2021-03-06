/* this program takes two arguments the number of cells and generations
 to calculate for and creates a 1d cellular automata using arrays */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "memcheck.h"


int* initialize(int length);
int* update(int* cells, int length);
void print_automata(int* automata, int length);



int main(int argc, char *argv[]) {
    int i;
    int generations;
    int numberofCells;
    int* seed;
    if (argc != 3) {
            fprintf(stderr, "invalid arguments, please input"
                "the number of cells followed by"
                "the number of generations which the program takes in."
                "\n");
            exit(1);
        }
    numberofCells = atoi(argv[1]);
    generations = atoi(argv[2]);
    seed = initialize(numberofCells);
    print_automata(seed, numberofCells);
    for (i = 0; i < generations; i++) {
        seed = update(seed, numberofCells);
        print_automata(seed, numberofCells);
    } 
    free(seed);
    
    print_memory_leaks();
    return 0;
}

/* initialize the seed array and returns it */

int* initialize(int length) {
    int* seed;
    int i;
    srand(time(NULL));
    seed = (int *) calloc(length, sizeof(int));
    if (seed == NULL)
{
        fprintf(stderr, "Error! Memory allocation failed!\n");
        exit(1);  /* abort the program */
}   
    for (i = 1; i < length - 1; i++) {
        
        seed[i] = rand() % 2;
    }
    return seed;
}

/* updates the seed array and returns the new updated array */

int* update(int* cells, int length) {
    int* new;
    int i;
    new = (int *) calloc(length, sizeof(int));
    if (new == NULL)
{
        fprintf(stderr, "Error! Memory allocation failed!\n");
        exit(1);  /* abort the program */
}   
    for (i = 1; i < length - 1; i++) {
        if (cells[i] == 1) {
            new[i] = 0;
        }
        else if (cells[i -1] == cells[i + 1]) {
            new[i] = 0;
        }
        else {
            new[i] = 1;
        }
    }
    free(cells);
    return new;
}

/* prints a 1dCellular automata */

void print_automata(int* automata, int length) {
    int i;
    for (i = 0; i < length; i++) {
        if (automata[i] == 0) {
            printf(".");    
        }
        else {
            printf("*");
        }
        if (i == length - 1) {
            printf("\n");
        }
    
    }
}
