#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;


int T, N;
vector<pair<int, int>>v;
int visit[100001];
int main()
{
	cin >> T;
	for(int t=0;t<T;t++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			int x = 0;
			int y = 0;
			cin >> x >> y;
			v.push_back(make_pair(x, y));
		}
		sort(v.begin(), v.end());

		int compy = v[0].second;
		int ans = 1;
		for (int i = 1; i < N; i++)
		{
			if (v[i].second < compy)
			{
				ans++;
				compy = v[i].second;
			}
		}
		cout << ans << "\n";
		v.clear();
		memset(visit, 0, sizeof(visit));
	}



}