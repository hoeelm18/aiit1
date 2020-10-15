#include <stdio.h>
#include <stdlib.h>

int gibGanzeZahlEin(const char *ptxt) {      //Text verändert sich nicht 
  
    char s[100];
    int wahl;
    int n;

    printf("%s: ", ptxt);
    do {
    fgets(s, 100, stdin);
    n = sscanf(s, "%d", &wahl);
    } while (n != 1);

    return wahl;
    
   }

void gibBruchEin(char *ptxt, int *pzaehler, int *pnenner) {
  
  *pzaehler = gibGanzeZahlEin("Zaehler");
  *pnenner  = gibGanzeZahlEin("Nenner");
}

void clrscr () {
  
  system("clear");  //terminal löschen 
  
}
void gibMenueAus() {
  clrscr();
  
  printf("Rechnen mit Bruechen\n"
         "---------------------\n");
  printf("1...Addition zweier Brueche\n");
  printf("2...Subtraktion zweier Brueche\n");
  printf("3...Anzahl der Stellen einer Zahl berechnen\n");
  printf("4...Programm beenden\n");
  //Menüfunktion auswählen 
}

void addiereBrueche(int z1, int n1, int z2, int n2, int *pze, int *pne) {
 
  *pze = z1 * n2 + z2 * n1;
  *pne = n1 * n2;
}

void subtrahiereBrueche(int z1, int n1, int z2, int n2, int *pze, int *pne) {
  
  *pze = z1 * n2 - z2 * n1;
  *pne = n1 * n2;
}

int ggT (int ze, int ne) {
  
    if (ze < 0) {
      ze = -ze;
      
    }
    
    if(ne < 0) {
      ne = -ne;
      
    }
    
    while (ze != ne) {
      if(ze > ne) {
        ze = ze - ne;
      } else {
        ne = ne - ze;
      }
    }
    return ze; 
  }

void kuerzen(int *pze, int *pne, int ggT) {
  
  *pze = *pze / ggT;
  *pne = *pne / ggT;
  
}

int berechneStellenAnzahl(int n) {
  
    int j;

    for(j = 1; abs(n) >= 10; j++) {

      n = n / 10;
      
      }
    
    if(n < 0) {
      j++;
      
    }
    
    return j;
    
  }


void gibBruchAus(char *ptxt, int ze, int ne)  {
  
  int d;                            // differenz
  int a = berechneStellenAnzahl(ze);
  int b = berechneStellenAnzahl(ne);
  
  d = a - b;                
  
    printf("%s:\n", ptxt);
    if(d > 0) {      
      printf("%d\n", ze);
      for(int j = 1; j <= a; j++) {
        printf("-");
        
      }

       printf("\n");
       for(int j = 1; j <= d; j++) {
       printf(" ");
       
      }

      printf("%d\n", ne);
    } else if(d < 0) {
      for(int j = 1; j <= abs(d); j++) {
        printf(" ");
        
      }

      printf("%d\n", ze);
      for(int j = 1; j <= b; j++) {
        printf("-");
        
      }

      printf("\n%d\n", ne);
    } else {          
      printf("%d\n", ze);
      for(int j = 1; j <= a; j++) {
        printf("-");
        
      }

      printf("\n%d\n", ne);
      
    }
  }
void auswahlAddition () {
  
  int z1, z2, n1, n2;
  int pze;
  int pne;
  
    printf("Addieren\n");
    gibBruchEin("Bruch 1", &z1, &n1);
    gibBruchEin("Bruch 2", &z2, &n2);
    addiereBrueche(z1, n1, z2, n2, &pze, &pne);
    if(pze == 0 && pne == 0) {
      printf("Division durch 0!\n");

    } else if (pze == 0 || pne == 0) {
      if(pze == 0) {
        printf("Ergennis : 0\n");
      } else if(pne == 0) {
        printf("Division durch O!\n");
      }
    } else {
     int ggTeiler = ggT(pze, pne);
     kuerzen(&pze, &pne, ggTeiler);
     gibBruchAus("Ergebnis", pze, pne);
    }
 }

void auswahlSubtraktion (){
  
  int z1, z2, n1, n2;
  int pze;
  int pne;
  
  printf("Subtrahieren\n");
  gibBruchEin("Bruch 1", &z1, &n1);
  gibBruchEin("Bruch 2", &z2, &n2);
  subtrahiereBrueche(z1, n1, z2, n2, &pze, &pne);
  if(pze == 0 && pne == 0) {
     printf("Division durch 0!\n");
     
   } else if (pze == 0 || pne == 0) {
     if(pze == 0) {
       printf("Ergennis : 0\n");
     } else if(pne == 0) {
       printf("Division durch O!\n");
     }
   } else {
    int ggTeiler = ggT(pze, pne);
    kuerzen(&pze, &pne, ggTeiler);
    gibBruchAus("Ergebnis", pze, pne);
  }
}

void auswahlAnzahlDerStellen () {
  
  printf("Anzahl der Stellen\n");
  int z1 = gibGanzeZahlEin("Ihre Zahl "); 
  int anzahl = berechneStellenAnzahl(z1);
  if(anzahl == 1) {
    printf("Die Zahl hat %d Stelle\n", anzahl);
  } else {
    printf("Die Zahl hat %d Stellen\n", anzahl);
  }
}

int main ()
{
  int wahl;
  char s[4]; 
  do {
    gibMenueAus();              //Menüfunktion auswählen
    
    wahl = gibGanzeZahlEin("Waehle die Funktion (1-4)");
    switch(wahl) {
      case 1:                    
        auswahlAddition();
        break;
    
      case 2:                     
        auswahlSubtraktion();
        break;
      
      case 3:                     
        auswahlAnzahlDerStellen();
        break;
      
      case 4:                     
        printf("Programmende\n");
        break;
      
      default: // in allen anderen Fällen
        printf("Die Auswahl %d ist ungültig! Bitte nocheinmal: \n", wahl);
    }
    if (wahl != 4) {            
      fgets(s, 4, stdin);        //warten, bis der User fortfährt
    }
  } while (wahl != 4);
  
  return 0;
}
