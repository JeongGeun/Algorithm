#include<iostream>
#include<string.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<utility>
#include<queue>
using namespace std;

int arr[11][11];
int T, N,ans;
vector<pair<int, int>> stair;
vector<pair<int, int>>person;

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] > 1)
				{
					stair.push_back(make_pair(i,j));
				}
				else if (arr[i][j] == 1)
				{
					person.push_back(make_pair(i,j));
				}
			}
		}
		vector<int> answer;
		for (int i = 0; i < (1<<person.size()); i++)
		{
			vector<pair<int, int>>v1;
			vector<pair<int, int>>v2;
			for (int j = 0; j < person.size(); j++)
			{

				if (i&(1 << j))
				{
					v1.push_back(make_pair(person[j].first, person[j].second));
				}
				else
				{
					v2.push_back(make_pair(person[j].first, person[j].second));
				}
			}

				for (int m2 = 0; m2 < 2; m2++)
				{
					vector<int>a;
					int cnt = 0;
					for (int m = 0; m < v1.size(); m++)
					{	
						cnt = 0;
						cnt += (abs(v1[m].first - stair[m2].first) + abs(v1[m].second - stair[m2].second));
						cnt++;
						a.push_back(cnt);
					}
					if (!a.empty())
					{
						sort(a.begin(), a.end());
						cnt = a[a.size() - 1];
						//cnt++;
						
						cnt += arr[stair[m2].first][stair[m2].second];
						ans = max(ans, cnt);
					}
					a.clear();
					int m3 = 0;
					if (m2 == 0)
						m3 = 1;
					for (int m = 0; m < v2.size(); m++)
					{
					cnt = 0;
					cnt += (abs(v2[m].first - stair[m3].first) + abs(v2[m].second - stair[m3].second));
					cnt++;
					a.push_back(cnt);
					}
					if (!a.empty())
					{
						sort(a.begin(), a.end());
						cnt = a[a.size() - 1];
						//cnt++;
					
						cnt += arr[stair[m3].first][stair[m3].second];
						ans = max(ans, cnt);
					}
					answer.push_back(ans);
					ans = 0;
				}
				
		}
		sort(answer.begin(), answer.end());
		cout << "#" << t << " "<< answer[0]<<'\n';
		memset(arr, 0, sizeof(arr));
		ans = 0;
		stair.clear();
		person.clear();
	}



}