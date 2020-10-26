#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
struct bank
{
 int acc;
 char name[30];
 int d,c;
 int bal;
 int total;
 };
 struct bank b;
 void input();
 void output();
 int avlacc(int);
 void debit();
 void credit();
 void login();
 void menu();
/************************ EMPTY **********************************************/
 int empty()
 {
  FILE *fp;
  int c=0;
  fp=fopen("deepu","r");
  while(fread(&b,sizeof(b),1,fp));
  c=1;
  fclose(fp);
  return(c);
  }
/*************************** MAIN ****************************************/
  int main()
  {

  login();
  getch();
  }
/*************************** MENU ***************************************/
  void menu()
  {
  int c,emp;
  char ch;
   system("cls");
   do
   {


   printf("\t\t");
   printf(" ***** MENU ***** \n\n");
   printf("\n 1:-ENTER THE ACCOUNTS");
   printf("\n 2:-DISPLAY ALL ACCOUNTS");
   printf("\n 3:-DEBIT");
   printf("\n 4:-CREDIT");
   printf("\n 5:-EXIT");
   printf("\n\n ENTER YOUR CHOICE:");
   scanf("%d",&c);
   switch(c)
   {
    case 1:input();
	   break;
    case 2:emp=empty();
	   if(emp == 0)
	   printf("\nTHE FILE IS EMPTY\n");
	   else
	   output();
	   break;
    case 3:emp=empty();
	   if(emp == 0)
	   printf("\nTHE FILE IS EMPTY\n");
	   else
	   debit();
	   break;
    case 4:emp=empty();
	   if(emp==0)
	   printf("\n THE FILE IS EMPTY");
	   else
	   credit();
	   break;
	case 5:exit(1);

    default:printf("\n WRONG CHOICE");
    }
    printf("\n\n*******************************************************");
    printf("\n\n WANT TO ANOTHER CHOICE (Y/N): ");
    scanf("%s",&ch);
    }while((ch=='y')||(ch=='Y'));
     	}
 /*************************** INPUT *************************************/
    void input()
    {
     FILE *fp;
     char a;
     system("cls");
     fp=fopen("deepu","a");
     printf("\n ENTER THE ACCOUNT NO:");
     scanf("%d",&b.acc);
     printf("\n ENTER THE NAME:");
     scanf("%s",&b.name);
     printf("\n ENTER THE BALANCE:");
     scanf("%d",&b.bal);
     fwrite(&b,sizeof(b),1,fp);
     fclose(fp);
     printf("\n WANT TO ADD MORE ACCOUNTS(Y/N):");
     scanf("%s",&a);
     if((a=='y')||(a=='Y'))
     {
      input();
      }
      else
      {
       menu();
       }
	}
 /************************** OUTPUT **************************************/

     void output()
     {
      FILE *fp;
    system("cls");
      fp=fopen("deepu","r");
      printf("\n account no \t name \t\t balance");
      while(fread(&b,sizeof(b),1,fp))
      {
      printf("\n %d \t\t %s \t\t %d ",b.acc,b.name,b.bal);
      }
      fclose(fp);

       }

 /************************* LOGIN ***************************************/
       void login()
       {
	int id=12345,pin;
	char pas[20]="deepu",pass[20],ch;
	system("cls");
	printf("\n \t ********** LOGIN **********");
	printf("\n\n");
	printf("\n ENTER THE PIN: ");
	scanf("%d",&pin);
	printf("\n ENTER THE PASSWORD: ");
	scanf("%s",&pass);
	if((strcmp(pas,pass)==0)&&(pin==id))
	{
	 menu();
	 }
	 else
	 {
	  printf("\n PIN AND PASSWORD ARE WRONG");
	  printf("\n\n IF YOU WANT TO AGAIN ENTER PIN AND PASSWORD(Y/N): ");
	  scanf("%s",&ch);
	  if((ch=='y')||(ch=='Y'))
	  {
	   login();
	   }
	   else
	   {
	    exit(0);
	    }
	    }
	     }
