#include <stdio.h>
#include <stdlib.h>

int sayi; 
int *x;

int main()
{       
    scanf("%d", &sayi);
     
    x = (int*)malloc(sizeof(int)*sayi);
    
    int a=0;
    
    for( ; a<sayi ; a++)
    {
    	x[a]=0;    
    }    
    
    for( int j=1 ; j<=sayi ; j++)
    {
    	for( int k=1 ; k<=sayi ; k++)
    	{
    		if( k%j == 0)
    		{
    			if( x[k-1] == 0 )
    			{	
    				x[k-1]=1;
    			}
    			else
    			{
    				x[k-1]=0;
    			}
    		}    	  
    	}
    }
        
    for(int j=0 ; j<sayi ; j++)
    {
       	if(x[j] == 1)
       	{
       		printf("%d ",j+1);
       	}    
    }
      
    return 0;
}
