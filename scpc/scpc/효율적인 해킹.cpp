#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

int N, M;
vector<int> arr[10001];
int visit[10001];
int hacking[10001];
int ans;

void dfs(int x)
{
	hacking[x]++;
	ans = max(ans,hacking[x]);

	for (int i = 0; i < arr[x].size(); i++)
	{
		if (!visit[arr[x][i]])
		{
			visit[arr[x][i]]++;
			dfs(arr[x][i]);
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int x = 0;
		int y = 0;
		cin >> x >> y;
		arr[x].push_back(y);
	}
	for (int i = 1; i <= N; i++)
	{
		memset(visit, 0, sizeof(visit));
		visit[i]++;
		dfs(i);
	}
	for (int i = 1; i <= N; i++)
	{
		if (ans == hacking[i])
			cout << i << " ";
	}
}