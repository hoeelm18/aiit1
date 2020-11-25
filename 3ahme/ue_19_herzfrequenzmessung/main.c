#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MDATA_MAX_SIZE   1000
#define MOVINGAVERAGING_WINDOW_SIZE   10
#define NO_ERROR 0
#define OUT_OF_MEMORY_ERROR 1
#define FILE_ERROR 2
#define Fenster 4

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
  
  for(int i = 0; i < length; i++) {
    
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

int main () {
  
  double f[999];
  int length = 999;
  
  readDataFromFile("mdata.csv", f, length, &length);
   writeData2File("EKG1.csv", f, length);
  double offset = removeOffset(f, length);
  calcMovingAveraging(f, length);
  writeData2File("EKG_gefiltert.csv", f, length);
  diffSignal(f, length);
  normalizeSignal(f, length);
  writeData2File("EKG3.csv", f, length);
  system("python3 plotdata.py EKG1.csv EKG3.csv");
  return 0;
}
