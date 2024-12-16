#ifndef INFO2_LECTURE_BST_H
#define INFO2_LECTURE_BST_H

#include <stdio.h>
#include <stdlib.h>

// TODO---->
typedef int (*compare_func_t) (const void* a, const void* b);
typedef void (*print_func_t) (const void* a);


typedef struct BSTNode
{
    void *data;
    compare_func_t compare_func;
    print_func_t print_func;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode_t;

// Erstelle einen neuen Baumknoten mit dem übergebenen Wert.
BSTNode_t* createNode(void *data, int numBytes, compare_func_t comp, print_func_t print_func);
// Füge einen neuen Baumknoten mit dem übergebenen Wert in den Baum ein (gibt die Wurzel des neuen Baums zurück).
BSTNode_t* insert(BSTNode_t *root, void* data, int numBytes, compare_func_t comp, print_func_t print_func);
// Traversiert die Baumknoten in der Reihenfolge ihrer Werte und gibt sie aus.
void inorderTraversal(const BSTNode_t *root);
// Gibt den Speicher des übergebenen Elements frei.
void freeNode(BSTNode_t** node);
// Gibt den Speicher des gesamten Baums frei.
void freeBST(BSTNode_t** head);

// <----TODO

#endif //INFO2_LECTURE_BST_H
