/*
 * Shervin Zare
 * 169064750
 * Assignment 6
 * October 29 2025
 */
#ifndef STACK_C
#define STACK_C
#include "common.h"

typedef struct stack {
  int length;  
  NODE *top;
} STACK;

/* 
 * Push a node into a linked list stack
 * @param STACK *sp - pointer to the stack 
 * @param NODE *np - pointer to the node.
*/ 
void push(STACK *sp, NODE *np);

/* 
 * Pop and return the pointer of the removed top node
 * @param STACK *sp - pointer to the stack
 * @return - the reference of the removed node and set it's next to NULL  
*/ 
NODE *pop(STACK *sp); 

/*
 * clean the linked list stack
 */ 
void clean_stack(STACK *sp);

#endif