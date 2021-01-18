/**************************************************************************************************
2. Aşağıdaki problemi Θ(n) işlem zamanında yapabilen C kodunu yazınız.

Kullanıcıdan pozitif tam n (n>1) sayısı girmesini isteyiniz. Kullanıcı n sayısını girdikten sonra tekrardan n tane tam sayı girmesini isteyiniz. 
Kullanıcının girdiği sayılar A[1],...A[n] ise ilk sıraya A[2]...A[n] çarpımını, 2. sıraya A[1].A[3]...A[n], 3. sıraya A[1].A[2].A[4]...A[n],...
n. sıraya A[1].A[2]...A[n-1] çarpımını yazınız.
Problemin çözümünde bölme işlemi kullanılmayacaktır ve bölme işlemi yapılan kodlar değerlendirilmeyecektir.
Yazdığınız kod script ile değerlendirilecektir. Dolayısıyla aşağıda belirtilen girdi ve çıktı formatlarına uymanız zorunludur.

Örnek : Aşağıdaki tablo örnek girdi ve çıktıları düzgün göstermek için yapılmıştır. Sizin ekrana tablo bastırmanıza gerek yok. 
Kullanıcıdan ilk n değerini alınıp, daha sonra n tane eleman girmesi beklenmektedir.

Girdi=> 3 1 2 3 // n=3
Çıktı=> 6 3 2 // 2x3 1x3 1x2

	 Girdi						Çıktı
	3 1 2 3						6 3 2
5 10 20 30 40 50         1200000 600000 400000 300000 240000
	2 15 25						25 15

***************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
     int n, *A, *B,i=0,j=0;
     scanf("%d", &n);
     A = (int*)malloc(sizeof(int)*n);
     B = (int*)malloc(sizeof(int)*n);
     
     for(int i=0 ; i<n ; i++)
     {          
          scanf(" %d", &A[i]);
          B[i]=1;
     }
     int x=1;     
   
     while(i<n)
     {     
          printf("%d\n",x);
          x++;          
          if( i!=j )
          {
               B[i] = B[i]*A[j];                       
          }
          j++;
          if(i==j)
          {
               j++;
          }         
          if( j==n )
          {
               j=0;
               i++;                              
          }          
     }
     
     for(int i=0 ; i<n ; i++)
     {          
          printf("%d ", B[i]);
     }
     
return 0; 
}