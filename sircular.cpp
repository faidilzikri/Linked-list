#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
	infotype 	info;
	address 	next;
} ElmtList;

typedef struct {
	address		first;
} List;

//SELEKTOR
#define First(L) (L).first
#define Next(P) (P)->next
#define Info(P) (P)->info

//KONSTANTA
#define Nil NULL
#define Infinity 99999



bool isListEmpty (List L){
	return (First(L)==Nil);
}
void createList (List *L){
	First(*L) = Nil;

}
address alokasi (infotype X){
	address P = address(malloc(sizeof(ElmtList)));
	if(P==Nil)
		return Nil;

	Info(P) = X;
	Next(P) = Nil;
	return P;

}
void dealokasi(address hapus){
    free (hapus);

}

void InsertFirst (List *L, infotype X){

	address P = alokasi(X);
	if(isListEmpty (*L)){
        First (*L)=P;
		Next(P)=First(*L);

	}else{
        Next(P) = First(*L);
        address temp = First(*L);
        while (Next(temp) != First(*L)){
            temp = Next(temp);
        }
        Next(temp) = P;
        First(*L)=P;

	}
}

void insertAfter (List *L, address P, address Prec){
	Next(P)=Next(Prec);
	Next(Prec)=P;
}
void insertLast (List *L, infotype X){

	address P = alokasi(X);
	if(isListEmpty(*L))
		InsertFirst(L, X);
	else{
            address temp = First (*L);
    while (Next (temp) != First (*L)){
        temp = Next (temp);
        }
        Next (temp)= P;
        Next (P)= First (*L);
	}
}

void printInfo (List L){
	cout<<"[";
	if(!isListEmpty(L)){
		address P = First(L);
		while(Next(P) != First(L)){
			cout<<Info(P)<<", ";
			P = Next(P);
		}
		cout<<Info(P);
	}
	cout<<"]"<<endl;
}
int main(){

int a,b;
cin >> a;
List L;
createList(&L);
InsertFirst (&L,a);
printInfo (L);
cin>>b;
InsertFirst (&L,b);
printInfo (L);
insertLast(&L, a);
printInfo(L);

}
