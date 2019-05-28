
/*
 * STM32F4 FIRST HOMEWORK
 *
 * Mehmet KÜÇÜK
 * Sedat Server YURT
 *
 *
 *
 * 25.03.2018
 *
 * moving avarage
 * isarat convalition yapacagız 5 durum var mesela xn imiz 0 ile 20 arasında deger alıyor.hn imiz ise 0 ile 5 isarette
 *convalusyon yaptıgımızda
 *birinci durum hn son degeri 0 dan küçük değerlerde 0 dir else teki durum
 *ikici durum hn sondegeri 0 ile 4 arasında  toplam sembolu (for)
 *üçüncü drum hn sondeğeri 5 20 arasında toplam sembolu (for)
 *dörtdüncü durum hn son değeri 21 ile 24 arasında toplam sembolu (for)
 *beşinci surum hn son değeri 25 ve sonraki degerleri 0 dir else durumu
 */
#include <stdio.h>
#include <stdlib.h>

int i,j;

double variableTransientNumber(); // kac tane integer ile sample adıgım (tirenziyent respond daki M gibi düşüne biliriz gibi de ) degeri girilecegi kullanicidan alinacak.
double variableNumber();//X[n] işaretinin n boyuuncaki girdisi
double *variableAvarage();// sınırlarda problem var.
int * variablexn(int c);
int *variableretun();


int main()
{
    variableAvarage();
}

double variableTransientNumber()//Hn boyutu kulanıcıdan aldı
{
    double N;
    printf("h[n] boyutu \n");
    scanf("%lf",&N);

    return N;

}

double variableNumber()//xn boyut kulanıcıdan aldı
{
    double T;
    printf("x[n] boyutu \n");
    scanf("%lf",&T);

    return T;
}
double *variableAvarage()
{

    int x; int h;
    int * numxn;


    double sum;
    i=0;
    j=0;
    h=variableTransientNumber();//hn
    x=variableNumber();//xn
    numxn=variablexn(x); // kullanıcıya xn değeri girecek

    double arrVariableyn[x+h-1]; // sonucun degeri
    do
    {
        sum=0;
        if (i<h) //ikinci durum
        {

            for(j=i;j>=0;--j)
            {


                sum=sum+(double)numxn[i];


            }
            arrVariableyn[i]=sum/h;

        }
        else if(i>=h && i<x)// üçünçü durum
        {
            for(j=h;j>0;--j)
            {

                sum=sum+(double)numxn[i];

            }
            arrVariableyn[i]=sum/h;

        }
        else if(i>=x && i<h+x-1) // 4. durum
        {
            for(j=0;j<h-1-(i%x);++j)
            {

                sum=sum+(double)numxn[j];

            }
            arrVariableyn[i]=sum/h;
        }
        else //diger durumlar
        {
            sum=0;
            arrVariableyn[i]=0;
            printf("eror!!!!!\n");
        }



        i++;
    } while(i<x+h-1); // convalutiun islemini iki döngu ile halletik
    for(i=0;i<h+x-1;++i) //sonucu ekrana yazdırma
    {
        printf("%f\n", arrVariableyn[i]);
    }


    return arrVariableyn;
}

int * variablexn(int c) //degerleri kullanıcıya girmesi
{

    int *num = malloc(sizeof(int)*c);
    int i;
    for (i = 0; i < c; ++i)
    {
        printf("xn %d giriniz\n",i);
        scanf("%d",&num[i]);

    }
    return num;

}
