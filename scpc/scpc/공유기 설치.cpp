#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int N, C;
vector<int>v;

bool pos(int dist)
{
	int prev = v[0];
	int cnt = 1;

	for (int i = 1; i < N; i++)
	{
		if (v[i] - prev >= dist)
		{
			cnt++;
			prev = v[i];
		}
	}

	if (cnt >= C)
		return true;
	else
		return false;

}

int main()
{
	cin.tie(0);
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		int x = 0;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int left = 1;
	int right = v[N - 1] - v[0];
	int ans = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (pos(mid))
		{
			ans = max(ans, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << ans << "\n";
}