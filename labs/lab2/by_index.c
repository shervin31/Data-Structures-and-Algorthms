/**
 * -------------------------------------
 * @file  by_index.c
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2024-05-04
 *
 * -------------------------------------
 */
#include "by_index.h"
#include <stdio.h>

void fill_values_by_index(int values[], int size) {

    for(int i = 0; i < size; i++) {
        values[i] = i + 1;
    }
}

void fill_squares_by_index(int values[], long int squares[], int size) {
    for (int i = 0; i < size; i++){ 
        squares[i] = values[i] * values[i];
    }
}

void print_by_index(int values[], long int squares[], int size) {
    for (int i = 0; i < size; i++){
        printf("%d",squares[i]);

    }

}
