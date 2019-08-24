#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<utility>
#include<algorithm>
using namespace std;

int r, c, t;
int arr[51][51];
int temp[51][51];
int dx[] = { 1,0,-1,0 };
int dy[] = {0,1,0,-1};
vector<int>row;

void rotate()
{
	for (int i = row[0] - 1; i >= 1; i--)
	{
		if (arr[i+1][1] != -1)
		{
			temp[i + 1][1] = temp[i][1];
		}
	}
	for (int i = 2; i <=c; i++)
	{
		temp[1][i - 1] = temp[1][i];
	}
	for (int i = 2; i <= row[0]; i++)
	{
		temp[i - 1][c] = temp[i][c];
	}
	for (int i = c-1; i >=2; i--)
	{
		temp[row[0]][i+1] = temp[row[0]][i];
	}
	temp[row[0]][2] = 0;

	for (int i = row[1]+1; i <=r; i++)
	{
		if (arr[i-1][1] != -1)
		{
			temp[i-1][1] = temp[i][1];
		}
	}
	for (int i = 2; i <= c; i++)
	{
		temp[r][i - 1] = temp[r][i];
	}
	for (int i = r-1; i >=row[1]; i--)
	{
		temp[i+1][c] = temp[i][c];
	}
	for (int i = c - 1; i >= 2; i--)
	{
		temp[row[1]][i + 1] = temp[row[1]][i];
	}
	temp[row[1]][2] = 0;
}

int main()
{
	cin >> r >> c >> t;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == -1)row.push_back(i);
		}
	}
	for (int m = 0; m < t; m++)
	{
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				if (arr[i][j] != 0 && arr[i][j] != -1)
				{
					int cnt = 0;
					for (int a = 0; a < 4; a++)
					{
						int nx = i + dx[a];
						int ny = j + dy[a];
						if (nx >= 1 && nx <= r && ny >= 1 && ny <= c)
						{
							if (arr[nx][ny] != -1) { 
								cnt++;
								temp[nx][ny] += arr[i][j] / 5;
							}
						}
					}
					temp[i][j] += (arr[i][j] - arr[i][j] / 5 * cnt);
				}
			}
		}
		rotate();
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				if(arr[i][j]!=-1)
				arr[i][j] = temp[i][j];
			}
		}
		memset(temp, 0, sizeof(temp));
	}
	int ans = 0;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (arr[i][j] != -1)
				ans += arr[i][j];
		}
	}
	cout << ans << endl;
}