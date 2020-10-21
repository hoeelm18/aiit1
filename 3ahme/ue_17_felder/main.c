
#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
//Funktion zum einlesen einer ganzen Zahl von der Konsole 

  /*Anmerkungen:
  So lange einlesen bis der Benutzer eine korrekte Zahl eingibt
  EIngabeaufforderung mit printf--> txt mit Doppelpunkt 
  Einlesen eines "Textes" von der Standardeingabe mit fgets  */
  


#define S_LEN_MAX 80
#define ARRAY_SIZE_MAX 10

int gibGanzeZahl(char  *ptxt) {
   int zahl = 0;
   char s[S_LEN_MAX];
   int i = 0;
   
   
   printf("%s: ", ptxt);
   
   do{
    fgets(s, S_LEN_MAX, stdin); fflush(stdin);
   }while( sscanf(s, "%d", &zahl) < 1);
   
  
   
   return zahl; 
}

int main () {
    int zahl[ARRAY_SIZE_MAX], i=0;
    
    
    for (int i = 0; i < ARRAY_SIZE_MAX; i++) {
    gibGanzeZahl("Zahl %d",i+1);    
    }
    
    for(i =0; i < ARRAY_SIZE_MAX, i++){
      printf("Zahl %d\n", i+1, zahl[i]);
      
    }
    
    return 0;
}
/*
Zahl 1: xxx
Zahl 2: xxx
....
Zahl 10: xxx
  
 2. Speichern die Zahl in einem Array int zahl[10]
 
 3. Ausgabe des Feldes (zeilenweise)
 * 
 * Zahl 1: wert
 * Zahl 2: wert 
 * ...
 * Zahl 10: wert
 */