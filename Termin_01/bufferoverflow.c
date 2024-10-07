#include <stdio.h>
#include <string.h>

int checkPassword();
void showSecretInformation();

int main()
{
   if(checkPassword())
      showSecretInformation();
   else
      printf("Falsches Passwort!\n");

   return 0;
}

int checkPassword()
{
   char buffer[5];

   printf("Bitte Passwort eingeben: ");
   scanf("%s", buffer);

   int correct = strcmp(buffer, "pass") == 0;

   return correct;
}

void showSecretInformation()
{
   printf("Erfolg!\n");
}
