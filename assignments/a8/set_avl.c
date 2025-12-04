 /*
 * Shervin Zare
 * 169064750
 * Assignment 8
 * November 12 2025
 */

#include "string.h" 
#include "avl.h"
#include "set_avl.h"

int set_size(SET *s) {
    return s->size;
}

int set_contain(SET *s, char *e){
    AVLNODE *node = avl_search(s->root, e);
    if (node != NULL){
        return 1; 
    }
    else{
        return 0;
    }

}

void set_add(SET *s, char *e){
    RECORD record;
    strcpy(record.name, e);

    if (set_contain(s, e) == 0){
        avl_insert(&s->root, record);
        s->size ++;
    } 

}

void set_remove(SET *s, char *e){
    if (set_contain(s, e) == 1){
        avl_delete(&s->root, e);
        s->size --;
    } 

}

void set_clean(SET *s){
    avl_clean(&s->root);
    s->size = 0;
}   