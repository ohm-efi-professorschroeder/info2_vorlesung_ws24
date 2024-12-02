#include "namesarchive.h"
#include "stringlist.h"

#include <string.h>

static StringListNode *head = NULL;

int addName(const char *name)
{
    return pushBack(&head, name);
}

int removeName(const char *name)
{
    StringListNode *foundNode = findString(head, name);

    if (foundNode != NULL)
    {
        removeNode(&head, foundNode);
        return 1;
    }

    return 0;
}

void printNames()
{
    if (head == NULL)
        return;

    printList(head);
}

void clearArchive()
{
    freeList(&head);
}

