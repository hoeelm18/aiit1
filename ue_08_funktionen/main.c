#include <stdio.h>
#include <stdlib.h>


double liefereEingabewert () {

  char s[100];
  int n;
  double rv; // return value
  
  do {
    printf("Wert: ");
    fgets(s, 100, stdin);
    n = sscanf(s, "%lf", &rv);
    
    
    
  } while (n != 1);
  
  return rv;
}  
  
int main () {
  printf("UE08 - Spannungsteiler\n\n");
  
  // Eingabe 
  
  printf("R1 ");
  double r1 = liefereEingabewert();
  printf("R2 ");
  double r2 = liefereEingabewert();
  printf("Uein ");
  double ue = liefereEingabewert();
  
  // Verarbeitung
  
  double ua = ue * r2 / (r1 + r2);
  
  // Ausgabe
  
  printf("Uaus = %.2lf\n", ua);
  
  
  
  
  return 0;
}

