/*
 * Shervin Zare
 * 169064750
 * Assignment 5
 * October 22 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include "dllist.h"

NODE *dll_node(char data) {
    NODE *np = (NODE *) malloc(sizeof(NODE));
    np->data = data;
    np->prev = NULL;
    np->next = NULL;
    return np;
}

void dll_insert_start(DLL *dllp, NODE *np) {
    if (dllp->start == NULL) { 
        // empty list
        dllp->start = np;
        dllp->end = np;
    } 
    else { 
        // insert at beginning
        np->next = dllp->start;
        np->prev = NULL;
        dllp->start->prev = np;
        dllp->start = np;
    }
    dllp->length++;
}

void dll_insert_end(DLL *dllp, NODE *np) {
    if (dllp->end == NULL) { 
        // empty list
        dllp->start = np;
        dllp->end = np;
    } 
    else { 
        // insert at end
        np->prev = dllp->end;
        np->next = NULL;
        dllp->end->next = np;
        dllp->end = np;
    }
    dllp->length++;
}

void dll_delete_start(DLL *dllp) {
    if (dllp->start == NULL) return;  // empty list

    NODE *temp = dllp->start;

    if (dllp->start == dllp->end) {
        // only one node
        dllp->start = NULL;
        dllp->end = NULL;
    } 
    else {
        // remove first node
        dllp->start = dllp->start->next;
        dllp->start->prev = NULL;
    }

    free(temp);
    dllp->length--;
}

void dll_delete_end(DLL *dllp) {
    if (dllp->end == NULL) return; // empty list

    NODE *temp = dllp->end;

    if (dllp->start == dllp->end) {
        // only one node
        dllp->start = NULL;
        dllp->end = NULL;
    } 
    else {
        // remove last node
        dllp->end = dllp->end->prev;
        dllp->end->next = NULL;
    }

    free(temp);
    dllp->length--;
}

void dll_clean(DLL *dllp) {
    NODE *ptr = dllp->start, *temp;
    while (ptr != NULL) {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    dllp->start = NULL;
    dllp->end = NULL;
    dllp->length = 0;
}
