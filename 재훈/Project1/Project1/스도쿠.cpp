#include<iostream>
#include<utility>
#include<vector>
#include<string.h>
using namespace std;

int vsize;
int nct;
int arr[9][9];
vector<pair<int, int>>v;

bool check(int x,int y,int n)
{
	int r, c = 0;
	if (x / 3 == 0)
	{
		r = 0;
	}
	else if (x / 3 == 1)
	{
		r = 3;
	}
	else if (x / 3 == 2)
	{
		r = 6;
	}

	if (y / 3 == 0)
	{
		c = 0;
	}
	else if (y / 3 == 1)
	{
		c = 3;
	}
	else if (y / 3 == 2)
	{
		c = 6;
	}
	for (int i = r; i < r + 3; i++)
	{
		for (int j = c; j < c + 3; j++)
		{
			if (arr[i][j] == n)
				return false;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		
		if (arr[i][y] == n)
			return false;
	}
	for (int i = 0; i < 9; i++)
	{
		
		if (arr[x][i] == n)
			return false;
	}
	return true;


}


void backtrack(int num)
{
	if (num >= nct)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		exit(0);
	}
	int row = v[num].first;
	int col = v[num].second;
	for (int i = 1; i < 10; i++)
	{
		if (check(row, col, i))
		{
			arr[row][col] = i;
			backtrack(num + 1);
			arr[row][col] = 0;	
		}
	}
	
};



int main()
{
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> arr[i][j];
			if (!arr[i][j])
			{
				v.push_back(make_pair(i, j));
			}
		}
	}
	nct = v.size();
	backtrack(0);
	
}