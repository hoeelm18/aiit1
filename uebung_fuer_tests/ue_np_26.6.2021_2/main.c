#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
/*es ist eine Klassenliste zu erstellen, in welcher der Vorname, der Nachname und das Geburtsdatun gespeichert werden sollen
 zum Testen dieses Programmes ist es nötig, 4 Personen einzugeben. Die Personen sollen auch bei beenden des Programmes gespeichert
 * werden und bei starten des Programmmes durch Eingabe von 10 eingelesen werden 
*/

struct geburtsdatum{
  
  int tag;
  int monat;
  int jahr;
  
};

struct personen{
  
 struct geburtsdatum datum;
 char vorname[100];
 char nachname[100];
 
  
};

int dateianlegen(struct personen daten[]){
  int rv;
  
  FILE *f = NULL;
  f = fopen("Daten.txt","w");
  
  if(f == NULL){
    
    printf("Fehlerhafte Datei");
    
    return 0;
  }
  
  for(int i = 0; i < 4 ; i++){
  rv = fprintf(f, "%s %s %d %d %d", daten[i].vorname, daten[i].nachname, daten[i].datum.tag, daten[i].datum.monat,
                                        daten[i].datum.jahr);
  
    }
  
  rv = fclose(f); 
  return rv;
}

int eingabeDaten(struct personen daten[]){
  
  char s[100];
  int anzahl = 4;
  
  for(int i=0; i < anzahl ;i++){
    
  printf("Bitte geben Sie Ihren Vornamen ein: \n");
  fgets(daten[i].vorname, 100 ,stdin);
  
  printf("Bitte geben Sie Ihren Nachnamen ein: \n");
   fgets(daten[i].nachname, 100 ,stdin);
   
  printf("Bitte geben Sie Ihr Geburtstag ein: \n");
   fgets(s, 100 ,stdin);          // TT.MM.JJJJ 23.04.2021
   sscanf(s, "%d", &daten[i].datum.tag);
   
   printf("Bitte geben Sie Ihr Geburtsmonat ein: \n");
   fgets(s, 100 ,stdin);          // TT.MM.JJJJ 23.04.2021
   sscanf(s, "%d", &daten[i].datum.monat);
   
   printf("Bitte geben Sie Ihr Geburtsjahr ein: \n");
   fgets(s, 100 ,stdin);          // TT.MM.JJJJ 23.04.2021
   sscanf(s, "%d", &daten[i].datum.jahr);
   
  }
  
  return 0;
}

int ausgabedaten(struct personen daten[]){
  
  char s[100];
  int anzahl = 4;
  
  for(int i=0; i < anzahl ;i++){
    
    printf("%s | %s ", daten[i].vorname, daten[i].nachname);
    printf(" %d | %d | %d", daten[i].datum.tag, daten[i].datum.monat, daten[i].datum.jahr);
    
    
  }
}

int main ()
{
  
  struct personen daten[4];
  
  printf("Klassenliste\n"
          "------------\n");  
  eingabeDaten(daten);
  ausgabedaten(daten);
  dateianlegen(daten);
  
  return 0;
}

