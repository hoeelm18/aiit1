#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ANZAHL_SCHUELER 24

struct Name{
    char nachname[30];
    char vorname[30];
};

struct Datum{
    int tag;
    int monat;
    int jahr;
};

struct Anschrift{
    char strasse[30];
    char ort[30];
    int plz;  
};

struct Schuelerdaten{
    struct Name schuelername;
    struct Datum geburtsdatum;
    struct Anschrift schueleranschrift;    
};

void ausgabeSchueler(struct Schuelerdaten gruppe[], int anzahl){
   
    printf("\nDie Gruppe umfasst folgende Schueler:\n");
    printf("============================================================================");
   
    for(int i = 0; i < anzahl; i++){
        printf("\n%d. %s %s  | %d.%d.%d  | %s %s %d ", i+1,
               gruppe[i].schuelername.vorname, gruppe[i].schuelername.nachname, //Name
                gruppe[i].geburtsdatum.tag, gruppe[i].geburtsdatum.monat, gruppe[i].geburtsdatum.jahr, // geburtstag
                gruppe[i].schueleranschrift.strasse, gruppe[i].schueleranschrift.ort, gruppe[i].schueleranschrift.plz); //Datum
    }
}

int eingabeGanzeZahl(char *text, int min, int max, int *zahl){

int ok = 0;
char s[100];
   
    do{
        if(!ok){
          printf(" Bitte geben sie eine zahl zwischen %d und %d ein", min, max);  
        }
        printf("%s", text);
        fgets(s, sizeof(s), stdin);
        fflush(stdin);
        if(s[0] == '<')
            return 0;
        ok = sscanf(s, "%d", zahl);
        ok &=(*zahl >= min) && (*zahl <= max);
       
    }while(!ok);
   
    return 1;
}

int eingabeText(char *textausgabe, int len, char *texteingabe){
   
    int ok = 1;
    char s[100];
   
    do{
         if(!ok){
          printf(" Ihre Eingabe ist zu lang. Bitte geben Sie einen Text mit maximal %d Zeichen ein \n", len);  
        }
        if(textausgabe != NULL){
        printf(textausgabe);
        }
        fgets(s, len, stdin);
        fflush(stdin);
        if( s[0] == '<'){
            return 0;
        }
        ok = (strlen(s) > 0) && (strlen(s) < (len-1));
    }while(!ok);
    strcpy(texteingabe, s);
    texteingabe[strlen(s)-1] = '\0';
    return 1;
}

int eingabeGeburtsdatum(struct Datum *geburtsdatum){
   
   int jahr;
   int monat;
   int tag;
   
   printf("Bitte geben Sie Ihr Geburtsdatum ein: \n");
   
   if(eingabeGanzeZahl("jahr: ", 1980, 2010,  &jahr)){
      if(eingabeGanzeZahl("Monat: ", 1, 12, &monat)){
           if(eingabeGanzeZahl("Tag: ", 1, 31, &tag)){
               
              geburtsdatum->jahr = jahr;
              geburtsdatum->monat = monat;
              geburtsdatum->tag = tag;
              return 1;
           }
      }
   }  
   return 0;
}

int eingabeAnschrift(struct Anschrift *schueleranschrift){
   
    char so[100], ss[100];
    int plz;
   
    printf("Bitte geben Sie Ihre Anschrift ein: \n");
   
    if(eingabeGanzeZahl("Postleitzahl", 1000, 9999, &plz))
        if(eingabeText("Ort: ", 19, so)){
            if(eingabeText("Straße und Hausnummer:", 19, ss)){

                strcpy(schueleranschrift->strasse, ss);
                strcpy(schueleranschrift->ort, so);
                schueleranschrift->plz = plz;
                return 1;
            }
        }
   return 0;
}

int eingabeName(struct Name *schuelername){
   
    char s[100], sv[100];
   
    printf("Bitte geben Sie Ihren Namen ein: \n");
    if(eingabeText("Vorname: ", 19, sv)){
        if(eingabeText("Nachname: ", 19, s)){
           
            strcpy(schuelername->vorname, sv);
            strcpy(schuelername->nachname, s);
            return 1;
        }
    }
   return 0;
}

int neueSchueler( struct Schuelerdaten *schueler, int *anzahl){
   
    if(!eingabeName(&schueler[*anzahl].schuelername)){
        return 0;
    }
    if(!eingabeAnschrift(&schueler[*anzahl].schueleranschrift)){
        return 0;
    }
    if(!eingabeGeburtsdatum(&schueler[*anzahl].geburtsdatum)){
        return 0;
    }
    printf("Neuer Schüler wurde angelegt");
    *anzahl = *anzahl + 1;
}

int main (int argc, char** argv) {

    struct Schuelerdaten aiit_schuelerliste[MAX_ANZAHL_SCHUELER] = {
        {{"Höbel", "Elias"}, {13, 11, 2003}, {"Oberdorfweg 11", "Dobl-Zwaring", 8143}} ,
        {{"Höbel", "Lukas"}, {12, 06, 2005}, {"Oberdorfweg 11", "Dobl-Zwaring", 8143}} ,
    };
    int schueleranzahl = 2;
   
    neueSchueler(aiit_schuelerliste, &schueleranzahl);
    printf("sCHÜLERANZAHL: %d", schueleranzahl);
    ausgabeSchueler(aiit_schuelerliste, schueleranzahl);
    return 0;
}
