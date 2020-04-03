#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getInputIntegerValue( char text[]) {

  char s[100];
  int n;
  int rv;

  do {

    printf("%s\n", text);
    fgets(s, 100, stdin);
    n = sscanf(s, "%d", &rv);

      } while (n != 1);

  return rv;

}
double getInputDoubleValue( char text[]) {

   char s[100];
    int n;
    double rv;

  do {
    printf("%s\n", text);
    fgets(s, 100, stdin);
    n = sscanf(s, "%lf", &rv);

      } while (n != 1);

  return rv;

}
int getSelectMenu() {

    char s[100];
    int n;
    double rv;

  do {

    printf("------------------------\n");
    printf("1 ... Wuerfel\n");
    printf("2 ... Quader\n");
    printf("3 ... Kugel");
    printf("4 ... Programm beenden\n\n");
    printf("  Auswahl (1-4): ");
    fgets(s, 100, stdin);
      sscanf(s, "%d", &rv);

    rv = getInputIntegerValue("Auswahl 1-4");

   }while (rv < 1 || rv > 4);

}
double calcCube() {

    double l;

    printf("Würfel\n");

  do{

    l = getInputDoubleValue("Länge: ");

    }while (l < 0);

    double Volumen = l * l * l;
    double Oberflaeche = 6 * (l * l);

    printf("Volumen: %.2lf\n", Volumen);
    printf("Oberfläche: %.2lf\n", Oberflaeche);

    return 0;

 double calcCuboid() {

    double b;
    double h;

    printf("Quader\n");

  do{

    l = getInputDoubleValue("Länge: ");

    }while (l < 0);

  do{

    double h = getInputDoubleValue("Höhe: ");

    }while (h < 0);

  do {

    b = getInputDoubleValue("Breite: ");

    }while ( b < 0);

    double Volumen = b * h * l;
    double Oberflaeche = 2 * l * b + 2 * l * h + 2 * b * h;

    printf("Volumen: %.2lf\n", Volumen);
    printf("Oberfläche: %.2lf\n", Oberflaeche);

    return 0;

}

 double calcSphere() {

    double d;

    printf("Kugel\n");

  do{

    d = getInputDoubleValue("Durchmesser: ");

    }while (d < 0);

    double r = d / 2;
    double Volumen = 4 / 3 * M_PI * r * r * r;
    double Oberflaeche = 4 * M_PI * r * r;

    printf("Volumen: %.2lf\n", Volumen);
    printf("Oberfläche: %.2lf\n", Oberflaeche);

    return 0;

}

int main()

{

    while (1 == 1) {
    int wahl;
    wahl = getSelectMenu();

    printf("UE11 - Koerperberechnung mit Menuefunktion\n\n");

    switch(wahl) {

     case 1: {

            calcCube();

            break;

        } case 2: {

            calcCuboid();

            break;

        } case 3: {

            calcSphere();

            break;

        } case 4: { return 0; }


}

}

}




