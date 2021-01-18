#include <stdio.h>
 
int attribute(int a, int b,int counter){
        if( a%2==0 && b%2==0 ){
            printf("a ");
            a=a/2;
            b=b/2;
            counter++;
            return attribute(a,b,counter);
        }
        else if( a%2==0 && b%2==1){
            printf("b ");
            a=a/2;
            return attribute(a,b,counter);
        }
        else if(b==0){
            printf("c ");
            return counter*a;
        }
        else if( a>=b ){
            printf("d ");
            int t=a-b;
            a=b;
            b=t;
            return attribute(a,b,counter);
        }
        printf("e ");
        return attribute(b,a,counter);
}

int main(void){
    int a, b;
    scanf("%d%d", &a, &b);
    printf ("%d",attribute(a,b,1));
    return 0;
}