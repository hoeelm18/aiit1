

#include <stdio.h>
#include <string.h>

int mystrlen(char *text){
  
  int n;
  for(n=0; text[n] != NULL; ++n){    //NULL = 0 '\0'
    
    ;
  }
  
  
    return n;
 
  
}

int main () {

  int f[3];
  
  // Ein Text wird immer mit einem NULL-Zeichen abgeschlossen
  //Das Nullzeichen hat den Wert 0
  
  char satz[] = "Das ist mein erster Text";
  
  
  satz[0] = 'A' ;
  //satz[1] = 'B' ;
  //satz[2] = 0 ;
  
  //printf gibt nur jene Zeichen aus die vor der Terminierung stehen!!
  printf("%s", satz);
  //Zeichen nach der Terminierung
  printf("%s", &satz[3]);
  //satz[24] = 'A';
  
  int laenge = strlen(satz);
  printf("\nLaenge = %d Zeichen", laenge);
  printf("\nsize of (satz) = %ld Bytes\n", sizeof(satz));
  printf("\nmystrlen(satz) = %ld Bytes\n", mystrlen(satz));
  printf("\nsize of (laenge) = %ld Bytes\n", sizeof(laenge));
  printf("\nsize of (f) = %ld Bytes\n", sizeof(f)/sizeof(int));
  
  //strings kopieren
  
  char ziel[200];
  strcpy(ziel, satz);
  
  
  //ziel = satz;  geht nicht
  
  printf("ziel: %s\n", ziel);
  //sizeof(satz);
  //sizeof(laenge);
  
  char ziel2[5];
  strncpy(ziel2, satz, 4);
  ziel2[4]=0;

  printf("ziel2: %s\n", ziel2);
  printf("1 -> 0x%02x %c\n", ziel2[0] ziel2[0]);
  printf("1 -> 0x%02x %c\n", ziel2[1] ziel2[1]);
  printf("1 -> 0x%02x %c\n", ziel2[2] ziel2[3]);
  printf("1 -> 0x%02x %c\n", ziel2[4] ziel2[5]);
  
  char name1[]= "Kolb";
  char name2[]= "Grasmugg";
  
  printf("ziel2: %s\n", ziel2);
  return 0;
}

