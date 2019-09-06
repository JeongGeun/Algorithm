#include<iostream>
#include<vector>
using namespace std;

vector<int>v[101];
int arr[101][101];
int visit[101][101];
int n;

void dfs(int start,int end)
{
	if (!visit[start][end])
	{
		visit[start][end]++;
	}
	else return;

	if (!v[end].empty())
	{
		for (int i = 0; i < v[end].size(); i++)
		{
			dfs(start, v[end][i]);
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j])v[i].push_back(j);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j]) dfs(i, j);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << visit[i][j] << " ";
		}
		cout << endl;
	}
}