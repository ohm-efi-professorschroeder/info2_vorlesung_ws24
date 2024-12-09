#include "stringbst.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO Beginn

StringBSTNode_t* createNode(const char* string)
{
    StringBSTNode_t *node = calloc(1, sizeof(StringBSTNode_t));
    if(node == NULL)
        return 0;

    node->string = calloc(strlen(string)+1, sizeof(char));
    if(node->string == NULL) {
        free(node);
        return 0;
    }

    // Baumknoten füllen
    strcpy(node->string, string);

    return node;
}

StringBSTNode_t* insert(StringBSTNode_t* root, const char* string)
{
    // Fall 1: Baum ist leer
    if(root == 0)
    {
        root = createNode(string);
        return root;
    }

    if(strcmp(string, root->string) < 0)
    {
        // links einfügen
        root->left = insert(root->left, string);
    }
    else
    {
        // rechts einfügen
        root->right = insert(root->right, string);
    }
    return root;
}

void inorderTraversal(const StringBSTNode_t *root)
{
    if(root != 0) {
        inorderTraversal(root->left);
        printf("...%s\n", root->string);
        inorderTraversal(root->right);
    }
}

void freeNode(StringBSTNode_t** node)
{
    if(*node != 0)
    {
        free((*node)->string);
        free(*node);
        *node = 0;
    }
}

void freeBST(StringBSTNode_t** root)
{
    if(*root != 0) {
        freeBST(&(*root)->left);
        freeBST(&(*root)->right);
        freeNode(root);
    }
}

StringBSTNode_t* findString(StringBSTNode_t* root, const char *string)
{
    if(root == 0)
        return 0;

    if(strcmp(root->string, string) == 0)
        return root;
    else if(strcmp(root->string, string) < 0)
        return findString(root->left, string);
    else
        return findString(root->right, string);
}

StringBSTNode_t* delete(StringBSTNode_t *root, const char* string)
{
    if(root == 0)
        return 0;

    if(strcmp(root->string, string) < 0) {
        root->left = delete(root->left, string);
    }
    else if(strcmp(root->string, string) > 0) {
        root->right = delete(root->right, string);
    }
    else
    {
        // Fall 1: Keine Kindknoten
        if(root->left == 0 && root->right == 0) {
            freeNode(&root);
            return 0;
        }
        // Fall 2: Ein Kind
        else if(root->left == 0 || root->right == 0)
        {
            StringBSTNode_t *tmp;
            if(root->left == 0)
                tmp = root->right;
            else
                tmp = root->left;
            freeNode(&root);
            return tmp;
        }
        // Fall 3: Zwei Kinder
        else
        {
            StringBSTNode_t *min = findMin(root->right);
            char* tmp = root->string;
            root->string = min->string;
            min->string = tmp;

            root->right = delete(root->right, tmp);
        }
    }

    return root;
}

StringBSTNode_t* findMin(StringBSTNode_t* root)
{
    if(root && root->left)
        return findMin(root->left);
    return root;
}

// TODO Ende
