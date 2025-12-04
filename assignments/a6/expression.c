/*
 * Shervin Zare
 * 169064750
 * Assignment 6
 * October 29 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expression.h"

/* 
 * Convert infix expression string to postfix expression reprsented by queue data structure. 
 * @param infixstr - string of infix expression. 
 * @return - postfix expression in queue of QUEUE type. 
*/
QUEUE infix_to_postfix(char *infixstr){
    char *p = infixstr;
    QUEUE queue = {0};
    STACK stack = {0};
    int sign = 1, num = 0;
    while(*p){
        if (*p == '-' && (p == infixstr || *(p - 1) == '(')){
            sign = -1;
        }
        else if (mytype(*p) == 0){
            num = *p - '0';
            while (*(p + 1) >= '0' && *(p + 1) <= 9){
                num = num * 10 + *(p + 1) - '0';
                p ++;
            }
            enqueue(&queue, new_node(sign * num, 0));
            sign = 1;
        }
        else if (mytype(*p) == 1) {
            while (stack.top != NULL && mytype(stack.top->data) == 1 && priority(stack.top->data) >= priority(*p)){
                enqueue(&queue, pop(&stack));
            }
            push(&stack, new_node(*p, 1));
        }

        else if (mytype(*p) == 2)  {
            push(&stack, new_node(*p, 2));
        }

        else if (mytype(*p) == 3) { //    *p == ‘)‘    
            while(stack.top != NULL && mytype(stack.top->data) != 2){
                enqueue(&queue, pop(&stack));
            }
            if (stack.top != NULL && stack.top->type == 2){
                pop(&stack); 
            }
                } 
    
        p++;
        
        }
    while (stack.top){
        enqueue(&queue, pop(&stack) );  
    } 
        
    return queue;  

    }
     
    
/* 
 * Evaluate and return the value postfix expression passed by queue.
 * @parame queue - postfix expression in queue of QUEUE type.
 ^ @return - value of postfix expression
*/
int evaluate_postfix(QUEUE queue) {
    NODE *curr = queue.front;
    STACK stack = {0};
    int type = 0;
    while(curr != NULL){
        if (curr->type == 0){
            push(&stack, new_node(curr->data, 0));
        }
        else if (curr->type == 1){
            int b = pop(&stack)->data;
            int a = pop(&stack)->data;
            int result;
            switch (curr->data) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                case '%': result = a % b; break;
                default: result = 0; break;
            }
        
            push(&stack, new_node(result, 0));
        }

        curr = curr->next;
        }
    int final = pop(&stack)->data;
    clean_stack(&stack);
    return final;

    }



/* 
 * Evaluate and return the value of infix expression passed by string infixstr, 
 * using infix_to_postfix() and evaluate_postfix() functions.
 * @param infixstr - string of infix expression.  
 * @return - value of the infix expression.
*/
int evaluate_infix(char *infixstr) {
    QUEUE postfix = infix_to_postfix(infixstr);
    int result = evaluate_postfix(postfix);
    clean_queue(&postfix);  // assuming you have a function to free the queue
    return result;
}
