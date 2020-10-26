#include<stdio.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<string.h>
struct student
{
 int roll,total;
 char name[20],grade;
 int e,m,h,sc,c;
 float per;
 };
struct student s;
void input();
void output();
int empty();
int avlrol(int);
void menu();
void modify();
void login();
void part();
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
/*********************** MAIN *****************************************/
int main()
{
 system("cls");
 login();
 return 0;
 }
/*********************** MENU ******************************************/
void menu()
{
 int c,emp;
 char ch;
 do
 {
  system("cls");
  printf("\n\t\t ***** MENU ***** ");
  printf("\n\n 1:- INPUT THE RECORDS ");
  printf("\n\n 2:- DISPLAY ALL THE RECORDS ");
  printf("\n\n 3:- MODIFY THE RECORDS ");
  printf("\n\n 4:- DISPLAY DETAILS OF A PARTICULAR STUDENT");
  printf("\n\n 5:- EXIT");
  printf("\n\n***********************************************************");
  printf("\n\n ENTER YOUR CHOICE:- ");
  scanf("%d",&c);
  switch(c)
  {
   case 1:input();
	  break;
   case 2:emp=empty();
	  if(emp==0)
	  {
	   printf("\n FILE IS EMPTY");
	   }
	   else
	   {
	    output();
	    }
	    break;
   case 3:emp=empty();
	  if(emp==0)
	  {
	   printf("\n FILE IS EMPTY");
	   }
	   else
	   {
	    modify();
	    }
	    break;
   case 4:emp=empty();
	  if(emp==0)
	  {
	   printf("\n FILE IS EMPTY");
	   }
	   else
	   {
	    part();
	    }
	    break;
   case 5:exit(0);
	    break;
   default:printf("\n\n !!!! WRONG CHOICE !!!!");
   }
   printf("\n\n***********************************************************");
   printf("\n\n IF YOU WANT TO ANOTHER CHOICE (Y/N): ");
   scanf("%s",&ch);
   }while((ch=='Y')||(ch=='y'));
   }

/************************** INPUT **************************************/

void input()
{

 FILE *fp;
 int i,p,t;
 system("cls");
 fp=fopen("record","a");
 printf("\n ENTER THE ROLL NO: ");
 scanf("%d",&s.roll);
 printf("\n ENTER THE NAME: ");
 scanf("%s",&s.name);
 printf("\n\t *** ENTER THE MARKS OUT OF 100 ***");
 printf("\n\n ENTER THE MARKS IN ENGLISH: ");
 scanf("%d",&s.e);
 printf("\n ENTER THE MARKS IN HINDI: ");
 scanf("%d",&s.h);
 printf("\n ENTER THE MARKS IN MARKS: ");
 scanf("%d",&s.m);
 printf("\n ENTER THE MARKS IN SCIENCE: ");
 scanf("%d",&s.sc);
 printf("\n ENTER THE MARKS IN COMPUTER: ");
 scanf("%d",&s.c);
  s.total=s.sc+s.c+s.e+s.h+s.m;
 t=s.total;
 s.per=(float)t*100/500;
 if(s.per>=90.0)
 {
  s.grade='A';
  }
  else if(s.per>=80.0)
 {
  s.grade='B';
  }
  else if(s.per>=70.0)
 {
  s.grade='C';
  }
  else if(s.per>=60.0)
 {
  s.grade='D';
  }
  else
  {
   s.grade='E';
   }
 fwrite(&s,sizeof(s),1,fp);
  fclose(fp);
   }


/************************** OUTPUT **************************************/

void output()
{
 FILE *fp;
 int i;
 system("cls");

 fp=fopen("record","r");
 printf("\n\t\t ***** STUDENTS DETAIL *****");
 printf("\n\n");
 printf("ROLL NO          NAME              PERCENTAGE         GRADE ");
 while(fread(&s,sizeof(s),1,fp))
 {
  printf("\n %d               %s              %f            %c ",s.roll,s.name,s.per,s.grade);

  }
  fclose(fp);
  }

/*************************** EMPTY ***************************************/

int empty()
{
 FILE *fp;
 int c;
 fp=fopen("record","r");
 fread(&s,sizeof(s),1,fp);
 fclose(fp);
 return 1;

  }

 /************************** AVAILABLE ROLL NO ****************************/

int avlrol(int a)
{
 FILE *fp;
 fp=fopen("record","r");
 while(fread(&s,sizeof(s),1,fp))
 {
  if(a==s.roll)
  {
    fclose(fp);
    return 1;
    }
    }
    fclose(fp);
    return 0;
    }

