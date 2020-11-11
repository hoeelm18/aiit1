#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_WINDOW_SIZE 100
#define MDATA_MAX_SIZE 1000


double getSinusWithNoise(double f[], int length, double length_period, double amplitude, double offset, double amplitude_noise)
{



    for(int i=0; i <length ; i++)
        f[i] = amplitude * sin(2*M_PI/length_period * i) + offset + (rand() % 100) * amplitude_noise/100;



    return 0;
}

double removeOffset(double f[], int length)
{   
  
    double x = 0;
    double summe = 0;
	double offset = 0;
    
    for(int i=0; i < length; ++i)
        summe += f[i];
		
    offset = summe/length;
    
    for(int i=0; i < length; ++i)
    {
      
        f[i] -= offset;
        
    }
    
    return offset;
}



void calcMovingAveraging(double f[], int length)
{
    int s = 0;
    int n = 10;
    
    
    for(int f_i = 0; f_i < length; f_i++)
      
    {
      
        if( f_i <= 989){
            
        
            for(int data_i = 0; data_i < n; data_i ++)
            {
              
            s = s + f[f_i+data_i]; 

            }
            
            f[f_i] = s/n;
        
        }else{
            break; 
        }   
        if( f_i = 990){ 
          
          for(int data_i = 0; data_i < 9; data_i ++)
            
            {
            
            s = s + f[f_i+data_i]; 

            }
          
            f[f_i] = s/n;  
            
        }
        
    }
    
}



int main()
{
		double mdata[MDATA_MAX_SIZE];
    double offset = 0.0;
    

    getSinusWithNoise(mdata, MDATA_MAX_SIZE, 100.0, 2.0, 1.0, 0.0);
    offset = removeOffset(mdata, MDATA_MAX_SIZE);
    
    if (offset == 1.0)
    	printf("HuHu\n");
    else
    	printf("Offset-Differenz %3.2f", 1.0 - offset);
    return 0;
    
}