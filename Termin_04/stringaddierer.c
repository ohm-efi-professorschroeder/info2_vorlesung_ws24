/*
 * Ergänzen Sie im untenstehenden Programm die fehlenden Funktionen. addiereText bekommt dabei eine Folge von
 * Zahlenwörtern kleiner zehn übergeben und ermittelt daraus die Summe. Groß- und Kleinschreibung soll keine Rolle spielen.
 * Zudem liefert die Funktion 0, wenn ein Zahlenwort nicht aufgelöst werden konnte, ansonsten 1.
 *
 * 1. Beispielhafter Programmablauf:
 * >> Addiere: Fuenf achT SIEBEN
 * Das Ergebnis lautet 20.
 *
 * 2. Beispielhafter Programmablauf:
 * >> Addiere: fuenf achtzehn sieben
 * Falsche Eingabe.
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "eingabe.h"

#define MAX_EINGABE_LEN 100

char *wandleKlein(char *text);                  // Reihe 1
int wandleZahl(const char *wort);               // Reihe 2
int addiereText(const char *text, int *erg);    // Reihe 3

int main()
{
    char eingabeText[MAX_EINGABE_LEN];
    int erg;

    gibTextEin("Addiere: ", eingabeText, MAX_EINGABE_LEN);

    if(addiereText(eingabeText, &erg))
        printf("Das Ergebnis lautet %d.\n", erg);
    else
        printf("Falsche Eingabe.\n");

    return EXIT_SUCCESS;
}

// TODO Anfang

char* wandleKlein(char *text)
{
    int laenge = strlen(text);
    for(int i = 0; i < laenge; i++)
    {
        text[i] = tolower(text[i]);
        //*(text+i) = tolower(*(text+i));
    }
    return text;
}

int wandleZahl(const char *wort)
{
    const char numbers[][7] = {"null", "eins", "zwei", "drei", "vier", "fuenf", "sechs", "sieben", "acht", "neun"};

    char kleinWort[7];
    strncpy(kleinWort, wort, 7);
    wandleKlein(kleinWort);

    for(int i = 0; i < 10; i++){
        if(strcmp(numbers[i], kleinWort) == 0)
            return i;
    }
    return -1;
}

int addiereText(const char *text, int *erg)
{
    char textCpy[MAX_EINGABE_LEN];
    strncpy(textCpy, text, MAX_EINGABE_LEN);
    char *wort = strtok(textCpy, " ");

    *erg = 0;
    while(wort != NULL)
    {
        int wert = wandleZahl(wort);
        if(wert < 0)
            return -1;
        *erg += wert;
        wort = strtok(0, " ");
    }
    return 1;
}

// TODO Ende