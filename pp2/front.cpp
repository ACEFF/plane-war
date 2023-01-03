#include"front.h"
IMAGE i_curse;
IMAGE i_start;
IMAGE i_back;
char jianpan;
int y = 7;
void load_frontimage()
{
	loadimage(&i_curse, _T("sourse\\f1.jpeg"), 50, 50);
	loadimage(&i_start, _T("sourse\\开始游戏.png"), 200, 50);
	loadimage(&i_back, _T("sourse\\历史积分.png"), 200, 50);
}
int keyboard_front()
{
	static int a = 1;
		if (_kbhit())

		{
			
			jianpan = _getch();
				switch (jianpan)
				{
				case '\r':if(y==7)a=0; if (y == 9)a=2; break;
				case'w':case'W':if (y != 7)y=y-2; PlaySound(MAKEINTRESOURCE(IDR_WAVE2), NULL, SND_RESOURCE | SND_ASYNC); break;
				case's':case'S':if (y != 9)y=y+2; PlaySound(MAKEINTRESOURCE(IDR_WAVE2), NULL, SND_RESOURCE | SND_ASYNC); break;
				case'q':case 'Q':a--; break;
				default:return a; break;
				}
			
		}
		
		return a;

}
void show_frontimage()
{
	putimage(2* 50, y * 50, &i_curse);
	putimage(3 * 50, 7 * 50, &i_start);
	putimage(3 * 50, 9 * 50, &i_back);
}