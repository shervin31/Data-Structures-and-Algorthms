#ifndef MYSORT_H
#define MYSORT_H

void select_sort(void *a[], int left, int right);
void quick_sort(void *a[], int left, int right);
void my_sort(void *a[], int left, int right, int (*cmp)(void*, void*));

#endif
