 
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<string.h>
#include<ctype.h>//����ַ�
#include<windows.h>
#include<time.h>
#define LEN sizeof(user)
#define GRAY RGB(180,200,168)
#define H 10
#define L 10



typedef struct user //ȷ�Ͻṹ��
{

	char id[20];
	char name[31];
	char cloege[27];
	char schoolcard[20];
	int _x;
	int _y;
}user;


user Menu0(user stu);
void Menu1();
void WriteToFile();
user file(user stu);
void first(user stu);
int showseat(user stu,int seat[H][L]);
void prinfor(user stu);
void ReadFromFile();
user file0(user stu);
void seachsea();
void fixinfor();
void Deletseat();
void DeletAllSeat();
void Administator();
void Administator1();
//int x;
//int y;
//user stu;
int seat[H][L];
int main()
{
	user stu;
	stu=Menu0(stu);
	
	//file(stu);



	//system("pause");

	 first(stu);
	 return 0;
}
void first(user stu)
{ //user stu;
initgraph(700,670);
MOUSEMSG m1;
//cleardevice();
IMAGE background,m0;	
loadimage(&background,"C:\\Users\\xhm\\Pictures\\ͼ���3.jpg",700,670);//ҳ��
putimage(0,0,&background);
setbkmode(TRANSPARENT);
setfillcolor(GRAY);
    fillrectangle(100, 150, 400, 190);
	fillrectangle(100, 205, 400, 245);
	fillrectangle(100, 260, 400, 300);
	fillrectangle(100, 315, 400, 355);
	fillrectangle(100, 370, 400, 410);
	fillrectangle(100, 425, 400, 465);
   // fillrectangle(100, 475, 400, 520);
	setbkmode(TRANSPARENT);
	settextstyle(37, 0, "����");
	char FirstSelect1[20] = { "ѡ����λ" };
	char FirstSelect2[20] = { "��ѯ��λ��Ϣ" };
	char FirstSelect3[20] = { "�޸ĸ�����Ϣ" };
	char FirstSelect4[20] = {"ɾ����λ"};
	char FirstSelect5[20] = {"������ѧ��"};
	char FirstSelect6[20] = {"�˳�����"};
//	char FirstSelect7[20] = {"�˳�����"};
	outtextxy(110,155,FirstSelect1);
	outtextxy(110,210,FirstSelect2);
	outtextxy(110,265,FirstSelect3);
	outtextxy(110,320,FirstSelect4);
	outtextxy(110,375,FirstSelect5);
	outtextxy(110,430,FirstSelect6);
//	outtextxy(110,485,FirstSelect7);
	while(1)
	{

		m1=GetMouseMsg();
		if(m1.x>=100&&m1.x<=400&&m1.y>=150&&m1.y<=190)
		{
         setlinecolor(BLACK);
		 rectangle(100, 150, 400, 190);
		if(m1.uMsg== WM_LBUTTONDOWN)
		{
			//user stu;
			//stu= file(stu );
			showseat(stu,seat);
			break;
		}
		}
	else 
		if(m1.x>=100&&m1.x<=400&&m1.y>=205&&m1.y<=245)
	{
		setlinecolor(BLACK);
		rectangle(100,205,400,245);
		if(m1.uMsg==WM_LBUTTONDOWN)
		{		
          //showseat(stu,seat);//2ѡ����λ
				closegraph();
			 seachsea();//4��ѯ��λ��Ϣ
			 first(stu);
			 break;
		}
	}
	else if(m1.x>=100&&m1.x<=400&&m1.y>=260&&m1.y<=300)
	{
		setlinecolor(BLACK);
		rectangle(100,260,400,300);
		if(m1.uMsg==WM_LBUTTONDOWN)
		{
				//file(stu);//3ѡ����λ
			 closegraph();
			fixinfor();
			//5�޸ĸ�����Ϣ
			first(stu);
			break;

		}
	}
	
	else if(m1.x>=100&&m1.x<=400&&m1.y>=315&&m1.y<355)
	{
		setlinecolor(BLACK);
		rectangle(100,315,400,355);
		if(m1.uMsg==WM_LBUTTONDOWN)
		{
			//closegraph();
			// seachsea();
			 //4��ѯ��λ��Ϣ
			// break;
				closegraph();
				Deletseat();//ɾ����λ
				//break;
		}
	}
	else if(m1.x>=100&&m1.x<=400&&m1.y>=370&&m1.y<=410)
	{
		setlinecolor(BLACK);

		rectangle(100,370,400,410);
		if(m1.uMsg==WM_LBUTTONDOWN)
		{
			// closegraph();
			//fixinfor();//5�޸ĸ�����Ϣ
		//	exit(0);
			stu= file(stu );

		}
	}
	else if(m1.x>=100&&m1.x<=400&&m1.y>=425&&m1.y<=465)
	{
		setlinecolor(BLACK);
		rectangle(100,425,400,465);
		if(m1.uMsg==WM_LBUTTONDOWN)
		{
			    //closegraph();
			//	Deletseat();//ɾ����λ
				exit(0);
		}
	}




	else
	{
	   setlinecolor(WHITE);
			rectangle(100,150,400,190);
			rectangle(100,205,400,245);
			rectangle(100,260,400,300);
			rectangle(100,315,400,355);
			rectangle(100,370,400,410);
			rectangle(100,425,400,465);
		//	rectangle(100,475,400,520);
	}
	}
}
user file(user stu)
{
	/*FILE *fp = NULL;
	fp = fopen("book1.dat", "ab+");//���ļ�
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		exit(1);//1��ʾ���д�ķ�ʽ�˳�����
	}*/
	InputBox(stu.id , 20, "������ѧ�ţ�");
	InputBox(stu.name ,31,"������������");
	InputBox(stu.cloege ,27,"����������Ժϵ��");
	InputBox(stu.schoolcard ,20,"������У԰���ţ�");
	/*first(stu);
	/fwrite(&stu, LEN, 1, fp);
	fflush(stdin);
	fclose(fp);*/
	//�ر��ļ�
	return stu;

}
int showseat(user stu ,int seat[H][L])

