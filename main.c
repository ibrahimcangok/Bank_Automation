#include<math.h>
#include<ctype.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

int main()
{
 setlocale(LC_ALL,"Turkish");
 char isim [155];
 int parola , bakiye=1000,i=1,*kayit;
 char sec, sec1, sec2, sec3, sec4, sec5;
 
 time_t zaman;
 struct tm *tarih[15];
 char buffer[80];
 time( &zaman );
 
 kayit=calloc(15,sizeof(int));
 
 system("cls");
 printf("L�tfen isminizi giriniz \n");
 scanf("%s",&isim);
 printf("Ho�geldiniz say�n %s , l�tfen parola girin \n",isim);
 scanf("%d",&parola);
 if(parola==1234)
 {
 
	 printf("Hesab�n�za 1000 lira ho�geldin avans� yat�r�lm��t�r \n");	
	 printf("��lem yapmak herhangi bir tu�a bas�n�z  ");
	 getch();
	 
	 menu:
	 system("cls");
	 printf("\n \t ATM ��LEMLER�\n\n");
	 printf("\t ------------------\n\n");
	 printf("\t 1) Hesap ��lemleri \n\n");
	 printf("\t 2) Para Transferi \n\n");
	 printf("\t 3) �demeler \n\n");
	 printf("\t 4) Ba�vuru ��lemleri \n\n");
	 printf("\t 5) Cikis\n\n");
	 printf("Say�n %s l�tfen yapmak istedi�iniz i�lemi se�iniz: \n",isim);
	 scanf("%s",&sec);
	 switch(sec)
	 {
		  
		  case '1':
		  {
		  	menu1 :
		   system("cls");		  
		   {	   		
		   	 printf("\n \t HESAP ��LEMLER� \n\n");
		   	 printf("\t -------------------\n\n");
		     printf("\t 1) Para �ekme \n\n");
			 printf("\t 2) Para Yat�rma \n\n");
			 printf("\t 3) Bakiye-Bilgi Sorgu \n\n");
	 		 printf("\t 4) Hesap �zeti \n\n");
	 		 printf("\t 5) IBAN Sorgulama \n\n");
	 		 printf("Say�n %s l�tfen yapmak istedi�iniz i�lemi se�iniz: \n",isim);
		   	 scanf("%s",&sec1);
					 
			 switch(sec1)
			 {						 	
				case '1':
				{					
				system("cls");
				int cek;
			    printf("\n\n \t PARA �EKME \n\n");
				printf("\t -------------------\n\n");
				printf("�ekmek istedi�iniz para miktar�n� girin \n");
				scanf("%d",&cek);
				printf("Say�n %s , para �ekme i�leminiz ger�ekle�mi�tir. \n",isim);
				bakiye=bakiye-cek;
				printf("Hesab�n�zdaki kalan tutar %d tl'dir \n",bakiye);
				tarih[i] = localtime( &zaman );
				kayit[i]=-cek;
				i++;
				if(i>15)
				i=1;				
				}
				break;
			    case '2' :
				{							
				int yat;
				system("cls");
				printf("\n\n \t PARA YATIRMA \n\n");
				printf("\t -------------------\n\n");
				printf("L�tfen yat�rmak istedi�iniz para miktar�n� girin \n");
				scanf("%d",&yat);
				printf("Say�n %s ,para yat�rma i�leminiz ger�ekle�mi�tir. \n",isim);
				bakiye=bakiye+yat;
				printf("Hesab�n�zdaki kalan tutar %d tl'dir \n",bakiye);
				tarih[i] = localtime( &zaman );
				kayit[i]=yat;
				i++;
				if(i>15)
				i=1;
				}
				break;
				case '3' :
				{
				system("cls");
				printf("\n\n \t BAK�YE-B�LG� SORGU \n\n");
				printf("\t ------------------------\n\n");
				printf("Say�n %s , hesap bakiyeniz %d tl'dir \n",isim,bakiye);
				}
				break;
				case '4' :
				{
				system("cls");
				printf("\n\n \t HESAP �ZET� \n\n");
				printf("\t --------------------------------\n\n");
				printf(" Tutar   \t��lem Tipi  \tTarih\n");
				printf(" --------\t----------  \t-----\n");
				for(i=1;i<=15;i++)
				{
				if(kayit[i]<0)
				{
					kayit[i]=-kayit[i];
					printf("%4.d Lira\tPara �ekme  \t%s",kayit[i],asctime(tarih[i]));
				}
				else if(kayit[i]>0)
				{
					printf("%4.d Lira\tPara Yat�rma\t%s",kayit[i],asctime(tarih[i]));
				}
				}
				}
				break;
				case '5' :
				{									
				double hesno;
				system("cls");
				printf("\n\n \t IBAN SORGULAMA \n\n");
				printf("\t --------------------\n\n");
				printf("\n Say�n %s , Kart�n�z�n �st�ndeki 16 haneli numaray� bo�luksuz girin \n",isim);
				scanf("%lf",&hesno);										
				if(1010000000000000<=hesno&&hesno<=9990000000000000)
					printf("\n IBAN NO = TR56 00061 0 %.0f \n",hesno);
				else
					printf("Giriginiz numara XXXXXXXXXXXXXXX formatinda 16 haneli olmalidir.\n");		
				}
				break;
				}	 	
		   		}	  
				secenekler1:
				printf("\n >>>  (A=Ana Men�/M=Se�im Men�s�/C=��k��):");
				scanf("%s",&sec);
				if(sec=='a'||sec=='A')
				{system("cls");
				goto menu;}
				else if(sec=='m'||sec=='M')			   
				{system("cls");
				goto menu1;}
				else if(sec=='c'||sec=='C')
				{exit(0);}
				else
				{printf("Lutfen varolan bir secenegi giriniz\n");
				getch();
				system("cls");
				goto secenekler1;}
				}
				break;
				case '2':
				{
				menu2 :
				system("cls");															
				{
				printf("\n \t  PARA TRANSFER� \n\n");
				printf("\t -------------------\n\n");
				printf("\t 1) Havale ��lemleri \n\n");
				printf("\t 2) Cebe Havale  \n\n");
				printf("\t 3) Hesaba EFT \n\n");
				printf("Say�n %s l�tfen yapmak istedi�iniz i�lemi se�iniz: \n",isim);
				scanf("%s",&sec2);
				switch(sec2)
				{
				case '1':
				{
				system("cls");
				printf("\n\n \t HAVALE ��LEMLER� \n\n");
				printf("\t ----------------------\n\n");
				printf("\n Say�n %s Ba�ka bir bankaya ait hesaba havale i�in l�tfen �nceki men�den \n EFT i�lemini se�iniz. \n \n",isim);
				double hesno;
				int havale;																									
				printf("\n Havale etmek istedi�iniz miktar� tl cinsinden girin \n");
				scanf("%d",&havale);
				printf("\n Para havale etmek istedi�iniz 16 haneli hesap numaras�n� girin \n");
				scanf("%lf",&hesno);																					
				if(1010000000000000<=hesno&&hesno<=9990000000000000)
				{
				printf("\n Say�n %s %16.0f nolu hesaba %d lira havale i�leminiz ger�ekle�mi�tir. \n",isim,hesno,havale);
				printf("\n Havale i�leminiz hesap �zetinize i�lenememektedir.\n L�tfen banka ile ileti�ime ge�in. \n");
				}																													
				else
				printf("Giriginiz numara XXXXXXXXXXXXXXX formatinda 16 haneli olmalidir.\n");													
				}
				break;
				case '2' :
				{
				double deneme;
				int havale;
				system("cls");
				printf("\n \t CEBE HAVALE \n\n");
				printf(" \t --------------- \n\n");
				printf("\n Havale etmek istedi�iniz miktar� tl cinsinden girin \n");
				scanf("%d",&havale);
				printf("Havale yapmak istedi�iniz cep numaras�n� girin\n ");
				printf("Giriginiz numara 5XXXXXXXXX formatinda 10 haneli olmalidir.\n");	
				scanf("%lf",&deneme);
				if(5010000000<=deneme&&deneme<=5550000000)
				printf("Say�n %s , %.0lf numaras�na %d lira havale i�leminiz ger�ekle�mi�tir.  ",isim,deneme,havale);
				else
				printf("HATALI G�R�� ! \n Giriginiz numara 5XXXXXXXXX formatinda 10 haneli olmalidir.\n");
				}
				break;
				case '3' :
				{
				system("cls");																							
				printf("\n\n \t HESABA EFT \n\n");
				printf("\t -------------------\n\n");
				double hesno;
				int havale;
				char bankad[111];																											
				printf("\n Say�n %s EFT yapmak istedi�iniz hesab�n ait oldu�u bankan�n 'yaln�zca ismini' girin \n",isim);
				printf(" 'XXX bankas�' �eklinde giri�ler kabul edilmemektedir, sadece XXX k�sm�n� yaz�n. \n");
				scanf("%s",&bankad);																									
				printf("\n Havale etmek istedi�iniz miktar� tl cinsinden girin \n");
				scanf("%d",&havale);							
				printf("\n Para havale etmek istedi�iniz 16 haneli hesap numaras�n� girin \n");
				scanf("%lf",&hesno);																								
				if(1010000000000000<=hesno &&hesno <=9990000000000000)
				{
				printf("\n Say�n %s , %s bankas�na ait %16.0f nolu hesaba \n %d lira havale i�leminiz ger�ekle�mi�tir. \n",isim,bankad,hesno,havale);
				printf("\n EFT i�leminiz hesap �zetinize i�lenememektedir. \n L�tfen banka ile ileti�ime ge�in. \n");
				}				
				else
				printf("Giriginiz hesap numaras� XXXXXXXXXXXXXXX formatinda 16 haneli olmalidir.\n");			
				}
				break;								
				}	 		 	
				}		   
				secenekler2:
				printf("\n >>>  (A=Ana Men�/M=Se�im Men�s�/C=��k��):");
				scanf("%s",&sec);
				if(sec=='a'||sec=='A')
				{system("cls");
				goto menu;}
				else if(sec=='m'||sec=='M')
				{system("cls");
				goto menu2;}
				else if(sec=='c'||sec=='C')
				{exit(0);}
				else
				{printf("Lutfen varolan bir secenegi giriniz\n");
				getch();
				system("cls");
				goto secenekler2;}
				}
				break;															  
				case '3':
				{
				menu3 :
				system("cls");
				{															  
				printf("\n \t  �DEMELER \n\n");
				printf("\t -------------\n\n");
				printf("\t 1) TL Y�kleme ( TC, KKTC t�m operat�rler) \n\n");												     	  
				printf("\t 2) �niversite Katk� Pay� �deme  \n\n");												      
				printf("Say�n %s l�tfen yapmak istedi�iniz i�lemi se�iniz: \n",isim);
				scanf("%s",&sec3);
				switch(sec3)
				{
				case '1':
				{
				system("cls");
				printf("\n\n \t TL Y�KLEME ( TC, KKTC t�m operat�rler)\n");
				printf("\t --------------------------------\n\n");																			
				double deneme;
				int yukleme;
																							
				printf("\n Say�n %s Y�klemek istedi�iniz miktar� tl cinsinden girin \n",isim);
				scanf("%d",&yukleme);
				printf("Y�kleme yapmak istedi�iniz cep numaras�n� girin\n ");
				printf("Giriginiz numara 5XXXXXXXXX formatinda 10 haneli olmalidir.\n");
				scanf("%lf",&deneme);
				if(5010000000<=deneme&&deneme<=5550000000)
				printf("%.0lf numaras�na %d lira havale i�leminiz ger�ekle�mi�tir.  ",deneme,yukleme);
				else
				printf("HATALI G�R�� ! \n Giriginiz numara 5XXXXXXXXX formatinda 10 haneli olmalidir.\n");
				}
				break;
				case '2' :
				{
				system("cls");					
				printf("\n\n \t 2) �N�VERS�TE KATKI PAYI �DEME \n");
				printf("\t --------------------------------\n\n");														      							
				double deneme;
				int yukleme;					
				char uni [155];																																														
				char fak [155];																					
				printf(" Say�n %s L�tfen �niversitenizin 'yaln�zca ismini' girin \n",isim);
				printf(" 'XXX �niversitesi' �eklinde giri�ler kabul edilmemektedir, sadece XXX k�sm�n� yaz�n. \n");
				scanf("%s",&uni);
				printf("L�tfen fak�ltenizin 'yaln�zca ismini' girin \n");
				printf(" 'XXX fak�ltesi' �eklinde giri�ler kabul edilmemektedir, sadece XXX k�sm�n� yaz�n. \n");
				scanf("%s",&fak);																							
				printf("\n Yat�rmak istedi�iniz katk� pay� miktar�n� tl cinsinden girin \n");
				scanf("%d",&yukleme);
				printf("L�tfen okul Numaran�z� girin\n ");
				printf("Giriginiz numara XXXXXXXXX formatinda 9 haneli olmalidir.\n");
				scanf("%lf",&deneme);
				if(101000000<=deneme&&deneme<=999000000)
				printf(" %s �niversitesi %s Fak�ltesi %.0lf numaral� ��renci ad�na \n %d lira havale i�leminiz ger�ekle�mi�tir.  ",uni,fak,deneme,yukleme);
				else
				printf("HATALI G�R�� ! \n Giriginiz numara XXXXXXXXX formatinda ve 9 haneli olmalidir.\n");														      							
				}
				break;																										 
				}	  
				}
				secenekler3:
				printf("\n >>>  (A=Ana Men�/M=Se�im Men�s�/C=��k��):");
				scanf("%s",&sec);
				if(sec=='a'||sec=='A')
				{system("cls");
				goto menu;}
				else if(sec=='m'||sec=='M')
				{system("cls");
				goto menu3;}
				else if(sec=='c'||sec=='C')
				{exit(0);}
				else
				{printf("Yanl�� se�im yapt�n�z.\n");
				getch();
				system("cls");
				goto secenekler3;}
				}
				break;																	  
				menu5 :
				case '4':
				{
				system("cls");																		
				{
				printf("\n \t  BA�VURU ��LEMLER� \n\n");
				printf("\t ----------------------\n\n");
				printf("\t 1) Bireysel Kredi Ba�vuru \n\n");
				printf("\t 2) Kredi Kart� Ba�vurusu \n\n");
				printf("Say�n %s l�tfen yapmak istedi�iniz i�lemi se�iniz: \n",isim);
				scanf("%s",&sec5);
				switch(sec5)
				{
				case '1':
				{	menukredi :
				system("cls");														
				printf("\n\n \t B�REYSEL KRED� BA�VURUSU \n\n");
				printf("\t --------------------------------\n\n");																						
				double tcno , tel;
				int gun,ay,yil;																									
				basla:																								
				printf("\n Say�n %s TC Kimlik Numaran�z� girin \n\n",isim);
				scanf("%lf",&tcno);																								
				if(10000000000<=tcno&&tcno <=99999999999)																										
				{
				basla2:
				printf("\n Cep telefonu Numaran�z� girin \n\n");
				scanf("%lf",&tel);
				if(5010000000<=tel&&tel<=5550000000)																														
				{
				//	printf("do�ru") ;
				}
				else
				{
				printf("\n Giriginiz numara 5XXXXXXXXX formatinda 10 haneli olmalidir.\n");
				goto basla2 ;
				}																										
				}	
				else
				{
				printf("\n Giriginiz numara XXXXXXXXXXX formatinda 11 haneli olmalidir.\n");
				goto basla;
				}																												
				def :
				printf("\n Do�um tarihinizin g�n�n� girin \n\n");
				scanf("%d",&gun);
				printf("\n Do�um tarihinizin ay�n� rakamla girin \n\n");
				scanf("%d",&ay);
				printf("\n Do�um tarihinizin y�l�n� girin \n\n");
				scanf("%d",&yil);																																																													
				system("cls");																	
				printf("\n Say�n %s Bilgilerinizin do�rulu�unu l�tfen kontrol edin. \n\n",isim);
				printf("\n TC Kimlik Numaran�z = %.0lf \n\n",tcno);
				printf("\n Cep telefonu Numaran�z = %.0lf \n\n",tel);
				printf("\n Do�um tarihiniz = %d/%d/%d \n\n",gun,ay,yil);																										
				seceneklerk :
				printf("\n >>> Bilgileriniz do�ru mu?  (Y=Yanl��/D=Do�ru):");
				scanf("%s",&sec);																										
				if(sec=='y'||sec=='Y')
				{system("cls");
				goto basla;}																																																			
				else if(sec=='d'||sec=='D')																																								   
				{system("cls");
				goto devam;}																									
				else
				{printf("Lutfen varolan bir secenegi giriniz\n");
				getch();
				system("cls");
				goto seceneklerk;}
				devam:
				printf("\n Say�n %s Faizsiz Kredi ba�vurunuz al�nm��t�r.\n\n Bizi tercih etti�iniz i�in te�ekk�r ederiz. \n",isim);																													
				}
				break;
				case '2' :
				{
				system("cls");									
				printf("\n\n \t KRED� KARTI BA�VURUSU \n\n");
				printf("\t --------------------------------\n\n");
				printf(" Say�n %s L�tfen TC kimlik numaran�z� giriniz. \n",isim);																						
				double deneme;
				scanf("%lf",&deneme);
				if(10000000000<=deneme&&deneme<=99999999999)
				printf("Kredi kart� ba�vurunuz al�nm��t�r. \n Te�ekk�r ederiz.");	
				else
				printf(" Hatal� Giri� ! \n TC kimlik numaras� XXXXXXXXX format�nda ve 11 haneli olmalidir.\n");										
				}
				break;								
				}
				}
				secenekler5:
				printf("\n >>>  (A=Ana Men�/M=Se�im Men�s�/C=��k��):");
				scanf("%s",&sec);
				if(sec=='a'||sec=='A')
				{system("cls");
				goto menu;}
				else if(sec=='m'||sec=='M')
				{system("cls");
				goto menu5;}
				else if(sec=='c'||sec=='C')
				{exit(0);}
				else
				{printf("Lutfen varolan bir secenegi giriniz\n");
				getch();
				system("cls");
				goto secenekler5;}
				}
				break;
				case '5':
				{exit(0);}
				break;
				default:
				{printf("Lutfen varolan bir secenegi giriniz\n");
				getch();
				goto menu;}
				}
				}
				else
				printf("\n Say�n %s �zg�n�z, parolay� yanl�� girdiniz.\n L�tfen banka ile ileti�ime ge�in.\n",isim);
				return 0;
			}

