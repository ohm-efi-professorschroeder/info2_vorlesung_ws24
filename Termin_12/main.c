/*
Aufgabe: Spielzeugsortierung in Santas Werkstatt

In Santas Werkstatt herrscht reges Treiben, und er benötigt Ihre Hilfe, um die verpackten Spielzeuge effizient zu organisieren.
Die Aufgabe besteht darin, ein C-Programm zu schreiben, das Argumente von der Befehlszeile entgegennimmt:
* die Namen der Spielzeuge (als Zeichenketten) und
* ihre Herstellungsjahre (als Ganzzahlen).

Das Programm soll einen binären Suchbaum verwenden, um die Daten zu organisieren, und nach Herstellungsjahr sortiert ablegen.

1. Schreiben Sie ein C-Programm, das zwei Argumente von der Befehlszeile entgegennimmt:
   -- die Namen der Spielzeuge (als Zeichenketten) und ihre Herstellungsjahre (als Ganzzahlen).

2. Implementieren Sie eine Struktur zur Repräsentation eines Spielzeugs mit den folgenden Attributen:
   -- Spielzeugname
   -- Herstellungsjahr

3. Verwenden Sie Ihre Implementierung eines binären Suchbaums aus den vergangenen Übungen und modifizieren ihn so, dass
 er beliebige Daten (nicht mehr nur Strings) speichern kann. Nutzen Sie sie dann zur Speicherung der eingegebenen Spielzeuge.
 Konzentrieren Sie sich auf die Funktionen zum Hinzufügen und Ausgeben von Einträgen im binären Suchbaum.

4. Geben Sie die sortierte Liste der Spielzeuge aus, wobei der Name und das Herstellungsjahr jedes Spielzeugs angezeigt werden.

 */
#include <stdio.h>
#include <string.h>
#include "bst.h"

// TODO---->
#define MAX_STR_LEN 50
typedef struct
{
    char name[MAX_STR_LEN];
    int year;
} Toy;

int compareToys(const void* t1, const void* t2) {
    const Toy* toy1 = (Toy*)t1;
    const Toy* toy2 = (Toy*)t2;
    return toy2->year - toy1->year;
}

void printToy(const void* t) {
    const Toy* toy = (Toy*)t;
    printf("%s (%d)\n", toy->name, toy->year);
}

int main(int argc, char* argv[])
{
    if (argc % 2 == 0) {
        printf("Verwendung: santa <Name1> <Jahr1> ...\n");
        return -1;
    }

    BSTNode_t *root = 0;
    for (int i = 1; i < argc; i+=2) {
        Toy toy;
        strncpy(toy.name, argv[i], MAX_STR_LEN);
        toy.year = atoi(argv[i+1]);
        root = insert(root, &toy, sizeof(Toy), compareToys, printToy);
    }

    printf("Santa hat folgende Spielzeuge verpackt:\n");
    inorderTraversal(root);

    freeBST(&root);

    return 0;
}

// <----TODO