{
	//user stu1;
	//char x[20];
	//InputBox(stu.id , 20, "������ѧ�ţ�");


	

	
	int seatx1=-1,seaty1=-1,seatx2=-1,seaty2=-1;
	int row=0,column=0;
	//int seat[10][10]={0};

	
	//MOUSEMSG m3;
	IMAGE p1,p2,p3,b1;


	loadimage(&b1, ("C:\\Users\\xhm\\Pictures\\΢��ͼƬ1.jpg"),700,670);
	putimage(0, 0, &b1);
		setbkmode(TRANSPARENT);
	setfillcolor(GRAY);
    setbkmode(TRANSPARENT);
    solidrectangle(590,14,760,53);
	settextstyle(30, 0, "����");
    char chioce[20]={"��ѡ����"};
    outtextxy(560, 19,chioce );
	loadimage(&p1,"C:\\Users\\xhm\\Pictures\\��λ1_8.jpg");//��ѡ��λͼƬ
	loadimage(&p2,"C:\\Users\\xhm\\Pictures\\��ѡ��λ1_3.jpg");//ѡ��ͼƬ
	loadimage(&p3,"C:\\Users\\xhm\\Pictures\\��ѡ��λ 2.jpg");//��λ
for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)

		{
			if(seat[i][j]==0)
			{
				putimage(100+j*45,100+i*45,&p1);
			}

			else //if(seat[row][column]!=2)//��ɫ��λ
			{
				putimage(100+j*45,100+i*45,&p3);
			}

		
		}
	}

