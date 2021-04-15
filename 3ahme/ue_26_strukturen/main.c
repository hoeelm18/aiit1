#include <stdio.h>
#include <stdlib.h>
#define MAX_ANZAHL_SCHUELER 24

struct Name{
   
    char nachname[30];
    char vorname[30];
};

struct Datum{
   
    int tag;
    int Monat;
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
   
   
   
    for(int i = 0; i < anzahl; i++){
        printf("\n%d. %s %s", i+1, gruppe[i].schuelername.vorname, gruppe[i].schuelername.nachname);
        //printf("Geburtsdatum: %02d.%02d.%01d\n", gruppe[i].geburtsdatum.Tag, gruppe[i].geburtsdatum.Monat);
    }
}

int eingabeGanzeZahlen(char *text, int min, int max, int *zahl){
    
    
}


int eingabegeburtsdatum(struct Datum geburtsdatum){
   //eingabe von tag/monat/jahr
    int ok =1;
    int jahr;
    int monat;
    int tag;
    
    
    printf("bitte geben sie das Geburtsdatum ein: \n");
   
    if (eingabeGanzeZahlen("Jahr", 1980, 2005, &jahr)){
        if (eingabeGanzeZahlen("Monat", 1, 12, &monat)){
            if (eingabeGanzeZahlen("Tag", 1, 31, &tag)){
                //geburtsdatum ->jahr = jahr;
                //geburtsdatum ->monat = monat;
               // geburtsdatum ->tag = tag;
                
                return 1;
            }
        }
    }
 
    
    
    return 0;
}
int eingabeText(char *textausgabe, int len, char *texteingabe){
    
    //int ok = 1;
    //char s[80];
    
    //do {
        //if(!ok){
            
            //printf("Ihre Eingabe ist zu lang! Bitte reduzieren Sie die Textlaenge auf %d Zeichen!");
        
        
    }


//int eingabeanshrift( struct Anschrift ){
    
//}

//int eingabedesSchuelers(){
    
//}


int main (int argc, char** argv) {

    struct Schuelerdaten aiit_schuelerliste[MAX_ANZAHL_SCHUELER] = {
        {{"Hoebel", "Elias"}, {13, 11, 2003}, {"Oberdorfweg 11", "Dobl", 8143}} ,
        {{"Hoebel", "Lukas"}, {12, 6, 2005}, {"Oberdorfweg 11", "Dobl", 8143}} ,
    };
    int schueleranzahl = 2;
   
    ausgabeSchueler(aiit_schuelerliste, schueleranzahl);
    return 0;
}