/*
 * Shervin Zare
 * 169064750
 * Assignment 6
 * October 29 2025
 */

#include "queue.h"
#include "stdio.h"


/* 
 * Enqueue a node into a queue
 * @param *qp - pointer to the queue 
 * @param NODE *np - pointer to the node.
*/
void enqueue(QUEUE *qp, NODE *np){
    if (qp->rear == NULL && qp->front == NULL){
        qp->front = np;
        qp->rear = np;
    }
    else{
        qp->rear->next = np;
        qp->rear = np;
    }
    qp->length ++;
}

/* 
 * Dequeue and return the pointer of the removed node. 
 * @param *qp - pointer to the queue
 * @return - the reference of the removed node, and set it's next to NULL 
*/
NODE *dequeue(QUEUE *qp){
    if (qp->length == 0){
        return NULL;
    }
    NODE *temp  = qp->front;
    qp->front = qp->front->next;
    if (qp->front == NULL){
        qp->rear = NULL;
    }
    temp->next = NULL;   

    qp->length --;
    
    return temp;
}

/* 
 * Clean the linked list queue
 * @param *qp - pointer to the queue
*/
void clean_queue(QUEUE *qp) {
  clean(&(qp->front));
  qp->front = NULL;
  qp->rear = NULL;
  qp->length=0;
}