/*************************** DEPOSIT *************************************/

  void debit()
  {
   FILE *fpd,*fpt;
   int ac,s,r;
   char ch;
   system("cls");
   printf("\n ENTER THE ACCOUNT NO:");
   scanf("%d",&ac);
   r=avlacc(ac);
   if(r==0)
   {
    printf("\n ACCOUNT NO ARE NOT FOUND:");
	}
    else
    {
     fpd=fopen("deepu","r");
     fpt=fopen("temp","w");
     while(fread(&b,sizeof(b),1,fpd))
     {
     s=b.acc;
     if(s!=ac)
     fwrite(&b,sizeof(b),1,fpt);
     else
     {
      system("cls");
      printf("\n\t\t ***** ACCOUNT DETAILS *****\n\n");
      printf("\n ACCOUNT NO     :- %d",b.acc);
      printf("\n NAME           :- %s",b.name);
      printf("\n BALANCE        :- %d",b.bal);
      printf("\n\n-------------------------------------------------------");
      printf("\n enter the deposited amount :");
      scanf("%d",&b.d);
      b.total=b.bal+b.d;
      b.bal=b.total;
      fwrite(&b,sizeof(b),1,fpt);
      }
      }
      fclose(fpd);
      fclose(fpt);
      fpd=fopen("deepu","w");
      fpt=fopen("temp","r");
      while(fread(&b,sizeof(b),1,fpt))
      {
       fwrite(&b,sizeof(b),1,fpd);
	}
       fclose(fpd);
       fclose(fpt);
	printf("\n\n\t *****  TRANSACTION SUCCESSFUL  *****");
       }
	}

/************************* CREDIT ****************************************/
 void credit()
 {
  FILE *fpc,*fpt;
  int r,s,ac;
  system("cls");
  printf("\n ENTER THE ACCOUNT NO:");
  scanf("%d",&ac);
  r=avlacc(ac);
  if(r==0)
  {
   printf("\n ACCOUNT ARE NOT FOUND");
   }
   else
   {
    system("cls");
    fpc=fopen("deepu","r");
    fpt=fopen("tempfile","w");
    while(fread(&b,sizeof(b),1,fpc))
    {
     s=b.acc;
     if(s!=ac)
     {
      fwrite(&b,sizeof(b),1,fpt);
      }
      else
      {
       printf("\n\t ***** ACCOUNT DETAIL *****");
       printf("\n ACCOUNT NO  :- %d",b.acc);
       printf("\n NAME        :- %s",b.name);
       printf("\n BALANCE     :- %d",b.bal);
       printf("\n-------------------------------------------------------");
       printf("\n\n ENTER THE CREDIT AMOUNT : ");
       scanf("%d",&b.c);
       if(b.bal<100)
       {
	printf("\n\n\t !!!!! BALANCE AMOUNT ARE LOW !!!!!");
	printf("\n\n\n\t SO,YOU ARE NOT CREDIT AMOUNT ");
	printf("\n\n\n\t >>> TRANSCATION FAILED <<<");
	}
	else
	{
	 if(b.c>b.bal)
	 {
	  printf("\n\n \t !!!!! BALANCE AMOUNT ARE LOW !!!!!");
	  printf("\n\n\t SO,YOU ARE NOT CREDIT AMOUNT ");
	  printf("\n\n\t >>> TRANSCATION FAILED <<<");
	  printf("\n\n PRESS ANY KEY TO CONTINUE");
	  getch();
	   menu();
	   }
	  else
      {
       b.total=b.bal-b.c;
       b.bal=b.total;
       fwrite(&b,sizeof(b),1,fpt);
       }
       }
       }
       }
       fclose(fpt);
       fclose(fpc);
       fpc=fopen("deepu","w");
       fpt=fopen("tempfile","r");
       while(fread(&b,sizeof(b),1,fpt))
       {
	fwrite(&b,sizeof(b),1,fpc);
	}
	fclose(fpc);
	fclose(fpt);
	}
	printf("\n\n\t *****  TRANSCATION SUCCESSFUL  *****");
	}

/*************************** FIND ACCOUNT *********************************/

 int avlacc(int ac)
 {
  FILE *fp;
  fp=fopen("deepu","r");
  while(fread(&b,sizeof(b),1,fp))
  {
   if(ac==b.acc)
   {
    printf("\n ACCOUNT NO ARE FOUND");
    fclose(fp);
    return 1;
    }
    }
    fclose(fp);
    return 0;
    }
/*********************** END OF THE PROGRAM *****************************/










