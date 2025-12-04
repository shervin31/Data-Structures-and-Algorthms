/*
 * Shervin Zare
 * 169064750
 * Assignment 6
 * October 29 2025
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "common.h"

typedef struct queue {
  int length;  
  NODE *front;
  NODE *rear;
} QUEUE;    

void enqueue(QUEUE *qp, NODE *np);  

NODE *dequeue(QUEUE *qp);

void clean_queue(QUEUE *qp);

#endif