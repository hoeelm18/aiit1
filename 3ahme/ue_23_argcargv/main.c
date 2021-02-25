#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main (int argc, char* argv[]){
  
  
  double fzahlfalsch[100];
  double fzahl[100];
  double merker; 
  double min;
  double max;
  int n;
  int x;
  int zaehler;
    
  for(int j = 0; j < argc; j++){

    n =  sscanf( argv[j], "%lf", &fzahl[j]);
    if (n == 1){
        
     zaehler++;
     
       if (zaehler > 10){
         return 1;
          
     }
      
   }
      
 }

  for(int y = argc - zaehler; y < argc; y++){
      
    x = sscanf(argv[y], "%lf", &fzahlfalsch[y]);
    
    if(x != 1){
        
    printf("\n\tBuchstabe als Eingabe nicht erlaubt!\n\n");
    return 1;
        
  }
      
 }


  for(int k = 0; k < (argc-zaehler); k++){

    if (strcasecmp("-sum", argv[k+1]) == 0){
        
      merker = 0;
      for(int l = 0; l < argc; l++){
          
        merker = merker + fzahl[l];
          
      }
        
    printf("\nSumme: \t %lf\n", merker);
      
   
    }else if (strcasecmp("-avg", argv[k + 1]) == 0){
      merker = 0;
      for(int l = 0; l < argc; l++){
          
        merker = merker + fzahl[l];
          
      }
      
    merker = merker / zaehler;
    printf("\nDurchschnitt: \t %lf\n", merker);
      
      

    }else if (strcasecmp("-min", argv[k + 1]) == 0){
        
    merker = 0;
    min = fzahl[argc - zaehler];
      for(int l = argc - zaehler; l < argc; l++){
          
        if (fzahl[l] < min) {
            
          min = fzahl[l];
            
       }
          
     }
      
      printf("\nMinimal: \t %lf\n", min);
     
      
      
   }else if (strcasecmp("-max", argv[k + 1]) == 0){
        
    merker = 0;
    max = fzahl[0];
      for(int l = 0; l < argc; l++){
          
        if (fzahl[l] > max) {
            
          max = fzahl[l];
          
      }
        
    }
      
      printf("\nMaximal: \t %lf\n", max);
      
    }

  }
    
  return 0;
  
}