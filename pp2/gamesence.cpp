#include "pp2.h"
#include "rank.h"
elist *a;
using namespace std;
vector<int>bossbullents;

map<int, int>bullent_hp;//�����ӵ�����
ebullent eullent[100];
TCHAR sscore[9];


int px=4, py=13;
int bx = px, by = py - 1;
int speed = 0;//�����ٶ�
int mex;//�л�����
int mey;//�л�����
char ch1;
char ch;//��ȡ��������//
IMAGE i_player, i_bullon,i_enemy1,i_boss1,i_ebullon;
int i;
int i1;//�������ѭ��������
int mapback[14][10];
int score = 0;//��Ϸ����
int cscore = 0;//����ɻ���������
int php = 1;//�ɻ�����ֵ
//0Ϊ��ͼ||1Ϊ���Ƿɻ�||11Ϊ�����ӵ�||31Ϊ�л�||311boss
void kuaika1(elist** q)
{
	elist* r;
	elist* newnode = (elist*)malloc(sizeof(elist));

	
	int n = rand();
	
		n = n % 9;
	
		
	newnode->ephone = 31;
	newnode->data++;
	newnode->x = n;
	newnode->y = 0;
	newnode->hp = 1;
	
	newnode->next = NULL;

	if (*q == NULL)
	{
		*q = newnode;
	}
	else
	{
		r = *q;
		while (r->next != NULL)
		{
			r = r->next;
		}


		r->next = newnode;
		

	}
}
void kuaikaboss(elist** q)
{
	elist* r;
	elist* newnode = (elist*)malloc(sizeof(elist));


	


	newnode->ephone = 311;
	newnode->data++;
	newnode->x = 5;
	newnode->y = 0;
	newnode->hp = 7;

	newnode->next = NULL;

	if (*q == NULL)
	{
		*q = newnode;
	}
	else
	{
		r = *q;
		while (r->next != NULL)
		{
			r = r->next;
		}


		r->next = newnode;


	}
}

void loadiimage()
{
	loadimage(&i_player,_T("sourse\\f1.jpeg"), 50, 50);
	loadimage(&i_bullon, _T("sourse\\jidan.jpeg"), 50, 50);
	loadimage(&i_enemy1, _T("sourse\\��.jpg"), 50, 50);
	loadimage(&i_boss1, _T("�ɻ�����\\�ɻ�6.jpeg"), 100, 100);
}

void backshow()
{
	
	void tiji();
	
	ShowEnmey(a);
	
	bullent();
	tiji();
}
void show()                                                                                                                                                                                                                                                                                                                                                                                                          
{
	_stprintf_s(sscore, _T("%d"), score);
	outtextxy(9 * 50,0 , sscore);
	static int  ecount = 0;
	static int  bucount = 0;
	if (ecount < 5)
	{
		ecount++;
	}
	if (bucount < 5)
	{
		bucount++;
	}
	if (speed == 10)
	{
		speed -10;
}
	elist* r = a;
	
	if(php==1)
	{
		BeginBatchDraw();
		putimage(px * 50, py * 50, &i_player);
		for (int cishu = 0; cishu < ecount;)//ÿ�ζ�ȡ��������
		{
			if (r->hp)
			{
				switch (r->ephone)
				{
				case 31:
					putimage(r->x * 50, r->y * 50, &i_enemy1);
					cishu++; break;
				case 311:if(cscore>=20)
				{
					putimage(r->x * 50, r->y * 50, &i_boss1);
					for (i = 0; i < bucount; i++)
					{
						if (eullent[i].hp = 1)
							putimage(eullent[i].x * 50, eullent[i].y * 50, &i_bullon);

					}
				}
					
					cishu++;break;
				}
}

			if (r->next != NULL)
			{
				r = r->next;
			}
			else break;

		}
		
		if (php == 1 && py != 0)
		{
			putimage(bx * 50, by * 50, &i_bullon);
		}
		
		EndBatchDraw();
		
	}
	
}
void move()
{
	/*void bullent();*/
	mapback[py][px] = 0;
	if (_kbhit())

	{if(php==1)
		{
			ch = _getch();
			switch (ch)
			{
			case 'w':py--;
				if (py < 0)
					py++;
			 break;
			case'a':px--;
				if (px < 0)
					px++;
				  break; 
			case's':py++;
				if (py > 13)
					py--;
				 break;
			case'd':px++;
				if (px > 9)
					px--;
				; break;
			case'q':cin_rank(score); exit(1);
			default:break;
			}
		}
	}
	mapback[py][px] = 1;
}//���طɻ��ƶ�
void bullent()
{
	
	speed++;
	
	
	//�����ӵ�����
	
	if (php == 1&&py!=0)//�ɻ��Ƿ���
	{
		
		
		if (speed % 1 == 0) {
			if (bullent_hp[31] == 1)
			{
				
				by--;
				mapback[by][bx] = 11;
				mapback[by+1][bx] = 0;
			}
			
		}
	}
	
}

void tiji()
{
	void load_score(int a);
	elist *r = a;
	if (by == -1)//�ӵ��ж�
	{
		bullent_hp[31] = 0;
		
	}

	 if (bullent_hp[31] == 0)
	{
		bullent_hp[31] = 1;
		by = py - 1;
		bx = px;

	}


	if (mapback[py][px] != 1)
	{//���طɻ�����ж�
		
			mapback[py][px] = 0;
			php = 0;
	
		

	}
	static int  ecount = 0;
	if (ecount < 5)
	{
		ecount++;
	}
	
		
			//�л��ж�
				for (int cishu = 0; cishu < ecount; )
				{
					if (r->hp > 0)
					{
						cishu++;
						switch (r->ephone)
					  {
						case 31:  if (mapback[r->y][r->x] != r->ephone)
						{
							r->hp--;
							mapback[r->y][r->x] = 0;
							score++;
							cscore++;
							bullent_hp[31] = 0;
						}break;
						case 311:if (mapback[r->y][r->x] != r->ephone&&cscore>=20)
						{
							r->hp--;
							mapback[r->y][r->x] = 0;
							score++;
							cscore++;
							bullent_hp[31] = 0;
						}break;
					  }
					}
					

				
					

					if (r->next != NULL)
					{
						r = r->next;
					}
					else break;
				}
				load_score(score);
			
		}