MOUSEMSG m2;
while (1)
{
	m2=GetMouseMsg();
	if(m2.mkLButton)
	{
		if(m2.x>100,m2.x<550&&m2.y<550&&m2.y>100&&(m2.x-100)%45<40&&(m2.y-100)%45<40)
		{
			int row=(m2.y-100)/45,column=(m2.x-100)/45;
			int seatx=column*45+100,seaty=row*45+100;
            	stu._x =row;
				stu._y =column;
					
				FILE *fp = NULL;

	fp = fopen("book1.dat", "ab+");//���ļ�
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		exit(1);//1��ʾ���д�ķ�ʽ�˳�����
	}

	fwrite(&stu, LEN, 1, fp);
	fflush(stdin);
	fclose(fp);//�ر��ļ�

			if(seat[row][column]==1)//�ж��Ƿ�ѡ��
			{//��ʾ����λ��ռ��
				putimage(seatx,seaty,&p3);
				seat[row][column]=1;
				
				
			
				
			}
			else if(seat[row][column]==0)
			{
					putimage(seatx,seaty,&p2);
				seat[row][column]=1;
				
			}
			
		}
		else 
			if(m2.x>590&&m2.x<660&&m2.y>14&&m2.y<73)
		{
			

				if(MessageBoxA(NULL,"ȷ��ѡ���ˣ�","ȷ������",MB_YESNO|MB_SETFOREGROUND)==6)
				{
					 prinfor( stu);
					 Sleep(5000);
					 first(stu);				
					if(seat[seatx1][seaty1]==3)
						seat[seatx1][seaty1]=1;
					if(seat[seatx2][seaty2]==3)
						seat[seatx2][seaty2]=1;			

				}

		
		}
			else if(m2.x>100&&m2.x<170&&m2.y>100&&m2.y<40)
				
				return 0;
			

			FlushMouseMsgBuffer();
	
	}
	

}
	
}


void prinfor(user stu)
{
	
	char x[20];
	memcpy(x,stu.id ,sizeof(stu.id ));
	FILE *fp = NULL;	
	fp = fopen("book1.dat", "rb");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��");
		exit(1);
	}
