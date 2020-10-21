#include <stdio.h>
#include <stdlib.h>

int gibGanzeZahlEin(char *ptxt){                                                                   //Rückgabewert der Eingabe: Ihre Wahl:lehrzeichen
  
  char s[100];
  int wahl;
  int n; 
  do {
    printf("%s: ", ptxt);
    fgets(s, 100, stdin);
    fflush(stdin);
    n = sscanf(s, "%d", &wahl);
  } while(n != 1);
  
  return wahl;
  
}

double gibFkZahlEin(char* ptxt) {                                                                   //gleich wie die erste
  
  char s[100];
  double eingabe; 
  int n; 
  
  do {
    printf("%s: ", ptxt);
    fgets(s, 100, stdin);
    fflush(stdin);                    // Löschen der Tastaturpuffers
    n = sscanf(s, "%lf", &eingabe);
  } while(n != 1);
  
  return eingabe; 
}

char gibMatrixNameEin() {                                                                         //name einer Matrix eingeben (benutzer darf nur einen Großbuchstaben eingeben, alles andere wird nicht akzeptiert 
  
  char name[4];
  int n;
  
  do {
    printf("Bitte geben Sie den Namen der Matrix ein! \n");
    fgets(name, 4, stdin);
    fflush(stdin);
  } while(name[0] < 'A' || name[0] > 'Z');
  
  return name[0];
}

void gibMatrixEin(char name, double *pa11, double *pa12, double *pa21, double *pa22) {
  
  char s[80];   //Speicher für dynamischen String
  char kleinbuchstabe = name - 'A' + 'a';
  printf("Matrix %c:\n", name);
  sprintf(s, "%c11", kleinbuchstabe);
  *pa11 = gibFkZahlEin(s);
  sprintf(s, "%c12", kleinbuchstabe);
  *pa12 = gibFkZahlEin(s);
  sprintf(s, "%c21", kleinbuchstabe);
  *pa21 = gibFkZahlEin(s);
  sprintf(s, "%c22", kleinbuchstabe);
  *pa22 = gibFkZahlEin(s);
}

void gibMatrixAus(char name, double pa11, double pa12, double pa21, double pa22) {
  
  printf("Matrix %c\n/%10.3lf %10.3lf\\\n\\%10.3lf %10.3lf/\n\n", name, pa11, pa12, pa21, pa22);
 
}

void addiereMatrix(double a11, double a12, double a21, double a22, double b11, double b12, double b21, double b22,
                   double *c11, double *c12, double *c21, double *c22) {
  
  *c11 = a11 + b11; 
  *c12 = a12 + b12;
  *c21 = a21 + b21;
  *c22 = a22 + b22;
  
}

void subtrahiereMatrix(double a11, double a12, double a21, double a22, double b11, double b12, double b21, double b22,
                   double *c11, double *c12, double *c21, double *c22) {
  
  *c11 = a11 - b11;
  *c12 = a12 - b12;
  *c21 = a21 - b21;
  *c22 = a22 - b22;
}

void multipliziereMatrixMitSkalar(double *a11, double *a12, double *a21, double *a22, double skalar) {
  
  *a11 = *a11 * skalar;  //Auch möglich *a11 = *= skalar;
  *a12 = *a12 * skalar;
  *a21 = *a21 * skalar;
  *a22 = *a22 * skalar;
}
void multipliziereMatrix(double a11, double a12, double a21, double a22, double b11, double b12, double b21, double b22,
                         double *c11, double *c12, double *c21, double *c22) {
  
  *c11 = a11 * b11 + a12 * b21;
  *c12 = a21 * b12 + a22 * b22;
  *c21 = a21 * b11 + a22 * b21;
  *c22 = a21 * b12 + a22 * b22;
  
}
double berechneDeterminante(double a11, double a12, double a21, double a22){
  
  double determinate; 
  determinate = a11 * a22 - a12 * a21;
  
  return determinate;
}

int dividiereMatrizen(double a11, double a12, double a21, double a22,
                      double b11, double b12, double b21, double b22, 
                      double* c11, double* c12, double* c21, double* c22) {
  
  double erg; 
  double skalar;
  
    erg = (b11 * b22) - (b12 * b21);
  skalar = 1/erg;

  b11 *= skalar;
  b12 = (b12 * -1) * skalar;
  b21 = (b21 * -1) * skalar;
  b22 *= skalar;

  *c11 = a11 * b11 + a12 * b21;
  *c12 = a11 * b12 + a12 * b22;
  *c21 = a21 * b11 + a22 * b21;
  *c22 = a21 * b12 + a22 * b22;

  
  
}
int invertiereMatrix(double *a11, double *a12, double *a21, double *a22){
  
  double determinate;
  determinate = *a11 * *a22 - *a12 * *a21; 
  
  if(determinate == 0) {
   
    return 1;  
     
  } 
      double erg;
      erg = 1 / determinate;
      *a11 = erg * *a22;
      *a12 = erg * (-1 * *a12);
      *a21 = erg * (-1 * *a21);
      *a22 = erg * *a12;

  return 0;
}


