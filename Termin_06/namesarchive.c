#include "namesarchive.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// TODO Anfang
static char names[MAX_NAMES][MAX_NAME_LEN];
static int numNames = 0;

int addName(const char *name)
{
    if(numNames >= MAX_NAMES)
        return 0;
    strncpy(names[numNames++], name, MAX_NAME_LEN);
    return 1;
}

void printNames()
{
    for(int i = 0; i < numNames; i++)
        printf("%s\n", names[i]);
}

int compare(const void* elemA, const void* elemB)
{
    return strcmp((const char*)elemA, (const char*)elemB);
}

void sortNames()
{
    qsort(names, numNames, MAX_NAME_LEN, compare);
}

int addNameSorted(const char* name)
{
    if(numNames >= MAX_NAMES)
        return 0;

    int index = 0;

    while(index < numNames && strcmp(names[index], name) < 0)
        index++;

    for(int i = numNames; i > index; i--)
        strcpy(names[i], names[i-1]);

    strcpy(names[index], name);
    numNames++;
    return 1;
}

int removeName(const char *name)
{
    int index = 0;

    while(index <= numNames && strcmp(names[index], name) != 0)
        index++;

    if(index == numNames)
        return 0;

    for(int i = index; i < numNames; i++)
        strcpy(names[i], names[i+1]);

    numNames--;
    return 1;
}

// TODO Ende