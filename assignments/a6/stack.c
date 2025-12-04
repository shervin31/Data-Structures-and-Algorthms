/*
 * Shervin Zare
 * 169064750
 * Assignment 6
 * October 29 2025
 */

#include "stack.h"
#include "stdio.h"
#include <stdlib.h>
#include "common.h"
/* 
 * Push a node into a linked list stack
 * @param STACK *sp - pointer to the stack 
 * @param NODE *np - pointer to the node.
*/ 
void push(STACK *sp, NODE *np){
    np->next = sp->top;
    sp->top = np;
    sp->length++;
}

/* 
 * Pop and return the pointer of the removed top node
 * @param STACK *sp - pointer to the stack
 * @return - the reference of the removed node and set it's next to NULL  
*/ 
NODE *pop(STACK *sp){
    
    if (sp->top == NULL){
        return NULL;
    }
    else{
        NODE *top = sp->top;
        sp->top = sp->top->next;
        top->next = NULL;
        sp->length--;
        return top;
    }
}

/*
 * clean the linked list stack
 */ 
void clean_stack(STACK *sp) {
  clean(&(sp->top));
  sp->top = NULL;
  sp->length=0;
}