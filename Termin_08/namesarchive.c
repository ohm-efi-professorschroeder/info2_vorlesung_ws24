#include "namesarchive.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static Person archive[MAX_PERSONS];
static int numberOfPersons = 0;

int addPerson(const Person newPerson)
{
    if(numberOfPersons >= MAX_PERSONS)
        return 0;

    archive[numberOfPersons] = newPerson;
    numberOfPersons++;

    return 1;
}


int removePerson(const Person person)
{
    for(int i = 0; i < numberOfPersons; i++) {
        if(person.age == archive[i].age && (strcmp(person.name, archive[i].name) == 0)) {
           for(int j = i; j < numberOfPersons; j++) {
               archive[j] = archive[j+1];
           }
           numberOfPersons--;
           return 1;
        }
    }

    return 0;
}

void printPersons()
{
    for(int i = 0; i < numberOfPersons; i++) {
        printf("%s ist %d alt.\n", archive[i].name, archive[i].age);
    }
}

static int comparePersonByAge(const void* elem1, const void* elem2) {
    const Person* person1 = (const Person*) elem1;
    const Person* person2 = (const Person*) elem2;

    int ageDiff = person1->age - person2->age;

    if(ageDiff == 0)
        return strcmp(person1->name, person2->name);

    return ageDiff;
}

static int comparePersonByName(const void* elem1, const void* elem2) {
    const Person* person1 = (const Person*) elem1;
    const Person* person2 = (const Person*) elem2;

    int nameDiff = strcmp(person1->name, person2->name);

    if(nameDiff == 0)
        return person1->age - person2->age;

    return nameDiff;
}

void sortPersons(SortType type)
{
    switch(type) {
        case SORT_BY_AGE:
            qsort(archive, numberOfPersons, sizeof(Person), comparePersonByAge);
            break;
        case SORT_BY_NAME:
            qsort(archive, numberOfPersons, sizeof(Person), comparePersonByName);
            break;
        default:
            printf("Ungueltiger Sortierungsmodus.\n");
            break;
    }
}