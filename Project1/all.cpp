#include"all.h"
elist *a;
int score=0;
int php = 1;//�ɻ�����ж�
int speed = 0;//�����ٶ�
int mex=2;//�л�����
int mey=3;//�л�����
int mex1 = 2;//�л�����
int mey1 = 3; 
char ch1;
char ch;//��ȡ��������//
char plane[20][20] = {
		"  ^",
		" ^ ^",
		"^---^"

};//�ɻ�
int x=20, y = 19;//�ɻ�����//
int i;
int i1;//�������ѭ��������
char map[100][100] =
{    "||======================================||",
	 "||                                      ||",
	 "||                                      ||",
	 "||                                      ||",
	 "||                                      ||",
	 "||                                      ||",
	 "||                                      ||",
	 "||                                      ||",
	 "||                                      ||",
	 "||                                      ||",
	 "||                                      ||",
	 "||                                      ||",
	 "||                                      ||",
	 "||                                      ||",
	 "||                                      ||",
	 "||                                      ||",
	 "||                                      ||",
	 "||                                      ||",
	 "||                                      ||",
	 "||                                      ||",
	 "||                                      ||",
	 "||                                      ||",
	 "||                                      ||",
	 "||======================================||"
};
char map1[100][100];//��ͼ

char enemy1[20][20] = {
		"< >",
		" v"
};
//void initelist(elist* q)
//{
//	q->ephone = NULL;
//	q->x = NULL;
//	q->y = NULL;
//	q->hp = NULL;
//	/*enmey* tem= (enmey*)malloc(50 * (sizeof(enmey)));*/
//	q->ephone = (enmey(*)[20])malloc(50 * (sizeof(enmey[20])));
//	q->hp = (int*)malloc(50 * (sizeof(int)));
//	q->x = (int*)malloc(50 * (sizeof(int)));
//	q->y = (int*)malloc(50 * (sizeof(int)));
//	q->data = 0;
//	q->kongjian = 50;
//
//}
//void kuaika1(elist* q)
//{
//
//	for (i = 0; i < 19; i++)
//	{
//		speed++;
//		srand(speed);
//		int n = rand();
//		if (n % 19 > 1)
//		{
//			n = n % 19;
//		}
//		else n = 5;
//		for (i = 0; i < 20; i++)
//		{
//			strcpy_s(q->ephone[i], enemy1[i]);
//		}
//		q->data++;
//		q->x[i] = 2;
//		q->y[i] = (n);
//		q->hp[i] = 1;
//	}speed = 0;
//}

void kuaika1(elist** q,char p[20][20])
{
	elist* r;
	elist* newnode = (elist*)malloc(sizeof(elist));

	
			int n = rand();
			if (n % 19 > 1)
			{
				n = n % 19;
			}
			else n = 5;
	
			for (i = 0; i < 20; i++)
						{
							strcpy_s(newnode->ephone[i], enemy1[i]);
						}
			newnode->data++;
			newnode->x = 1;
			newnode->y = (n);
			newnode->hp = 1;
			
			newnode->next = NULL;

			if (*q==NULL)
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

void printphone()
{
	map[x][y + 2] = plane[0][2];//^

	map[x + 1][y + 1] = plane[1][1];//^
	
	map[x + 1][y + 3] = plane[1][3];//^
	map[x + 2][y] = plane[2][0];//^
	map[x + 2][y + 1] = plane[2][1];
	map[x + 2][y + 2] = plane[2][2];
	map[x + 2][y + 3] = plane[2][3];
	map[x + 2][y + 4] = plane[2][4];//^
	//���طɻ�
}

void load()
{
	void moveenemy(elist * q);
	void tiji();
	void bullent();
	
	bullent();
	if (php)
	{
		printphone();
	}

	moveenemy(a);
	tiji();
	
	
	
	for (i1 = 0; i1 < 24; i1++)
	{
		
		
		
		
		puts(map[i1]);//���ƽ���


	}
	printf("%30d", score);
}//����ȫ������

void reload()
{
	for (i = 0; i < 24; i++)
	{
		strcpy_s(map[i], map1[i]);
	}
}
//���ɻ��ƶ�ʱ�ػ��ͼ���������켣

void copy(char cangku[100][100], char huowu[100][100])//����ͼ����
{
	for (i = 0; i < 24; i++)
	{
		strcpy_s(cangku[i], huowu[i]);
	}
}//���ݵ�ͼ
void tiji()//������Ϊ��ͼ�߽�����ж�
{
	if(php)
	{//���طɻ�����ж�
		if (map[x][y + 2] != '^' || map[x + 1][y + 1] != '^' || map[x + 1][y + 3] != '^' || map[x + 2][y] != '^' || map[x + 2][y + 4] != '^')
		{
			memset(plane, 0, sizeof(plane));
			php = 0;
			reload();
		}
	}
	
	if (strcmp(map[0], map1[0]) != 0)//�������
	{

		x++;

		reload();


	}
	if (strcmp(map[23], map1[23]) != 0)//�ײ����
	{

		x--;

		reload();



	}
	for (i = 0; i < 24; i++)//���ڲ�����
	{

		if (map[i][1] == '^' || map[i][1] == '-')
		{

			y++;
			reload();


		}
		if (map[i][40] == '^' || map[i][40] == '-')//���ڲ�����
		{

			y--;
			reload();

		}
	}//ǽ������ж�
	
}
void move()
{
	void bullent();
	if (_kbhit())

	{if(php==1)
		{
			ch = _getch();
			switch (ch)
			{
			case 'w':x--;
				reload(); break;
			case'a':y--;
				reload();  break; 
			case's':x++;
				reload(); break;
			case'd':y++;
				reload(); break;
			default:break;
			}
		}
	}
	
}//���طɻ��ƶ�

void clear()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(handle, coord);
}//������ΪƵ��ˢ�´���������t

