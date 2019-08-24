#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<string.h>
using namespace std;

int arr[101][101];
int r, c, k;
int cnt[101];
int time;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
			cin >> arr[i][j];
	}
	while (1)
	{
		int rowsize = 0;
		int colsize = 0;
		vector<pair<int,int>>v;
		
		if (arr[r][c] == k)
			break;
		else time++;
		if (time > 100)
		{
			time = -1;
			break;
		}
		for (int i = 1; i <= 100; i++)
		{
			int cnt = 0;
			for (int j = 1; j <= 100; j++)
			{
				if (arr[i][j])
				{
					cnt++;
				}
				else break;
			}
			colsize = max(colsize, cnt);
		}
		for (int i = 1; i <= 100; i++)
		{
			int cnt = 0;
			for (int j = 1; j <= 100; j++)
			{
				if (arr[j][i])
				{
					cnt++;
				}
				else break;
			}
			rowsize = max(rowsize, cnt);
		}
		if (rowsize >= colsize) {
			for (int i = 1; i <= 100; i++)
			{
				for (int j = 1; j <= 100; j++)
				{
					if (arr[i][j])
						cnt[arr[i][j]]++;
					arr[i][j] = 0;
				}
				for (int k = 1; k <= 100; k++)
				{
					if (cnt[k])
						v.push_back(make_pair(cnt[k], k));
				}
				sort(v.begin(), v.end());
				for (int k=1,j = 0; k<=100,j < v.size();k+=2,j++)
				{
					arr[i][k] = v[j].second;
					arr[i][k + 1] = v[j].first;
					
				}
				memset(cnt, 0, sizeof(cnt));
				v.clear();
			}		
		}
		else {
			for (int i = 1; i <= 100; i++)
			{
				for (int j = 1; j <= 100; j++)
				{
					if (arr[j][i])
						cnt[arr[j][i]]++;
					arr[j][i] = 0;
				}
				for (int k= 1; k <= 100; k++)
				{
					if (cnt[k])
						v.push_back(make_pair(cnt[k], k));
				}
				sort(v.begin(), v.end());
				for (int k = 1, j = 0; k <= 100, j < v.size(); k += 2, j++)
				{
					arr[k][i] = v[j].second;
					arr[k+1][i] = v[j].first;

				}
				memset(cnt, 0, sizeof(cnt));
				v.clear();
			}
		}

	}
	cout << time << endl;

}