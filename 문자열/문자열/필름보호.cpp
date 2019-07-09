#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;


int d, w, k;
int arr[21][21];
int carr[21][21];
vector<int>a;
vector<int>b;
int visit[14];
int ans = 0;
void func()
{
	memset(carr, 0, sizeof(carr));
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < w; j++)
		{
			carr[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < d;i++ )
	{
		if (visit[i])
		{
			for (int j = 0; j < w; j++)
			{
				carr[i][j] = 0;
			}
		}
		else
		{
			for (int j = 0; j < w; j++)
			{
				carr[i][j] = 1;
			}
		}
	}
	bool flag = true;
	for (int i = 0; i < w; i++)
	{
		int cnt = 1;
		flag = false;
		for (int j = 0; j < d - 1; j++)
		{
			if (arr[j][i] == arr[j + 1][i])
			{
				cnt++;
			}
			if (cnt == k)
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			break;
		}
	}
	if(flag)
		ans=max
}

void calc(int num, int cnt, int wid)
{
	if (num == wid)
	{
		for (int i = 0; i < w; i++)
		{
			if (!visit[i])
				b.push_back(i);
		}
		func();
	}
	if (num < w)
	{
		visit[num]++;
		a.push_back(num);
		calc(num + 1, cnt + 1, wid);
		visit[num]--;
		a.pop_back();
		calc(num + 1, cnt, wid);
	}


}


int main()
{
	int T = 0;
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		
		cin >> d >> w >> k;
		for (int i = 0; i < d; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> arr[i][j];
			}
		}
		bool flag = false;

		for (int i = 0; i < w; i++)
		{
			int cnt = 1;
			flag = false;
			for (int j = 0; j < d-1; j++)
			{
				if (arr[j][i] == arr[j + 1][i])
				{
					cnt++;
				}
				if (cnt == k)
				{
					flag = true;
					break;
				}
			}	
			if (!flag)
			{
				break;
			}
		}
		if (flag)
		{
			cout << ans << "\n";
			continue;
		}
		for (int i = 0; i <= w; i++)
		{
			calc(0, 1, i);
		}
		
		cout << "#" << t << " " << ans << "\n";
		ans = 0;

	}






}