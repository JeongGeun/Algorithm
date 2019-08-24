#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int n;
int arr[202];

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	int a, b;
	int cnt = 1;
	while (cin >> a) {
		cin >> b;
		a += 101;
		b += 101;
		bool flag = false;
		int k = 0;
		for (int i = a; i <= b; i++)
		{
			if (arr[i] != 0)
			{
				flag = true;
				k = arr[i];
				break;
			}
		}
		
		for (int i = a; i <= b; i++)
		{
			if (k >0)
				arr[i] = k;
			else
				arr[i] = cnt;
		}
		cnt++;
		
	}
	vector<int>v;
	vector<pair<int, int>>ans;
	for (int j = 1; j <= 30; j++)
	{
		for (int i = 1; i <= 201; i++)
		{
			if (arr[i]==j)
			{
				v.push_back(i);
			}
		}
		if(v.size()>=1)
		ans.push_back(make_pair(v[0]-101, v[v.size() - 1]-101));
		v.clear();
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first << " " << ans[i].second << "\n";
	}

	return 0;
}