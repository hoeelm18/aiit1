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


int main(){
  
   int stimmen[MAXPART];
   int mandate[MAXPART];
   double tabelle[MAXMAND][MAXPART];
   char name[MAXPART][MAXNAMLEN]; 
   int anzPart, anzMand;
   
   printf("D'Hondt'sches Hoechstzaehlverfahren\n");
   printf("------------------------------------\n");
   
   eingabe(&anzPart, &anzMand, stimmen, name);

    return 0;
}
