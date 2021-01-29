#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mystrlen(char *text){

    int n;
    for(n=0; text[n] != 0; n++ );
    
    return n;
}



int main (int argc, char** argv) {
    
    
    //Ein text wird immer mit einem NULl Zeichen abgeschlossen
    char satz[] = "Das ist mein erster Satz";
    
    int f[3];
    
    //satz[0] = 'A';
    //satz[1] = 'B';
    //satz[2] = 0;
    
    //Printf gibt nur jene Zeichen aus die vor der Tederminierung stehen aus!!
    printf("%s", satz);
    //Zeichen nach der Teterminierung werden ausgegeben!
    printf("%s", &satz[3]);
    
    int laenge = strlen(satz);
    printf("\n Laenge = %d Zeichen", laenge); 
    
    
    sizeof(satz);
    sizeof(laenge);
    printf("\nsizeof(satz) = %ld Bytes", sizeof(satz));
    printf("\n mystrlen(satz) = %d Bytes", mystrlen);
    printf("\nsizeof(laenge) = %ld Bytes", sizeof(laenge));
    printf("\nsizeof(f) = %ld Bytes", sizeof(f));
    
    
    //strings kopieren ZIEL MUSS MEHR ZEICHEN HABEN ALS DAS WAS KOPIERT WIRD!!!!!
    char ziel[200];
    strcpy(ziel, satz);
    printf("\nziel: %s\n", ziel);
    
    char ziel2[5];
    strncpy(ziel2, satz, 4);
    printf("\nziel2: %s\n", ziel2);
    printf("0x%02x %c\n", ziel2[0], ziel[0]);
    printf("0x%02x %c\n", ziel2[1], ziel[1]);
    printf("0x%02x %c\n", ziel2[2], ziel[2]);
    
    //vergleichen
    char name1[] = "Kolb";
    char name2[] = "Koassmugg";
    
    int rv = strcmp(name1, name2);
    printf("%d", rv);
    
    char name3[] = "Hvbvbvbvb";
    rv = strcmp(name1, name3);
    printf("\n%d", rv);
    
    
    
    char wort1 [] = "Das";
    char wort2 [] = "Wetter";
    char wort3 [] = "ist";
    char wort4 [] = "bewoelkt";
    
    char ganzerSatz [20] = "AAAAAAAAAAAAAAAAAAAA";
    
    strncpy(ganzerSatz, wort1, sizeof(ganzerSatz));
    printf("len=%d  %s \n", strlen(ganzerSatz), ganzerSatz);
    
    strncat(ganzerSatz, " ", sizeof(ganzerSatz) - strlen(ganzerSatz) - 1);
    printf("len=%d  %s \n", strlen(ganzerSatz), ganzerSatz);
    
    return 0;
}