#include <stdio.h>
#include <stdlib.h>

int global_variable1 = 5;
int global_variable2;
int global_variable3 = 15;

void call_stack(int value) {
    if (value == 0) {
        return;
    }
    
    printf("From function, stack address: %p\n", &value);
    call_stack(value - 1);
}

int main() {
    printf("Address of main function: %p\n", main);
    printf("Address of initialized global_variable1: %p\n", &global_variable1);
    printf("Address of uninitialized global_variable2: %p\n", &global_variable2);
    printf("Address of initialized global_variable3: %p\n", &global_variable3);
    printf("\n");

    call_stack(3);
    printf("\n");

    int* heap_variable1 = (int*) malloc(sizeof(int));
    int* heap_variable2 = (int*) malloc(sizeof(int));
    int* heap_variable3 = (int*) malloc(sizeof(int));
    *heap_variable1 = 5;
    *heap_variable2 = 10;
    *heap_variable3 = 15;

    printf("Address of heap_variable1: %p\n", heap_variable1);
    printf("Address of heap_variable2: %p\n", heap_variable2);
    printf("Address of heap_variable3: %p\n", heap_variable3);


    free(heap_variable1);
    free(heap_variable2);
    free(heap_variable3);

    return 0; 
}
