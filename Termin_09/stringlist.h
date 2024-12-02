#ifndef INFO2_LECTURE_STRINGLIST_H
#define INFO2_LECTURE_STRINGLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct StringListNode
{
    char *string;
    struct StringListNode *next;
    struct StringListNode *prev;
} StringListNode;

// TODO
int pushBack(StringListNode **head, const char* string);
void printList(StringListNode const* head);
void freeList(StringListNode **head);
StringListNode* findString(StringListNode* head, const char* string);
void removeNode(StringListNode **head, StringListNode *node);

#endif //INFO2_LECTURE_STRINGLIST_H
