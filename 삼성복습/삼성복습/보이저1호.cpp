#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#include<utility>
using namespace std;

int n,m;
char arr[502][502];
int visit[502][502];
int pr, pc;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};


int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cin >> pr >> pc;
	string s="URDL";
	int ans = 0;
	int idx = 0;
	for (int i = 0; i < 4; i++)
	{
		memset(visit, -1, sizeof(visit));
		int x = pr;
		int y = pc;
		int dir = i;
		int cnt = 1;
		visit[x][y]=dir;
		while (1)
		{
			x = x + dx[dir];
			y = y + dy[dir];
			if (x >= 1 && x <= n&&y >= 1 && y <= m)
			{
				if (visit[x][y] != dir)
				{
					visit[x][y] = dir;
					if (arr[x][y] == '.') {
						cnt++;
						continue;
					}
					else if (arr[x][y] == '/') {
						if (dir == 0) dir = 1;
						else if (dir == 1) dir = 0;
						else if (dir == 2) dir = 3;
						else if (dir == 3) dir = 2;
						cnt++;
					}
					else if (arr[x][y] == '\\')
					{
						if (dir == 0) dir = 3;
						else if (dir == 3) dir = 0;
						else if (dir == 1) dir = 2;
						else if (dir == 2) dir = 1;
						cnt++;
					}
					else  break;
				}
				else {
					cout << s[i] << endl;
					cout <<"Voyager" << endl;
					return 0;
				}
			}
			else break;
		}
		if (ans < cnt)
		{
			ans = cnt;
			idx = i;
		}
	}
	cout << s[idx] << endl;
	cout << ans << endl;
	
}