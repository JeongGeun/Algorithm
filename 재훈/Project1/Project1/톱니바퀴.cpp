#include<iostream>
#include<cmath>
using namespace std;



int arr[4][9],K,num,dir;
bool flag[4];
int ret;

void circle(int num,int dir)
{
	if (dir == 1)
	{
		for (int k = 8; k >= 1; k--)
		{
			arr[num][k + 1] = arr[num][k];
		}
		arr[num][1] = arr[num][9];
		arr[num][9] = 0;
	}
	else
	{
		for (int k = 0; k <= 7; k++)
		{
			arr[num][k] = arr[num][k + 1];
		}
		arr[num][8] = arr[num][0];
		arr[num][0] = 0;
	}
}


int main()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			cin >> arr[i][j];
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
			if (arr[j][2] != arr[j + 1][7])
				flag[j] = true;
		}
		circle(num, dir);
		while (mnum >= 0)
		{
			if (flag[mnum])
			{
				dir = dir * (-1);
				circle(mnum, dir);
			}
		}

	}
	for (int i = 0; i < 4; i++)
	{
		if (arr[i][0])
			ret += pow(2, i);
	}



}