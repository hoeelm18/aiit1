#include <stdio.h>
#include <stdlib.h>

int wandleDreieckInStern(double rab, double rac, double rbc, double *pra, double *prb, double *prc) {
  
  double pruefe = rac + rab + rbc;
  
  if( pra != NULL && prb != NULL && prc != NULL && pruefe > 0 && rac > 0 && rab > 0 && rbc > 0 ) {
   *pra = (rac * rab) / (rac + rab + rbc);
   *prb = (rab * rbc) / (rac + rab + rbc);
   *prc = (rac * rbc) / (rac + rab + rbc);
   
   return 0;
   
  } else {
    
    return 1;
 }
}

int wandleSternInDreieck(double ra, double rb, double rc, double *prab, double *prac, double *prbc) {
  
  if( prac != NULL && prbc != NULL && prab != NULL && rb > 0 && ra > 0 && rc > 0) {
   *prac = ((ra * rb) + (rb * rc) + (rc * ra)) / rb;
   *prab = ((ra * rb) + (rb * rc) + (rc * ra)) / rc;
   *prbc = ((ra * rb) + (rb * rc) + (rc * ra)) / ra;
   
   return 0;
   
  } else {
  
    return 1;
 }
}

int main ()
{

  int rv;
  double ra, rb, rc;
  double rab, rac, rbc;
  
  rab = 1; rac = 2; rbc = 3;
  rv = wandleDreieckInStern(rab, rac, rbc, &ra, &rb, &rc);
  if(rv != 0) {
    printf("Test 1: Fehler rv = %d\n", rv);
  } else {
    if (ra == 0.333333 && rb == 0.500000 && rc == 1.000000) {
       printf("OK   ");
    } else {
       printf("ERROR");
    }   
    printf("rab=%lf, rac=%lf, rbc=%lf -> ra=%lf, rb=%lf, rc=%lf\n", rab, rac, rbc, ra, rb, rc);
  }
  
  return 0;
}