void ShowEnmey(elist *q)
{
	void enemybullent(elist * q);
	static int  ecount = 0;
	if (ecount < 5)
	{
		ecount++;
	}//���μ��ط�ֹ���ַɻ������ص�

	elist* r = q;
	if (speed % 4 == 0)//�ƶ��ٶ�
	{
		for (int cishu = 0; cishu < ecount;)//ÿ�ζ�ȡ��������||�л����ƶ�
		{
			if (r->hp)
			{

				switch (r->ephone)
				{
				case 31:	r->y++;
					if (r->y == 14)
					{

						r->y = 0; score--;
					};

					cishu++; break;
				case 311:cishu++; static int m = 0;
					switch (m)
					{
					case 0:if (r->x != 0)r->x--; else m = 1; break;
					case 1:if (r->x != 8)r->x++; else m = 0; break;
					}
					break;
				}
		}

			if (r->next != NULL)
			{
				r = r->next;
			}
			else break;

		}
	}
	r = q;//����ָ��
		for (int cishu = 0; cishu < ecount;)//ÿ�ζ�ȡ��������||�л���λ�ü���
		{
			switch (r->ephone)
			{

			case 31:
			
				if (r->hp)
				{
					if (r->y)
						mapback[r->y - 1][r->x] = 0; 
					else if(mapback[13][r->x]!=1) //�õл��ɵ��߽�ʱ���¼���
						mapback[13][r->x] = 0;
					
					mapback[r->y][r->x] = r->ephone;
					
					cishu++;
				}break;
			
			case 311:cishu++;
				if (r->hp&& cscore >=20)
				{
					
					mapback[r->y][r->x] = r->ephone;
					
					enemybullent(r);
				}
				break;


			}
			
		

			if (r->next != NULL)
			{
				r = r->next;
			}
			else return;

		}
	
	
		
	

}

void init()
{
	ebullent* ebullenttype1(ebullent eb[100], int ebtype = 11);
	
	
	*ebullenttype1(eullent);
	
	bullent_hp[31] = 1;
	mapback[py][px] = 1;
	srand(time(NULL));
	for (i1 = 0; i1 <20; i1++)
	{
		
	
		kuaika1(&a);
	}
	kuaikaboss(&a);
	
	ShowEnmey(a);
}
ebullent *ebullenttype1(ebullent eb[100],int ebtype=11)//��ʼ�л��ӵ�
{
	int i = 0;
	while(i<100)
	{
		eb[i].type = ebtype;
		eb[i].hp = 1;
		eb[i++].y = 2;
	}
	
	return eb;
}
void enemybullent(elist *q)//�л��ӵ�����
{
	static int bucount=0;
	if (bucount < 5)
	{
		bucount++;
	}
	
	
	
	for(i=0;i< bucount;i++)
	{
		bool isfire=true;
		switch (eullent[i].type)
		{
		case 11:
			if (eullent[i].y != 2)
				isfire = false;
		if(isfire)
			eullent[i].x = q->x;
			eullent[i].y++;
			if (eullent[i].y == 14)
			{
				eullent[i].y = 2;
			}
			mapback[eullent[i].y - 1][eullent[i].x] = 0;
			mapback[eullent[i].y][eullent[i].x] = eullent[i].type;

		break;
		}
	}

}
void load_score(int a)//�����Ƿɻ������������
{
	FILE* sfp; 
	fopen_s(&sfp, "score.txt", "a");
	if (php == 0)
	{
		fprintf(sfp,"\nscore:%d",score);
		
		exit(1);
	}
	fclose(sfp);


}
//void outline()
//{
//	for (; x0 < 24; x0++)
//	{
//		for (y0=0; y0 < 41; y0++)
//		{
//			if (x0==0||x0==23)
//			{
//				mapback[x0][y0] = 2;//
//			}
//			if ((y0==1||y0==39||y0 == 40 || y0 == 0) && (x0 > 0 && x0 < 23))
//			{
//				mapback[x0][y0] = 1;
//			}
//			if ((x0 > 1 && x0 < 22) && (y0 > 1 && y0 < 39))
//				mapback[x0][y0] = 0;
//		}
//	}
//}
//void printmapback()
//{
//	for (x0=0; x0 < 24; x0++)
//	{
//		printf("\n");
//		for (y0=0; y0 < 41; y0++)
//		{
//			if (mapback[x0][y0] ==1)
//			{
//				printf("|");
//			}
//			if (mapback[x0][y0] == 2)
//			{
//				printf("=");
//			}
//			if (mapback[x0][y0] == 0)
//			{
//				printf(" ");
//			}
//		}
//	}
//}
//int main()
//{
//	outline();
//	printmapback();
//	return 0;
//}

//typedef char enmey;
//typedef struct enemylist
//{
//	enmey ephone[20][20];
//	int data;
//	int kongjian;

//}elist;
//void initelist(elist* q) 
//{
//	q->ephone =NULL ;
//	q->data = 0;
//	q->kongjian =0;

//}
//void creatlist1(elist* q)
//{
//	for (i = 0; i < 20; i++)
//	{
//		strcpy_s(q->ephone[i], enemy1[i]);
//	}
//	q->data++;
//}
