/*
 * Shervin Zare
 * 169064750
 * Assignment 5
 * October 22 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myrecord_sllist.h"

NODE *sll_search(SLL *sllp, char *name) {
    NODE *np = sllp->start;
    while (np != NULL) {
        if (strcmp(np->data.name, name) == 0) {
            return np;   // found
        }
        np = np->next;
    }
    return NULL; // not found
}

void sll_insert(SLL *sllp, char *name, float score) {
    NODE *np = (NODE *) malloc(sizeof(NODE));
    strcpy(np->data.name, name);
    np->data.score = score;
    np->next = NULL;

    NODE *prev = NULL, *p = sllp->start;

    // find lexicographical insert position
    while (p != NULL && strcmp(p->data.name, name) < 0) {
        prev = p;
        p = p->next;
    }

    // insert at start
    if (prev == NULL) {
        np->next = sllp->start;
        sllp->start = np;
    } 
    else { // insert in middle or end
        prev->next = np;
        np->next = p;
    }

    sllp->length++;
}

int sll_delete(SLL *sllp, char *name) {
    NODE *prev = NULL, *p = sllp->start;

    // search for the node
    while (p != NULL && strcmp(p->data.name, name) != 0) {
        prev = p;
        p = p->next;
    }

    if (p == NULL) {
        return 0; // not found
    }

    // delete at start
    if (prev == NULL) {
        sllp->start = p->next;
    } 
    else { // delete in middle or end
        prev->next = p->next;
    }

    free(p);
    sllp->length--;
    return 1;
}

void sll_clean(SLL *sllp) {
    NODE *temp, *ptr = sllp->start;
    while (ptr != NULL) {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    sllp->start = NULL;
    sllp->length = 0;
}
