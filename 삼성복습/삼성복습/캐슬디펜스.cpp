#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;

typedef pair<int, int> pic;

int arr[20][20];
int N, M,D;
vector<pic>v;
vector<pic>arrow;
vector<pic>enemy;
int ans = 0;

void game()
{
	int temp[20][20] = {0,};
	int ret = 0;
	for(int i=0;i<N;i++)
	{ 
		for (int j = 0; j < M; j++)
			temp[i][j]=arr[i][j];
	}
	while (1)
	{
		enemy.clear();
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (temp[i][j])
				{
					enemy.push_back(pic(i, j));
				}
			}
		}
		if (enemy.empty()) break;
		vector<int> n;
		for (int i = 0; i < 3; i++)
		{
			int idx = -1;
			int dist = D;
			int left = 100;
			for (int j = 0; j < enemy.size(); j++)
			{
				if (dist > (abs(arrow[i].first - enemy[j].first) + abs(arrow[i].second - enemy[j].second)))
				{
					dist = (abs(arrow[i].first - enemy[j].first) + abs(arrow[i].second - enemy[j].second));
					idx = j;
					left = enemy[j].second;
				}
				else if (dist == (abs(arrow[i].first - enemy[j].first) + abs(arrow[i].second - enemy[j].second)))
				{
					if (left > enemy[j].second)
					{
						idx = j;
						left = enemy[j].second;
					}
				}
			}
			if (idx != -1) n.push_back(idx);
		}

		for (int i = 0; i < enemy.size(); i++)
		{
			bool flag = false;
			for (int j = 0; j < n.size(); j++)
			{
				if (i == n[j])
				{
					flag = true;
					ret++;
					temp[enemy[i].first][enemy[i].second]--;
					break;
				}
			}
			if (!flag)
			{
				temp[enemy[i].first][enemy[i].second]--;
				temp[enemy[i].first+1][enemy[i].second]++;
			}
		}

	}
	ans = max(ret, ans);

}


void make(int num,int cnt)
{
	if (cnt == 3)
	{
		game();
		return;
	}
	if (num < M)
	{
		arrow.push_back(pic(v[num].first,v[num].second));
		make(num + 1, cnt + 1);
		arrow.pop_back();
		make(num + 1, cnt);
	}

}


int main()
{
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < M; i++)
	{
		v.push_back(pic(N,i));
	}
	make(0, 0);
	cout << ans << endl;


}