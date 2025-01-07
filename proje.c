#include <stdio.h>
#include <stdlib.h>

struct veriler{
	char isim[20];
	int yas;
	long long int tc;
	char kan[5];
	char sikayet[20];
	int kod;
};


void girdi(struct veriler *hastalar, int hasta_sayisi) {
  for(int i=0; i<hasta_sayisi; i++){
		printf("\n%d numarali hastanin ozelliklerini giriniz\n",i+1);
		printf("adi(bosluk kullanmayin):  ");
		scanf("%s",hastalar[i].isim);
		printf("yasinizi giriniz:  ");
		scanf("%d",&hastalar[i].yas);		
		printf("TC:  ");
		scanf("%lld",&hastalar[i].tc);
		printf("kan grubu:  ");
		scanf("%s",hastalar[i].kan);
		printf("sikayetinizi giriniz(bosluk kullanmayin):  ");
		scanf("%s",hastalar[i].sikayet);
		printf("durumunuz acil ise \"1\" yazin:  ");
		scanf("%d",&hastalar[i].kod);	
	}
}


void siralama(struct veriler hastalar[], int hasta_sayisi){
	
    for (int i = 0; i < hasta_sayisi - 1; i++) {
        for (int j = 0; j < hasta_sayisi - i - 1; j++) {
            if (hastalar[j].kod < hastalar[j + 1].kod) {
                struct veriler x = hastalar[j];
                hastalar[j] = hastalar[j + 1];
                hastalar[j + 1] = x;
            }
        }
    }	
}


void muayene(struct veriler *hastalar, int hasta_sayisi) {
	int a;
	for(int i=0; i< hasta_sayisi; i++){
	    printf("\n=====================================================================");		
		printf("\n%d numarali hastanin bilgileri",i+1);
		printf("\nadi:  %s",hastalar[i].isim);
		printf("\nyas:  %d",hastalar[i].yas);
		printf("\nTC:  %lld",hastalar[i].tc);
		printf("\nkan grubu:  %s",hastalar[i].kan);
		printf("\nsikayeti:  %s",hastalar[i].sikayet);
		printf("\naciliyet durumu:  %s\n",hastalar[i].kod == 1 ? "VAR" : "YOK");		
	    printf("=====================================================================\n");
		
		printf("\nsiradaki icin herhangi bir sayiya basin: ");
		scanf("%d",&a);
	}
	printf("\nsirada hasta kalmadi.\n");
}


void ozet(struct veriler *hastalar, int hasta_sayisi) {
	printf("\n=====================================================================");
    printf("\nHasta ozeti:\n");
    for (int i = 0; i < hasta_sayisi; i++) {
        printf("Hasta %d -   isim: %s   |   TC: %d   |   Acil Durum: %s\n", i + 1
		, hastalar[i].isim, hastalar[i].tc, hastalar[i].kod == 1 ? "VAR" : "YOK");
    }
	printf("=====================================================================\n");    
}


int main() {
    int hasta_sayisi;
    int secim2;
    printf("Kac hasta girilecek: ");
    scanf("%d", &hasta_sayisi);

    struct veriler hastalar[hasta_sayisi];

    girdi(hastalar, hasta_sayisi);
	printf("\nseciminizi yapin\n");
	
	do{
	printf("muayene(1)   ozet(2):  ");
	scanf("%d",&secim2);
    }while (secim2 != 1 && secim2 != 2);
	
	siralama(hastalar, hasta_sayisi);
	
	switch(secim2){
		case 1: muayene(hastalar, hasta_sayisi); 
        break;
		case 2: ozet(hastalar, hasta_sayisi);
        break;
	}
    return 0;
}






