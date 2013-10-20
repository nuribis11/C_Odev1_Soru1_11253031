#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	char sifre[20];/*kullanici adi ve sifreyi tutmak icin char dizisi olusturdum.*/
	char kulAdi[20];
	int secim;
	float hesapNur=5100;/*programın calismasi icin ilk hesap degerini tanimladim*/
	float hesapTransfer;/*bankadan baska hesaba para gönderme islemi icin hesap degiskeni*/
	float hesapNo;/*kullanicidan alinan hesap numarasi*/
	float yatır;/*para yatirma islemi icin tanimlanan degisken*/
	float cek;/*para cekme islemi icin tanimlanan degisken*/
	float transfer;/*baska hesaba para yatirma isleminde transfer edilecek miktar*/
	printf("\n");
	printf("_______________________________BANKA HESAP SISTEMI______________________________");
	/*kullanici adi ve sifresini yanlis girmesi halinde tekrar edicek döngü*/
	/*programda kullanici adi=nur, sifre=1234 tanimli*/
	do
	{
		printf("\n");
		printf("Kullanici adi: ");
		scanf("%s",kulAdi);
		printf("\n");
		printf("Sifre: ");
		scanf("%s",sifre);

		if(strcmp(kulAdi,"nur")==0 && strcmp(sifre,"1234")==0)
		{
			system("cls");
			printf("\n");
			printf("Hosgeldiniz Nur ibis :) ");
			break;
		}
		else/*kullanici adi veya sifre yanlisliginda else yapisina girer*/
		{
			printf("\n");
			system("cls");
			printf("Kullanici adiniz veya sifreniz yanlis.\n");
		}
		printf("\n");
		printf("Lutfen tekrar giris yapiniz.\n");
		printf("________________________________________________________________________________\n");
	}
	while((kulAdi!="nur" && sifre!="1234"));

	/*bir islem sectikten sonra menüden cikis yapmadan ard arda birden fazla islem yapmayi saglayan döngü*/
	do
	{
		
		printf("\n");
		printf("_____________________________________MENU_______________________________________\n\n");
		printf("(1) Hesap Bakiyesi Goruntuleme\n");
		printf("(2) Hesabina Para Yatirma\n");
		printf("(3) Hesabindan Para Cekme\n");
		printf("(4) Para Transferi\n");
		printf("(5) Cikis\n\n");
		printf("Yukaridaki menuden yapmak istediginiz islem numarasini giriniz: ");
		scanf("%d",&secim);

		/*Girilen islem numarasi sistemde tanimli oldugu müddetce devam eden döngü*/
		do
		{
			if(secim==1)/*bu if yapisi hesap bakiyesi görüntüleme islemi yapar*/
			{
				system("cls");/*her secimden sonra ekrani temizler*/
				printf("\nHesap Bakiyeniz:%f\n",hesapNur);
				printf("\nCikis yapmak icin 5, devam etmek icin 0 tuslayiniz: ");
				scanf("%d",&secim);
				if(secim==5)
				{
					system("cls");/*her secimden sonra ekrani temizler*/
					printf("\nOturumunuz basariyla kapanmistir.\n");
				}
				break;
			}
			else if(secim==2)/*bu if yapisi hesabina para yatirma islemini yapar*/
			{
				system("cls");/*her secimden sonra ekrani temizler*/
				printf("\nYatirmak istediginiz tutar: ");
				scanf("%f",&yatır);
				hesapNur=hesapNur+yatır;/*hesaba para yatirma islemi*/
				printf("\nPara yatirma isleminiz gerceklesmistir.\n");
				printf("\nYeni Hesap Bakiyeniz:%f\n",hesapNur);
				printf("\nCikis yapmak icin 5, devam etmek icin 0 tuslayiniz: ");
				scanf("%d",&secim);
				if(secim==5)
				{
					system("cls");/*her secimden sonra ekrani temizler*/
					printf("\nOturumunuz basariyla kapanmistir.\n");
				}
				break;
			}
			else if(secim==3)/*bu if yapisi hesabindan para cekme islemini yapar*/
			{
				system("cls");/*her secimden sonra ekrani temizler*/
				printf("\nCekmek istediginiz tutar: ");
				scanf("%f",&cek);
				if(hesapNur>=cek)/*cekilecek tutarin hesaptan büyük olmaması kontrol edilip hata verdiriliyor*/
				{
					hesapNur=hesapNur-cek;/*hesaptan para cekme islemi*/
					printf("\nPara cekme isleminiz gerceklesmistir.\n");
					printf("\nYeni Hesap Bakiyeniz:%f\n",hesapNur);
				}
				else
				{
					printf("\nPara cekme islemi icin bakiyeniz yeterli degil.\n");
				}
				printf("\nCikis yapmak icin 5, devam etmek icin 0 tuslayiniz: ");
				scanf("%d",&secim);
				if(secim==5)
				{
					system("cls");/*her secimden sonra ekrani temizler*/
					printf("\nOturumunuz basariyla kapanmistir.\n");
				}
				break;
			}
			else if(secim==4)/*bu if yapisi baska hesaba para yatirma islemini yapar*/
			{
				system("cls");/*her secimden sonra ekrani temizler*/
				printf("\nPara transfer etmek istediginiz hesap numarasini giriniz: ");
				scanf("%f",&hesapNo);
				printf("\nTransfer etmek istediginiz miktari giriniz: ");
				scanf("%f",&transfer);
				if(transfer<=hesapNur)/*transfer edilecek miktarin hesaptaki paradan büyük olup olmadigi kontrol ediliyor ve hata verdiriliyor*/
				{
					hesapNur=hesapNur-transfer;/**/
					hesapTransfer=transfer;
					printf("\nBelirtilen hesaba paraniz basariyla transfer edilmistir.\n");
					printf("\nYeni Hesap Bakiyeniz:%f\n",hesapNur);
					printf("\nTransfer edilen miktar:%f\n",transfer);
				}
				else
				{
					printf("\nPara transfer islemi icin bakiyeniz yeterli degil.\n");
				}
				printf("\nCikis yapmak icin 5, devam etmek icin 0 tuslayiniz: ");
				scanf("%d",&secim);
				if(secim==5)
				{
					system("cls");/*her secimden sonra ekrani temizler*/
					printf("\nOturumunuz basariyla kapanmistir.\n");
				}
				break;
			}
			else if(secim==5)/*bu if yapisi hesaptan cikis islemini yapar*/
			{
				system("cls");/*her secimden sonra ekrani temizler*/
				printf("\nOturumunuz basariyla kapanmistir.\n");
				break;
			}
			else/*else yapisi islem numarasinin tanimli olmadıgı koşulda isler*/
			{
				system("cls");/*her secimden sonra ekrani temizler*/
				printf("Girmis oldugunuz islem numarasi tanimli degil.\n");
				break;
			}
		}while(secim==1 || secim==2 || secim==3 || secim==4 || secim==5);
	}while(secim!=5);
	
	system("PAUSE");
}
