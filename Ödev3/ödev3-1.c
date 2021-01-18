/*************************************************************************************************

n elemanlı bir A dizisi veriliyor. Bu dizinin yardımıyla elemanları B[i]=A[i+1]-A[i] (i=1,2,…n-1)
koşuluna uyan n-1 elemanlı bir B dizisi oluşturuluyor. B dizisinin ardışık terimlerinden oluşan ve
artan en uzun alt dizisinin uzunluğunu O(n) işlem zamanında bulabilen algoritmanın kodunu yazınız.
(Kodunuzun girişi A dizisi ve n sayısıdır, algoritmanızın tasarımda A dizisi dışında başka bir dizi
kullanımına izin verilmemektedir, yani algoritmanızda B dizisini de kullanamazsınız.)

Örnek:
Girdi=> 7 1 2 4 8 10 16 5     // n=7, A[] = {1, 2, 4, 8, 10, 16, 5}
Çıktı=> 1 2 4                 // B[] dizisi {1, 2, 4, 2, 6, -11} olmaktadır.Artan en uzun alt dizisi 1,2,4’tür.

Denemelerim:
10 5 6 8 13 16 17 24 33 43 51
1 7 9 10

10 3 4 6 9 8 10 13 17 22 29
-1 2 3 4 5 7

10 5 9 10 13 18 24 31 36 44 46
1 3 5 6 7

10 4 5 7 10 14 15 17 20 24 29
1 2 3 4 5

8 8 9 11 14 18 23 24 26
1 2 3 4 5 

11 3 7 8 11 2 5 4 7 9 21 52
2 12 31

11 1 2 4 8 10 16 5 7 10 14 19
-11 2 3 4 5
***********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
     int n, *A,enUzun=1,basIndex=0,uzunluk=1;
     scanf("%d", &n);
     A = (int*)malloc(sizeof(int)*n);
     
     for(int i=0 ; i<2*n-1 ; i++)
     {          
          if( i>0 && i<n )
          {
               scanf(" %d", &A[i]);
               A[i-1] = A[i] - A[i-1];
               if( i>1 && i<n )
               {
                    if( A[i-1] > A[i-2] )
                    {
                         uzunluk++;
                         if(uzunluk>=enUzun && i==n-1){
                              enUzun=uzunluk;
                              basIndex=i-uzunluk;
                         }
                    }
                    else if( uzunluk>=enUzun && uzunluk!=1 )
                    {
                         enUzun=uzunluk;
                         basIndex=i-(uzunluk+1);
                         uzunluk=1;
                    }
                    else uzunluk=1;
               }
          }
          if( n+basIndex<=i && i<n+basIndex+enUzun ){
               printf("%d ",A[i-n]);
          }
     }
return 0; 
}