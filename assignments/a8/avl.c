 /*
 * Shervin Zare
 * 169064750
 * Assignment 8
 * November 12 2025
 */

#include "avl.h"
#include "stdio.h"
#include "stdlib.h"
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}


AVLNODE *extract_smallest_node(AVLNODE **rootp){
    AVLNODE *p = *rootp;
    AVLNODE *parent = NULL;
    while (p != NULL){
        parent = p;
        p = p->left;
    }
    if (parent == NULL){
        *rootp = p->right;
    }
    else{
        parent->left = p->right;
    }
    p->left = NULL;
    p->right = NULL;

    return p;

}

 /* Insert a node of given record data into AVL tree.
 *
 * @param rootp - pointer of pointer to tree root.
 * @param data  - record data for the new node.
 */

void avl_insert(AVLNODE **rootp, RECORD data){
    if (*rootp == NULL){
        AVLNODE *np = (AVLNODE*)malloc(sizeof(AVLNODE));
        if (np){
            np->data = data;
            np->height = 1;
            np->left = NULL;
            np->right = NULL;
        }
        *rootp = np;
    }
    else{
        AVLNODE *root = *rootp;
        int comp = strcmp(data.name, root->data.name);
        if (comp < 0){
            avl_insert(&root->left, data);
        }
        else if (comp >0){
            avl_insert(&root->right, data);
        }
        else{
            return;
        }
        root->height = 1 + max(height(root->left), height(root->right));
        int bf = balance_factor(root);
        if (bf == 2 && balance_factor(root->left)>= 0){
            *rootp = rotate_right(root);
        }
        else if (bf == 2 && balance_factor(root->left) < 0){
            root->left = rotate_left(root->left);
            *rootp = rotate_right(root);
        }
        else if(bf == -2 && balance_factor(root->right) <= 0){
            *rootp = rotate_left(root);
        }
        else if (bf == -2 && balance_factor(root->right) > 0){
            *rootp = rotate_right(root->right);
            *rootp = rotate_left(root);
        }

    }

}

/* Delete a node of data.name matched with given key from AVL tree.
 *
 * @param rootp - pointer of pointer to tree root.
 * @param key -   key to match with data.name for deletion.
 */
void avl_delete(AVLNODE **rootp, char *key){
    AVLNODE *root = *rootp;
    AVLNODE *np;
    if (root == NULL){
        return;
    }
    int comp = strcmp(key, root->data.name);
    if (comp == 0){
        if (root->left == NULL && root->right == NULL){
            free(root);
            *rootp = NULL;
        }
        else if(root->left != NULL && root->right == NULL){
            np = root->left;
            free(root);
            *rootp = np;
        }
        else if(root->left == NULL && root->right != NULL){
            np = root->right;
            free(root);
            *rootp = np;
        }
        else if(root->left != NULL  && root->right != NULL){
            np = extract_smallest_node(&root->right);
            np->left = root->left;
            np->right = root->right;
            free(root);
            *rootp = np;
        }
           
    }
    else if(comp < 0){
        avl_delete(&root->left, key);
    }
    else{
        avl_delete(&root->right, key);
    }

    root = *rootp;      //  moving root pointer back to root
    if (root == NULL){
        return;
    }

    root->height = max(height(root->left), height(root->right)) + 1;
    int bf = balance_factor(root);
    if (bf == 2 && balance_factor(root->left) >= 0){
        *rootp = rotate_right(root);
    }
    else if(bf == 2 && balance_factor(root->left) < 0){
        root->left = rotate_left(root->left);
        *rootp = rotate_right(root);
    }
    else if(bf == -2 && balance_factor(root->right) <= 0){
        *rootp = rotate_left(root);
    }
    else if (bf == -2 && balance_factor(root->right) > 0){
        root->right = rotate_right(root->right);
        *rootp = rotate_left(root);

}
}
/* Search AVL tree by key of the name field
 * @param root - pointer to tree root.
 * @param key - key to match with data.name for search
 * @return - node pointer if found, otherwise NULL
 */
AVLNODE *avl_search(AVLNODE *root, char *key){
    
    AVLNODE *curr = root;
    if (curr == NULL){
        return NULL;
    }
    int comp = strcmp(key, root->data.name);
    if (comp == 0){
        return curr;
    }
    else if(comp < 0){
        return avl_search(curr->left, key);
    }
    else{
        return avl_search(curr->right, key);
    }

}

/* This function clean AVL tree.
 * @param rootp - pointer of pointer of tree root.
 */
void avl_clean(AVLNODE **rootp){
    AVLNODE *curr = *rootp;
    if (curr != NULL){
        avl_clean(&curr->left);
        avl_clean(&curr->right);
        free(curr);
    }
    *rootp = NULL;
}

/* Get the height of AVL tree
 * @param np - pointer to the root of tree
 * @return - the the height value at root.
 */
int height(AVLNODE *root){
    int h = 0;
    if (root){
        h = root->height;
    }
    return h;

}
/* Return the balance factor at the given node
 * @param np - pointer to the node of tree
 * @return - the balance factor a the node
 */
int balance_factor(AVLNODE *np){
    int b = 0;
    if (np){
        b = height(np->left) - height(np->right);
    }
    return b;
    
}

/* This function does the left rotation at a given node
 * @param np - pointer to the rotation node.
 * @return - the pointer to the replaced node.
 */
AVLNODE *rotate_left(AVLNODE *np){
    AVLNODE *y = np->right;
    AVLNODE *t2 = y->left;
    y->left = np;
    np->right = t2;

    np->height = max(height(np->left), height(np->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;

}

/* This function does the right rotation at a given node
 * @param np - pointer to the rotation node.
 * @return - the pointer to the replaced node.
 */
AVLNODE *rotate_right(AVLNODE *root){
    AVLNODE *x = root->left;
    AVLNODE *t3 = x->right;
    x->right = root;
    root->left = t3; 

    root->height = max(height(root->left), height(root->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}