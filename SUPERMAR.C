#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<process.h>
/************************** STRUCTURE *******************************/
struct super
{
  int n,bill,date,quan,price,tquan,total,pquan;
  char name[20],pname[20];

 };
 struct super s;
/************************ FUNCTION NAME *****************************/
void login();
void option();
int empty();
void output();
void input();
int avail(int);
/*************************** EMPTY **********************************/
int empty()
{
 int c=0;
 FILE *fp;
 fp=fopen("deepu","r");
 while(fread(&s,sizeof(s),1,fp))
 c=1;
 fclose(fp);
 return(c);
 }
/**************************** MAIN **********************************/
int main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:/TURBOC3/BGI");
 login();
 closegraph();
 return 0;
 }
/**************************** LOGIN **********************************/
void login()
{
 int id,pin=12345;
 char pass[20],password[20]="deependra";
 cleardevice();
 setcolor(RED);
 rectangle(100,100,500,400);
 rectangle(101,101,501,401);
 setcolor(BLUE);
 rectangle(105,105,495,395);
 rectangle(106,106,494,394);
 setcolor(GREEN);
 rectangle(110,110,490,390);
 rectangle(111,111,489,389);
 setcolor(9);
 settextstyle(7,0,5);
 outtextxy(230,110,"LOGIN");
 settextstyle(7,0,5);
 outtextxy(230,130,"-----");
 setcolor(14);
 settextstyle(1,0,1);
 outtextxy(120,200,"ENTER ID :- ");
 gotoxy(32,14);
 scanf("%d",&id);
 setcolor(14);
 settextstyle(1,0,1);
 outtextxy(120,248,"ENTER PASSWORD :- ");
 gotoxy(40,17);
 scanf("%s",&pass);
 setcolor(7);
 settextstyle(1,0,1);
 outtextxy(140,293,"PLEASE WAIT ");
 delay(1000);
 setcolor(7);
 settextstyle(1,0,3);
 outtextxy(260,290,".");
 delay(1000);
 setcolor(7);
 settextstyle(1,0,3);
 outtextxy(270,290,".");
 delay(1000);
 setcolor(7);
 settextstyle(1,0,3);
 outtextxy(280,290,".");
 delay(1000);
 setcolor(7);
 settextstyle(1,0,3);
 outtextxy(290,290,".");
 delay(1000);
 setcolor(7);
 settextstyle(1,0,3);
 outtextxy(300,290,".");


 if((strcmp(pass,password)==0)&&(pin==id))
 {
 setcolor(3);
 settextstyle(3,0,1);
 outtextxy(120,330,"* ID AND PASSWORD ARE CORRECT *");
 delay(1000);
 option();
  }
  else
  {
   setcolor(3);
 settextstyle(3,0,1);
 outtextxy(120,330,"* ID AND PASSWORD ARE NOT CORRECT *");
 delay(2000);
 login();
 }

 getch();
 return;
 }
