#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAXIMALE_ANZAHL_RADTOUREN   100
#define MAXIMALE_LAENGE_MENUTEXT    30
#define MAXIMALE_LAENGE_RADTOURNAME 50
#define ZEICHDEN_ABBRUCH_EINGABE    '\n'

#define DATEIPFAD_RADTOUREN  "radtouren.csv"

const char MENU_TEXT[][MAXIMALE_LAENGE_MENUTEXT] = {
    "Neue Radtour",
    "Ausgabe aller Radtouren",
    "Entfernen einer Radtour",
    "Laden aller Radtouren",
    "Speichern aller Radtouren",
    "Beenden"
    };

struct datum
{
    int tag;
    int monat;
    int jahr;
};


struct radtour
{
    char name[MAXIMALE_LAENGE_RADTOURNAME];
    int laenge; // [km]
    int anzahl; // Anzahl der Radausfluege[-]
    int hoehenmeter;
    struct datum letzter_ausflug;

};

void tauscheRadtour(struct radtour *radtour1, struct radtour *radtour2)
{
    struct radtour h;

    h=*radtour1;
    *radtour1 = *radtour2;
    *radtour2 = h;


    /* Alternativ
    memcpy(&h, radtour1, sizeof(h));
    memcpy(radtour1, radtour2, sizeof(h));
    memcpy(radtour2, &h, sizeof(h));
    */
}

void sortiereRadtouren(struct radtour *radtouren, int anzahl)
{
  int i;

  for (i=0;i<anzahl-1;i++)
  {
    int j, tausch=0;
    for (j=0;j<anzahl-1-i;j++)
    {
      if (strcasecmp(radtouren[j].name, radtouren[j+1].name) > 0)
      {
        tauscheRadtour(radtouren + j, radtouren + j + 1);
        tausch++;
      }
    }
    if (tausch==0)
      return;
  }
}

int eingabeGanzeZahl(char *text, int min, int max, int *zahl)
{
    int ok = 1;
    char s[100];
    do
    {
        if (!ok)
        {
           printf("\nIhre Eingabe ist ungueltig! Bitte geben Sie eine Zahl im Bereich %d-%d ein!\n", min, max);
        }

        printf("%s", text);

        fgets(s, sizeof(s), stdin);

        if (s[0] == ZEICHDEN_ABBRUCH_EINGABE)
            return 0;

        ok = sscanf(s, "%d", zahl);
        ok &= (*zahl >= min && *zahl <= max);
    }
    while(*zahl >= min && *zahl <= max);
    return 1;
}

int eingabeText(char *text, int len, char *neuer_text)
{
    int ok = 1;
    char s[100];
    do
    {
        if (!ok)
        {
           printf("\nIhre Eingabe ist zu lange! Die Textlaenge ist auf %d Zeichen reduziert\n", len);
        }

        printf(text);

        fgets(s, len, stdin);
        fflush(stdin);
        if (s[0] == ZEICHDEN_ABBRUCH_EINGABE)
            return 0;
        ok = (strlen(s) < (len-1)) && (strlen(s) > 0);

    }
    while(!ok);
    strcpy(neuer_text, s);
    neuer_text[strlen(s)-1] = '\0';
    return 1;
}

int eingabeDatum( char *text, struct datum *neues_datum )
{
    int jahr;
    int monat;
    int tag;
    char s[100];

    do
    {

        if (text != NULL)
            printf(text);

        fgets(s, 100, stdin);
        if (sscanf(s, "%d.%d.%d", &tag, &monat, &jahr) == 3)
        {
            if (tag >= 1 && tag <=31)
            {
                if (monat >= 1 && monat <=12)
                {
                    time_t t;
                    struct tm *ts;
                    t = time(NULL);
                    ts = localtime(&t);
                    if ( (jahr > 2000) & (jahr <= ts->tm_year+1900))
                    {
                        neues_datum->jahr = jahr;
                        neues_datum->monat = monat;
                        neues_datum->tag = tag;
                        return 1;
                    }

                }
            }
        }
        else if (s[0]==ZEICHDEN_ABBRUCH_EINGABE) //Abbruch der Eingabe
            return 0;

        printf("Bitte geben Sie das Datum im Format TT.MM.JJJ ein!\n");
    }
    while(1);
    return 0;
}

int eingabeMenu()
{
    int auswahl = 0;

    printf("Menue:\n");
    printf("------\n");
    for (int i = 0; i < sizeof(MENU_TEXT)/MAXIMALE_LAENGE_MENUTEXT; ++i)
        printf("%d...%s\n", i+1, MENU_TEXT[i]);

    fflush(stdin);
    eingabeGanzeZahl("\nIhre Eingabe:", 1, sizeof(MENU_TEXT)/MAXIMALE_LAENGE_MENUTEXT, &auswahl);

    return auswahl;
}


