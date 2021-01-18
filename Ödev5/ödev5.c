/**************************************************************************************************
Problem: Giriş değişkenlerimiz 10 tane 3 basamaklı pozitif tam sayıdan oluşan bir G dizisidir. Bu sayıları kullanıcıdan alıcaksınız. 
Amacımız bu sayıları küçükten büyüğe doğru sıralalama iddiası bulunan Hollerith algoritmasının kaç tane hata yaptığını bulmaktır. 
Bunun için aynı kodun içinde birbirine benzeyen ama farklı 2 yöntem kullanacaksınız.

1. yöntem, taban sıralaması (radix sort) algoritmasıdır.
Bu algoritmada, G dizisindeki sayıları önce birler basamağındaki rakamlara göre, sonra onlar basamağındaki rakamlara göre 
ve en son olarak da yüzler basamağındaki rakamlara göre sıralayacaksınız. Rakamlara göre sıralamaları aşağıda sözde kodu verilen 
sayarak sıralama algoritması ile yapacaksınız. Sıralanmış sayıları bir S1 dizisine yazacaksınız.
2. yöntem, Hollerith algoritmasıdır. (Genel durumda doğru sıralama yapmaz.)
Bu algoritmada G dizisindeki sayıları önce yüzler basamağındaki rakamlara göre, sonra onlar basamağındaki rakamlara göre ve en son 
olarak da birler basamağındaki rakamlara göre sıralayacaksınız. Rakamlara göre sıralamaları yine de aşağıda sözde kodu verilen 
sayarak sıralama algoritması ile yapacaksınız. Sıralanmış sayıları bir S2 dizisine yazacaksınız. Daha sonra ekrana S1 dizisini 
(elemanları arasında boşluk bulunarak), S2 dizisini (elemanları arasında boşluk bulunarak) yazdıracaksınız.
Son olarak, S1 ve S2 dizisinin uygun elemanlarını karşılaştırarak kaç tanesinin eşit olmadığını bulacaksınız ve ekrana m tane 
eşit olmayan ikili bulduğunuzda “%(m*10) hata” yazısını yazdıracaksınız.

Örnek : Girdi, çıktı kısımları ekrana yazdırılmayacaktır.

Girdi=> 111 222 333 666 555 444 777 888 999 123
Çıktı=> 
111 123 222 333 444 555 666 777 888 999
111 222 123 333 444 555 666 777 888 999
%20 hata

Girdi=> 123 236 547 852 698 452 145 852 963 354
Çıktı=> 
123 145 236 354 452 547 698 852 852 963
452 852 852 123 963 354 145 236 547 698
%100 hata

***************************************************************************************************/
#include <stdio.h>

void radix(int r[]){
     int temp;
     for(int tur = 0; tur < 10; tur++)
     {
          for(int i = 0; i < 9; i++)
          {
               if(r[i]%10 > r[i+1]%10)
               {
                    temp=r[i];
                    r[i]=r[i+1];
                    r[i+1]=temp;
               }
          }
     }

     for(int tur = 0; tur < 10; tur++)
     {
          for(int i = 0; i < 9; i++)
          {
               int a = (r[i]%100 - r[i]%10) / 10;
               int b = (r[i+1]%100 - r[i+1]%10) / 10;
               if(a > b)
               {
                    temp=r[i];
                    r[i]=r[i+1];
                    r[i+1]=temp;
               }
          }
     }

     for(int tur = 0; tur < 10; tur++)
     {
          for(int i = 0; i < 9; i++)
          {
               int a = (r[i] - r[i]%100 - r[i]%10) / 100;
               int b = (r[i+1] - r[i+1]%100 - r[i+1]%10) / 100;
               if(a > b)
               {
                    temp=r[i];
                    r[i]=r[i+1];
                    r[i+1]=temp;
               }
          }
     }
}

void Hollerith(int h[]){
     int temp;
     for(int tur = 0; tur < 10; tur++)
     {
          for(int i = 0; i < 9; i++)
          {
               int a = (h[i] - h[i]%100 - h[i]%10) / 100;
               int b = (h[i+1] - h[i+1]%100 - h[i+1]%10) / 100;
               if(a > b)
               {
                    temp = h[i];
                    h[i] = h[i+1];
                    h[i+1] = temp;
               }
          }
     }

     for(int tur = 0; tur < 10; tur++)
     {
          for(int i = 0; i < 9; i++)
          {
               int a = (h[i]%100 - h[i]%10) / 10;
               int b = (h[i+1]%100 - h[i+1]%10) / 10;
               if(a > b)
               {
                    temp = h[i];
                    h[i] = h[i+1];
                    h[i+1] = temp;
               }
          }
     }

     for(int tur = 0; tur < 10; tur++)
     {
          for(int i = 0; i < 9; i++)
          {
               if(h[i]%10 > h[i+1]%10)
               {
                    temp = h[i];
                    h[i] = h[i+1];
                    h[i+1] = temp;
               }
          }
     }
}

void printFunc(int x[]){
     for(int i=0; i<10; i++)
     {
          printf("%d ", x[i]);
     }
}

void error(int x[],int y[]){
     int counter=0;
     for(int i=0; i<10; i++)
     {
          if(x[i] != y[i])
          {
               counter++;
          }
     }
     printf("%%%d hata",counter*10);     
}

int main()
{
     int a[10], r[10], h[10];

     for(int i=0; i<10; i++)
     {
          scanf("%d", &a[i]);
          r[i]=a[i];
          h[i]=a[i];
     }

     radix(r);
     Hollerith(h);

     printFunc(r);
     printf("\n");
     printFunc(h);
     printf("\n");
     error(r,h);

return 0; 
}