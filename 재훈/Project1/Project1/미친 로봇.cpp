#include<iostream>
#include<iomanip>
using namespace std;

int N;
double arr[4];
double p=1;
double ret;
int map[50][50];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void dfs(int row,int col,int num)
{
	map[25][25] = 1;
	if (num >=N)
	{
		ret += p;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int x = row + dx[i];
		int y = col + dy[i];
		if (!map[x][y])
		{
			if (arr[i] != 0)
			{
				p *= arr[i];
				map[x][y] = 1;
				dfs(x, y, num + 1);
				p /= arr[i];
				map[x][y] = 0;
			}
		}
	}

}


int main()
{
	cin >> N;
	for (int i = 0; i < 4; i++)
	{
		cin >> arr[i];
		arr[i] /= 100;
	}
	dfs(25,25,0);
	cout << fixed << setprecision(9)<<ret<< endl;
}