/******************************* OPTION ********************************/
 void option()
 {
 int ch,emp;
 cleardevice();
 setcolor(RED);
 rectangle(100,100,500,400);
 rectangle(101,101,501,401);
 setcolor(BLUE);
 rectangle(105,105,495,395);
 rectangle(106,106,494,394);
 setcolor(GREEN);
 rectangle(110,110,490,390);
 rectangle(111,111,489,389);
 setcolor(14);
 settextstyle(7,0,2);
 outtextxy(125,120,"WELCOME TO SUPER MARKET");
 settextstyle(7,0,5);
 outtextxy(125,125,"-------------");
 setcolor(9);
 settextstyle(2,0,7);
 outtextxy(130,165,"1: CREATE A NEW BILL");
 setcolor(9);
 settextstyle(2,0,7);
 outtextxy(130,200,"2: PRINT A BILL");
 setcolor(9);
 settextstyle(2,0,7);
 outtextxy(130,235,"3: PARTICULAR BILL DETAIL");
 setcolor(9);
 settextstyle(2,0,7);
 outtextxy(130,270,"4: EXIT");
 setcolor(9);
 settextstyle(2,0,7);
 outtextxy(120,295,"------------------------------");
 setcolor(3);
 settextstyle(2,0,7);
 outtextxy(130,328,"ENTER YOUR CHOICE: ");
 gotoxy(45,22);
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:input();
	 break;
  case 2:emp=empty();
	 if(emp==0)
	 { cleardevice();
	   setcolor(RED);
	   rectangle(100,100,500,400);
	   rectangle(101,101,501,401);
	   setcolor(BLUE);
	   rectangle(105,105,495,395);
	   rectangle(106,106,494,394);
	   setcolor(GREEN);
	   rectangle(110,110,490,390);
	   rectangle(111,111,489,389);
	   setcolor(14);
	   settextstyle(7,0,2);
	   outtextxy(125,120,"WELCOME TO SUPER MARKET");
	   settextstyle(7,0,5);
	   outtextxy(125,125,"-------------");
	   setcolor(9);
	   settextstyle(2,0,7);
	   outtextxy(170,220,"!!! FILE IS EMPTY !!!");
	   delay(2000);
	   option();

	    }
	    else
	    {
	     output();
	     }
	     break;
    case 4:exit(0);
    }

 getch();
 return;
 }
/********************************* INPUT *******************************/
void input()
{
 int t,i;
 FILE *fp;
 fp=fopen("deepu","w");
 cleardevice();
 setcolor(RED);
 rectangle(100,100,500,400);
 rectangle(101,101,501,401);
 setcolor(BLUE);
 rectangle(105,105,495,395);
 rectangle(106,106,494,394);
 setcolor(GREEN);
 rectangle(110,110,490,390);
 rectangle(111,111,489,389);
 setcolor(14);
 settextstyle(7,0,2);
 outtextxy(125,120,"WELCOME TO SUPER MARKET");
 settextstyle(7,0,5);
 outtextxy(125,125,"-------------");
 setcolor(7);
 settextstyle(2,0,7);
 outtextxy(130,183,"1: BILL NO      : ");
 gotoxy(45,13);
 scanf("%d",&s.bill);
 setcolor(7);
 settextstyle(2,0,7);
 outtextxy(130,232,"2: DATE         : ");
 gotoxy(45,16);
 scanf("%d",&s.date);
 setcolor(7);
 settextstyle(2,0,7);
 outtextxy(130,281,"3: CUSTOMER NAME: ");
 gotoxy(45,19);
 scanf("%s",&s.name);
 setcolor(7);
 settextstyle(2,0,7);
 outtextxy(130,330,"4: NO OF PRODUCT: ");
 gotoxy(45,22);
 scanf("%d",&s.n);
 t=s.n;
 for(i=1;i<=t;i++)
 {
 cleardevice();
 setcolor(RED);
 rectangle(100,100,500,400);
 rectangle(101,101,501,401);
 setcolor(BLUE);
 rectangle(105,105,495,395);
 rectangle(106,106,494,394);
 setcolor(GREEN);
 rectangle(110,110,490,390);
 rectangle(111,111,489,389);
 setcolor(14);
 settextstyle(7,0,2);
 outtextxy(125,120,"SUPER MARKET");
 settextstyle(7,0,5);
 outtextxy(125,125,"-------");
 setcolor(CYAN);
 settextstyle(3,0,2);
 outtextxy(205,183,"PRODUCT:- ");
 gotoxy(42,13);
 printf("%d",i);
 setcolor(WHITE);
 settextstyle(2,0,7);
 outtextxy(130,232," PRODUCT NAME   : ");
 gotoxy(45,16);
 scanf("%s",s.pname);
 setcolor(WHITE);
 settextstyle(2,0,7);
 outtextxy(130,281," PRICE          : ");
 gotoxy(45,19);
 scanf("%d",&s.price);
 setcolor(WHITE);
 settextstyle(2,0,7);
 outtextxy(130,330," QUANTITY       : ");
 gotoxy(45,22);
 scanf("%d",&s.quan);
 s.pquan=s.quan*s.price;
 s.total=s.total+s.pquan;
 }
 fwrite(&s,sizeof(s),1,fp);
 fclose(fp);
 getch();
 option();
 }
