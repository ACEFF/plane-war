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
	settextcolor(BLACK);		// ����������ɫΪ��ɫ
	setbkmode(TRANSPARENT);		// �������ֱ���Ϊ͸��ɫ
	while (keyboard_front())//��ʼ����
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






	while (1)//��Ϸ����
	{
		
		cleardevice();
		move();
		show();
		backshow();
	

		Sleep(100);
	}

	return 0;
}