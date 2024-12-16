#include "bst.h"

#include <stdlib.h>
#include <string.h>

// TODO---->

BSTNode_t* createNode(void *data, int numBytes, compare_func_t comp, print_func_t print_func)
{
    BSTNode_t *node = calloc(1, sizeof(BSTNode_t));
    if(node == NULL)
        return 0;

    node->data = calloc(numBytes, 1);
    if(node->data == NULL) {
        free(node);
        return 0;
    }

    // Baumknoten füllen
    memcpy(node->data, data, numBytes);
    node->compare_func = comp;
    node->print_func = print_func;

    return node;
}

BSTNode_t* insert(BSTNode_t *root, void* data, int numBytes, compare_func_t comp, print_func_t print_func)
{
    // Fall 1: Baum ist leer
    if(root == 0)
    {
        root = createNode(data, numBytes, comp, print_func);
        return root;
    }

    if(comp(data, root->data) < 0)
    {
        // links einfügen
        root->left = insert(root->left, data, numBytes, comp, print_func);
    }
    else
    {
        // rechts einfügen
        root->right = insert(root->right, data, numBytes, comp, print_func);
    }
    return root;
}

void inorderTraversal(const BSTNode_t *root)
{
    if(root != 0) {
        inorderTraversal(root->left);
        root->print_func(root->data);
        inorderTraversal(root->right);
    }
}

void freeNode(BSTNode_t** node)
{
    if(*node != 0)
    {
        free((*node)->data);
        free(*node);
        *node = 0;
    }
}

void freeBST(BSTNode_t** root)
{
    if(*root != 0) {
        freeBST(&(*root)->left);
        freeBST(&(*root)->right);
        freeNode(root);
    }
}


// <----TODO