/********************************** OUTPUT ****************************/
void output()
{
 int bill,ava,m;
 FILE *fp;
 cleardevice();
 setcolor(RED);
 rectangle(100,100,500,400);
 rectangle(101,101,501,401);
 setcolor(BLUE);
 rectangle(105,105,495,395);
 rectangle(106,106,494,394);
 setcolor(GREEN);
 rectangle(110,110,490,390);
 rectangle(111,111,489,389);
 setcolor(14);
 settextstyle(7,0,2);
 outtextxy(125,120,"WELCOME TO SUPER MARKET");
 settextstyle(7,0,5);
 outtextxy(125,125,"-------------");
 setcolor(7);
 settextstyle(2,0,8);
 outtextxy(130,228," ENTER BILL NO: ");
 gotoxy(46,16);
 scanf("%d",&bill);
 getch();
 ava=avail(bill);
 if(ava==0)
 {
 cleardevice();
 setcolor(RED);
 rectangle(100,100,500,400);
 rectangle(101,101,501,401);
 setcolor(BLUE);
 rectangle(105,105,495,395);
 rectangle(106,106,494,394);
 setcolor(GREEN);
 rectangle(110,110,490,390);
 rectangle(111,111,489,389);
 setcolor(14);
 settextstyle(7,0,2);
 outtextxy(125,120,"WELCOME TO SUPER MARKET");
 settextstyle(7,0,5);
 outtextxy(125,125,"-------------");
 setcolor(11);
 settextstyle(10,0,1);
 outtextxy(120,260," BILL IS UNAVAILABLE!!! ");
 getch();
 option();
 getch();
  }
  else
  {
 fp=fopen("deepu","r");
 while(fread(&s,sizeof(s),1,fp))
 {
 cleardevice();
 setcolor(RED);
 rectangle(100,100,500,400);
 rectangle(101,101,501,401);
 setcolor(BLUE);
 rectangle(105,105,495,395);
 rectangle(106,106,494,394);
 setcolor(GREEN);
 rectangle(110,110,490,390);
 rectangle(111,111,489,389);
 setcolor(14);
 settextstyle(7,0,2);
 outtextxy(125,120,"WELCOME TO SUPER MARKET");
 settextstyle(7,0,5);
 outtextxy(125,125,"-------------");
 setcolor(7);
 settextstyle(2,0,7);
 outtextxy(130,183," BILL NO       : ");
 gotoxy(42,13);
 printf("%d",s.bill);
 setcolor(7);
 settextstyle(2,0,7);
 outtextxy(130,232," CUSTOMER NAME : ");
 gotoxy(42,16);
 printf("%s",s.name);
 setcolor(7);
 settextstyle(2,0,7);
 outtextxy(130,281," NO OF PRODUCT : ");
 gotoxy(42,19);
 printf("%d",s.n);
 setcolor(GREEN);
 settextstyle(2,0,7);
 outtextxy(110,299,"-------------------------------  ");
 setcolor(9);
 settextstyle(1,0,4);
 outtextxy(128,330," TOTAL     : ");
 gotoxy(42,23);
 printf("%d",s.total);

 getch();
 }
 fclose(fp);
 }
 option();
 }


/***************************** AVAILABLE BILL *************************/
int avail(int a)
{
  int c;
  FILE *fp;
  fp=fopen("deepu","r");
  while(fread(&s,sizeof(s),1,fp))
  {
   if(a==s.bill)
   {
    c=1;
   }
   else
   {
    c=0;
    }
     }
     fclose(fp);
     return(c);
     }
/******************************** END OF PROGRAM ************************/



























