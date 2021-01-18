#include <stdio.h>

int main()
{
    float number;
    scanf("%f",&number);
    float x=2;
    int counter=0;

    if(number>=2)
    {
        while(x<=number){
            x=x*2;
            counter++;
        }
    }

    else if (number>0 && number<1)
    {   
        x=1;
        while (x>=number)
        {
            x=x/2;
            counter--;
        }        
    } 
    float a=1;
    while(a>0.000000001){
    a=a/2;
	    if(a==number){
	    counter++;
	    break;
	    }    
    }       
    printf("%d",counter);
    return 0;
}