outtextxy(200,0,"�û���Ϣ");	
fseek(fp, 0, SEEK_SET);		
	IMAGE picture2;
	loadimage(&picture2, "C:\\Users\\xhm\\Pictures\\΢��ͼƬ.jpg", 860, 760);
	putimage(0, 0, &picture2);
		
		while(!feof(fp))
{
	if(fread(&stu,LEN,1,fp))
	{
		if(strcmp(x ,stu.id )==0){
		
        outtextxy(200,0,"�û���Ϣ");
		outtextxy(60,20,"ѧ�ţ�");
		outtextxy(60,50,"������");
		outtextxy(60,90,"����ѧԺ��");
		outtextxy(60,130,"У԰����");
		outtextxy(60,160,"�У�");
		outtextxy(60,190,"�У�");

	    outtextxy(200,20,stu.id  );
		outtextxy(200,50,stu.name );
		outtextxy(200,90,stu.cloege );
		outtextxy(200,130,stu.schoolcard  );
		char row[4];
		char column[4];
		sprintf(row,"%d",stu._x );
		sprintf(column,"%d",stu._y );
		outtextxy(200,170,row);
		outtextxy(200,210,column);






		}
	}
}
		fclose(fp);
		return;
}
void ReadFromFile()//����Ա����
{
    system("cls");
	Menu1();
	FILE *fp = NULL;
	user stu;
	fp = fopen("book1.dat", "rb");

	if (fp == NULL)
	{
		printf("�ļ���ʧ��");
		exit(1);
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("    \t\tѧ��\t\t����\tѧԺ\t\t\t��λ��\n");

	fseek(fp, 0, SEEK_SET);

	while (!feof(fp))
	{
		if (fread(&stu.id , LEN, 1, fp))
		{
			printf("\t\t%s\t%s\t%s\t\t%d,%d\n",stu.id , stu.name, stu.cloege   ,stu._x ,stu._y);
		}
	}

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	system("pause");
	system("cls");
	fclose(fp);
	return;

}
void Menu1()
{

	system("mode con cols=120 lines=40");
	system("color F0");
	printf("                          ********��ӭʹ�ù��ݳ�������ѧͼ�����ϵͳ*********\n");

}//���⺯��1
user Menu0(user stu)
{
	user stu1;
initgraph(700,670);
MOUSEMSG m1;

cleardevice();
//MOUSEMSG m1;
IMAGE background;
IMAGE p1,p2;	
loadimage(&background,"C:\\Users\\xhm\\Pictures\\ͼ���3.jpg",700,670);//ҳ��
loadimage(&p1,"C:\\Users\\xhm\\Pictures\\��¼1_5.jpg",130,130);//ҳ��
loadimage(&p2,"C:\\Users\\xhm\\Pictures\\��¼1_6.jpg");//ҳ��

putimage(0,0,&background);
putimage(100,200,&p1);
putimage(470,200,&p2);
setfillcolor(GRAY);
setbkmode(TRANSPARENT);
settextstyle(25, 0, "����");
fillrectangle(100,360,230,380);
fillrectangle(470,360,600,380);
char FirstSelect1[20] = { "�û���¼" };
	char FirstSelect2[20] = { "����Ա��¼" };
	outtextxy(100,360,FirstSelect2);
	outtextxy(470,360,FirstSelect1);
	while(1)
	{
		m1=GetMouseMsg();
		if(m1.x>=100&&m1.x<=230&&m1.y>=360&&m1.y<=380)
		{
			
			
		   setlinecolor(BLACK);
		   rectangle(100, 360, 230, 380);
			
			if(m1.uMsg==WM_LBUTTONDOWN)
			{
			//	closegraph();
				//cleardevice();
				 //Menu1();
				//ReadFromFile();
				char y[20];
				char pw[20];
				char x[20]={"kirito"};
				char psw[20]={"12346"};
				InputBox(y , 20, "���������Ա�˺ţ�");
				InputBox(pw, 20, "���������룺");
				if(strcmp(y ,x )==0||strcmp(pw ,psw )==0){

					Administator();}
				break;
				
			}
		}
		
		else
			if(m1.y>=360&&m1.y<=380&&m1.x>=470&&m1.x<=600)
			{
		     setlinecolor(BLACK);
		     rectangle(470,360,600,380);
		   if(m1.uMsg==WM_LBUTTONDOWN)
		   {		
             
			 stu1=file(stu);
			 break ;
			 //2ѡ����λ
		   }
		}
			else
			{
			setlinecolor(WHITE);
			rectangle(100,360,230,380);
			rectangle(470,360,600,380);			
			}
	}
	return stu1;
}
user file0(user stu)
{
    FILE *fp = NULL;
	fp = fopen("book1.dat", "ab+");//���ļ�
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		exit(1);//1��ʾ���д�ķ�ʽ�˳�����
	}
	InputBox(stu.id , 20, "������ѧ�ţ�");
	InputBox(stu.name ,31,"������������");
	InputBox(stu.cloege ,27,"����������Ժϵ��");
	InputBox(stu.schoolcard ,20,"������У԰���ţ�");
	first(stu);
	fwrite(&stu, LEN, 1, fp);
	fflush(stdin);
	fclose(fp);
	//�ر��ļ�
	return stu;
}







