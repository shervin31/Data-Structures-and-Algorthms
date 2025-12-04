#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include "queue_stack.h"

/* Define node structure of a binary tree
 * data - data field of tree node
 * left - pointer to the left child
 * right - pointer to the right child
*/
typedef struct tnode {
    char data;
    struct tnode *left;
    struct tnode *right;
} TNODE;

/* Define a structure to represent tree properties. 
 * order - the number of nodes 
 * height - the height
 */
typedef struct tree_props {
    int order;
    int height;
} TPROPS;


/* Compute and return the TPROPS value of a tree.
 * @param root - pointer to the root of a tree
 * @return - number of nodes and height in TPROPS type.
 */
TPROPS tree_property(TNODE *root){
    
    TPROPS r = {0,0};
    if (root != NULL){
        TPROPS ls = tree_property(root->left);
        TPROPS rs = tree_property(root->right);

        r.order = ls.order + rs.order + 1;
        r.height = (ls.height < rs.height? rs.height: ls.height) + 1;
    }
    return r;

}

/* Display the node data of the tree in pre-order and format "%c ".
 *
 *  @param root - pointer to the root of a tree
 */
void preorder(TNODE *root){

    if (root == NULL){
        return;
    }
    else{       
        printf("%c", root->data); 
        preorder(root->left);
        preorder(root->right);
    }
}

/* Display the node data of the tree in in-order and format "%c".
 *
 *  @param root - pointer to the root of a tree
 */
void inorder(TNODE *root){
    if (root == NULL){
        return;
    }
    else{
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
}

/* Display the node data of the tree in post-order and format "%c ".
 *
 *  @param root - pointer to the root of a tree
 */
void postorder(TNODE *root){
    if (root == NULL){
        return;
    }
    else{
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }

}

/* Display the node data of the tree in breadth-first-order and format "%c ".
 * Required to use auxiliary queue and iterative algorithm.
 *
 *  @param root - pointer to the root of a tree
 */
void bforder(TNODE *root){
    if (root == NULL){
        return;
    }

    QUEUE q = {NULL, NULL};
    enqueue(&q, root);

    while(q.front != NULL){
        TNODE *curr = (TNODE*)dequeue(&q);
        printf("%c", curr->data);

        if (curr->left != NULL){
            enqueue(&q, curr->left);
        }
        if (curr->right != NULL){
            enqueue(&q, curr->right);
        }
    }

    clean_queue(&q);

}

/* Search by key using breadth-first-search algorithm
 * Required to use auxiliary queue and iterative algorithm.
 *
 *  @param root - pointer to the root of a tree
 *  @param key -  search key
 *
 *  @return  - the found node pointer if fount, otherwise NULL
 */
TNODE *bfs(TNODE *root, char key){
    if (root == NULL){
        return NULL;
    }

    QUEUE q = {NULL, NULL};
    enqueue(&q, root);

    while(q.front != NULL){
        TNODE *curr = (TNODE*) dequeue(&q);
        if (curr->data == key){
            clean_queue(&q);
            return curr;
        }
        else{
            if (curr->left != NULL){
                enqueue(&q,curr);
            }
            if (curr->right != NULL){
                enqueue(&q, curr);
            }
        }
    }
    clean_queue(&q);
}


/* Search by key using depth-first-search algorithm.
 * Required to use auxiliary queue and iterative algorithm.
 *
 *  @param root - pointer to the root of a tree
 *  @param key -  search key
 *
 *  @return  - the found node pointer if fount, otherwise NULL
 */
TNODE *dfs(TNODE *root, char key){
    if (root == NULL){
        return NULL;
    }
    
    STACK *s = NULL;
    push(&s, root);
    while (s != NULL){
        TNODE *curr = pop(&s);
        if (curr->data == key){
            clean_stack(&s);
            return curr;
        }
        else{
            if (curr->right != NULL){
                push(&s, curr->right);
                
            }
            if (curr->left != NULL){
                push(&s, curr->left);
                
            }

        }
    }
    clean_stack(&s);
    return NULL;

}


TNODE *tree_node(char val) {
    TNODE *np = (TNODE *) malloc(sizeof(TNODE));
    if (np != NULL) {
        np->data = val;
        np->left = NULL;
        np->right = NULL;
    }
    return np;
}

void clean_tree(TNODE **rootp) {
    TNODE *p = *rootp;
    if (p) {
        if (p->left)
            clean_tree(&p->left);
        if (p->right)
            clean_tree(&p->right);
        free(p);
    }
    *rootp = NULL;
}

void insert_tree(TNODE **rootp, char val) {
    if (*rootp == NULL) {
        *rootp = tree_node(val);
    } else {
        QUEUE queue = { 0 };
        TNODE *p;
        enqueue(&queue, *rootp);
        while (queue.front) {
            p = dequeue(&queue);
            if (p->left == NULL) {
                p->left = tree_node(val);
                break;
            } else {
                enqueue(&queue, p->left);
            }

            if (p->right == NULL) {
                p->right = tree_node(val);
                break;
            } else {
                enqueue(&queue, p->right);
            }
        }
    }
}