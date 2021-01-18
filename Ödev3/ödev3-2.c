/******************************************************************************************
A[1...n] dizisinin elemanları [1, n] aralığından olan farklı tam sayılardır. 
Eğer A[i1]=i2, A[i2]=i3,...A[ik-1]=ik ve A[ik]=i1 ise (i1,i2, ...ik) indisler dizisine k uzunluklu döngü denir.
Bir i için A[i]=i ise (i) 1 uzunluklu döngüdür. Örneğin; 4, 6, 3, 5, 8, 7, 2, 1 dizisinde (1, 4, 5, 8)
dizisi 4-uzunluklu döngüdür. Bu dizide (2, 6, 7) dizisi 3 uzunluklu ve (3) ise 1 uzunluklu döngülerdir.
Yani bu dizide 3 adet döngü vardır. Verilen bir dizinin döngü sayısını O(n) işlem zamanında bulabilen bir 
algoritmanın kodunu yazınız. (Array indislerinin 0 değil 1’den başladığı farz edilecektir.)

Girdi=> 8 4 6 3 5 8 7 2 1       // n=8, A[] = {4, 6, 3, 5, 8, 7, 2, 1 }

Çıktı=> 1 4 5 8                 // A[1] = 4; A[4] = 5; A[5] = 8; A[8] = 1 => döngü
        2 6 7                   // A[2] = 6; A[6] =7; A[7]=2 => döngü
        3                       // A[3] = 3 => 1 uzunluklu döngü
*******************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
        int *A, *B, n, counter=1;
        scanf("%d", &n);
        A = (int*)malloc(sizeof(int)*n);
        B = (int*)malloc(sizeof(int)*n);
        for(int i=0; i<n; i++)
        {                
                scanf(" %d", &A[i]);
                B[i] = 1;
        }
        
        for(int i=0; i<n; i++)
        {
                if(B[i]==1)
                {
                        if( A[i]!=counter )
                        {
                                printf("%d ", A[i]);
                                B[i]=0;
                                i=A[i]-2;
                        }
                        else
                        {
                                printf("%d\n", A[i]);
                                B[i]=0;
                                i=counter-1;
                                counter++;
                        }
                }                
        }
/*
        printf("\n\n");
        for(int i=0; i<2*n; i++){
                if(i<n){
                        printf("%d ",A[i]);                        
                }
                else if(i==n){     printf("\n");  }
                if(i>=n){
                        printf("%d ",B[i-n]);                        
                }
        }
        printf("\ncounter : %d", counter);
*/
return 0;
}