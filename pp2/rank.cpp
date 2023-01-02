#include"rank.h"
TCHAR Rscore[9];
using namespace std;




void show_rankimage()//将存贮在txt内的数据输出
{
	
	FILE* sfp;
	wchar_t a[9];
	int i = 0;
	fopen_s(&sfp, "score.txt", "r");
	while (fgetws(a,9,sfp))
	{
		
		outtextxy(3 * 50, i++*50, a);
		memset(a, '\0', sizeof(a));
	}
	fclose(sfp);
}
void cin_rank(int score)//存入积分
{
	ofstream outfile;
	outfile.open("score.txt",ios::app);

	outfile << endl << "score:" << score;
	outfile.close();


}
void rankscore()
{
	int isos;
	vector<int>soscore;
	int i=0;
	int i1 = 0;
	char sos[4];
	FILE* sfp;
	ifstream infile;
	infile.open("score.txt");
	
	infile.seekg(i, ios::end);
	infile.seekg(i, ios::end);
	infile >> sos[i++];
	
	
	
	
	
	
	/*sos[0]=fseek(sfp, i--, SEEK_END);
	
	while(fgetc)
	while(fgetc(sfp)!=':')
	{
		sos[i1++] = fgetc(sfp);
	}
	isos = sos[0] + sos[1] * 10 + sos[2] * 100 + sos[3] * 1000;
	soscore.push_back(isos);*/

}