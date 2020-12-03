#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MDATA_MAX_SIZE   1000
#define MOVINGAVERAGING_WINDOW_SIZE   10
#define NO_ERROR 0
#define OUT_OF_MEMORY_ERROR 1
#define FILE_ERROR 2
#define Fenster 4
#define ECGDATA_SAMPLE_RATE 360

double genSinusWithNoise (double f[], int length, double length_period, double amplitude, double offset, double amplitude_noise) {
  
  for(int i = 0; i < length; i++) {                     
  
    f[i] = amplitude * sin(((2 * M_PI) / length_period) * i) + offset + (rand() % 100) * amplitude_noise / 100;
  }
  return 0;
}

int readDataFromFile(char *filepath, double *mdata, int max_length, int *length) {
  int idummy = 0;
  double ddummy = 0;
  
  FILE* f = fopen(filepath, "r");
  if (f==NULL)
    return FILE_ERROR;
  
  *length = 0;
  while (!feof(f) && (*length < max_length))    
  {
    char s[100];
    if (fgets(s,100,f) == NULL)   
      break;
    
    if (sscanf(s,"%d;%lf;%lf", &idummy, &mdata[*length], &ddummy) == 3)
        (*length)++;

  }
  
  fclose(f);
  return NO_ERROR;
}

int writeData2File(char *filepath, double data[], int length) {
  FILE* f = fopen(filepath, "w");
  if (f == NULL)
    return FILE_ERROR;
  for (int i=0;i<length;i++)
    fprintf(f,
      "%.3f\n", data[i]
    );
  fclose(f);
  return NO_ERROR;
}

double removeOffset(double f[], int length){
  
  double x = 0;
  double summe = 0;
  double offset = 0;
    
  for(int i = 0; i < length; ++i) {
    
    summe += f[i];
  }
  
  offset = summe/length;
    
  for(int i = 0; i < length; ++i) {
    
    f[i] -= offset;
  }
  return offset;
}

void calcMovingAveraging(double f[], int length) {
 
  double summe;
  double avg;
  double old;
  
  for(int i = 0; i < Fenster; i++) {
      summe += f[i];
  }
  
  
  for(int j = 0; j < (length - Fenster); j++) {
    avg = summe/10;
    summe+= f[Fenster +j];
    summe = summe - f[j];
    f[j] = avg;
  }
}

void diffSignal(double f[], int length) {
  
  for(int i = 0; i < (length -1); i++) {
    
    f[i] = f[i + 1] - f[i];
  }
}

double normalizeSignal(double f[], int length) {
  
  double groessterWert = 0; 
  double runden;
  
  for (int i = 0; i < length; i++) {
    
    if (abs(f[i]) > groessterWert) {
      
      groessterWert = abs(f[i]);
    }
  }
  
  for(int i = 0; i < length; i++) {
    
    f[i] = f[i] / groessterWert;
    runden = round(f[i]);
    f[i] = runden;
  }
  return 0;
}

double getMaxValue(double f[], int length, int *x) {
  
  double groessterWert = 0;
  
  for (int i = 0; i < length; i++) {
    
    if (abs(f[i]) > groessterWert) {
      
      groessterWert = abs(f[i]);
      *x = i;
    }
  }
  return 0;
}

int findRPeak(double f_2diff[], double f_orig[], int length, double rpeak[], int rpeak_length) {

    int nz_legnth = 0;
    int qrs_complex_start = -1, qrs_complex_end = -1;
    int rpeak_i = 0;
    int x = 0;

    const int nsep = 0.6 * ECGDATA_SAMPLE_RATE;

    

    for( int i = 0; i < length; ++i) {

        if (f_2diff[i] != 0) {

            qrs_complex_start = i;
            qrs_complex_end = i;
            break;
        }
    }

    

    for( int i = qrs_complex_start + 1; i < length; ++i) {

        if (f_2diff[i] != 0) { 

            if ( (i - qrs_complex_end) >= nsep ) { 

                if (rpeak_i < rpeak_length) {
                  
                   getMaxValue(&f_orig[qrs_complex_start], qrs_complex_end - qrs_complex_start, &x);
                   rpeak[rpeak_i] = x + qrs_complex_start;

                    

                    ++rpeak_i;
                    qrs_complex_start = i;
                }
                else {
                    break;
                }
            }
            qrs_complex_end = i;
        }
    }
    
    
    if (qrs_complex_end > qrs_complex_start) {

        getMaxValue(&f_orig[qrs_complex_start], qrs_complex_end - qrs_complex_start, &x);
        rpeak[rpeak_i] = x + qrs_complex_start;
        
        ++rpeak_i;
    }
    return rpeak_i;
}

void printHeartRate(double rpeak[], int length, double f_rpm[]) {
  
  int anzahl;
  
  for(int i = 0; i < (length - 1); i++) {
    anzahl = rpeak[i + 1] - rpeak[i];
    f_rpm[i] = (ECGDATA_SAMPLE_RATE * 60) /anzahl;
  }
    
}

void printSortHeartRate(double rpeak[], int length){
  
  double f_rpm[length - 1];
  int i, j, tmp;
  
  printHeartRate(rpeak, length, f_rpm);

  for (i = 1; i < length; i++) {
    for (j = 0; j < length - 1 ; j++)  {
      if (f_rpm[j] > f_rpm[j + 1]) {
          tmp = f_rpm[j];
          f_rpm[j] = f_rpm[j + 1];
          f_rpm[j + 1] = tmp;
      }
    }
    printf("\t%.2lf\n", f_rpm[i]);
  }
}
  
int changeFeld(double f[], double f_orgin[], int length) {
  
  for (int i = 0; i < length; i++) {
    f_orgin[i] = f[i];
  }
  return 0;
}

int main () {
  
  double f[999];
  double f_orig[999];
  double rpeak[10];
  int rpeak_length = 10; 
  int length = 999;
  
  
  readDataFromFile("mdata.csv", f, length, &length);
   writeData2File("EKG1.csv", f, length);
  double offset = removeOffset(f, length);
  calcMovingAveraging(f, length);
  changeFeld(f, f_orig, length);
  writeData2File("EKG_gefiltert.csv", f, length);
  diffSignal(f, length);
  normalizeSignal(f, length);
  diffSignal(f, length);
  writeData2File("EKG3.csv", f, length);
  double rpeak_i = findRPeak(f, f_orig, length, rpeak, rpeak_length); 
  printSortHeartRate(rpeak, rpeak_i);
  system("python3 plotdata.py EKG3.csv");
  return 0;
}
