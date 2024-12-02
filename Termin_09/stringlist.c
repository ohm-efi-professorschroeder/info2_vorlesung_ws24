#include "stringlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO Beginn
int pushBack(StringListNode **head, const char* string)
{
    // Listenknoten allokieren
    StringListNode *node = calloc(1, sizeof(StringListNode));
    if(node == NULL)
        return 0;

    node->string = calloc(strlen(string)+1, sizeof(char));
    if(node->string == NULL) {
        free(node);
        return 0;
    }

    // Listenknoten füllen
    strcpy(node->string, string);

    // Listenknoten ans Ende anfügen
    if(*head == NULL) {
        *head = node;
        return 1;
    }

    StringListNode *temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    node->prev = temp;
    temp->next = node;
    return 1;
}

void printList(StringListNode const* head)
{
    StringListNode const* temp = head;

    while(temp != NULL) {
        printf("%s\n", temp->string);
        temp = temp->next;
    }
}

void freeList(StringListNode **head)
{
    StringListNode *temp = *head;
    while(temp != NULL) {
        free(temp->string);
        StringListNode *next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}

StringListNode* findString(StringListNode* head, const char* string)
{
    StringListNode* temp = head;

    while(temp != NULL && strcmp(temp->string, string) != 0) {
        temp = temp->next;
    }
    return temp;
}

void removeNode(StringListNode **head, StringListNode *node)
{
    StringListNode *next = node->next;
    StringListNode *prev = node->prev;

    if(prev)
        prev->next = next;
    if(next)
        next->prev = prev;

    if(*head == node)
        *head = next;

    free(node->string);
    free(node);
}

// TODO Ende
