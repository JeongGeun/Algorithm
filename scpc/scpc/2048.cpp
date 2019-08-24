#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

int arr[30][30];
bool flag[30][30];
int n;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int ans = 0;

void func(int cnt, int carr[30][30])
{
	if (cnt >= 5) 
	{ 
		for(int i=0;i<n;i++)
		{
			for (int j = 0; j < n; j++)
				ans = max(ans, carr[i][j]);
		}
		return; 
	}

	for (int d = 0; d < 4; d++)
	{
		int tarr[30][30];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				tarr[i][j] = carr[i][j];
		}
		if (d == 0)
		{
			for (int i = 0; i < n; i++)
			{
				vector<int>v;
				vector<int>bv;
				for (int j = 0; j < n; j++)
				{
					if (tarr[i][j]) 
						v.push_back(tarr[i][j]);
					tarr[i][j] = 0;
				}
				if (v.size() == 1)
				{
					tarr[i][n - 1] = v[0];
					continue;
				}
				for (int m = v.size()-1; m >0 ; m--)
				{
					if (v.size() == 0)break;
					if (v[m] == v[m - 1])
					{
						v[m] += v[m - 1];
						v[m - 1] = 0;
					}
				}
				for (int m = 0; m < v.size(); m++)
				{
					if (v[m]) bv.push_back(v[m]);
				}
				int cnt2 = bv.size()-1;
				for (int j = n - 1; j >= 0; j--)
				{
					if (cnt2 >=0)
					{
						tarr[i][j] = bv[cnt2];
						cnt2--;
					}
					else
					{
						tarr[i][j] = 0;
					}
				}
				
			}
		}
		if (d == 1)
		{
			for (int i = 0; i < n; i++)
			{
				vector<int>v;
				vector<int>bv;
				for (int j = 0; j < n; j++)
				{
					if (tarr[i][j]) v.push_back(tarr[i][j]);
					tarr[i][j] = 0;
				}
				if (v.size() == 1)
				{
					tarr[i][0] = v[0];
					continue;
				}
			
				for (int m = 0; m <v.size()-1; m++)
				{
					if (v.size() == 0)break;
					if (v[m] == v[m +1])
					{
						v[m] += v[m + 1];
						v[m + 1] = 0;
					}
				}
				for (int m = 0; m < v.size(); m++)
				{
					if (v[m]) bv.push_back(v[m]);
				}
				int cnt2 = 0;
				for (int j = 0; j <n; j++)
				{
					if (cnt2 < bv.size())
					{
						tarr[i][j] = bv[cnt2];
						cnt2++;
					}
					else
					{
						tarr[i][j] = 0;
					}
				}

			}
		}
		if (d == 2)
		{
			for (int i = 0; i < n; i++)
			{
				vector<int>v;
				vector<int>bv;
				for (int j = 0; j < n; j++)
				{
					if (tarr[j][i]) v.push_back(tarr[j][i]);
					tarr[j][i] = 0;
				}
				if (v.size() == 1)
				{
					tarr[n - 1][i] = v[0];
					continue;
				}
				for (int m = v.size()-1; m > 0; m--)
				{
					if (v.size() == 0)break;
					if (v[m] == v[m - 1])
					{
						v[m] += v[m - 1];
						v[m - 1] = 0;
					}
				}
				for (int m = 0; m < v.size(); m++)
				{
					if (v[m]) bv.push_back(v[m]);
				}
				int cnt2 = bv.size() - 1;
				for (int j = n - 1; j >= 0; j--)
				{
					if (cnt2 >= 0)
					{
						tarr[j][i] = bv[cnt2];
						cnt2--;
					}
					else
					{
						tarr[j][i] = 0;
					}
				}

			}
		}
		if (d == 3)
		{
			for (int i = 0; i < n; i++)
			{
				vector<int>v;
				vector<int>bv;
				for (int j = 0; j < n; j++)
				{
					if (tarr[j][i]) v.push_back(tarr[j][i]);
					tarr[j][i] = 0;
				}
				if (v.size() == 1)
				{
					tarr[0][i] = v[0];
					continue;
				}
				for (int m = 0; m < v.size()-1; m++)
				{
					if (v.size() == 0) break;
					if (v[m] == v[m + 1])
					{
						v[m] += v[m+1];
						v[m + 1] = 0;
					}
				}
				for (int m = 0; m < v.size(); m++)
				{
					if (v[m]) bv.push_back(v[m]);
				}
				int cnt2 = 0;
				for (int j = 0; j < n; j++)
				{
					if (cnt2 < bv.size())
					{
						tarr[j][i] = bv[cnt2];
						cnt2++;
					}
					else
					{
						tarr[j][i] = 0;
					}
				}

			}
		}
		func(cnt + 1, tarr);
		memset(tarr, 0, sizeof(tarr));
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
		}
	}

	func(0, arr);
	cout << ans << endl;

}