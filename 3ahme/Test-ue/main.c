#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int zufallszahlen(int max, int min) {
 
  int rz;
  
  rz = (rand() % (max - min + 1) + min);

  return rz;
}

void ziehung(int f[], int anzahl, int max, int min) {
  
  for(int i = 0; i < anzahl; i++) {
    
    f[i] = zufallszahlen(max, min);
  }
  for(int j = 0; j < anzahl; j++) {
   
   for(int k = 0; k < anzahl; k++) {
     
     if(j == k){
       break;
     }
     
     if(f[j] == f[k]) {
       
       f[k] = zufallszahlen(max, min);
     }
     continue;
   } 
     
  }
  
}

int eingabe(int f[], int max, int min, int anzahl, char *txt) {
  
  char s[100];
  int n = 0;
  printf("%s", txt);
  int merker;
  
    for(int i = 0; i < anzahl; i++) {
      do{
        merker = 0;
        printf("Ihre %d Eingabe: ", i + 1);
        fgets(s, 100, stdin);
        n = sscanf(s, "%d", &f[i]);
        if(f[i] > max || f[i] < min ) { 
          printf("Falsche Eingabe \n");
          merker++;
          break;
        }
        for(int j = 0; j < i; j++) {
          if (f[i] == f[j]) {
            merker++;
          }
        }
        continue;
      } while (n != 1 || merker == 1);
    } 
  }

  

void vergleiche(int f[], int f1[], int anzahl) {
  
  int tips = 0;
  
  for(int i = 0; i < anzahl; i++ ) {
    for(int j = 0; j < anzahl; j++) {
      
      if(f[j] == f1[i]){
        
        tips++;
        
      }
     
    }
   
  }
  
  
  printf("\n\tDu hast %d mal Richtig getippt", tips);
  
  
}

void bubblesort(int f[], int anzahl){
  
  int t = 0;
  int merker = 0;
  
  for(int i = 0; i < anzahl; i++ ) {
    for(int j = 0; j < anzahl - 1 - i; j++) {
      
      if(f[j] > f[j + 1]) {
        
        t = f[j];
        f[j] = f[j + 1];
        f[j + 1] = t;
        merker++; 
     } 
     if (merker == 0) {
       return;
     } 
    }
   }
 
  
  
}
int ausgabe(int f[], int anzahl, char *txt) {
  
  printf("%s", txt);
  
  for(int i = 0; i < anzahl; i++) {
    
    printf("%d ", f[i]);
    
  } 
}



int main ()
{
  int f[10], f1[10];
  srand(time(NULL));
  
  eingabe(f, 45, 1, 6, "\n\tIhre Tipps\n");
  bubblesort(f, 6);
  ziehung(f1, 6, 45, 1);
  bubblesort(f1, 6);
  ausgabe(f, 6, "\n\tIhre Tipps");
  ausgabe(f1, 6, "\n\tGezogene Tipps");
  vergleiche( f, f1, 6);
  
  return 0;
}