int neueRadtour(struct radtour radtouren[], int *anzahl)
{
    char name[MAXIMALE_LAENGE_RADTOURNAME] = "";
    struct radtour neueradtour;
    int found = 0;

    memset(&neueradtour, 0, sizeof(neueradtour)); //Alles loeschen mit Nullen ueberschreiben!

    if (*anzahl == MAXIMALE_ANZAHL_RADTOUREN)
    {
        printf("Zu wenig Speicher! Es koennen keine neuen Radtouren angelegt werden!");
        return 0;
    }
    do
    {
        found = 0;
        if (eingabeText("Bitte geben Sie eine Bezeichnung fuer die Radtour ein:", MAXIMALE_LAENGE_RADTOURNAME, name))
        {
            for (int i = 0; i < *anzahl; ++i)
            {
                if (strcasecmp(radtouren[i].name, name)==0)
                {
                    printf("\nEs existiert bereits eine Radtour mit der Bezeichnung ""%s""!",  name);
                    printf("Bitte verwenden Sie eine andere Bezeichnung!\n\n");
                    found = 1;
                    break;
                }
            }
        }
        else
            return 0; //Eingabe abgebrochen
    }
    while(found);

    strcpy(neueradtour.name, name);

    //Laenge
    if (eingabeGanzeZahl("Laenger der Radtour [km]: ", 0, 10000, &neueradtour.laenge))
    {
        //Hoehenmeter
        if (eingabeGanzeZahl("Hoehenmeter [m]: ", 0, 10000, &neueradtour.hoehenmeter))
        {
            //Anzahl
            if (eingabeGanzeZahl("Anzahl [-]: ", 0, 10000, &neueradtour.anzahl))
            {

                if ( (neueradtour.anzahl == 0) || (eingabeDatum("Letzer Ausflug [TT.MM.JJJJ]: ", &neueradtour.letzter_ausflug) >0) )
                {
                   
                    struct radtour *hlp = realloc(radtouren, (*anzahl+1) * sizeof(struct radtour));
                    if ( hlp == NULL)
                    {
                        printf("Zu wenig Speicher! Es koennen keine neuen Radtouren angelegt werden!");
                        return 0;

                    }
                    radtouren = hlp;
                    memcpy(&radtouren[*anzahl], &neueradtour, sizeof(struct radtour));
                    *anzahl = *anzahl + 1;
                    return 1;
                }
            }
        }
    }
    return 0;
}

void ausgabeRadtourKopf(void)
{
    printf("Nr.  | Bezeichnung                              | Streckenlaenge | Hoehenmeter | Anzahl | Datum     \n");
    printf("----------------------------------------------------------------------------------------------------\n");
}

void ausgabeRadtour(struct radtour *tour)
{
    if (strlen(tour->name) > 40 ) //Der Text ist zu lange fuer eine einzeilige Darstellung
        printf("%37s...", tour->name);
    else
        printf("%-40s", tour->name);
    printf(" | %14.2lf", (double) tour->laenge);
    printf(" | %11.0lf", (double) tour->hoehenmeter);
    printf(" | %6d", tour->anzahl);
    printf(" | %02d.%02d.%04d\n", tour->letzter_ausflug.tag, tour->letzter_ausflug.monat, tour->letzter_ausflug.jahr);
}

void ausgabeRadtouren(struct radtour radtouren[], int anzahl)
{
    double summe = 0.0;

    if (anzahl)
    {
        for (int i=0; i<anzahl; ++i)
        {
            summe += radtouren[i].laenge;
        }

        printf("Die durchschnittliche Streckenlaenge aller Touren betraegt %.1lf km\n", summe/anzahl);
        printf("-----------------------------------------------------------------\n");

        sortiereRadtouren(radtouren, anzahl);

        ausgabeRadtourKopf();
        for (int i=0; i < anzahl; ++i)
        {
            printf("%4d | ", i+1);
            ausgabeRadtour(&radtouren[i]);
        }
    }
    else
        printf("Keine Radtouren gespeichert!\n");
}

