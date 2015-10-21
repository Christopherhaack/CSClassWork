/* this function takes in a list of numbers and sorts them from 
least to greatest. the function uses a minimal element sort unless
the user specifies -b for bubblesort. If the user wants nothing to occur
they can enter -q */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAXCHARACTERS 32

void minimalElementSort(int a[], int length);
void bubbleSort(int b[], int length);

int main (int argc, char *argv[]) { 
    int i;
    int choice = 0;
    int quit = 0;
    int counter =0;
    int arr[MAXCHARACTERS];
    for (i = 1; i < argc; i++) {
        if(strcmp(argv[i], "-b") == 0) {
            choice = 1;
        }
        else if(strcmp(argv[i], "-q") == 0) {
            quit = 1;
        }
        else {
            if (counter >= MAXCHARACTERS) {
                printf("(maximum 32 numbers) usage error");
                return 1;
            }
            arr[counter] = atoi(argv[i]); 
            counter ++;
               
            
        }
    }
    if (counter == 0) {
        printf("usage error");
        return 1;
    }
    if (choice == 0) {
        minimalElementSort(arr, counter); 
    }
    else if (choice == 1) {
        bubbleSort(arr, counter);
    }
    if (quit != 1) {
        for (i = 0; i < counter; i++) {
            printf("%d\n", arr[i]);
    }
}
    return 0;
}
/* uses a bubbleSort algorithm to sort the elements of an input
array */
void bubbleSort(int arr[], int length) {
    int i;

    int remaining;
    int temp;
    for (remaining = length; remaining > 0; remaining--) {
        for (i =0; i < remaining - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
            
    }
     
}

/* uses a minimalElementSort to sort the element of an array */
void minimalElementSort(int arr[], int length) {
    int i;
    int start = 0;
    int smallest = start;
    int temp = 0;
    while (start < length) {
        for (i = start; i < length; i++) {
            if (arr[i] < arr[smallest]) {
                smallest = i;
            }
        }
        temp = arr[start];
        arr[start] = arr[smallest];
        arr[smallest] = temp;
        start ++;
        smallest = start;
    }
     
}


