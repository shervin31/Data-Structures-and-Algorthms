 /*
 * Shervin Zare
 * 169064750
 * Assignment 10
 * December 1 2025
 */

#ifndef EDGELIST_H
#define EDGELIST_H

// edgenode is a single edge in a linked list of edges (edgelist)
typedef struct edgenode {
  int from; // the starting node
  int to;   // the node it goes to 
  int weight;   // weight of edge 
  struct edgenode *next;  // pointer to the next edgenode in linked list of edges (edgelist)
} EDGENODE;

// linked list of edges 
typedef struct edgelist { 
  int size;    // size of edgelist 
  EDGENODE *start;  // first node in linked list of edge nodes 
  EDGENODE *end;    // last node in linked list of edge nodes 
} EDGELIST;

EDGELIST *new_edgelist();

void insert_edge_start(EDGELIST *g, int from, int to, int weight);

void insert_edge_end(EDGELIST *g, int from, int to, int weight);

void delete_edge(EDGELIST *g, int from, int to);

int weight_edgelist(EDGELIST *g);

void clean_edgelist(EDGELIST **gp);

void display_edgelist(EDGELIST *g);

#endif