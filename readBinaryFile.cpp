#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
struct book_st
{
	char TacGia[30];
	char TenSach[30];
	char theloai[30];
	int giatien;
	int STT;
};
typedef struct book_st bookList;
void printfLine(int n)
{
	printf("\n");
	for(int i=1; i<=n; i++)
	{
		printf("=");
	}
}
void Enter(bookList &a)
{
	printf("\nNhap ten sach: ");
	fflush(stdin);
	gets(a.TenSach);
	printf("Nhap ten tac gia: ");
	fflush(stdin);
	gets(a.TacGia);
	printf("Nhap the loai: ");
	fflush(stdin);
	gets(a.theloai);
	printf("Nhap gia tien: ");
	scanf("%d",&a.giatien);
}
void OutPut(bookList a, int i)
{
	printfLine(100);
	printf("\n00%d",i+1);
	printf("||%-15s",a.TenSach);
	printf("||%-20s",a.TacGia);
	printf("||%-15s",a.theloai);
	printf("||%d",a.giatien);
}
void OutPuts(bookList *a, int n)
{
	printf("\n%s||%-15s%-20s%-15s%s","STT","Ten Sach","Ten Tac Gia","The Loai","Gia Tien");
	for(int i=0; i<n; i++)
	{
		OutPut(a[i],i);
	}
}
void textFile(FILE *readPtr)
{
	FILE *writePtr;
	int result;
	bookList a;
	writePtr = fopen("book.txt","w");
	rewind(readPtr);
	fprintf(writePtr,"\n%s||%-15s%-20s%-15s%s","STT","Ten Sach","Ten Tac Gia","The Loai","Gia Tien");
	while(!feof(readPtr))
	{
		result = fread(&a,sizeof(bookList),1,readPtr);
		if(result != 0 && a.STT !=0)
		{
			fprintf(writePtr,"\n00%d||%-15s||%-20s||%-15s||%d",a.STT,a.TenSach,a.TacGia,a.theloai,a.giatien);
		}
	}
	fclose(writePtr);
}
void OutPutFile(FILE *cfPtr)
{
	bookList a;
	int r;
    rewind(cfPtr);
	printf("\n%s||%-15s%-20s%-15s%s","STT","Ten Sach","Ten Tac Gia","The Loai","Gia Tien");
    while(!feof(cfPtr))
	{
		r= fread(&a,sizeof(bookList),1,cfPtr);
		if(r !=0 && a.STT !=0)
		{
			printfLine(100);
        	printf("\n00%d",a.STT);
        	printf("||%-15s",a.TenSach);
        	printf("||%-20s",a.TacGia);
        	printf("||%-15s",a.theloai);
        	printf("||%d",a.giatien);
		}
	    
	}
}
void updateRecord( FILE *fPtr)
{
	int stt;
	bookList a;
	printf("\nNhap so thu tu cua quyen sach can cap nhat thong tin: ");
	scanf("%d",&stt);
	fseek(fPtr,(stt-1)*sizeof(bookList),SEEK_SET);
	fread(&a,sizeof(bookList),1,fPtr);
	if(a.STT != stt )
	{
		printf("\nSo thu tu khong ton tai!");
	}
	else
	{
		printf("\n00%d",stt);
    	printf("||%-15s",a.TenSach);
    	printf("||%-20s",a.TacGia);
    	printf("||%-15s",a.theloai);
    	printf("||%d",a.giatien);
    	printf("\nNhap thong tin can cap nhat: ");
    	Enter(a);
    	printf("\n00%d",stt);
    	printf("||%-15s",a.TenSach);
    	printf("||%-20s",a.TacGia);
    	printf("||%-15s",a.theloai);
    	printf("||%d",a.giatien);
    	fseek(fPtr,(a.STT-1)*sizeof(bookList),SEEK_SET);
    	fwrite(&a,sizeof(bookList),1,fPtr);  	
	}
}
void deleteRecord(FILE *fPtr)
{
	bookList a;
	bookList blankBook = {"","","",0,0};
	int stt;
	printf("\nNhap so thu thu quyen sach can xoa: ");
	scanf("%d",&stt);
	fseek(fPtr,(stt-1)*sizeof(bookList),SEEK_SET);
	fread(&a,sizeof(bookList),1,fPtr);
	if(a.STT != stt)
	{
		printf("\nSo thu tu khong ton tai");
	}
	else
	{
		fseek(fPtr,(stt-1)*sizeof(bookList),SEEK_SET);
		fwrite(&blankBook,sizeof(bookList),1,fPtr);
	}
}
void newRecord(FILE *fPtr)
{
    
	int stt;
	bookList a;
	printf("\nNhap so thu tu : ");
	scanf("%d",&stt);
	fseek(fPtr,(stt-1)*sizeof(bookList),SEEK_SET);
	fread(&a,sizeof(bookList),1,fPtr);
	if(a.STT != NULL )
	{
		printf("\nSo thu tu da ton tai!");
	}
	else
	{
    	printf("\nNhap thong tin can them: ");
    	Enter(a);
    	a.STT=stt;
    	printf("\n00%d",stt);
    	printf("||%-15s",a.TenSach);
    	printf("||%-20s",a.TacGia);
    	printf("||%-15s",a.theloai);
    	printf("||%d",a.giatien);
    	fseek(fPtr,(a.STT-1)*sizeof(bookList),SEEK_SET);
    	fwrite(&a,sizeof(bookList),1,fPtr);  	
	}
}
int enterChoice(void)
{
	int choice;
	system("cls");
	printf("%s","\n======MENU THAO TAC VOI FILE======\n"
	"1 - Luu tru thong tin da luu tu file nhi phan vao file van ban book.txt\n"
	"2 - Cap nhat thong tin\n"
	"3 - Them thong tin moi\n"
	"4 - Xoa thong tin\n"
	"5 - Hien thi thong tin trong file\n"
	"6 - Thoat\n"
	"Nhap lua chon cua ban: ");
	scanf("%d",&choice);
	return choice;
}
void menu(void)
{
	FILE *cfPtr;
	int Choice;
	cfPtr = fopen("book.dat","rb+");
	while((Choice = enterChoice()) !=6)
	{
		switch(Choice)
		{
			case 1:
				textFile(cfPtr);
				break;
			case 2:
				updateRecord(cfPtr);
				system("pause");
				break;
			case 3:
				newRecord(cfPtr);
				system("pause");
				break;
			case 4:
				deleteRecord(cfPtr);
				system("pause");
				break;
			case 5:
				OutPutFile(cfPtr);
				system("pause");
				break;
			default:
				printf("\nLua chon cua ban chua hop le !");
				system("pause");
			    break;	
		}
	}
	fclose(cfPtr);
}
int main()
{

  menu();
}
