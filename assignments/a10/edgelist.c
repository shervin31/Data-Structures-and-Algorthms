 /*
 * Shervin Zare
 * 169064750
 * Assignment 10
 * December 1 2025
 */

#include <stdio.h>
#include <stdlib.h> 
#include "edgelist.h" 


/* Create and return a new edge list graph*/
EDGELIST *new_edgelist(){
    EDGELIST *edge_list = (EDGELIST*) malloc(sizeof(EDGELIST));
    if (edge_list == NULL) {   // always good to check
        printf("Memory allocation failed\n");
        exit(1);
    }

    edge_list->start = NULL;
    edge_list->end = NULL;
    edge_list->size = 0;

    return edge_list;
}

/* Add a new edge at the start of the linked list of edges*/
void insert_edge_start(EDGELIST *g, int from, int to, int weight){
    EDGENODE *edge = (EDGENODE*) malloc(sizeof(EDGENODE));
    if (!edge) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    edge->from = from;
    edge->to = to;
    edge->weight = weight;
    edge->next = NULL;
    
    if (g->size == 0){
        g->start = edge;
        g->end = edge;
        g->size = 1;
    }
    
    else{
        edge->next = g->start;
        g->start = edge;
        g->size++;
    }

}

/* Add an new edge at the end of the linked list of edges */
void insert_edge_end(EDGELIST *g, int from, int to, int weight){
    EDGENODE *edge = (EDGENODE*) malloc(sizeof(EDGENODE));
    if (!edge) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    edge->from = from;
    edge->to = to;
    edge->weight = weight;
    edge->next = NULL;

    if (g->size == 0){
        g->start = edge;
        g->end = edge;
        g->size = 1;
    }
    else{
        g->end->next = edge;
        g->end = edge;
        g->size++;
    }

}

/* Delete edge (from to) from the edgelist */
void delete_edge(EDGELIST *g, int from, int to){
    EDGENODE *curr = g->start;
    EDGENODE *prev = NULL;

    while(curr != NULL){
        if(curr->from == from && curr->to == to){
            // If deleting the first node
            if(curr == g->start){
                g->start = curr->next;
                // If it was also the only node
                if(curr == g->end){
                    g->end = NULL;
                }
                free(curr);
            }
            else {
                prev->next = curr->next;
                // If deleting the last node, update end
                if(curr == g->end){
                    g->end = prev;
                }
                free(curr);
            }
            g->size--;
            break; // exit after deleting the first matching edge
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
}

/* Get the weight of the graph */
int weight_edgelist(EDGELIST *g){
    EDGENODE *curr = g->start;
    int weight = 0;
    while (curr != NULL){
        weight += curr->weight;
        curr = curr->next;
    }

    return weight;
}

/* clean the graph by free all dynamically allocated memory*/
void clean_edgelist(EDGELIST **gp){
    EDGELIST *g = *gp;
    EDGENODE *curr = g->start;
    EDGENODE *temp;

    while (curr != NULL){
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(g);
    *gp = NULL;

}

/* Display edge list graph*/
void display_edgelist(EDGELIST *g) {
    if (g == NULL)
        return;
    printf("size %d ", g->size);
    printf("(from to weight) ");
    EDGENODE *p = g->start;
    while (p) {
        printf("(%d %d %d) ", p->from, p->to, p->weight);
        p = p->next;
    }
}

