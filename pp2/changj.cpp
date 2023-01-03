#include"front.h"
#include"pp2.h"
#include"rank.h"

static int s = 0;
int main()
{
	
	init();
	
	
	loadiimage();
	load_frontimage();
	initgraph(500, 700);
	setbkcolor(WHITE);
	settextcolor(BLACK);		// 设置文字颜色为白色
	setbkmode(TRANSPARENT);		// 设置文字背景为透明色
	while (keyboard_front())//开始画面
	{
		switch (keyboard_front())
		{
			
		case 1:
			cleardevice();
			show_frontimage();
			break;
		case 2:
		{
		if(s--)
			cleardevice();
			show_rankimage();
		}
			break;
		
		}
		
		
      }






	while (1)//游戏画面
	{
		
		cleardevice();
		move();
		show();
		backshow();
	

		Sleep(100);
	}

	return 0;
}