#include<iostream>
#include<deque>
#include<cmath>
using namespace std;

deque<int>q[5];
int T, K, m;
int ans;
bool flag[5][5];

void func(int num, int dir)
{
	int pnum = 0;
	if (dir == 1)
	{
		pnum= q[num].back();
		q[num].pop_back();
		q[num].push_front(pnum);
	}
	else
	{
		pnum = q[num].front();
		q[num].pop_front();
		q[num].push_back(pnum);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> K;
		for (int i = 1; i < 5; i++)
		{
			for (int j = 1; j < 9; j++)
			{
				cin >> m;
				q[i].push_back(m);
			}
		}
		for (int m = 0; m < K; m++)
		{
			int num = 0;
			int dir = 0;
			for (int i = 1; i < 4; i++)
			{
			if (q[i][2] != q[i + 1][6])
			{
				flag[i][i + 1] = true;
				flag[i+1][i] = true;

			}
			}
			cin >> num >> dir;
			func(num, dir);
			int n = num;
			int mnum = num - 1;
			int pnum = num + 1;
			int mdir = dir;
			int pdir = dir;
			while (1)
			{
				if (mnum >=1)
				{
					if (flag[n][mnum])
					{
						mdir *= -1;
						func(mnum, mdir);
						n = mnum;
						mnum--;
					}
					else
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
			n = num;
			while (1)
			{
				
				if (pnum <5)
				{
					if (flag[n][pnum])
					{
						pdir *= -1;
						func(pnum, pdir);
						n = pnum;
						pnum++;
					}
					else
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
			memset(flag, 0, sizeof(flag));

		}
		for (int a = 1; a < 5; a++)
		{
			if (q[a][0] == 1)
				ans += pow(2, (a - 1));
		}

		cout << "#" << t << " " <<ans<<"\n";
		ans = 0;
		for (int i = 0; i < 5; i++)
		{
			q[i].clear();
		}
	}


}