#include <stdio.h>
#include<Windows.h>
#include<string.h>
#include<conio.h>  
#include<stdlib.h>
#include<time.h>
#include<graphics.h>


//typedef char enmey;
//typedef struct enemylist
//{
//	enmey(*ephone)[20];
//	int  *x;
//	int  *y;
//	int data;
//	int kongjian;
//	int* hp;
//
//}elist;��������˳�������˳����봢���ά������Ҫ����ά���顣
typedef char enmey;
typedef struct enemylist
{
	enmey ephone[20][20];
	int x;
	int y;
	int data;
	
	int hp;
	enemylist* next;

}elist;//���˵��ж�������

void load();
void reload();
void tiji();
void move();
void copy(char cangku[100][100], char huowu[100][100]);
void clear();
void bullent();
void init();
void moveenemy(elist* q);

//void creatlist1(elist* q);