void seachsea()
{
	system("cls");
	Menu1();
	user stu;
	char x[20];
	int tc = 0;
	FILE *fp;

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t\t������ѧ��:");
	scanf("%s", x);
	printf("  ѧ��     ����      Ժϵ      ��λ��\n");

	fp = fopen("book1.dat", "rb");

	if (fp == NULL)
	{
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("����\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		return;
	}
	
	fseek(fp, 0, SEEK_SET);
	while (fread(&stu, LEN, 1, fp))
	{

		if (strcmp(x, stu.id) == 0)
		{
			printf("%3s  %5s  %5s    %10s %d%d\n", stu.id, stu.name, stu.cloege,stu.schoolcard , stu._x,stu._y );
			tc = 1;
		}

		if (tc = 0)
		{
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("����û��ԤԼ��λ");
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		}
	}

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	fclose(fp);
	system("pause");
	system("cls");
	return;
}




void fixinfor()
{
	system("cls");
	Menu1();
	
	user stu;
	FILE *fp;
	char x[20];

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("������ѧ��:");
	scanf("%s", x);

	fp = fopen("book1.dat", "rb+");

	if (fp == NULL)
	{
		printf("�ļ���ʧ��");
		exit(1);
	}

	fseek(fp, 0, SEEK_SET);
	while (fread(&stu, LEN, 1, fp))
	{

		if (strcmp(x, stu.id) == 0)
		{
			printf("����������ѧ��:   ");
			scanf("%s", stu.id);

			printf("��������������:    ");
			scanf("%s", stu.name);

			printf("��������������Ժϵ  : ");
			scanf("%s", stu.cloege);

		//	printf("������������λ  : ");
		//	scanf("%s", &stu.);

		
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			fflush(stdin);
			fseek(fp, 0-LEN, SEEK_CUR);
			fwrite(&stu, LEN, 1, fp);
			fclose(fp);
		}

		if (feof(fp))
		{
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("û����λ��Ϣ");
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		}

	}

	system("pause");
	system("cls");
	return;
}
void Administator()
{
	initgraph(700,670);
    MOUSEMSG m1;
//cleardevice();
  IMAGE background,m0;	
loadimage(&background,"C:\\Users\\xhm\\Pictures\\ͼ���3.jpg",700,670);//ҳ��
putimage(0,0,&background);
setbkmode(TRANSPARENT);
setfillcolor(GRAY);
    fillrectangle(100, 150, 400, 190);
	fillrectangle(100, 205, 400, 245);
	fillrectangle(100, 260, 400, 300);
	fillrectangle(100,315,400,355);
	setbkmode(TRANSPARENT);
	settextstyle(37, 0, "����");
	char FirstSelect1[20] = { "�鿴��Ϣ" };
	char FirstSelect2[20] = { "�ͷ��û���λ" };
	char FirstSelect3[20] = { "�ͷ�������λ" };
	char FirstSelect4[20] = {"�˳�"};
	outtextxy(110,155,FirstSelect1);
	outtextxy(110,210,FirstSelect2);
	outtextxy(110,265,FirstSelect3);
	outtextxy(110,320,FirstSelect4);
	while(1)
	{

		m1=GetMouseMsg();
		if(m1.x>=100&&m1.x<=400&&m1.y>=150&&m1.y<=190)
		{
         setlinecolor(BLACK);
		 rectangle(100, 150, 400, 190);
		if(m1.uMsg== WM_LBUTTONDOWN)
		{
			closegraph();
			ReadFromFile();
		Administator1();
			break;
			//user stu;
			//stu= file(stu );		
		}
		}
	else 
		if(m1.x>=100&&m1.x<=400&&m1.y>=205&&m1.y<=245)
	{
		setlinecolor(BLACK);
		rectangle(100,205,400,245);
		if(m1.uMsg==WM_LBUTTONDOWN)
		{
		closegraph();
          Deletseat();
		  Administator1();
		  break;//showseat(stu,seat); //2ѡ����λ
		}
	}
	else if(m1.x>=100&&m1.x<=400&&m1.y>=260&&m1.y<=300)
	{
		setlinecolor(BLACK);
		rectangle(100,260,400,300);
		if(m1.uMsg==WM_LBUTTONDOWN)
		{
			closegraph();
			DeletAllSeat();//	file(stu);//3ѡ����λ
             Administator1();
		}
	}
	else if(m1.x>=100&&m1.x<=400&&m1.y>=315&&m1.y<355)
	{
		setlinecolor(BLACK);
		rectangle(100,315,400,355);
		if(m1.uMsg==WM_LBUTTONDOWN)
		{
			exit(0);
			 //4��ѯ��λ��Ϣ
			 break;
		}
	}
	else
	{ setlinecolor(WHITE);
			rectangle(100,150,400,190);
			rectangle(100,205,400,245);
			rectangle(100,260,400,300);
			rectangle(100,315,400,355);

}
}
}


void Deletseat()
{
	system("cls");
	Menu1();
	user s;
	FILE* fp;
	char a[10];
	fp = fopen("book1.dat", "rb+");

	if (fp == NULL)
	{
		printf("���ļ����󣡣���\n");
		exit(1);
	}

	printf("\n������ѧ�ţ�");
	scanf("%s", a);
	printf("\n\t\t\tɾ���ɹ�\n");

	fseek(fp, 0, SEEK_SET);
	FILE* fp1;
	fp1 = fopen("linshi.dat", "ab+");//��д�½�һ����ʱ�ļ�

	while (fread(&s, LEN, 1, fp))//��ԭ�ļ���һ�����
	{
		if (strcmp(a, s.id) != 0)//����Ҫɾ��������
		{
			fwrite(&s, LEN, 1, fp1);
		}
	}

	fclose(fp);
	fclose(fp1);
	remove("book1.dat");//ɾ��ԭ�ļ�
	rename("linshi.dat", "book1.dat");//������Ϊԭ�ļ�

	fflush(stdin);
	system("pause");
	system("cls");
	return;
}

void DeletAllSeat()
{

	remove("book1.dat");//ɾ��ԭ�ļ�
	return;
}


void Administator1()
{
	initgraph(700,670);
    MOUSEMSG m1;
//cleardevice();
  IMAGE background,m0;	
loadimage(&background,"C:\\Users\\xhm\\Pictures\\ͼ���3.jpg",700,670);//ҳ��
putimage(0,0,&background);
setbkmode(TRANSPARENT);
setfillcolor(GRAY);
    fillrectangle(100, 150, 400, 190);
	fillrectangle(100, 205, 400, 245);
	fillrectangle(100, 260, 400, 300);
	fillrectangle(100,315,400,355);
	setbkmode(TRANSPARENT);
	settextstyle(37, 0, "����");
	char FirstSelect1[20] = { "�鿴��Ϣ" };
	char FirstSelect2[20] = { "�ͷ�������λ" };
	char FirstSelect3[20] = { "�ͷ��û���λ" };
	char FirstSelect4[20] = {"�˳�"};
	outtextxy(110,155,FirstSelect1);
	outtextxy(110,210,FirstSelect2);
	outtextxy(110,265,FirstSelect3);
	outtextxy(110,320,FirstSelect4);
	while(1)
	{

		m1=GetMouseMsg();
		if(m1.x>=100&&m1.x<=400&&m1.y>=150&&m1.y<=190)
		{
         setlinecolor(BLACK);
		 rectangle(100, 150, 400, 190);
		if(m1.uMsg== WM_LBUTTONDOWN)
		{
			closegraph();
			ReadFromFile();
			break;
			//user stu;
			//stu= file(stu );		
		}
		}
	else 
		if(m1.x>=100&&m1.x<=400&&m1.y>=205&&m1.y<=245)
	{
		setlinecolor(BLACK);
		rectangle(100,205,400,245);
		if(m1.uMsg==WM_LBUTTONDOWN)
		{
		closegraph();
          Deletseat();
		  break;//showseat(stu,seat); //2ѡ����λ
		}
	}
	else if(m1.x>=100&&m1.x<=400&&m1.y>=260&&m1.y<=300)
	{
		setlinecolor(BLACK);
		rectangle(100,260,400,300);
		if(m1.uMsg==WM_LBUTTONDOWN)
		{
			closegraph();
			DeletAllSeat();//	file(stu);//3ѡ����λ

		}
	}
	else if(m1.x>=100&&m1.x<=400&&m1.y>=315&&m1.y<355)
	{
		setlinecolor(BLACK);
		rectangle(100,315,400,355);
		if(m1.uMsg==WM_LBUTTONDOWN)
		{
			exit(0);
			 //4��ѯ��λ��Ϣ
			 break;
		}
	}
	else
	{ setlinecolor(WHITE);
			rectangle(100,150,400,190);
			rectangle(100,205,400,245);
			rectangle(100,260,400,300);
			rectangle(100,315,400,355);

}
}
}


