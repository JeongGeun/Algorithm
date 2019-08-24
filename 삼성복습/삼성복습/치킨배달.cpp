#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;
typedef pair<int, int> pic;
int N, M;
int arr[51][51];
vector<pic>home;
vector<pic>chicken;
vector<pic>v;
int ans = 987654321;

void com(int num, int cnt)
{
	if (cnt >= M)
	{
		int res = 0;
		for (int i = 0; i < home.size(); i++)
		{
			int cnt2 = 987654321;
			for (int j = 0; j < v.size(); j++)
			{
				if (cnt2 > (abs(home[i].first - v[j].first) + abs(home[i].second - v[j].second)))
				{
					cnt2 = abs(home[i].first - v[j].first) + abs(home[i].second - v[j].second);
				}
			}
			res += cnt2;
		}
		ans = min(ans, res);
		return;
	}
	if (num < chicken.size())
	{
		v.push_back(pic(chicken[num].first, chicken[num].second));
		com(num + 1,cnt+1);
		v.pop_back();
		com(num + 1, cnt);
	}

}


int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1) home.push_back(pic(i, j));
			if (arr[i][j]==2) chicken.push_back(pic(i, j));
		}
	}
	com(0, 0);
	cout << ans << endl;


}