#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;

int r, c, m;
int arr[101][101];
struct shark
{
	int r;
	int c;
	int s;
	int d;
	int z;
	bool f;
};
vector<shark> sang[10001];
int dx[] = {0,-1,1,0,0};
int dy[] = {0,0,0,1,-1};



int main()
{
	cin >> r >> c >> m;
	for (int i = 0; i < m; i++)
	{
		shark sh;
		int x, y, s, d, z;
		cin >> x >> y >> s >> d >> z;
		sh.r = x;
		sh.c = y;
		sh.s = s;
		sh.d = d;
		sh.z = z;
		sh.f = false;
		arr[x][y] = z;
		sang[z].push_back(sh);
	}
	int ans = 0;
	for (int a = 1; a <= c; a++)
	{
		for (int j = 1; j <=r; j++)
		{
			if (arr[j][a])
			{
				sang[arr[j][a]][0].f = true;
				ans += arr[j][a];
				break;
			}
		}
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i <= 10000; i++)
		{
			if (!sang[i].empty())
			{
				if (!sang[i][0].f)
				{
					sang[i][0].r += dx[sang[i][0].d] * sang[i][0].s;
					sang[i][0].c += dy[sang[i][0].d] * sang[i][0].s;
					while (1)
					{
						if (sang[i][0].r > 0 && sang[i][0].r <= r && sang[i][0].c > 0 && sang[i][0].c <= c) break;
						if (sang[i][0].r > r) { 
							sang[i][0].r = r - (sang[i][0].r - r);
							sang[i][0].d = 1;
						}
						if (sang[i][0].r < 1) {
							sang[i][0].r = 1 + (1 - sang[i][0].r);
							sang[i][0].d = 2;
						}
						if (sang[i][0].c > c) { 
							sang[i][0].c = c - (sang[i][0].c - c); 
							sang[i][0].d = 4;
						}
						if (sang[i][0].c < 1) { 
							sang[i][0].c = 1 + (1 - sang[i][0].c); 
							sang[i][0].d = 3;
						}
					}
					if (arr[sang[i][0].r][sang[i][0].c])
					{
						if (arr[sang[i][0].r][sang[i][0].c] > sang[i][0].z)
						{
							sang[i][0].f = true;
						}
						else
						{
							sang[arr[sang[i][0].r][sang[i][0].c]][0].f = true;
							arr[sang[i][0].r][sang[i][0].c] = sang[i][0].z;
						}
					}
					else
					{
						arr[sang[i][0].r][sang[i][0].c] = sang[i][0].z;
					}
				}
			}
		}
	}
	cout << ans << endl;

}