#include<iostream>
#include<vector>
using namespace std;

int m, n, x, y, k;
int arr[21][21];
int dice[6];
int cnt[6];
int check[6][4] = { {2,3,1,4},{2,3,4,0},{5,0,1,4},{0,5,1,4},{2,3,0,5},{2,3,4,1} };
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int main()
{
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int w = 0; w < k; w++)
	{
		int dir= 0;
		cin >> dir;
		dir--;
		x += dx[dir];
		y += dy[dir];
		if (x < 0 || x >= n || y < 0 || y >= m)
		{
			x -= dx[dir];
			y -= dy[dir];
			continue;
		}
		else{
		
			
			int temp[6] = { 0, };
			
			if (dir == 0) {
				temp[0] = dice[3];
				temp[1] = dice[1]; 
				temp[2] = dice[0];
				temp[3] = dice[5];
				temp[4] = dice[4];
				temp[5] = dice[2];
			}
			if (dir == 1) {
				temp[0] = dice[2];
				temp[1] = dice[1];
				temp[2] = dice[5];
				temp[3] = dice[0];
				temp[4] = dice[4];
				temp[5] = dice[3];
			}
			if (dir == 2) {
				temp[0] = dice[4];
				temp[1] = dice[0];
				temp[2] = dice[2];
				temp[3] = dice[3];
				temp[4] = dice[5];
				temp[5] = dice[1];
			}
			if (dir == 3) {
				temp[0] = dice[1];
				temp[1] = dice[5];
				temp[2] = dice[2];
				temp[3] = dice[3];
				temp[4] = dice[0];
				temp[5] = dice[4];
			}
			if (arr[x][y]) {
				temp[5] = arr[x][y];
				arr[x][y] = 0;
			}
			else {
				arr[x][y]=temp[5];
			}
			cout << temp[0] << endl;
			for (int i = 0; i < 6; i++)
			{
				dice[i] = temp[i];
			}
		}
	}
}