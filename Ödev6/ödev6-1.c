/***********************************************************************************************************************
Amacınız C dilinde maksimum karı elde edebilen algoritma tasarlamaktır.

Örnek 1. 
Girdi=> 7, 1, 5, 3, 6, 4 // Malın i. gün için satış fiyatları
Çıktı=> 7 // çıktıda elde edilen maksimum kar yazılacaktır.
Fiyatlar sırasıyla 7, 1, 5, 3, 6, 4 olsun. Bu dizi için cevap 7 olur. Bunu elde etmek için 2. Gün 1 liradan alır, 3. Gün 5 liradan satarız. 
Sonra 4. Gün 3 liradan alır, 5. Gün 6 liradan satarız ve karımız 5-1+6-3=7 olur.

Örnek 2. 
Girdi=> 1, 2, 3, 4, 5
Çıktı=> 4
Fiyatlar sırasıyla 1, 2, 3, 4, 5 olsun. Bu dizi için kar 4 lira olur, bunu elde etmek için 1. Gün 1 liradan alır, 5. Gün 5 liradan satarız, kar 5-1=4 lira olur.

Örnek 3. 
Girdi=>7, 6, 4, 3, 1
Çıktı=> 0
Fiyatlar sırasıyla 7, 6, 4, 3, 1 olsun. Bu dizi için kar 0 lira olur, malı hangi gün alırsak, diğer günlerdeki fiyat daha küçük olacağından satıştan kar edemeyiz.
*************************************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int MaxKar (int P[],int b,int s)
{
   if (s<=b)
   {
      return 0;
   }

   int Kar = 0;
   int yeni_kar;
   
   for (int i = b; i < s; i++)
   {
      for (int j = i+1; j < s; j++)
      {
         if (P[j] > P[i])
         {
            yeni_kar = P[j] - P[i] + MaxKar(P,b,i-1) + MaxKar(P,j+1,s);
            if (yeni_kar > Kar)
            {
               Kar = yeni_kar;
            }            
         }         
      }      
   }
   return Kar;
}

int main( )
{
   int *B;
   char A[50], *p;
   fgets(A,50,stdin);

   int length = strlen(A);
   int size = 1;
   B = (int*)malloc(sizeof(int)*length);

   p = strtok (A, ","||" ");
   while (p != NULL)
   {
      B[size] = atoi(p);
      size++;
      p = strtok (NULL, ","||" ");      
   }

   int kar = MaxKar(B,1,size);   
   printf("%d\n",kar);

   return 0;
}