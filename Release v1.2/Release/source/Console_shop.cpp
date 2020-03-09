//  Poorya Mohammadi Nasab
// 9621160025

//preprossesors
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
//structures
struct kala {
	int num;
	char name[20];
	int kharid;
	int foroosh;
	int takhfif;
	int tedad;
};
struct getpool {
	int get;
};
//functions
int strcmp(char a[], char b[]);
void menu();
void add();
void remove();
void search();
void manage();
void list()
;
void list_no();
void list_all();
void US();
void shopping();
void shopping();
void search_all_code();
void search_all_name();
void search_all_pay();
void search_no_code(char []);
void search_no_name(char[]);
void search_no_pay(char[]);
void sell();
void reset();
void list_foroosh();
void edit();
//main

int main() {
	menu();
	return 0;
}

//functions
    // MENU

void menu() {
	int choose;
	while (1) {
		system("cls");
		FILE *p;
		struct getpool f;
		int i;
		//p = fopen("pool", "rb+");
		p = fopen("pool", "rb");
		if (p != NULL)
		{
		//	fread(&f, sizeof(f), 1, p);
			printf("\n\n\t\t\t\t\t\t   ==========\n\t\t\t\t\t\t ..:: MENU ::..\n\t\t\t\t\t\t   ==========\n");//menu display
			//=================
			while (fread(&f, sizeof(f), 1, p)==1);
			printf("\n\t\t..::  your cash ::: %d", f.get);
			fclose(p);
		}
		else
		{
			reset();
		}
		printf("\n\t\t\t\t\t\t..:: [1] ::: SHOPPING\n\t\t\t\t\t\t..:: [2] ::: MANAGE\n\t\t\t\t\t\t..:: [3] ::: ABOUT US\n\t\t\t\t\t\t..:: [0] ::: EXIT\n\n\t\t\t\t\t\t..:: Your choice ::: ");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1://SHOPPING
			shopping();
			break;
		case 2://MANAGE
			manage();
			break;
		case 3:
			//US
			US();
			break;
		case 0:
			exit(1);
		default:
			printf("\n\t\t\t\t\t\t..:: %d is unknown !!!!\n", choose);
			break;
		}
	}
}
void manage() {
	system("cls");
	int choose;
	printf("\n\n\t\t\t\t\t\t    ==========\n\t\t\t\t\t\t ..:: MANAGE ::..\n\t\t\t\t\t\t    ==========\n");//manage display
	printf("\n\t\t\t\t\t\t..:: [1] ::: ADD NEW\n\t\t\t\t\t\t..:: [2] ::: EDIT\n\t\t\t\t\t\t..:: [3] ::: DELETE\n\t\t\t\t\t\t..:: [4] ::: SEARCH\n\t\t\t\t\t\t..:: [5] ::: LIST\n\t\t\t\t\t\t..:: [6] ::: RESET DATA\n\t\t\t\t\t\t..:: [7] ::: MAIN MENU\n\t\t\t\t\t\t..:: [0] ::: EXIT\n\n\t\t\t\t\t..:: Your choice ::: ");
	scanf("%d", &choose);
	switch (choose)
	{
	case 0:
		exit(1);
	case 1:
		add();
		break;
	case 2:
		//Edit
		edit();
		break;
	case 3:
		remove();
		break;
	case 4:
		search();
		break;
	case 5 :
		list();
		break;
	case 7:
		//main menu
		break;
	case 6:
		//reset prog
		reset();
	default:
		printf("%d is unknown !!!!\n");
		break;
	}
}
void shopping() {
	system("cls");
	int choose;
	printf("\n\n\t\t\t\t\t\t     ==========\n\t\t\t\t\t\t ..:: SHOPPING ::..\n\t\t\t\t\t\t     ==========\n");//shopping display
	printf("\n\t\t\t\t\t\t..:: [1] ::: LIST\n\t\t\t\t\t\t..:: [2] ::: SELL A COMMODITY\n\t\t\t\t\t\t..:: [3] ::: MAIN MENU\n\t\t\t\t\t\t..:: [0] ::: EXIT\n\n\t\t\t\t\t\t..:: Your choice ::: ");
	scanf("%d", &choose);
	switch (choose)
	{
	case 0:
		exit(1);
	case 1://LIST of sells
		list_foroosh();
		break;
	case 2://SELL 
		sell();
		break;
	case 3:
		//MAIN MENU
		break;
	default:
		printf("%d in unknown !!!!\n", choose);
		break;
	}
}
void US() {
	system("cls");
	int choose;
	printf("\n\n\t\t\t\t\t\t     ==========\n\t\t\t\t\t\t    ..:: US ::..\n\t\t\t\t\t\t     ==========\n");//shopping display
	printf("\n\t\t\t\t\t..:: POORYA MOHAMMADI NASAB\n\t\t\t\t\t..:: POORYA.M.N.B@GMAIL.COM\n\n\t\t\t\t\t..:: MAHDI TORABI\n\t\t\t\t\t..:: NIMATORABI@ROCKETMAIL.COM\n\n\t\t\t\t\t..:: [1] ::: MAIN MENU\n\t\t\t\t\t..:: [0] ::: EXIT\n\n\t\t\t\t\t..:: Your choice ::: "); // \n\t\t\t\t\t..:: \n\n\t\t\t\t\t..:: Your choice : ");
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:
		break;
	case 0:
		exit(1);
	default:
		printf("\t\t\t\t\t\t%d is unknowm !!!!\n", choose);
		break;
	}
}
void add() {
	system("cls");
	FILE *f,*k;
	struct kala p;
	int i=0,j;
		char name_no_2[20], name_no[20];
	printf("\n\n\t\t\t\t\t\t    ===========\n\t\t\t\t\t\t ..:: ADD NEW ::..\n\t\t\t\t\t\t    ===========\n");//shopping display
	list_no();
	printf("\n\n\t\t\t\t\t..:: Enter name of kind ::: ");
	scanf("%s", name_no);
	system("cls");
	for (j = 0; name_no[j]; j++)
	{
		if (name_no[j] >= 97 && name_no[j] <= 122)
		{
			name_no[j] = name_no[j] - 32;
		}
	}
	f = fopen(name_no, "ab+");
	k = fopen("noo.txt", "ab+");
	while (!feof(k))
	{
	//	fread(name_no_2, sizeof(char), 20, k) == 1
		fgets(name_no_2, 20, k);
		if(strcmp(name_no, name_no_2) == 0){
			i = 1;
		}
	}
	if (i==0)
	{
		fprintf(k, name_no);
		fprintf(k, "\n");
	}
	fclose(k);
	//list noo nanaveshtiaaaaaaaa!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	printf("\n\n\t\t\t\t\t..:: Code ::: ");
	scanf("%d", &p.num);
	printf("\n\n\t\t\t\t\t..:: Name ::: ");
	scanf("%s", p.name);
	printf("\n\n\t\t\t\t\t..:: Buy pay ::: ");
	scanf("%d", &p.kharid);
	printf("\n\n\t\t\t\t\t..:: Sell pay ::: ");
	scanf("%d", &p.foroosh);
	printf("\n\n\t\t\t\t\t..:: Off pay ::: ");
	scanf("%d", &p.takhfif);
	printf("\n\n\t\t\t\t\t..:: Number of it ::: ");
	scanf("%d", &p.tedad);
	fwrite(&p, sizeof(p), 1, f);
	fclose(f);
}
void list() {
	system("cls");
	struct kala p;
	FILE *f;
	char name_no[20];
	int choose;
	printf("\n\n\t\t\t\t\t\t    ===========\n\t\t\t\t\t\t ..:: LIST ::..\n\t\t\t\t\t\t    ===========\n");//shopping display
    list_no();
	printf("\n\t\t\t\t\t..:: Enter L to list all");
	printf("\n\n\t\t\t\t\t..:: Enter name of kind ::: ");
	scanf("%s", name_no);
	if (strcmp(name_no,"l")==0 || strcmp(name_no, "L") == 0)
	{
		list_all();
	}
	else {
		system("cls");
		f = fopen(name_no, "rb");
		if (f == NULL)
		{
			printf("\n\n\t\t\t\t\t..:: Nothing to show !!");
		}
		else
		{
			printf("\n\n\t\tTYPE\tCODE\tNAME\t\tBUY PAY\t\tSELL PAY\tOFF PAY\t\tNUMBER OF IT\n");
			while (fread(&p, sizeof(p), 1, f) == 1)
			{
				printf("\n\n\t\t=============================================================================================\n\n");
				printf("\t\t%s\t%d\t%s\t%d\t\t%d\t\t%d\t\t%d", name_no,p.num, p.name, p.kharid, p.foroosh, p.takhfif, p.tedad);
			}
		}
		fclose(f);
	}
	printf("\n\n\t\t=============================================================================================\n\n");
	printf("\n\n\t\t\t\t\t..:: [1] ::: MAIN MENU\n\t\t\t\t\t..:: [0] ::: EXIT\n\n\t\t\t\t\t..:: Your choice ::: ");
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:
		break;
	case 0:
		exit(1);
	default:
		break;
	}
}
void search() {
	system("cls");
	char name_no[20];
	int choose;
	printf("\n\n\t\t\t\t\t\t    ===========\n\t\t\t\t\t\t ..:: SEARCH ::..\n\t\t\t\t\t\t    ===========\n");//shopping display
	printf("\n\n\t\t\t\t\t..:: Search in ::: ");
	list_no();
	printf("\n\t\t\t\t\t..:: Enter L to search in all");
	printf("\n\n\t\t\t\t\t..:: Enter name of kind ::: ");
	scanf("%s", name_no);
	system("cls");
	printf("\n\n\t\t\t\t\t\t    ===========\n\t\t\t\t\t\t ..:: SEARCH ::..\n\t\t\t\t\t\t    ===========\n");//shopping display
	printf("\n\n\t\t\t\t\t..:: Search by ::: ");
	printf("\n\n\t\t\t\t\t..:: [1] ::: CODE");
	printf("\n\n\t\t\t\t\t..:: [2] ::: NAME");
	printf("\n\n\t\t\t\t\t..:: [3] ::: SELL PAY");
	printf("\n\n\t\t\t\t\t..:: Your choice ::: ");
	scanf("%d", &choose);
	if (strcmp(name_no, "L") == 0 || strcmp(name_no, "l") == 0)
	{
		switch (choose)
		{
		case 1:
			search_all_code();
			break;
		case 2:
			search_all_name();
			break;
		case 3:
			search_all_pay();
			break;
		default:
			break;
		}
	}
	else
	{
		switch (choose)
		{
		case 1:
			search_no_code(name_no);
			break;
		case 2:
			search_no_name(name_no);
			break;
		case 3:
			search_no_pay(name_no);
			break;
		default:
			break;
		}
	}
}
void list_no() {
	FILE *k,*p;
	char name_no[20];
	int i = 0;
	k = fopen("noo.txt", "a+");
	if (k==NULL)
	{
		printf("\n\n\t\t\t\t\t..:: NOTHING TO SHOW !!!!\n");
	}
	else
	{
		while (!feof(k))
		{
			fscanf(k, "%s", name_no);
			i++;
		}
	}
	fclose(k);
	i--;
	p = fopen("noo.txt", "a+");
	for ( ;  i>0 ; i--)
	{
		fscanf(p, "%s", name_no);
		printf("\n\t\t\t\t\t..:: %s", name_no);
	}
}
int strcmp(char a[], char b[])
{
	int i, j = 0;
	for (i = 0; a[i]; i++)
	{
		if (a[i]>b[i])
		{
			j = 1;
			break;
		}
		if (a[i]<b[i])
		{
			j = -1;
			break;
		}
	}
	return j;
}
void list_all() {
	system("cls");
	struct kala y;
	FILE *k, *p,*q;
	char name_no[20];
	int i = 0;
	k = fopen("noo.txt", "a+");
	if (k == NULL)
	{
		printf("\n\n\t\t\t\t\t..:: NOTHING TO SHOW !!!!\n");
	}
	else
	{
		while (!feof(k))
		{
			fscanf(k, "%s", name_no);
			i++;
		}
	}
	fclose(k);
	i--;
	p = fopen("noo.txt", "a+");
	printf("\n\n\t\tTYPE\tCODE\tNAME\t\tBUY PAY\t\tSELL PAY\tOFF PAY\t\tNUMBER OF IT\n");
	for (; i>0; i--)
	{
		fscanf(p, "%s", name_no);
		//printf("\n\t\t\t\t\t..:: %s", name_no);
		q = fopen(name_no, "rb");
		if (q == NULL)
		{
			printf("\n\n\t\t\t\t\t..:: Nothing to show !!");
		}
		else
		{
			while (fread(&y, sizeof(y), 1, q) == 1 && y.tedad!=0)
			{
				printf("\n\n\t\t=============================================================================================\n\n");
				printf("\t\t%s\t%d\t%s\t%d\t\t%d\t\t%d\t\t%d",name_no, y.num, y.name, y.kharid, y.foroosh, y.takhfif, y.tedad);
			}
		}
		fclose(q);
	}
	fclose(p);
}
void search_no_code(char a[]) {
	system("cls");
	FILE *f;
	struct kala p;
	f = fopen(a, "rb");
	int search,choose;
	if (f==NULL)
	{
		printf("ERROR IN OPENING!!");
	}
	else
	{
		printf("\n\n\t\t\t\t\t..:: Enter code ::: ");
		scanf("%d", &search);
		printf("\n\n\t\tTYPE\tCODE\tNAME\t\tBUY PAY\t\tSELL PAY\tOFF PAY\t\tNUMBER OF IT\n");
		while (fread(&p,sizeof(p),1,f)==1)
		{
			if (p.num==search)
			{
				printf("\n\n\t\t=============================================================================================\n\n");
				printf("\t\t%s\t%d\t%s\t%d\t\t%d\t\t%d\t\t%d",a, p.num, p.name, p.kharid, p.foroosh, p.takhfif, p.tedad);
			}
		}
		printf("\n\n\t\t=============================================================================================\n\n");
		printf("\n\n\t\t\t\t\t..:: [1] ::: MAIN MENU\n\t\t\t\t\t..:: [0] ::: EXIT\n\n\t\t\t\t\t..:: Your choice ::: ");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			break;
		case 0:
			exit(1);
		default:
			break;
		}
	}
}
void search_no_name(char a[]) {
	system("cls");
	FILE *f;
	struct kala p;
	f = fopen(a, "rb");
	int choose;
	char search[20];
	if (f == NULL)
	{
		printf("ERROR IN OPENING!!");
	}
	else
	{
		printf("\n\n\t\t\t\t\t..:: Enter name ::: ");
		scanf("%s", search);
		printf("\n\n\t\tTYPE\tCODE\tNAME\t\tBUY PAY\t\tSELL PAY\tOFF PAY\t\tNUMBER OF IT\n");
		while (fread(&p, sizeof(p), 1, f) == 1)
		{
			if (strcmp(p.name,search)==0)
			{
				printf("\n\n\t\t=============================================================================================\n\n");
				printf("\t\t%s\t%d\t%s\t%d\t\t%d\t\t%d\t\t%d",a, p.num, p.name, p.kharid, p.foroosh, p.takhfif, p.tedad);
			}
		}
		printf("\n\n\t\t=============================================================================================\n\n");
		printf("\n\n\t\t\t\t\t..:: [1] ::: MAIN MENU\n\t\t\t\t\t..:: [0] ::: EXIT\n\n\t\t\t\t\t..:: Your choice ::: ");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			break;
		case 0:
			exit(1);
		default:
			break;
		}
	}
}
void search_no_pay(char a[]) {
	system("cls");
	FILE *f;
	struct kala p;
	f = fopen(a, "rb");
	int search, choose;
	if (f == NULL)
	{
		printf("ERROR IN OPENING!!");
	}
	else
	{
		printf("\n\n\t\t\t\t\t..:: Enter SELL PAY ::: ");
		scanf("%d", &search);
		printf("\n\n\t\tTYPE\tCODE\tNAME\t\tBUY PAY\t\tSELL PAY\tOFF PAY\t\tNUMBER OF IT\n");
		while (fread(&p, sizeof(p), 1, f) == 1)
		{
			if (p.foroosh == search)
			{
				printf("\n\n\t\t=============================================================================================\n\n");
				printf("\t\t%s\t%d\t%s\t%d\t\t%d\t\t%d\t\t%d",a, p.num, p.name, p.kharid, p.foroosh, p.takhfif, p.tedad);
			}
		}
		printf("\n\n\t\t=============================================================================================\n\n");
		printf("\n\n\t\t\t\t\t..:: [1] ::: MAIN MENU\n\t\t\t\t\t..:: [0] ::: EXIT\n\n\t\t\t\t\t..:: Your choice ::: ");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			break;
		case 0:
			exit(1);
		default:
			break;
		}
	}
}
void search_all_code() {
	
	system("cls");
	struct kala y;
	int search,choose;
	FILE *k, *p,*q;
	char name_no[20];
	int i = 0;
	k = fopen("noo.txt", "a+");
	printf("\n\n\t\t\t\t\t..:: Enter CODE ::: ");
	scanf("%d", &search);
	if (k == NULL)
	{
		printf("\n\n\t\t\t\t\t..:: NOTHING TO SHOW !!!!\n");
	}
	else
	{
		while (!feof(k))
		{
			fscanf(k, "%s", name_no);
			i++;
		}
	}
	fclose(k);
	i--;
	p = fopen("noo.txt", "a+");
	printf("\n\n\t\tTYPE\tCODE\tNAME\t\tBUY PAY\t\tSELL PAY\tOFF PAY\t\tNUMBER OF IT\n");
	for (; i>0; i--)
	{
		fscanf(p, "%s", name_no);
		q = fopen(name_no, "rb");
		if (q == NULL)
		{
			printf("\n\n\t\t\t\t\t..:: Nothing to show !!");
		}
		else
		{
			while (fread(&y, sizeof(y), 1, q) == 1)
			{
				if (search==y.num)
				{
				printf("\n\n\t\t=============================================================================================\n\n");
				printf("\t\t%s\t%d\t%s\t%d\t\t%d\t\t%d\t\t%d",name_no, y.num, y.name, y.kharid, y.foroosh, y.takhfif, y.tedad);
			}
		}
		fclose(q);
	}
}
	fclose(p);
	printf("\n\n\t\t=============================================================================================\n\n");
	printf("\n\n\t\t\t\t\t..:: [1] ::: MAIN MENU\n\t\t\t\t\t..:: [0] ::: EXIT\n\n\t\t\t\t\t..:: Your choice ::: ");
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:
		break;
	case 0:
		exit(1);
	default:
		break;
	}
}
void search_all_pay() {

	system("cls");
	struct kala y;
	int search, choose;
	FILE *k, *p, *q;
	char name_no[20];
	int i = 0;
	k = fopen("noo.txt", "a+");
	printf("\n\n\t\t\t\t\t..:: Enter SELL PAY ::: ");
	scanf("%d", &search);
	if (k == NULL)
	{
		printf("\n\n\t\t\t\t\t..:: NOTHING TO SHOW !!!!\n");
	}
	else
	{
		while (!feof(k))
		{
			fscanf(k, "%s", name_no);
			i++;
		}
	}
	fclose(k);
	i--;
	p = fopen("noo.txt", "a+");
	printf("\n\n\t\tTYPE\tCODE\tNAME\t\tBUY PAY\t\tSELL PAY\tOFF PAY\t\tNUMBER OF IT\n");
	for (; i>0; i--)
	{
		fscanf(p, "%s", name_no);
		q = fopen(name_no, "rb");
		if (q == NULL)
		{
			printf("\n\n\t\t\t\t\t..:: Nothing to show !!");
		}
		else
		{
			while (fread(&y, sizeof(y), 1, q) == 1)
			{
				if (search == y.foroosh)
				{
					printf("\n\n\t\t=============================================================================================\n\n");
					printf("\t\t%s\t%d\t%s\t%d\t\t%d\t\t%d\t\t%d",name_no, y.num, y.name, y.kharid, y.foroosh, y.takhfif, y.tedad);
				}
			}
			fclose(q);
		}
	}
	fclose(p);
	printf("\n\n\t\t=============================================================================================\n\n");
	printf("\n\n\t\t\t\t\t..:: [1] ::: MAIN MENU\n\t\t\t\t\t..:: [0] ::: EXIT\n\n\t\t\t\t\t..:: Your choice ::: ");
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:
		break;
	case 0:
		exit(1);
	default:
		break;
	}
}
void search_all_name() {

	system("cls");
	struct kala y;
	int choose;
	char search[20];
	FILE *k, *p, *q;
	char name_no[20];
	int i = 0;
	k = fopen("noo.txt", "a+");
	printf("\n\n\t\t\t\t\t..:: Enter NAME::: ");
	scanf("%s", search);
	if (k == NULL)
	{
		printf("\n\n\t\t\t\t\t..:: NOTHING TO SHOW !!!!\n");
	}
	else
	{
		while (!feof(k))
		{
			fscanf(k, "%s", name_no);
			i++;
		}
	}
	fclose(k);
	i--;
	p = fopen("noo.txt", "a+");
	printf("\n\n\t\tTYPE\tCODE\tNAME\t\tBUY PAY\t\tSELL PAY\tOFF PAY\t\tNUMBER OF IT\n");
	for (; i>0; i--)
	{
		fscanf(p, "%s", name_no);
		q = fopen(name_no, "rb");
		if (q == NULL)
		{
			printf("\n\n\t\t\t\t\t..:: Nothing to show !!");
		}
		else
		{
			while (fread(&y, sizeof(y), 1, q) == 1)
			{
				if (strcmp(search,y.name)==0)
				{
					printf("\n\n\t\t=============================================================================================\n\n");
					printf("\t\t%s\t%d\t%s\t%d\t\t%d\t\t%d\t\t%d",name_no, y.num, y.name, y.kharid, y.foroosh, y.takhfif, y.tedad);
				}
			}
			fclose(q);
		}
	}
	fclose(p);
	printf("\n\n\t\t=============================================================================================\n\n");
	printf("\n\n\t\t\t\t\t..:: [1] ::: MAIN MENU\n\t\t\t\t\t..:: [0] ::: EXIT\n\n\t\t\t\t\t..:: Your choice ::: ");
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:
		break;
	case 0:
		exit(1);
	default:
		break;
	}
}
void remove() {
	int flag = 0;
	FILE *f,*ft;
	struct kala p;
	char name_no[20], s_name[20];
	int choose, s_code;
	system("cls");
	printf("\n\n\t\t\t\t\t\t   ==========\n\t\t\t\t\t\t ..:: REMOVE ::..\n\t\t\t\t\t\t   ==========\n");//menu display
	list_no();
	printf("\n\n\t\t\t\t\t..:: Enter name of kind ::: ");
	scanf("%s", name_no);
	f = fopen(name_no, "rb");
	ft = fopen("temp", "wb+");
	system("cls");
	printf("\n\n\t\t\t\t\t..:: Enter CODE ::: ");
	scanf("%d", &s_code);
	printf("\n\n\t\t\t\t\t..:: Enter NAME ::: ");
	scanf("%s", s_name);
	if (f == NULL)
	{
		printf("ERROR IN OPENING!!");
	}
	else
	{
		printf("\n\n\t\tTYPE\tCODE\t\tNAME\t\tBUY PAY\t\tSELL PAY\tOFF PAY\t\tNUMBER OF IT\n");
		while (fread(&p, sizeof(p), 1, f) == 1)
		{
			if (strcmp(p.name,s_name)!=0 || p.num!=s_code)
			{
				fwrite(&p, sizeof(p), 1, ft);
			}
			else
			{
				flag++;
			}
		}
		fclose(ft);
		fclose(f);
		if (flag==0)
		{
			printf("\n\n\t\t\t\t\t..:: NOT FOUND TO REMOVE ");
			remove("temp");
		}
		else
		{
			printf("\n\n\t\t\t\t\t..:: %d ITEM(S) REMOVED",flag);
			remove(name_no);
			rename("temp", name_no);
		}
		printf("\n\n\t\t=============================================================================================\n\n");
		printf("\n\n\t\t\t\t\t..:: [1] ::: MAIN MENU\n\t\t\t\t\t..:: [0] ::: EXIT\n\n\t\t\t\t\t..:: Your choice ::: ");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			break;
		case 0:
			exit(1);
		default:
			break;
		}
	}
}
void sell () {
	system("cls");
	struct kala pj,y;
	FILE *f,*k, *p, *q,*temp;
	int choose, foroosh,i=0,flag=0,selled, s_code,get_pool;
	char name_no[20],s_name[20];
	printf("\n\n\t\t\t\t\t\t    ===========\n\t\t\t\t\t\t ..:: SELL ::..\n\t\t\t\t\t\t    ===========\n");//shopping display
	list_no();
	printf("\n\t\t\t\t\t..:: Enter L to list all");
	printf("\n\n\t\t\t\t\t..:: Enter name of kind ::: ");
	scanf("%s", name_no);
	if (strcmp(name_no, "l") == 0 || strcmp(name_no, "L") == 0)
	{
		list_all();
	}
	else {
		system("cls");
		f = fopen(name_no, "rb");
		if (f == NULL)
		{
			printf("\n\n\t\t\t\t\t..:: Nothing to show !!");
		}
		else
		{
			printf("\n\n\t\tTYPE\tCODE\tNAME\t\tBUY PAY\t\tSELL PAY\tOFF PAY\t\tNUMBER OF IT\n");
			while (fread(&pj, sizeof(pj), 1, f) == 1 && pj.tedad!=0)
			{
				printf("\n\n\t\t=============================================================================================\n\n");
				printf("\t\t%s\t%d\t%s\t%d\t\t%d\t\t%d\t\t%d",name_no, pj.num, pj.name, pj.kharid, pj.foroosh, pj.takhfif, pj.tedad);
			}
		}
		fclose(f);
	}
	printf("\n\n\t\t=============================================================================================\n\n");
	printf("\n\n\t\t\t\t\t..:: Enter CODE ::: ");
	scanf("%d", &s_code);
	printf("\n\n\t\t\t\t\t..:: Enter NAME ::: ");
	scanf("%s", s_name);
	//mes tabe search peydakon . bad ye adad brgi ke befrooshi
	system("cls");
	k = fopen("noo.txt", "a+");
	if (k == NULL)
	{
		printf("\n\n\t\t\t\t\t..:: NOTHING TO SHOW !!!!\n");
	}
	else
	{
		while (!feof(k))
		{
			fscanf(k, "%s", name_no);
			i++;
		}
	}
	fclose(k);
	i--;
	p = fopen("noo.txt", "a+");
	printf("\n\n\t\tTYPE\tCODE\tNAME\t\tBUY PAY\t\tSELL PAY\tOFF PAY\t\tNUMBER OF IT\n");
	for (; i>0; i--)
	{
		flag = 0;
		fscanf(p, "%s", name_no);
		q = fopen(name_no, "rb+");
		temp = fopen("temp", "wb");
		if (q == NULL)
		{
			printf("\n\n\t\t\t\t\t..:: Nothing to show !!");
		}
		else
		{
			while (fread(&y, sizeof(y), 1, q) == 1)
			{
				if (strcmp(y.name, s_name) == 0 && y.num == s_code && y.tedad != 0 )
				{
					printf("\n\n\t\t=============================================================================================\n\n");
					printf("\t\t%s\t%d\t%s\t%d\t\t%d\t\t%d\t\t%d", name_no, y.num, y.name, y.kharid, y.foroosh, y.takhfif, y.tedad);
					//=======================
					printf("\n\n\t\t\t\t\t..:: How many ::: ");
					scanf("%d", &foroosh);
					if (foroosh > y.tedad)
					{
						printf("\n\n\t\t\t\t\t..:: We have only %d of it !!", y.tedad);
						fwrite(&y, sizeof(y), 1, temp);
					}
					else
					{
						FILE *b, *v;
						struct getpool m;
						int i, g;
						selled = y.tedad - foroosh;
						g = y.tedad;
						y.tedad = foroosh;
						v = fopen("selled", "ab+");
						b = fopen("pool", "rb+");
						//b = fopen("pool.txt", "a+");
						fwrite(&y, sizeof(y), 1, v);
						y.tedad = g - foroosh;
						fwrite(&y, sizeof(y), 1, temp);
				/*		if (b == NULL)
						{
							foroosh = foroosh*y.foroosh;
							m.get = foroosh;
							fwrite(&m, sizeof(m), 1, b);
							//================
							//fprintf(b,"%d" ,&m.get);
							//fprintf(b, "\n");
						}*/
					//	else
						//{
							foroosh = foroosh*y.foroosh;
							while(fread(&m, sizeof(m), 1, b)==1);
							//fscanf(b, "%d", &i);
							foroosh = foroosh + m.get;
							m.get = foroosh;
							fwrite(&m, sizeof(m), 1, b);
							//fprintf(b, "%d", &i);
							//fprintf(b, "\n");
					//	}
						fclose(b);
						fclose(v);
						//	break;
					}
					//==========================
				}//else ::: beriz to file jadid
				else
				{
					fwrite(&y, sizeof(y), 1, temp);
				}
			}
			//if (flag == 1)
			//{
				
			//}
			fclose(q);
			fclose(temp);
			remove(name_no);
			rename("temp", name_no);
		}
	}
	fclose(p);
	printf("\n\n\t\t=============================================================================================\n\n");
	printf("\n\n\t\t\t\t\t..:: [1] ::: MAIN MENU\n\t\t\t\t\t..:: [0] ::: EXIT\n\n\t\t\t\t\t..:: Your choice ::: ");
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:
		break;
	case 0:
		exit(1);
	default:
		break;
	}
}
void list_foroosh() {
	system("cls");
	int choose;
	FILE *f;
	struct kala p;
	f = fopen("selled", "rb+");
	if (f == NULL)
	{
		printf("\n\n\t\t\t\t\t..:: NOTHIG FOUND !!!");
	}
	else
	{
		printf("\n\n\t\tCODE\tNAME\t\tBUY PAY\t\tSELL PAY\tOFF PAY\t\tNUMBER OF SELL\n");
		while (fread(&p, sizeof(p), 1, f) == 1)
		{
			printf("\n\n\t\t=============================================================================================\n\n");
			printf("\t\t%d\t%s\t%d\t\t%d\t\t%d\t\t%d", p.num, p.name, p.kharid, p.foroosh, p.takhfif, p.tedad);
		}
	}
	fclose(f);
	printf("\n\n\t\t=============================================================================================\n\n");
	printf("\n\n\t\t\t\t\t..:: [1] ::: MAIN MENU\n\t\t\t\t\t..:: [0] ::: EXIT\n\n\t\t\t\t\t..:: Your choice ::: ");
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:
		break;
	case 0:
		exit(1);
	default:
		break;
	}
	
}
void reset() {
	struct getpool f;
	FILE *k, *p;
	char name_no[20];
	int i = 0;
	k = fopen("noo.txt", "a+");
	if (k == NULL)
	{
		printf("\n\n\t\t\t\t\t..:: NOTHING TO SHOW !!!!\n");
	}
	else
	{
		while (!feof(k))
		{
			fscanf(k, "%s", name_no);
			i++;
		}
	}
	fclose(k);
	i--;
	p = fopen("noo.txt", "a+");
	for (; i>0; i--)
	{
		fscanf(p, "%s", name_no);
		remove(name_no);
	}
	fclose(p);
	remove("noo.txt");
	remove("selled");
	remove("pool");
	p = fopen("pool", "wb+");
	f.get = 0;
	fwrite(&f, sizeof(f), 1, p);
	fclose(p);
	p = fopen("selled", "wb+");
	fclose(p);
	p = fopen("noo.txt", "w+");
	fclose(p);
	menu();
}
void edit() {
	int flag = 0;
	FILE *f, *ft;
	struct kala p;
	char name_no[20], s_name[20],edit[3];
	int choose, s_code;
	system("cls");
	printf("\n\n\t\t\t\t\t\t   ==========\n\t\t\t\t\t\t ..:: EDIT ::..\n\t\t\t\t\t\t   ==========\n");//menu display
	list_no();
	printf("\n\n\t\t\t\t\t..:: Enter name of kind ::: ");
	scanf("%s", name_no);
	f = fopen(name_no, "rb");
	ft = fopen("temp", "wb+");
	system("cls");
	printf("\n\n\t\t\t\t\t..:: Enter CODE ::: ");
	scanf("%d", &s_code);
	printf("\n\n\t\t\t\t\t..:: Enter NAME ::: ");
	scanf("%s", s_name);
	if (f == NULL)
	{
		printf("ERROR IN OPENING!!");
	}
	else
	{
		system("cls");
		printf("\n\n\t\t\t\t\t..::Enter '0' to not change !!");
		while (fread(&p, sizeof(p), 1, f) == 1)
		{
			if (strcmp(p.name, s_name) == 0 && p.num == s_code)
			{
				printf("\n\n\t\t\t\t\t..:: Code ::: ");
				scanf("%d", &p.num);
				printf("\n\n\t\t\t\t\t..:: Name ::: ");
				scanf("%s", p.name);
				printf("\n\n\t\t\t\t\t..:: Buy pay ::: ");
				scanf("%d", &p.kharid);
				printf("\n\n\t\t\t\t\t..:: Sell pay ::: ");
				scanf("%d", &p.foroosh);
				printf("\n\n\t\t\t\t\t..:: Off pay ::: ");
				scanf("%d", &p.takhfif);
				printf("\n\n\t\t\t\t\t..:: Number of it ::: ");
				scanf("%d", &p.tedad);
				fwrite(&p, sizeof(p), 1, ft);
			}
			else
			{
				fwrite(&p, sizeof(p), 1, ft);
			}
		}
		fclose(ft);
		fclose(f);
		remove(name_no);
		rename("temp", name_no);
	}
}