 /*
 * Shervin Zare
 * 169064750
 * Assignment 8
 * November 12 2025
 */

#ifndef SET_AVL_H
#define SET_AVL_H

#include "avl.h"

typedef struct {
  int size;
  AVLNODE *root;
} SET;

int set_size(SET *s);
int set_contain(SET *s, char *e); 
void set_add(SET *s, char *e);
void set_remove(SET *s, char *e);
void set_clean(SET *s);

#endif 