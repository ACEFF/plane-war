#include <stdio.h>
#include<Windows.h>
#include<string.h>
#include<conio.h>  
int main()
{
	char ch;//收取键盘数据//
	
	int x, y = 0;//飞机坐标//
	int i;
	char map[1000][1000] =
	{ "||======================================||",
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
	
	x = 20;
	y = 19;//飞机初始坐标
	
	char plane[100][100] = {
		"  ^",
		" ^ ^",
		"^---^"

	};
	

	


	while (1)
	{
		for (i = 0; i < 24; i++)
		{
			map[x][y + 2] = plane[0][2];
			map[x + 1][y] = plane[1][0];
			map[x + 1][y + 1] = plane[1][1];
			map[x + 1][y + 2] = plane[1][2];
			map[x + 1][y + 3] = plane[1][3];
			map[x + 2][y] = plane[2][0];
			map[x + 2][y + 1] = plane[2][1];
			map[x + 2][y + 2] = plane[2][2];
			map[x + 2][y + 3] = plane[2][3];
			map[x + 2][y + 4] = plane[2][4];
			puts(map[i]);

		}

		ch = _getch();
		switch (ch)
		{
		case 'w':x--; 
			map[x + 3][y] = plane[0][0];
			map[x + 3][y + 1] = plane[0][0];
			map[x + 3][y + 2] = plane[0][0];
			map[x + 3][y + 3] = plane[0][0];
			map[x + 3][y + 4] = plane[0][0];
			puts(map[i]); break;
		case'a':y--; 
			map[x][y + 3] = plane[0][0]; 
			map[x + 1][y + 4] = plane[0][0]; 
			map[x + 2][y + 5] = plane[0][0]; break;
		case's':x++;
			map[x-1][y + 2] = plane[0][0];
			map[x ][y + 1] = plane[0][0];
			map[x ][y + 3] = plane[0][0];
			map[x+1][y] = plane[0][0];
			map[x + 1][y + 4] = plane[0][0]; break;
		case'd':y++;
			map[x][y + 1] = plane[0][0];
			map[x + 1][y-1] = plane[0][0];
			map[x + 2][y-1] = plane[0][0];

		}
		system("cls");
	}return 0;
}
