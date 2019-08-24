#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>
#include<utility>
using namespace std;

typedef pair<int, int> pic;
char map[11][11];
int N, M;
deque<pic>rq;
deque<pic>bq;
int ex, ey;
int ans = 987654321;
void bfs(int cnt,char arr[][11])
{
	if (cnt > 10) return;

	for (int d = 0; d < 4; d++)
	{
		char temp[11][11];
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				temp[i][j] = arr[i][j];
				if (temp[i][j] == 'R') rq.push_back(pic(i, j));
				else if (temp[i][j] == 'B') bq.push_back(pic(i, j));
			}
		}

		if (d == 0) {
			vector<pic>v;
			int col = 0;
			if (rq[0].second >= bq[0].second)
			{
				v.push_back(pic(rq[0].first, rq[0].second));
				v.push_back(pic(bq[0].first, bq[0].second));
				col = 0;
			}
			else
			{
				v.push_back(pic(bq[0].first, bq[0].second));
				v.push_back(pic(rq[0].first, rq[0].second));
				col = 1;
			}
			rq.clear();
			bq.clear();
			bool flag[2] = {false,};
			for (int m = 0; m < 2; m++)
			{
				int xx = v[m].second;
				xx++;
				while (1)
				{
					if (temp[v[m].first][xx] == 'O')
					{
						flag[m] = true;
						break;
					}
					if (temp[v[m].first][xx] == '#'|| temp[v[m].first][xx] == 'R' || temp[v[m].first][xx] == 'B') {
						xx--;
						char tmp[2];
						tmp[0] = temp[v[m].first][v[m].second];
						temp[v[m].first][v[m].second] = '.';
						temp[v[m].first][xx] = tmp[0];
						break;
					}
					xx++;
				}
				if (!col&&flag[0] && !flag[1])
				{
					ans = min(ans, cnt);
				
				}
				else if (col && !flag[0] && flag[1])
				{
					ans = min(ans, cnt);
				}
			}
		}
		
		if (d == 1) {
			vector<pic>v;
			int col = 0;
			if (rq[0].second >= bq[0].second)
			{
				v.push_back(pic(bq[0].first, bq[0].second));
				v.push_back(pic(rq[0].first, rq[0].second));
				col = 1;
			}
			else
			{
				v.push_back(pic(rq[0].first, rq[0].second));
				v.push_back(pic(bq[0].first, bq[0].second));
			}
			rq.clear();
			bq.clear();
			bool flag[2] = { false, };
			for (int m = 0; m < 2; m++)
			{
				int xx = v[m].second;
				xx--;
				while (1)
				{
					if (temp[v[m].first][xx] == 'O')
					{
						flag[m] = true;
						break;
					}
					if (temp[v[m].first][xx] == '#' || temp[v[m].first][xx] == 'R' || temp[v[m].first][xx] == 'B') {
						xx++;
						char tmp[2];
						tmp[0] = temp[v[m].first][v[m].second];
						temp[v[m].first][v[m].second] = '.';
						temp[v[m].first][xx] = tmp[0];
						break;
					}
					xx--;
				}
				if (!col&&flag[0] && !flag[1])
				{
					ans = min(ans, cnt);

				}
				else if (col && !flag[0] && flag[1])
				{
					ans = min(ans, cnt);
					
				}
			}
		}

		if (d == 2) {
			vector<pic>v;
			int col = 0;
			if (rq[0].first >= bq[0].first)
			{
				v.push_back(pic(rq[0].first, rq[0].second));
				v.push_back(pic(bq[0].first, bq[0].second));
			}
			else
			{
				v.push_back(pic(bq[0].first, bq[0].second));
				v.push_back(pic(rq[0].first, rq[0].second));
				col = 1;
			}
			rq.clear();
			bq.clear();
			bool flag[2] = { false, };
			for (int m = 0; m < 2; m++)
			{
				int xx = v[m].first;
				xx++;
				while (1)
				{
					if (temp[xx][v[m].second] == 'O')
					{
						flag[m] = true;
						break;
					}
					if (temp[xx][v[m].second] == '#' || temp[xx][v[m].second] == 'R' || temp[xx][v[m].second] == 'B') {
						xx--;
						char tmp[2];
						tmp[0] = temp[v[m].first][v[m].second];
						temp[v[m].first][v[m].second] = '.';
						temp[xx][v[m].second] = tmp[0];
						break;
					}
					xx++;
				}
				if (!col&&flag[0] && !flag[1])
				{
					ans = min(ans, cnt);	
				}
				else if (col && !flag[0] && flag[1])
				{
					ans = min(ans, cnt);
				}
			}
		}

		if (d == 3) {
			vector<pic>v;
			int col = 0;
			if (rq[0].first >= bq[0].first)
			{
				v.push_back(pic(bq[0].first, bq[0].second));
				v.push_back(pic(rq[0].first, rq[0].second));
				col = 1;
			}
			else
			{
				v.push_back(pic(rq[0].first, rq[0].second));
				v.push_back(pic(bq[0].first, bq[0].second));
			}
			rq.clear();
			bq.clear();
			bool flag[2] = { false, };
			for (int m = 0; m < 2; m++)
			{
				int xx = v[m].first;
				xx--;
				while (1)
				{
					if (temp[xx][v[m].second] == 'O')
					{
						flag[m] = true;
						break;
					}
					if (temp[xx][v[m].second] == '#' || temp[xx][v[m].second] == 'R' || temp[xx][v[m].second] == 'B') {
						xx++;
						char tmp[2];
						tmp[0] = temp[v[m].first][v[m].second];
						temp[v[m].first][v[m].second] = '.';
						temp[xx][v[m].second] = tmp[0];
						break;
					}
					xx--;
				}
				if (!col&&flag[0] && !flag[1])
				{
					ans = min(ans, cnt);
				}
				else if (col && !flag[0] && flag[1])
				{
					ans = min(ans, cnt);
				}
			}
		}

		bfs(cnt + 1, temp);
		memset(temp, 0, sizeof(temp));
	}

}


int main()
{
	cin >> N >> M;
	for(int i=0;i<N;i++)
	{ 
		for (int j = 0; j < M;j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'R') rq.push_back(pic(i, j));
			else if (map[i][j] == 'B') bq.push_back(pic(i, j));
			else if (map[i][j] == 'O')
			{
				ex = i;
				ey = j;
			}
		}
	}
	bfs(1, map);
	if (ans == 987654321)
		cout << "-1" << endl;
	else
		cout << ans << endl;
}