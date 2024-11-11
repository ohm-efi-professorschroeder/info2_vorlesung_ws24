/*
 * Schreiben Sie eine Funktion schreibeAnfangGross, die eine Zeichenkette übergeben bekommt, den Anfangsbuchstaben jedes Wortes groß
 * schreibt und einen Zeiger auf den Anfang dieser Zeichenkette zurückgibt. Nutzen Sie für die Eingabe die Eingabefunktion aus
 * einer der vorherigen Übungen.
 *
 * Möglicher Programmablauf:
 * >> Geben Sie einen Text nur mit Kleinbuchstaben ein: das ist das haus vom nikolaus. und nebendran wohnt der weihnachtsmann.
 * Der bearbeitete Text lautet:
 * "Das Ist Das Haus Vom Nikolaus. Und Nebendran Wohnt Der Weihnachtsmann."
 */

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "eingabe.h"

#define MAX_TEXT_LEN 64

char *schreibeAnfangGross(char *text, int maxZeichen);

int main()
{
    char text[MAX_TEXT_LEN];

    gibTextEin("geben Sie einen Text nur mit Kleinbuchstaben ein: ", text, MAX_TEXT_LEN);

    printf("Der bearbeitete Text lautet:\n\"%s\"\n", schreibeAnfangGross(text, MAX_TEXT_LEN));

    return EXIT_SUCCESS;
}

// TODO Anfang
char *schreibeAnfangGross(char *text, int maxZeichen) {
    char gross[maxZeichen];
    gross[0] = '\0';

    char *word = strtok(text, " ");

    while(word != 0) {
        *word = toupper(*word);
        strncat(gross, word, maxZeichen-1-strlen(gross));
        strncat(gross, " ", maxZeichen-1-strlen(gross));
        word = strtok(NULL, " ,.!?");
    }

    strncpy(text, gross, maxZeichen-1);
    text[maxZeichen-1] = '\0';
    return text;
}
// TODO Ende