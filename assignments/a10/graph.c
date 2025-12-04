 /*
 * Shervin Zare
 * 169064750
 * Assignment 10
 * December 1 2025
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_stack.h"
#include "graph.h"

/* create and return a new adjacent list graph of order n */
GRAPH *new_graph(int order) {
  GRAPH *gp = malloc(sizeof(GRAPH));
  gp->nodes = malloc(order * sizeof(GNODE*));
  
  int i;
  for (i = 0; i < order; i++) {
    gp->nodes[i] = malloc(sizeof(GNODE));
    gp->nodes[i]->nid = i;
    strcpy(gp->nodes[i]->name, "null");
    gp->nodes[i]->neighbor = NULL;
  }
  
  gp->order = order;
  gp->size = 0;  
 
  return gp;
}

/* Add edge (from, to, weight) to a graph. If edge (from, to) exists, update its weight by the new weight,
 * This indicates that if (from, to) does not exist, the new edge will be added to the end of the linked list.  
*/
void insert_edge_graph(GRAPH *g, int from, int to, int weight){
    
    GNODE *src = g->nodes[from];
    ADJNODE *curr = src->neighbor;
    ADJNODE *prev = NULL;

    while (curr != NULL){
        if (curr->nid == to){
            curr->weight = weight;
            return;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
    ADJNODE *new = (ADJNODE*)malloc(sizeof(ADJNODE));
    new->next = NULL;
    new->nid = to;
    new->weight = weight;

    if (src->neighbor == NULL){
        src->neighbor = new;
    }
    else{
        prev->next = new;
    }

    g->size ++;

}

/* Delete edge (from, to)*/
void delete_edge_graph(GRAPH *g, int from, int to){
    
}


/* Get and return the weight of edge (from, to) if exists, otherwise return INFINITY*/
int get_edge_weight(GRAPH *g, int from, int to){
    

    
}


/* Travere graph nodes in breadth-first-order using auxiliary queue */
void traverse_bforder(GRAPH *g, int start){
    int visited[g->order];
    for (int i = 0; i < g->order; i++)
        visited[i] = 0;

    QUEUE q = {NULL, NULL};
    enqueue(&q, g->nodes[start]);
    visited[start] = 1;

    while (q.front != NULL){
        GNODE *node = (GNODE*) dequeue(&q);

        printf("(%d %s) ", node->nid, node->name);

        ADJNODE *adj = node->neighbor;
        while (adj != NULL){
            int v = adj->nid;
            if (!visited[v]){
                visited[v] = 1;
                enqueue(&q, g->nodes[v]);
            }
            adj = adj->next;
        }
    }
    clean_queue(&q);
}



/* Traverse graph in depth-first-order using auxiliary stack */
void traverse_dforder(GRAPH *g, int start){
    int visited[g->order];
    for (int i = 0; i < g->order; i++)
        visited[i] = 0;

    STACK st = {NULL};
    push(&st, g->nodes[start]);

    while (st.top != NULL){
        GNODE *node = (GNODE*) pop(&st);

        if (!visited[node->nid]){
            visited[node->nid] = 1;
            printf("(%d %s) ", node->nid, node->name);

            ADJNODE *adj = node->neighbor;

            ADJNODE *rev = NULL;
            while (adj != NULL){
                ADJNODE *next = adj->next;
                adj->next = rev;
                rev = adj;
                adj = next;
            }

            while (rev != NULL){
                if (!visited[rev->nid])
                    push(&st, g->nodes[rev->nid]);
                rev = rev->next;
            }
        }
    }

    clean_stack(&st);
}



void clean_graph(GRAPH **gp) {
  int i;
  GRAPH *g = *gp;
  ADJNODE *temp, *ptr;
  for (i = 0; i < g->order; i++) {
    ptr = g->nodes[i]->neighbor;
    while (ptr != NULL) {
      temp = ptr;
      ptr = ptr->next;
      free(temp);
    }
    free(g->nodes[i]);
  }
  free(g->nodes);
  free(g);
  *gp = NULL;
}

void display_graph(GRAPH *g) {
  if (g ) {
  printf("order %d ", g->order);
  printf("size %d ", g->size);
  printf("(from to weight) ");
  int i;
  ADJNODE *ptr;
  for (i = 0; i < g->order; i++) {
    //printf("\n%d:", g->nodes[i]->nid);
    ptr = g->nodes[i]->neighbor;
    while (ptr != NULL) {
      printf("(%d %d %d) ", i,  ptr->nid, ptr->weight);
      ptr = ptr->next;
    }
  }
  }
}