void bullent()
{   speed++;
    char ball = 'I';
	static int bx = x, by = y + 2;
	//�����ӵ�����
	if(php==1)//�ɻ��Ƿ���
	{
		if (speed % 200 == 0) {
			if (bx != 1 && bx != 0)
			{
				map[bx][by] = ' ';
				bx--;

				map[bx][by] = ball;
			}
			else
			{
				reload();
				bx = x;
				by = y + 2;
			}
		}
	}
}
void moveenemy(elist* q)
{
	static int size=0;
	static int z=1;
	/*static int z = 1; */
	
	static elist* r  = q;
	static elist* r1 = q->next;
	if(z)
	{
		mex = r->x;
		mey = r->y;
		mex1 = r1->x;
		mey1 = r1->y;
		z = 0;
	}
		/*if (z)
		{
			for (i = 0; i < 20; i++)
			{
				strcpy_s(enemy[i], r->ephone[i]);
			}
			z = 0;
		}*/
	
	
		if(r!=r1)

		{
			if (r->hp)//�÷ɻ��Ƿ���ֵ
			{//�л��Ƿ񱻹���
				if (map[mex-1][mey] == 'I' || map[mex - 1][mey + 2] == 'I' || map[mex ][mey + 1] == 'I'||map[mex][mey] == 'I' || map[mex][mey + 2] == 'I' || map[mex + 1][mey + 1] == 'I')
				{
					score++;
					memset(r->ephone, 0, sizeof(r->ephone));
					
					reload();
					printphone();
					r->hp = 0;
					if (r->next != NULL)
						
					{
						r=r->next;
						if (r == r1&& r->next != NULL)
						{
							r = r->next;
					    }
						else
						{
							mex = r->x;
							mey = r->y;
						}
					}

				}
				else
				{
					

					map[mex][mey] = r->ephone[0][0];
					map[mex][mey + 2] = r->ephone[0][2];
					map[mex + 1][mey + 1] = r->ephone[1][1];

					if (speed % 1000 == 0) {//�����л�����
						if (mex != 21)//�л��ƶ�
						{

							mex++;
							map[mex - 1][mey] = ' ';
							map[mex - 1][mey + 2] = ' ';
							map[mex + 1 - 1][mey + 1] = ' ';

						}
						else
						{
							map[mex][mey] = ' ';
							map[mex][mey + 2] = ' ';
							map[mex + 1][mey + 1] = ' ';
							mex = r->x;
							mey = r->y;

						}
					}
				}

			}
			else if (r->next != NULL)
			{
				r = r->next;
				
			}
		}
		else if (r->next != NULL)
		{
			r = r->next;
		}
		if (r1!= r)

		{
			if (r1->hp)//�л��Ƿ񱻹���
			{
				if (map[mex1-1][mey1] == 'I' || map[mex1 - 1][mey1 + 2] == 'I' || map[mex1][mey1 + 1] == 'I'|| map[mex1][mey1] == 'I' || map[mex1][mey1 + 2] == 'I' || map[mex1 + 1][mey1 + 1] == 'I')
				{
					score++;
					memset(r1->ephone, 0, sizeof(r1->ephone));
					size++;
					reload();
					printphone();
					r1->hp = 0;
					if (r1->next != NULL)

					{
						r1 = r1->next;
						if (r1 == r && r1->next != NULL)
						{
							r1 = r1->next;
						}
						else
						{
							mex1 = r1->x;
							mey1 = r1->y;
						}
					}

				}
				else
				{


					map[mex1][mey1] = r1->ephone[0][0];
					map[mex1][mey1 + 2] = r1->ephone[0][2];
					map[mex1 + 1][mey1 + 1] = r1->ephone[1][1];
					if (speed % 1000 == 0) {//�����л�����
						if (mex1 != 21)//�л��ƶ�
						{

							mex1++;
							map[mex1 - 1][mey1] = ' ';
							map[mex1 - 1][mey1 + 2] = ' ';
							map[mex1 + 1 - 1][mey1 + 1] = ' ';

						}
						else
						{
							map[mex1][mey1] = ' ';
							map[mex1][mey1 + 2] = ' ';
							map[mex1 + 1][mey1 + 1] = ' ';
							mex1 = r1->x;
							mey1 = r1->y;

						}
					}

				}

			}
			else if (r1->next != NULL)
			{
				r1 = r1->next;
				
			}
		}
		
		else if (r1->next != NULL)
		{
			r1 = r1->next;
		}
}
	
void init()
{
	srand(time(NULL));
	a = NULL;
	for (i1 = 0; i1 <= 18; i1++)
	{
		kuaika1(&a, enemy1);
	}
	
	copy(map1, map); 
	speed = 0;

}


	/*void creatlist1(elist* q)
	{
		for(i=0;i<100;i++)
		{
			
			*q->ephone = 1;
			q->y++;
			q->data++;
		}
	}*/