int loescheRadtour(struct radtour radtouren[], int *anzahl)
{
    int ngefunden = 0;
    struct radtour *zuloeschende_radtour = NULL;

    char name[MAXIMALE_LAENGE_RADTOURNAME] = "";
    while(1)
    {
        if (eingabeText("Bitte geben Sie ein Suchkriterium fuer die zu loeschende Radtour ein:", MAXIMALE_LAENGE_RADTOURNAME, name))
        {
            for (int i = 0; i < *anzahl; ++i)
            {
                if (strstr(radtouren[i].name, name))
                {
                    if(!ngefunden++)
                        ausgabeRadtourKopf();
                    zuloeschende_radtour = &radtouren[i];

                    printf("%4d | ", ngefunden);
                    ausgabeRadtour(&radtouren[i]);
                }
            }

            if (ngefunden == 1) // Nur eine Radtour gefunden -> Loeschen moeglich
            {
                char s[4];

                while(eingabeText("\nMoechten Sie die Radtour wirklich loeschen (J/N)?: ", sizeof(s), s))
                {
                    if ((s[1] == '\0') && ((s[0] == 'J') || (s[0]=='j')))
                    {
                        memcpy(radtouren + (zuloeschende_radtour - radtouren), zuloeschende_radtour + 1, sizeof(struct radtour) * (*anzahl - (zuloeschende_radtour - radtouren) - 1));
                        *anzahl = *anzahl - 1;
                        return 1;
                    }
                    else if ((s[1] == '\0') && ((s[0] == 'N') || (s[0]=='n')))
                        return 0;
                    else //ungueltige Eingabe
                    {
                        printf("Ungueltige Eingaben nur [J/j] oder [N/n] erlaubt!\n\n");
                    }
                }
            }
            else if (ngefunden > 1) //Zu viele Radtouren gefunden. Die Suche muss eingeschraenkt werden!
            {
                printf("Zu viele Radtouren mit dieser Teilbezeichnung gefunden. Bitte konkretisieren Sie Ihre Eingabe!\n\n");
            }
            else //Keine Radtour gefunden
            {
                printf("Keine Radtouren mit diser Teilbezeichnung gefunden. Bitte aendern Sie Ihren Suchbegriff!\n\n");
            }
        }
        else    //Eingabe abgebrochen
            return 0;
    }


    return 0;
}

void ladeRadtouren(struct radtour radtouren[], int *anzahl)
{
    char s[1000];

    FILE *f = fopen(DATEIPFAD_RADTOUREN, "r");

    int n = 0;

    if ( f == NULL)
    {
        printf("Fehler beim Oeffnen der Datei!");
        return;
    }

    *anzahl = 0;
    fgets(s, sizeof(s),f); //Kopfzeile ignorieren
    while(fgets(s, sizeof(s),f) != NULL)
    {
        n = sscanf(s, "%[^\t]\t%d\t%d\t%d\t%d.%d.%d\n",
                radtouren[*anzahl].name,
                &(radtouren[*anzahl].laenge),
                &(radtouren[*anzahl].hoehenmeter),
                &(radtouren[*anzahl].anzahl),
                &(radtouren[*anzahl].letzter_ausflug.tag),
                &(radtouren[*anzahl].letzter_ausflug.monat),
                &(radtouren[*anzahl].letzter_ausflug.jahr)
                );
        if ( n == 7 )
        {
            //Position in die Liste uebernehmen
            ++(*anzahl);
        }
    }
    fclose(f);
    return *anzahl;
}

void speichereRadtouren(struct radtour radtouren[], int anzahl)
{
    FILE *f = fopen(DATEIPFAD_RADTOUREN, "w");

    fputs("#Beschreibung\tStreckenlaenge\tHoehenmeter\tAnzahl\tDatum\n", f);

    for (int i = 0; i < anzahl; ++i)
    {
        fprintf(f,"%s\t%d\t%d\t%d\t%d.%d.%d\n",
                radtouren[i].name,
                radtouren[i].laenge,
                radtouren[i].hoehenmeter,
                radtouren[i].anzahl,
                radtouren[i].letzter_ausflug.tag,
                radtouren[i].letzter_ausflug.monat,
                radtouren[i].letzter_ausflug.jahr);
    }
    fclose(f);
}

int main()
{
    struct radtour *radtouren = NULL;
   
   
   
   
    struct radtour radtourenstart[] = {
        {.name="Lieblingstour", .hoehenmeter=1000, .laenge=2000, .anzahl = 1, .letzter_ausflug={1,12,2001}},
        {.name="ABC", .hoehenmeter=2000, .laenge=1000, .anzahl = 2, .letzter_ausflug={1,1,2021}}};
     
    radtouren = malloc (sizeof(radtourenstart ));
     
     memcpy (radtouren, radtourenstart, sizeof(radtourenstart) );
     
    int radtouren_anzahl = sizeof(radtourenstart)/ sizeof (struct radtour);

    while(1)
    {
        //system("cls");
        switch(eingabeMenu())
        {
            case 1://Neue Radtour
                neueRadtour(radtouren, &radtouren_anzahl);
                break;
            case 4:
                ladeRadtouren(radtouren, &radtouren_anzahl);
            case 2: //Ausgabe aller Radtouren
                ausgabeRadtouren(radtouren, radtouren_anzahl);
                break;
            case 3: //Entfernen von Radtouren
                loescheRadtour(radtouren, &radtouren_anzahl);
                break;
            case 5:
                speichereRadtouren(radtouren, radtouren_anzahl);
                break;
            case 6: //Beenden des Programmes
            case 0:
                return 0;
                break;
        }

        printf("\nWeiter mit Enter...\n");
        getchar();
    }

    return 0;
}