#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int arr[102];
int visit[102];
int visit2[102];
vector<int>v;

void find(int s)
{
	visit[s]++;
	if (!visit[arr[s]])
	{
		find(arr[s]);
	}
	else if (visit[arr[s]] && !visit2[arr[s]])
	{
		visit2[arr[s]]++;
		find(arr[s]);
	}
	else if (visit[arr[s]] && visit2[arr[s]]) return;

	
}

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) { 
		if(!visit2[i])
		find(i); 
		memset(visit, 0, sizeof(visit));
	}
	for (int i = 1; i <= n; i++)
	{
		if (visit2[i]) v.push_back(i);
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}



