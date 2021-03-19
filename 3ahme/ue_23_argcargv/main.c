#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getOP(char *txt){
  
  if(*txt == '+'){
    return 1;
  } else if (*txt == '-'){
    return 2;
  } else if (*txt == '*'){
    return 3;
  }else if (*txt == '/'){
    return 4;
  }
  
}
int getLengthOfNumber ( char* txt){
  
    int z;
    int a;
    int b;

    for (int i = 0; a == 0;i++){
      
        if ((txt[i] >= '0' && txt[i] <= '9') || txt[i] == '.' || txt[i] == '-'){
          
            z++;
            
            if (txt[i] == '.'){
              
                b++;
                
            }
            
            if (b > 1){
              
                printf ("\n Du hast zwei Komma eingegeben\n");
                return -1;

            }

        }else{
          
            a++;

        }
    }
    return z;

}

int calc(double num1, double num2, int op, double *result){
  
  if(op = 1){
    *result = num1 + num2;
  } else if(op = 2){
    *result = num1 - num2;
  } else if(op = 3){
    *result = num1 * num2;
  } else if(op = 3){
    *result = num1 / num2;
  }
  
}

int parseText (char*txt, int length, double *result ){
  
    double num1 = 0.0;
    double num2 = 0.0;
    int offset = 0;
    int op = 0;
    int bracket_open = 0;

    if ( *txt =='\0'){
      
        return -1;
        
    }else{
      
        op = getOP(txt);
        
    }
    
    if (txt[offset]=='('){
      
        bracket_open = 1;
        offset = offset++;
        
    }else{
      
        return 0;
        
    }
    if (txt[offset] == '('){
      
        offset = offset + parseText(txt+offset,length-offset,result);
        return offset;
        
    }else{
      
        return 0;
    }
    
    if (op == 0){
      
        if (sscanf(txt+offset, "%lf", &num1)!=1){
          
            return-1;
            
        }else{
          
            return 0;

        }
        
    }else{
      
        num1 = *result;
    }
    
    if (op == 0){
      
        return -1;
        offset = offset ++;
        
    }else{
      
         return 0;
         
    }
    
    if (txt[offset]=='('){
        offset = offset+parseText(txt+offset,length-offset,&num2);
        
    }else{
      
        if (sscanf(txt+offset, "%lf",&num2)==1)
        {
            offset = offset+getLengthOfNumber(txt+offset);
            
        }else{
          
            return-1;
        }
    }
    if((op<3)&&(txt[offset]=='*'|| txt[offset]=='/')&&(txt[offset] != ')' )){
      
        offset = offset +parseText(txt+offset,length-offset,&num2);
        //calc(num1,num2,op,result);
        
    }else{
      
        //calc(num1,num2,op,result);
        
    }
    
    if (txt[offset]==')'){
      
        if(bracket_open == 0){
          return offset;
                        
        }else{
          
            return 0;
            
        }
        offset = offset++;
        if (*(txt-1)=='*'||*(txt-1)=='*'){
          
            return offset;
                    
        }else{
          
            return 0;
            
        }

    }else{
      
        return 0;
        
    }
    if (txt[offset]==')'){
      
        return offset;
        
    }else{
        return 0;
        
    }
    
    return (offset+parseText(txt+offset,length-offset,result));
}

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