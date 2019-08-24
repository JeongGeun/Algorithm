#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#include<utility>
using namespace std;

struct pic {
	int x;
	int y;
};
int N;
vector<pic>v;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		pic p;
		cin >> p.x >> p.y;
		v.push_back(p);
	}
	vector<int>ret;
	for (int i = 0; i < N; i++)
	{
		int cnt = 1;
		for (int j = 0; j < N; j++)
		{
			if (i == j) continue;
			if (v[i].x < v[j].x&&v[i].y < v[j].y) cnt++;
		}
		ret.push_back(cnt);
	}
	for (int i = 0; i < N; i++)
	{
		cout << ret[i] << " ";
	}

}