void auswahl_1(){
  double a11 = 0, a12 = 0, a21 = 0, a22 = 0;
  double b11 = 0, b12 = 0, b21 = 0, b22 = 0;
  double c11 = 0, c12 = 0, c21 = 0, c22 = 0;
  gibMatrixEin('A', &a11, &a12, &a21, &a22);
  gibMatrixEin('B', &b11, &b12, &b21, &b22);
  addiereMatrix(a11, a12, a21, a22, b11, b12, b21, b22, &c11, &c12, &c21, &c22);
  gibMatrixAus('C', c11, c12, c21, c22);
  }

void auswahl_2() {
  
  double a11 = 0, a12 = 0, a21 = 0, a22 = 0;
  double b11 = 0, b12 = 0, b21 = 0, b22 = 0;
  double c11 = 0, c12 = 0, c21 = 0, c22 = 0;
  gibMatrixEin('A', &a11, &a12, &a21, &a22);
  gibMatrixEin('B', &b11, &b12, &b21, &b22);
  subtrahiereMatrix(a11, a12, a21, a22, b11, b12, b21, b22, &c11, &c12, &c21, &c22);
  gibMatrixAus('C', c11, c12, c21, c22);
}

void auswahl_3(){
  
  double a11 = 0, a12 = 0, a21 = 0, a22 = 0;
  gibMatrixEin('A', &a11, &a12, &a21, &a22);
  double skalar = gibFkZahlEin("Skalar");
  multipliziereMatrixMitSkalar(&a11, &a12, &a21, &a22, skalar);
  gibMatrixAus('B', a11, a12, a21, a22);
}

void auswahl_4() {
  
  double a11 = 0, a12 = 0, a21 = 0, a22 = 0;
  double b11 = 0, b12 = 0, b21 = 0, b22 = 0;
  double c11 = 0, c12 = 0, c21 = 0, c22 = 0;
  gibMatrixEin('A', &a11, &a12, &a21, &a22);
  gibMatrixEin('B', &b11, &b12, &b21, &b22);
  multipliziereMatrix(a11, a12, a21, a22, b11, b12, b21, b22, &c11, &c12, &c21, &c22);
  gibMatrixAus('C', c11, c12, c21, c22);
}
void auswahl_5() {
  
  double determinante;
  double a11 = 0, a12 = 0, a21 = 0, a22 = 0;
  gibMatrixEin('A', &a11, &a12, &a21, &a22);
  determinante = berechneDeterminante(a11, a12, a21, a22);
  printf("Determinante: %lf \n", determinante);
  
  
}

void auswahl_6() {
  

  double a11 = 0, a12 = 0, a21 = 0, a22 = 0;
  gibMatrixEin('A', &a11, &a12, &a21, &a22);
  
  
  
  
  
}
void auswahl_7() {
  
  double a11 = 0, a12 = 0, a21 = 0, a22 = 0;
  double b11 = 0, b12 = 0, b21 = 0, b22 = 0;
  double c11 = 0, c12 = 0, c21 = 0, c22 = 0;
  gibMatrixEin('A', &a11, &a12, &a21, &a22);
  gibMatrixEin('B', &b11, &b12, &b21, &b22);
  multipliziereMatrix(a11, a12, a21, a22, b11, b12, b21, b22, &c11, &c12, &c21, &c22);
  gibMatrixAus('C', c11, c12, c21, c22);
  
  
}






void menue() {
  int auswahl; 
  do {
    auswahl = gibGanzeZahlEin("1...Addieren\n2...Subtrahieren\n3...Mit Skalar\n4...Multiplizieren\n5...Berechne Determinate\n6...Invertiere Matrix\n7...Dividieren\n8...Beenden\n");
  } while (auswahl < 1 || auswahl > 8);
  
  switch (auswahl){
    
    case 1: auswahl_1();
            break;
    
    case 2:  auswahl_2();
             break;
       
    case 3: auswahl_3();
            break;
            
    case 4: auswahl_4();
            break;
            
    case 5: auswahl_5(); 
            break;
            
    case 6: auswahl_6();
            break;
    
    case 7: auswahl_7(); 
            break;
            
    case 8: break;
            
   
            
    
  }
}

int main () {
  
  menue();

  return 0;
}