/**************************** MODIFY **************************************/
 void modify()
 {
  FILE *fpd,*fpt;
  int r,t,avl,ch;
  char c;
  system("cls");
  printf("\n ENTER THE ROLL NO WHICH YOU WANT TO MODIFY: ");
  scanf("%d",&r);
  avl=avlrol(r);
  if(avl==0)
  {
   printf("\nROLL NO ARE NOT FOUND");
   }
   else
   {
    fpd=fopen("record","r");
    fpt=fopen("temp","w");
    while(fread(&s,sizeof(s),1,fpd))
    {
     t=s.roll;
     if(r!=t)
     {
      fwrite(&s,sizeof(s),1,fpt);
      }
      else
      {
      system("cls");
       printf("\n ROLL NO   :- %d",s.roll);
       printf("\n NAME      :- %s",s.name);
       printf("\n\t\n *** MARKS ***");
       printf("\n\n ENGlISH  :- %d",s.e);
       printf("\n HINDI    :- %d",s.h);
       printf("\n MATHS    :- %d",s.m);
       printf("\n SCIENCE  :- %d",s.sc);
       printf("\n COMPUTER :- %d",s.c);
       printf("\n\n******************************************************");
       printf("\n\n IF YOU WANT TO CHANGE ANYTHING (Y/N): ");
       scanf("%s",&c);
       if((c=='y')||(c=='Y'))
       {
       system("cls");
       printf("\n 1:- CHANGE THE ROLL NO ");
       printf("\n 2:- CHANGE THE NAME ");
       printf("\n 3:- CHANGE THE ENGLISH MARKS ");
       printf("\n 4:- CHANGE THE HINDI MARKS ");
       printf("\n 5:- CHANGE THE MATHS MARKS ");
       printf("\n 6:- CHANGE THE SCIENCE MARKS ");
       printf("\n 7:- CHANGE THE COMPUTER MARKS ");
       printf("\n\n ENTER YOUR CHOICE:- ");
       scanf("%d",&ch);
       switch(ch)
       {
	case 1: printf("\n ENTER THE NEW ROLL NO: ");
		 scanf("%d",&s.roll);
		 break;
	case 2: printf("\n ENTER THE NEW NAME: ");
		 scanf("%d",&s.name);
		 break;
	case 3: printf("\n ENTER THE NEW ENGLISH MARKS: ");
		 scanf("%d",&s.e);
		 break;
	case 4: printf("\n ENTER THE NEW HINDI MARKS: ");
		 scanf("%d",&s.h);
		 break;
	case 5: printf("\n ENTER THE NEW MATHS MARKS: ");
		 scanf("%d",&s.m);
		 break;
	case 6: printf("\n ENTER THE NEW SCIENCE MARKS: ");
		 scanf("%d",&s.sc);
		 break;
	case 7: printf("\n ENTER THE NEW COMPUTER MARKS: ");
		 scanf("%d",&s.c);
		 break;
	default:printf("!!!! WROnG CHOICE !!!!");
	 }
	    s.total=s.sc+s.c+s.e+s.h+s.m;
 t=s.total;
 s.per=(float)t*100/500;
 if(s.per>=90.0)
 {
  s.grade='A';
  }
  else if(s.per>=80.0)
 {
  s.grade='B';
  }
  else if(s.per>=70.0)
 {
  s.grade='C';
  }
  else if(s.per>=60.0)
 {
  s.grade='D';
  }
  else
  {
   s.grade='E';
   }
	 fwrite(&s,sizeof(s),1,fpt);

	}
	}
	}
	 fclose(fpt);
	 fclose(fpd);
	fpd=fopen("record","w");
	fpt=fopen("temp","r");
	while(fread(&s,sizeof(s),1,fpt))
	{
	 fwrite(&s,sizeof(s),1,fpd);
	 }
	 fclose(fpt);
	 fclose(fpd);
	 }
	 printf("\n\n \t *** UPDATE SUCCESSFUL ***");

	 }

/********************* DISPLAY DETAIL OF PARTICULAR STUDENT *************/
void part()
{
 FILE *fpw;
 int r,t,avl;
system("cls");
 printf("\n ENTER THE ROLL NO:- ");
 scanf("%d",&r);
 avl=avlrol(r);
 if(avl==0)
 {
  printf("\n ROLL NO ARE NOT FOUND");
  }
  else
  {

 fpw=fopen("record","r");
 while(fread(&s,sizeof(s),1,fpw))
 {
  t=s.roll;
  if(t==r)
  {
   system("cls");
 printf("\n\t\t **** STUDENT DETAILS **** ");
 printf("\n\n");
 printf("\n NAME         :- %s",s.name);
 printf("\n ROLL NO      :- %d\n",s.roll);
 printf("\n\t **** MARKS ****");
 printf("\n ENGLISH      :- %d",s.e);
 printf("\n HINDI        :- %d",s.h);
 printf("\n MATHS        :- %d",s.m);
 printf("\n SCIENCE      :- %d",s.sc);
 printf("\n COMPUTER     :- %d",s.c);
 printf("\n\n***********************************************************");
 printf("\n");
 printf("\n TOTAL        :- %d",s.total);
 printf("\n PERCENTAGE   :- %f",s.per);
 printf("\n GRADE        :- %c",s.grade);
 printf("\n\n*************************************************************");
 }
 }
 fclose(fpw);
 }
 }
/******************** TO CALCULATE TOTAL,GRADE,PERCENTAGE ****************/








