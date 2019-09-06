#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

struct pic {
	int rx;
	int ry;
	int bx;
	int by;
	int ans;
};
char arr[22][22];
int check[22][22][22][22];
int n, m;
deque<pic>q;
int dx[] = {1,0,-1,0};
int dy[] = { 0,1,0,-1 };


int main()
{
	cin >> n >> m;
	int rx=0, ry=0, bx=0, by=0;
	int c = 0;
	for(int i=0;i<n;i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'o')
			{ 
				if (c == 0)
				{
					rx = i, ry = j;
					c++;
				}
				else 
				{
					bx = i, by = j;
				}
			}
		}
	}
	check[rx][ry][bx][by]++;
	q.push_back({ rx,ry,bx,by,0 });
	while (!q.empty())
	{
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int ans = q.front().ans;
		q.pop_front();
		if (ans >= 10) break;
		for (int i = 0; i < 4; i++)
		{
			int nrx = rx + dx[i];
			int nry = ry + dy[i];
			int nbx = bx + dx[i];
			int nby = by + dy[i];
			int rf = 0, bf = 0,rc=0,bc=0;
			if (nrx < 0 || nrx >= n || nry < 0 || nry >= m) rf++;
			if (nbx < 0 || nbx >= n || nby < 0 || nby >= m) bf++;
			if (rf && bf) continue;
			else if (!rf && !bf)
			{
				if (arr[nrx][nry] == '#')
				{
					nrx = rx;
					nry = ry;
				}
				else rc++;

				if (arr[nbx][nby] == '#')
				{
					nbx = bx;
					nby = by;
				}
				else bc++;
				
				if (nrx == nbx && nry == nby)
				{
					if (rc > bc) {
						nrx = rx;
						nry = ry;
					}
					else {
						nbx = bx;
						nby = by;
					}
				}
				if (!check[nrx][nry][nbx][nby]) { 
					q.push_back({nrx,nry,nbx,nby,ans+1});
					check[nrx][nry][nbx][nby]++; 
				}
			}
			else {
				cout << ans + 1 << endl;
				return 0;
			}
		}
	}
	cout << "-1" << endl;




}