#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//CÝFT YONLU BAGÝL LÝSTE
typedef struct List{
	int sayi;
	int sayiKatsayi;
	int bolen;
	int bolum;
	int kalan;
	struct List *next;
	struct List *prev;
}list;

list *New ,*First=NULL,*Last=NULL,*Temp;

int  Gcd(int,int);
void AddList(int,int);
void SearchList();
void CalculateGcdNum(int,int);
void TerminalClean();
bool Menu();

int  gcdNum,a,b;
int main(){
	while(Menu());
	system("PAUSE");
	return 0;
}

// gcd(a,b ) = ax+by
int Gcd(int a, int b){
	if(b!=0){
		AddList(a,b);
		return Gcd(b,a%b);
	}else{
		return a;	
	}
}

void AddList(int a,int b){
		New = (list *)malloc(sizeof(list));
		New->sayi = a;
		New->bolen = b;
		New->bolum = (int)a/b;
		New->kalan = a % b;
		New->sayiKatsayi = 1;
		New->next = NULL;
		if(First ==NULL){
			First = New;
			Last = First;
			First->prev = NULL;
		}else{
			Last->next = New;
			New->prev = Last;
			Last = Last->next;
		}
}

void SearchList(){
	Temp = First;
	while(Temp!=NULL){
		printf("%d*%d = %d*%d+%d\n"
								,Temp->sayiKatsayi
								,Temp->sayi
							    ,Temp->bolum
							    ,Temp->bolen
							    ,Temp->kalan);
		Temp = Temp->next;
	}
	printf("\n-------------------\n");
	Temp = Last;
	while(Temp!=NULL){
		printf("\n%d*%d = %d*%d+%d"
								,Temp->sayiKatsayi
								,Temp->sayi
							    ,Temp->bolum
							    ,Temp->bolen
							    ,Temp->kalan);
		Temp = Temp->prev;
	}
	printf("\n-------------------\n");
}

void CalculateGcdNum(int a,int b){
		Temp = Last->prev;
		list *Temp2 = Last->prev;
		bool loopBool = false; 
		
	if(Temp == NULL){
		printf("Birbirlerinin kati oldugu icin oklid algoritmasi hesaplanamamaktadir.\n");
	}else{
		if(Temp == First){
		printf("%d*%d - %d*%d = (%d)\n"
								,Temp2->sayiKatsayi
								,Temp2->sayi
							    ,Temp2->bolum
							    ,Temp2->bolen
							    ,Temp2->kalan);
	}else{
		while(Temp !=First){
		Temp = Temp->prev;
		if(!loopBool){
			Temp2->bolum = Temp->sayiKatsayi*Temp2->bolum;
			Temp2->sayiKatsayi = Temp->bolum * Temp2->bolum + Temp2->sayiKatsayi;
			Temp2->bolen = Temp->sayi;
			loopBool = true;
		}else{
			Temp2->bolum = (Temp2->sayiKatsayi * Temp->bolum) + Temp2->bolum;	
			Temp2->sayiKatsayi = Temp2->sayiKatsayi*Temp->sayiKatsayi;
			Temp2->sayi = Temp->sayi;
			Temp2->bolen = Temp->bolen;
			loopBool = false;
		}
		printf("%d*%d = %d*%d+(%d)\n"	 ,Temp2->sayiKatsayi
										 ,Temp2->sayi
										 ,Temp2->bolum
										 ,Temp2->bolen
										 ,Temp2->kalan);	
	}
	}
	printf("\n-------------------\n");
		if(Temp2->sayiKatsayi * Temp2->sayi < Temp2->bolum * Temp2->bolen){
				Temp2->sayiKatsayi *= -1;
			}else{
				Temp2->bolum *= -1;
			}
	printf("gcd(%d,%d) =(%d) *  %d + (%d) * %d\n",a
											 	 ,b
											 	 ,Temp2->sayiKatsayi
										 	 	 ,Temp2->sayi
										 	 	 ,Temp2->bolum
										 	 	 ,Temp2->bolen
										 	 	 ,Temp2->kalan);
	}	
	
}

bool Menu(){
	int selection;
	printf("Lutfen Secim Yapin:\n"
		   "1-gcdNum Degeri Bulma\n"
		   "2-Yapilan Adimlari Gösterme\n"
		   "3-ax+by denklemini bulma\n"
		   "4-Cikis\n"
		   "Secim:");
	scanf("%d",&selection);
	switch(selection){
		case 1:{
			printf("a ve b Degerleri Giriniz:");
			scanf("%d,%d",&a,&b);
			if(b > a){
			int x = a;
			a = b;
			b = x;}
			gcdNum = Gcd(a,b);
			printf("gcdNum=%d\n",gcdNum);
			break;
		}
		case 2:{
			SearchList();
			break;
		}
		case 3:{
			printf("Denklem Bulunuyor...\n");
			CalculateGcdNum(a,b);
			break;
		}
		case 4:{
			return false;
			break;
		}
		default:{
			printf("Hatali Deger Girdiniz. Lütfen Tekrar Deneyin.\n");
			break;
		}
	}
	TerminalClean();
	return true;
}

void TerminalClean(){
	getchar();
	getchar();
	system("CLS");
}


