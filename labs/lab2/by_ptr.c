/**
 * -------------------------------------
 * @file  by_ptr.c
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2024-05-04
 *
 * -------------------------------------
 */

 #include <stdio.h>

void fill_values_by_ptr(int *values, int size) {

    for(int i = 0; i < size; i++) {
        *(values + i) = i;
    }
}

void fill_squares_by_ptr(int *values, long int *squares, int size) {

    for (int i = 0; i < size; i++){ 
        *(squares + i) = (*(values + i)) * (*(values + i));
    }
    
}

void print_by_ptr(int *values, long int *squares, int size) {

    for (int i = 0; i < size; i ++){
        int value = *(values + i); 
        int square = value * value;
        printf("Value = %d, Square = %d", value, square);
    }

}
