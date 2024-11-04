/*
 * Erweitern Sie das folgende Programm, sodass es die Funktion qsort der Standard-Bibliothek verwendet, 
 * um das enthaltene String-Array sortiert auszugeben. Es sollen zuerst die Strings ohne Zahlen ausgegeben werden 
 * und am Ende die mit Zahlen. Die Strings ohne Zahlen sollen aufsteigend sortiert werden, die mit Zahlen absteigend.
 * Sie können davon ausgehen, dass die im Array enthaltenen Strings immer nur aus Buchstaben oder nur aus Zahlen bestehen.
 * Es ist also ausreichend, das erste Zeichen mittels isdigit(...) zu prüfen.
 * 
 */

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void gibStringsAus(const char *strings[], unsigned int anzahl);

int compare(const void* elem1, const void* elem2)
{
    const char* str1 = *(const char**)elem1;
    const char* str2 = *(const char**)elem2;

    if(isdigit(str1[0]) && isdigit(str2[0]))
    {
        return strtol(str2, NULL, 10) - strtol(str1, NULL, 10);
    }
    else if(isdigit(str1[0]) || isdigit(str2[0]))
    {
        if(isdigit(str1[0]))
            return 1;
        else
            return -1;
    }
    else
    {
        return strcmp(str1, str2);
    }
}

int main()
{
    const char *strings[] = {"789", "Zorro", "Adam", "Werner", "123", "Bernd", "Hubert", "456"};
    unsigned int anzahlStrings = sizeof(strings)/sizeof(strings[0]);

    printf("Vor Sortierung:\n");
    gibStringsAus(strings, anzahlStrings);

    // TODO: Hier sortieren
    qsort(strings, anzahlStrings, sizeof(char*), &compare);

    printf("\nNach Sortierung:\n");
    gibStringsAus(strings, anzahlStrings);

    return EXIT_SUCCESS;
}

void gibStringsAus(const char *strings[], unsigned int anzahl)
{
    for(int i = 0; i < anzahl; i++)
    {
        printf("%s\n", strings[i]);
    }
}