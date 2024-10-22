// TODO Anfang
#include <stdio.h>
#include <string.h>

int gibTextEin(const char prompt[], char eingabe[], int laenge)
{
    printf("%s", prompt);

    if(fgets(eingabe, laenge, stdin) != 0)
    {
        if(eingabe[strlen(eingabe)-1] == '\n')
            eingabe[strlen(eingabe)-1] = '\0';

        while(getchar() != '\n');

        return 1;
    }
    return 0;
}

// TODO Ende