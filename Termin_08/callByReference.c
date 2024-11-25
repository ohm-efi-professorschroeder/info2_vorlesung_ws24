/*
 * Was gibt folgendes Programm aus? Erst überlegen, dann ausführen.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_TEXT_LEN 100

typedef struct
{
    char text1[MAX_TEXT_LEN];
    char *text2;
    int number;
} MyStruct;
// Speicher: text1[0] text1[1] ..... text1[MAX_TEXT_LEN] text2* number
//

void modify1(MyStruct arg);
// -> Struct wird kopiert, aber Vorsicht: text2 ist Zeiger!
// Speicher: text1[0] text1[1] ..... text1[MAX_TEXT_LEN] text2* number
void modify2(MyStruct *arg);
// -> Zeiger auf die Struct wird kopiert
// Speicher: arg*

int main()
{
    char text[MAX_TEXT_LEN] = "Text 2";
    MyStruct someStruct = {"Text 1", text, 15};
    
    printf("someStruct.text1  = %s\n", someStruct.text1);   // Text 1
    printf("someStruct.text2  = %s\n", someStruct.text2);   // Text 2
    printf("someStruct.number = %d\n", someStruct.number);  // 15
    modify1(someStruct);

    printf("\nNach modify1:\n");
    printf("someStruct.text1  = %s\n", someStruct.text1);   // 1. Text 1
    printf("someStruct.text2  = %s\n", someStruct.text2);   // 2. Text 2
    printf("someStruct.number = %d\n", someStruct.number);  // 3. 15
    modify2(&someStruct);

    printf("\nNach modify2:\n");
    printf("someStruct.text1  = %s\n", someStruct.text1);
    printf("someStruct.text2  = %s\n", someStruct.text2);
    printf("someStruct.number = %d\n", someStruct.number);

    return EXIT_SUCCESS;
}

void modify1(MyStruct arg)
{
    strcpy(arg.text1, "Neuer Text 1");
    strcpy(arg.text2, "Neuer Text 2");
    arg.number = 100;
}

void modify2(MyStruct *arg)
{
    strcpy(arg->text1, "Wieder neuer Text 1");
    strcpy(arg->text2, "Wieder neuer Text 2");
    arg->number = 200;
    (*arg).number = 200; // equivalent
}