 /*
 * Shervin Zare
 * 169064750
 * Assignment 10
 * December 1 2025
 */

 #include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "edgelist.h"
#include "heap.h"

/* --- Helper: add edge to edgelist --- */
static void add_edge(EDGELIST *el, int from, int to, int weight) {
    insert_edge_end(el, from, to, weight);
}

/* --- Prim's MST --- */
EDGELIST *mst_prim(GRAPH *g, int start) {
    int *visited = (int*)calloc(g->order, sizeof(int));
    HEAP *pq = new_heap(g->size * 2);
    EDGELIST *mst = new_edgelist();

    visited[start] = 1;

    ADJNODE *adj = g->nodes[start]->neighbor;
    while (adj) {
        HEAPDATA hd = {adj->weight, adj->nid};
        heap_insert(pq, hd);
        adj = adj->next;
    }

    while (mst->size < g->order - 1 && pq->size > 0) {
        HEAPDATA min = heap_extract_min(pq);
        int to = min.value;
        int weight = min.key;

        if (!visited[to]) {
            add_edge(mst, start, to, weight);
            visited[to] = 1;

            ADJNODE *curr = g->nodes[to]->neighbor;
            while (curr) {
                if (!visited[curr->nid]) {
                    HEAPDATA hd = {curr->weight, curr->nid};
                    heap_insert(pq, hd);
                }
                curr = curr->next;
            }
        }
    }

    free(visited);
    heap_clean(&pq);
    return mst;
}

/* --- Dijkstra's SPT --- */
EDGELIST *spt_dijkstra(GRAPH *g, int start) {
    int *dist = (int*)malloc(sizeof(int) * g->order);
    int *prev = (int*)malloc(sizeof(int) * g->order);
    for (int i = 0; i < g->order; i++) {
        dist[i] = INFINITY;
        prev[i] = -1;
    }
    dist[start] = 0;

    HEAP *pq = new_heap(g->size * 2);
    HEAPDATA hd = {0, start};
    heap_insert(pq, hd);

    while (pq->size > 0) {
        HEAPDATA cur = heap_extract_min(pq);
        int u = cur.value;

        ADJNODE *adj = g->nodes[u]->neighbor;
        while (adj) {
            int v = adj->nid;
            int w = adj->weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                HEAPDATA new_hd = {dist[v], v};
                heap_insert(pq, new_hd);
            }
            adj = adj->next;
        }
    }

    EDGELIST *spt = new_edgelist();
    for (int i = 0; i < g->order; i++) {
        if (prev[i] != -1) {
            add_edge(spt, prev[i], i, dist[i] - dist[prev[i]]);
        }
    }

    free(dist);
    free(prev);
    heap_clean(&pq);
    return spt;
}

/* --- Dijkstra's shortest path --- */
EDGELIST *sp_dijkstra(GRAPH *g, int start, int end) {
    EDGELIST *spt = spt_dijkstra(g, start);
    EDGELIST *path = new_edgelist();
    int stack[g->order];
    int top = -1;
    int cur = end;

    while (cur != start && cur != -1) {
        stack[++top] = cur;
        EDGENODE *e = spt->start;
        while (e) {
            if (e->to == cur) {
                cur = e->from;
                break;
            }
            e = e->next;
        }
        if (!e) break;
    }
    stack[++top] = start;

    for (int i = top; i > 0; i--) {
        add_edge(path, stack[i], stack[i-1], 0); // weight can be updated if needed
    }

    clean_edgelist(&spt);
    return path;
}
