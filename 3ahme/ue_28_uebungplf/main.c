#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main()
{
    //Datei anlegen -> fopen

    int jahr = 2021, monat = 5, tag = 5;
    char s[80];
    char test[100]= "Test 1";
    FILE *f = fopen("test.txt", "w");
    if(f == NULL) //Datei konnte nicht angelegt werden
    {
        printf("Fehler aufgetreten (Fehler %d)\n", errno);
        printf("-> %s\n", strerror(errno));
    }

    int rv = fputs("Mahlzeit \n", f);
    rv = fprintf(f, "%d;%d;%d\n", jahr, monat, tag);
    if(rv == EOF)
        printf("Fehler");
    //Datei schließen:
    if (fclose(f) == EOF)
    {
        printf("Datei konnte nicht geschlossen werden.");
    }

    f = fopen("test.txt", "r");

    if(f == NULL)
        return 0;

    while(fgets(s, sizeof(s), f) != NULL)
    {
        //s = 2021;5;6\n
        // Variante 1 mit sscanf: s ="Test 1;2021;5;6\n
        /*if (sscanf(s, "%[^;];%d;%d;%d" , test, &jahr, &monat, &tag) != 4)
        {
            printf("Fehler du Pfuscher. Text konnte nicht konvertiert werden: \n");
            printf("Text: %s", s);
         
        }
          */
        //Variante 2 mit strtok - Trennung eines Strings bei bestimmten 
        char *p = strtok(s,";");
        if (p == NULL)
            break;
        strcpy(test, p);
        
        p = strtok(NULL,";");
        if (p == NULL);
            break;
            sscanf(s, "%d", &jahr);
            
        p = strtok(NULL,";");
        if (p == NULL);
            break;
            sscanf(s, "%d", &monat);
            
         p = strtok(NULL,";");
         if (p == NULL);
            break;
            sscanf(s, "%d", &tag);
        
    }
    fclose(f);

    return 0;
}