int cmp(void *x, void *y) {
    float a = *(float*)x;
    float b = *(float*)y;
    if (a > b) return 1;
    else if (a < b) return -1;
    else return 0;
}

void swap(void **x, void **y) {
    void *tmp = *x;
    *x = *y;
    *y = tmp;
}

/**
 * Use selection sort algorithm to sort array of pointers such that their pointed values 
 * are in increasing order.
 *
 * @param *a[] - array of void pointers.
 * @param left - the start index of pointer in array.
 * @param right - the end index of pointer in array
 */

void select_sort(void *a[], int left, int right) {
    for (int i = left; i < right; i++) {
        int min_index = i;
        for (int j = i + 1; j <= right; j++) {
            if (cmp(a[j], a[min_index]) < 0) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(&a[i], &a[min_index]);
        }
    }
}


/**
 * Use quick sort algorithm to sort array of pointers such that their pointed values 
 * are in increasing order.
 *
 * @param *a[] - array of void pointers. 
 * @param left - the start index of pointer in array.
 * @param right - the end index of pointer in array
 */
void quick_sort(void *a[], int left, int right){
    if (left < right){ 
        int i = left + 1; 
        int j = right; 
        while(i <= j){
            while(i <= right && cmp(a[i], a[left]) <= 0){ 
                i++;
            }
            while (j >= left && cmp(a[j], a[left]) > 0){
                j --; 
            }
            if (j > i){ 
                swap(&a[i], &a[j]);
            }
        }
        swap(&a[left], &a[j]); 
        quick_sort(a, left, j-1);
        quick_sort(a, j + 1, right);
    }
}

/**
 * Use either selection or quick sort algorithm to sort array of pointers such that their pointed values 
 * are in order defined by the given comparison function
 *
 * @param *a[] - array of void pointers. 
 * @param left - the start index of pointer in array.
 * @param right - the end index of pointer in array
 * @param (*cmp) - pointer to a comparison function used to compaire pointers by their pointed values.
 */
void my_sort(void *a[], int left, int right, int (*cmp)(void*, void*)) {
    if (left < right) {
        int i = left + 1;
        int j = right;
        while (i <= j) {
            while (i <= right && cmp(a[i], a[left]) <= 0) i++;
            while (j >= left && cmp(a[j], a[left]) > 0) j--;
            if (i < j) {
                void *tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
        void *tmp = a[left];
        a[left] = a[j];
        a[j] = tmp;

        my_sort(a, left, j - 1, cmp);
        my_sort(a, j + 1, right, cmp);
    }
}
