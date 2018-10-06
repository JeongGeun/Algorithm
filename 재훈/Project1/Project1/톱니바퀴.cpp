#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;



int arr[4][10],K,num,dir;
bool flag[4];
int ret;
int m;

void circle(int num,int dir)
{
	if (dir == 1)
	{
		for (int t = 8; t >= 1; t--)
		{
			arr[num][t + 1] = arr[num][t];
		}
		arr[num][1] = arr[num][9];
		arr[num][9] = 0;
	}
	else
	{
		for (int t = 0; t <= 7; t++)
		{
			arr[num][t] = arr[num][t + 1];
		}
		arr[num][8] = arr[num][0];
		arr[num][0] = 0;
	
	}
}


int main()
{
	for (int i = 0; i < 4; i++)
	{
		cin >> m;
		for (int j = 8; j>=1 ; j--)
		{
			arr[i][j] = m % 10;
			m /= 10;
		}
	}

	cin >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> num >> dir;
		num--;
		int mnum = num - 1;
		int pnum = num + 1;
		for (int j = 0; j < 4; j++)
		{
			if (arr[j][3] != arr[j + 1][7])
				flag[j] = true;
		}
		circle(num, dir);
		int mdir = dir;
		while (mnum >= 0)
		{
			if (flag[mnum])
			{
				mdir = mdir * (-1);
				circle(mnum, mdir);
				mnum--;
			}
			else
				break;
		}
		int pdir = dir;
		while (pnum < 4)
		{
			if (flag[pnum-1])
			{
				pdir = pdir * (-1);
				circle(pnum, pdir);
				pnum++;
			}
			else
				break;
		}
		memset(flag, false, sizeof(flag));
	}
	
	for (int i = 0; i < 4; i++)
	{
		if (arr[i][1])
			ret += pow(2, i);
	}
	cout << ret << endl;


}