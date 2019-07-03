#include<vector>
#include<string.h>
#include<iostream>

using namespace std;

struct shark {

	int r;
	int c;
	int s;
	int d;
	int z;
};
vector<shark>s;
int arr[102][102];
int R, C, M;
int ans;
int dx[] = {-1,1,0,0};
int dy[] = { 0,0,1,-1 };
bool visit[10001];

int main() {

	cin >> R >> C >> M;
	for (int i = 0; i < M; i++)
	{
		shark sh;
		cin >> sh.r >> sh.c >> sh.s >> sh.d >> sh.z;
		sh.d--;
		s.push_back(sh);
		arr[sh.r][sh.c] = sh.z;
	}

	for (int i = 1; i <= C; i++)
	{
		int k = 0;
		for (int j = 1; j <= R; j++)
		{
			if (arr[j][i])
			{
				ans += arr[j][i];
				k = arr[j][i];
				visit[arr[j][i]] = true;
				break;
			}
		}
		for (int a = 0; a < M; a++)
		{
			if (visit[s[a].z])
			{
				s[a].z = 0;
			}
		}
		memset(arr, 0, sizeof(arr));

		for (int a = 0; a < M; a++)
		{
			if (s[a].z > 0&&!visit[s[a].z])
			{
				s[a].r += (s[a].s*dx[s[a].d]);
				s[a].c += (s[a].s*dy[s[a].d]);
				while (s[a].r <1 || s[a].r > R || s[a].c < 1 || s[a].c > C)
				{
					if (s[a].r < 1)
					{
						s[a].r = 1 + (1 - s[a].r);
						s[a].d = 1;
					}
					else if (s[a].r > R)
					{
						s[a].r = R - (s[a].r - R);
						s[a].d = 0;
					}
					else if (s[a].c < 1)
					{
						s[a].c = 1 + 1 - s[a].c;
						s[a].d = 2;
					}
					else if (s[a].c > C)
					{
						s[a].c = 2 * C - s[a].c;
						s[a].d = 3;
					}
				}
				if (arr[s[a].r][s[a].c] < s[a].z)
				{
					visit[arr[s[a].r][s[a].c]] = true;
					arr[s[a].r][s[a].c] = s[a].z;
				}
				else
				{
					visit[s[a].z] = true;
					s[a].z = 0;
				}
			}
		}

	}
	cout << ans << "\n";

}