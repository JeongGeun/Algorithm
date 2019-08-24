#include <iostream>
#include<string>
#include<vector>
using namespace std;

vector<int>ans;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	vector<string>v;
	string i;
	while (cin >> i) {
		v.push_back(i);
	}

	for (int i = 0; i < v.size(); i++)
	{
		int a = stoi(v[i]);
		ans.push_back(a);
	}
	vector<int>visit(v.size() + 1, 0);

	for (int i = 0; i < ans.size(); i++)
	{
		if (ans[i] > 200 && ans[i] < -200)
		{
			continue;
		}
		else
		{
			int a = 0;
			int b = 0;
			if (i - 2 >= 0)
			{
				a++;
				if (abs(ans[i] - ans[i - 2]) >= 3)
				{
					//flag = true;
					b++;
				}
			}
			if (i - 1 >= 0)
			{
				a++;
				if (abs(ans[i] - ans[i - 1]) >= 3)
				{
					//flag = true;
					b++;
				}
			}
			if (i + 1 < v.size())
			{
				a++;
				if (abs(ans[i] - ans[i + 1]) >= 3)
				{
					//flag = true;
					b++;
				}
			}
			if (i + 2 < v.size())
			{
				a++;
				if (abs(ans[i] - ans[i + 2]) >= 3)
				{
					//flag = true;
					b++;
				}
			}
			if (a != b)
				visit[i]++;
		}
	}
	int ret = 0;
	int cnt = 0;
	for (int i = 0; i < visit.size(); i++)
	{
		if (visit[i])
		{
			ret += ans[i];
			cnt++;
		}
	}
	if (cnt == 0)
	{
		cout << "ERROR" << "\n";
	}
	else
	{
		cout << ret / cnt << "\n";
	}
}