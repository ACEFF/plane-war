#pragma once
#include <stdio.h>
#include<Windows.h>
#include<string.h>
#include<conio.h>  
#include<stdlib.h>
#include<time.h>
#include<graphics.h>

#include<cstdio>
#include<queue>
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<sstream>
#include <fstream>
typedef int enmey;
typedef struct enemylist
{
	enmey ephone;
	int x;
	int y;
	int data;

	int hp;
	enemylist* next;

}elist;//敌人的判定单链表
typedef struct enmeybullent//敌人子弹的结构体
{
	int x;
	int y;
	int type;
	int hp;
}ebullent;


void loadiimage();
void show();
void move();
void bullent();
void init();
void ShowEnmey(elist* q);

void backshow();