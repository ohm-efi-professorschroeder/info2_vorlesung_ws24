#include "namesarchive.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// TODO Anfang
static char **names = 0;
static int numNames = 0;

int addName(const char *name)
{
    names = (char**)realloc(names, sizeof(char*) * numNames+1);
    if(names == 0)
        return 0;

    char* nameCopy = (char*) malloc((strlen(name)+1)*sizeof(char));
    if(nameCopy == 0)
    {
        names = (char**)realloc(names, sizeof(char*) * numNames);
        return 0;
    }
    strcpy(nameCopy, name);

    names[numNames++] = nameCopy;
    return 1;
}

void printNames()
{
    for(int i = 0; i < numNames; i++)
        printf("%s\n", names[i]);
}

int addNameSorted(const char* name)
{
    int index = 0;

    // Stelle zum einfügen finden
    while(index < numNames && strcmp(names[index], name) < 0)
        index++;

    // Array vergrößern
    names = (char**)realloc(names, sizeof(char*) * numNames+1);
    if(names == 0)
        return 0;

    // Einträge verschieben ("Platz machen")
    for(int i = numNames; i > index; i--)
        names[i] = names[i-1];

    // Namen kopieren
    char* nameCopy = (char*) malloc((strlen(name)+1)*sizeof(char));
    if(nameCopy == 0)
    {
        names = (char**)realloc(names, sizeof(char*) * numNames);
        return 0;
    }
    strcpy(nameCopy, name);

    // Zeiger in Liste einfügen
    names[index] = nameCopy;
    numNames++;
    return 1;
}

int compare(const void* elemA, const void* elemB)
{
    return strcmp(*(const char**)elemA, *(const char**)elemB);
}

void sortNames()
{
    qsort(names, numNames, sizeof(char*), compare);
}

int removeName(const char *name)
{
    int index = 0;

    // Zu löschende Stelle finden
    while(index <= numNames && strcmp(names[index], name) != 0)
        index++;

    if(index == numNames)
        return 0;

    // Speicher freigeben
    free(names[index]);

    // Elemente verschieben
    for(int i = index; i < numNames; i++)
        names[i] = names[i+1];

    // Array verkleinern
    names = (char**)realloc(names, sizeof(char*) * numNames-1);
    if(names == 0)
        return 0;

    numNames--;
    return 1;
}

void clearArchive()
{
    for(int i = 0; i < numNames; i++)
        free(names[i]);

    free(names);
    numNames = 0;
}

// TODO Ende
