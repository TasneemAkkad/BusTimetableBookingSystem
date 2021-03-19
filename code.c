#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FirmaGiris();
int HexaRandom();
void OtobusEkle();
void SeferBilgileri();
void SeferKoltukBilgileri();
void MusteriGiris();
FILE *fptr;
//variables
int secenek;
int kapasite;
char model[10];
int otobusNo[50];
int i;
int seferNo;
int seferBS;
int otobusNo[50];
int seferVS;
char const ogrNo = '01';
char sehir1[20];
char sehir2[20];
int toplamHasilat;
int ucret;
char ad[20];
char soyad[20];
int koltukNo;
int rezNo;
int musteriGirisi;

int main()
{

   fptr = fopen("C:\\program.txt","w+");


    int giris;
    anaMenu:
    printf("*******Ana Menu*******\n 1.FIRMA GIRIS\n 2.MUSTERI GIRIS\n 3.CIKIS\n");
    printf("Lutfen bir giris yapiniz:\n");
    scanf("%d",&giris);
    if(giris==1)
    {
        FirmaGiris();
    }
    else if(giris==2){

        MusteriGiris();
    }
    else{
        printf("CIKIS!");

    }

    fclose(fptr);
    return 0;
}

void FirmaGiris()
{


    firmaGrisi:
    printf(" 1.Otobus Ekle\n 2.Sefer Bilgisi Ekle\n 3.Sefer Koltuk Bilgi\n 4.Bir Ust Menuye Don\n Lutfen bir giris seciniz:\n");
    scanf("%d", &secenek);

    if (secenek == 1)
    {
        OtobusEkle();

        goto
             firmaGrisi;
    }

    else if(secenek == 2)
    {
        SeferBilgileri();
    }

    else if(secenek==3)
    {
         SeferKoltukBilgileri();
    }
    else if(secenek==4){
       printf("*******Ana Menu*******\n 1.FIRMA GIRIS\n 2.MUSTERI GIRIS\n 3.CIKIS\n");
       printf("Lutfen bir giris yapiniz:\n");
    }
    else{
        printf("uygun olmayan bir giris yaptiniz!!");
    }

}

void OtobusEkle()
{

    printf("otobus bilgileri ekle:\n");
    printf("otobus kapasitesi giriniz (kac kisilik): \n");
    scanf("%d", &kapasite);

    if(kapasite<30)
    {
        printf("kisa yol otobusu eklendi\n");
        printf("presonel sayisi: 2dir \n");
    }
    else
    {
        printf("uzun yol otobusu eklendi\n");
        printf("presonel sayisi: 3tur \n");
    }

    printf("otobusun modeli giriniz:\n");
    scanf("%x", &model);

    for(int i = 0; i < secenek; ++i)
    {
        printf("otobus numarasi :%d\n", otobusNo[i]);
    }

}

void SeferBilgileri()
{

    printf("sefer bilgileri ekle:\n");

    printf("sefer no:");
    HexaRandom();

    printf("\notonusun numarasi %d : \n", otobusNo[i]);
    fprintf(fptr, "otobusun numarasi %d : ", otobusNo[i]);
    fprintf("%d", otobusNo[i]);

    printf("lutfen saat baslangici giriniz: \n");
    scanf("%d", &seferBS);
    fprintf(fptr,"%d:%d", seferBS,ogrNo);

    printf("sefer baslangic saati : %d:%c\n", seferBS,ogrNo);

    if(seferBS>24)
    {
        printf("Sefer bu saatte gerceklesemez\n");
    }
    printf("varis saati giriniz : \n" );
    scanf("%d", &seferVS);
    fprintf(fptr, "%d", seferVS);

    if(kapasite<30 && seferVS<(seferBS+5))
    {
        printf("kisa yol otobus kullanilmalidir\n");
    }
    else
    {
        printf("uzun yol otobus kullanilmalidir\n");
    }
    printf("sefer baslangic sehir giriniz: \n");
    scanf("%s", &sehir1[20]);
    fprintf(fptr,"%s", sehir1[20]);
    printf("sefer bitis sehir giriniz: \n");
    scanf("%s", &sehir2[20]);
    fprintf(fptr,"%s", sehir2[20]);
    printf("bu sefer icin toplam hasilat giriniz: \n");
    scanf("%d", toplamHasilat);
    printf("otobusun kapasitesi giriniz (koltuk sayisi) :\n");
    scanf("%d", &kapasite);
    fprintf(fptr,"%d", kapasite);
    ucret=kapasite/toplamHasilat;
    printf("fiyat bir kisi icin : %d", ucret);

}

void SeferKoltukBilgileri()
{
    seferNo = HexaRandom();
    printf("suana kadar tum seferlerin numaralari %d", seferNo);
    printf("sefe numarasi seciniz: \n");
    scanf("%d", &seferNo );
    //printf(" 1.Admin giris\n2.Musteri giris\n3.Cikis\n");



}


void MusteriGiris(){
    ustMenu:
printf("1.seferleri listele\n2.sefer rezarvasyonu yap\n3.bir ust menuya don\n4.rezarvasounu goster\n");
scanf("%d", &musteriGirisi);
if(musteriGirisi==1){

}
else if(musteriGirisi==2){
        printf("otonus numarasi giriniz:\n");
        scanf("%d", otobusNo[i]);
        printf("lutfen adinizi giriniz:\n");
        scanf("%s",&ad[20]);
        printf("luften soyadinizi giriniz:\n");
        scanf("%s", &soyad[20]);
        printf("lutfen koltuk seciniz: \n");
        scanf("%d", &koltukNo);


}
else if(musteriGirisi==3){
    goto
        ustMenu;
}
else if(musteriGirisi==4){
        printf("rezarvasyon numarasi giriniz:");
        scanf("%d", &rezNo);
        printf("ad: soyad: %d %d", ad, soyad);
        fscanf(fptr, " %d \n%d \n%s\n %s\n %d:%d\n%d:%d\n", seferNo,otobusNo, sehir1, sehir2, seferBS,ogrNo, seferVS,ogrNo  );

}
else{
    printf("uygun olmayan bir giris yaptiniz!!");
}



}


//bu function random hexacedimal sayi üretmek için
int HexaRandom()
{
    int length;
    char str[] = "0123456789ABCDEF";
    /* Seed number for rand() */
    srand((unsigned int) time(0) + getpid());
    length = rand() % 15 + 8;

    while(length--)
    {
        printf("01");
        putchar(str[rand() % 16]);
        srand(rand());
    }

    return EXIT_SUCCESS;
}
