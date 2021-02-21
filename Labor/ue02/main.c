/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: elias
 *
 * Created on 27. Jänner 2021, 22:32
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXMAND 1000 
#define MAXPART 20 
#define MAXNAMLEN 11 



int gibGanzeZahlMitUgEin(char *txt, int ug){
  
  char s[100];
  int z = 0;      //zahl

   do{
    
     printf("%s:", txt);
     fgets(s, 100, stdin);
     fflush(stdin);
    
  }while (sscanf(s,"%d", &z)<1 || z <= ug);

  
  return z;
}

int gibGanzeZahlMitUgUndOgEin(char *txt, int ug, int og){
  
  char s[100];
  int z = 0;      

   do{
     
     printf("%s:", txt);
     fgets(s, 100, stdin);
     fflush(stdin);
     
  }while (sscanf(s, "%d", &z) <1 || z <= ug || z >= og);

  
  
  return z;
}


void gibStringEin(char *txt, char *eingabe, int maxLen){
  
  char s[100];
  int l = 0;     //laenge

   do {
     
     printf("%s:", txt);
     fgets(s, 100, stdin);
     fflush(stdin);
     l = strlen(eingabe);
    
  }while (sscanf(s, "%s", &eingabe) <1 || l> maxLen );
  
}

void eingabe(int *anzPart, int *anzMand, int stimmen[], char namen[][MAXNAMLEN]){
  
  int l = 0;

  *anzPart = gibGanzeZahlMitUgUndOgEin("\nAnzahl der Parteien", 0, MAXPART);
  *anzMand = gibGanzeZahlMitUgUndOgEin("\nAnzahl der Mandate", 0, MAXMAND);

  for(int i=0; i <*anzPart; i++){
    
    if (i>0)
     l = strlen(*namen);

     printf("\nName der %d. Partei", i+1);
     gibStringEin("", namen + l, MAXNAMLEN);
     printf("\nStimmen %s", *namen);
     gibGanzeZahlMitUgEin("", 0);

  }

}

void baueTabelle(int anzPart, int anzMand, int stimmen[], double tabelle[][MAXPART]){
  
  double max = 0;
  int merker = 0;
  int divisor;
  int zaehler = 0;
  
   for (int j = 0; j < anzPart; j++) {
      divisor = 1;
      
   for (int i = 0; i < anzMand; i++ ) {
      tabelle[i][j] = (double)stimmen[zaehler]/(double)(divisor);
      divisor++;
      
     }
      
    zaehler++;
    
   }
  
     max = tabelle[0][0];

}
  
void gibTabelleAus(int anzPart, int anzMand, double tabelle[][MAXPART]) {
  
    int j = 0;
    
      for (; j < anzMand; j++) {
      printf("\n");
      
      for (int i = 0; i < anzPart; i++) {
      printf("%12.3lf |", tabelle[j][i]);
      
    }
  }
}

void findeHoechstzahl(double tabelle[][MAXPART], int anzPart, int anzMand, int*zeile, int*spalte){
  
  int* zeile, int* spalte){
    double max = tabelle[0][0];
    *zeile = 0;
    *spalte = 0;

    for(int i = 0; i < anzMand; i++){
        for(int j = 0; j < anzPart; j++){
         if(tabelle[i][j] > max) {
            max = tabelle[i][j];
            *zeile = i;
            *spalte = j;
            }
        }
    }
}

  
}


void dhondt(double tabelle[][MAXPART], int anzPart, int anzMand, int mandate[]){
  
    int zeile, spalte;

    for(int i=0; i<anzMand; i++) {
    mandate[i]= 0;
    }
    for(int j = 0; j<anzMand;j++){
        findeHoechsteZahl (tabelle, anzPart, anzMand, &zeile, &spalte);
        mandate[spalte] ++;
        tabelle[zeile][spalte] = 0;
    }
}

void ausgabe(int anzPart, int anzMand, int mandate[], int stimmen[], char name[][MAXNAMLEN]) {
  
double gesamtstimmen = 0, hiv;

    printf("\n\n  Partei  | Stimmen | Prozent | Mandate"\n---------------------------------------");

    for(int i=0;i<anzPart;i++){
      
    gesamtstimmen += stimmen[i];
    
    }

    for(int i=0; i<anzPart;i++){
      
    hiv = 100.0 * stimmen[i]/gesamtstimmen;
    printf("\n %8s | %7d | %7.2lf | %7d", name [i], stimmen[i], hiv, mandate[i]);
    
    }
}


int main(){
  
   int stimmen[MAXPART];
   int mandate[MAXPART];
   double tabelle[MAXMAND][MAXPART];
   char name[MAXPART][MAXNAMLEN]; 
   int anzPart, anzMand;
   
   printf("D'Hondt'sches Hoechstzaehlverfahren\n");
   printf("------------------------------------\n");
   
   eingabe(&anzPart, &anzMand, stimmen, name);

   baueTabelle(anzPart, anzMand, stimmen, tabelle);
   gibTabelleAus(anzPart, anzMand, tabelle);
   dhondt(tabelle, anzPart, anzMand, mandate);
   ausgabe(anzPart, anzMand, mandate, stimmen, name);
   
   
    return 0;
}
