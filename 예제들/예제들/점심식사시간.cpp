#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#include<utility>
using namespace std;

typedef pair<int, int> P;
struct pic {
	int x;
	int y;
};
int arr[11][11];
int N;

vector<pic>person;
vector<pic>stair;
vector<int>s1;
vector<int>s2;
int ans = 1e9;
int T;
void move()
{
	deque<int>q1;
	deque<int>q2;
	deque<P>tq1;
	deque<P>tq2;

	for (int i = 0; i < s1.size(); i++)
	{
		int ret = abs(stair[0].x - person[s1[i]].x) + abs(stair[0].y - person[s1[i]].y);
		q1.push_back(ret);
	}
	for (int i = 0; i < s2.size(); i++)
	{
		int ret = abs(stair[1].x - person[s2[i]].x) + abs(stair[1].y - person[s2[i]].y);
		q2.push_back(ret);
	}
	if (!q1.empty()) sort(q1.begin(), q1.end());
	if (!q2.empty()) sort(q2.begin(), q2.end());
	int time = 0;
	int qs1 = q1.size();
	int qs2 = q2.size();
	while (1)
	{
		if (q1.empty()&& q2.empty()&& tq1.empty() && tq2.empty()) break;
		int lcnt = 0;
		for (int i = 0; i < q1.size(); i++)
		{
			int fl = 0;
			int fl2 = 0;
			if(q1[i]>-1) q1[i]--;
			else fl = 1;

			if (tq1.size() < 3)
			{
				if (q1[i] == -1) {
					if(fl) tq1.push_back({ i, 0 });
					else tq1.push_back({ i, -1 });
					lcnt++;
				}
				if (q1[i] == 0) {
					tq1.push_back({i,-2});
					lcnt++;
				}
			}
		}
		for (int i = 0; i < lcnt; i++) q1.pop_front();
		lcnt = 0;
		for (int i = 0; i < q2.size(); i++)
		{
			int fl = 0;
			int fl2 = 0;
			if(q2[i]>-1)q2[i]--;
			else fl = 1;
			
			if (tq2.size() < 3)
			{
				if (q2[i] == -1) {
					if (fl) tq2.push_back({ i, 0 });
					else tq2.push_back({ i, -1 });
					lcnt++;
				}
				if (q2[i] == 0) {
					tq2.push_back({ i,-2 });
					lcnt++;
				}
			}
		}
		for (int i = 0; i < lcnt; i++) q2.pop_front();
		lcnt = 0;
		int rcnt = 0;
		for (int i = 0; i < tq1.size(); i++)
		{
			tq1[i].second++;
			if (tq1[i].second == arr[stair[0].x][stair[0].y]) rcnt++;
		}
		for (int i = 0; i < rcnt; i++) tq1.pop_front();
		rcnt = 0;
		for (int i = 0; i < tq2.size(); i++)
		{
			tq2[i].second++;
			if (tq2[i].second == arr[stair[1].x][stair[1].y]) rcnt++;
		}
		for (int i = 0; i < rcnt; i++) tq2.pop_front();
		time++;
	}
	ans = min(time, ans);
}


int main()
{
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		person.clear();
		stair.clear();
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == 1)
				{
					person.push_back({ i,j });
				}
				else if (arr[i][j])
				{
					stair.push_back({ i,j });
				}
			}
		}

		for (int i = 0; i < (1 << person.size()); i++)
		{
			int cnt = 0;
			s1.clear();
			s2.clear();
			for (int j = 0; j < person.size(); j++)
			{
				if (i&(1 << j))
				{
					s1.push_back(j);
				}
				else s2.push_back(j);
			}
			move();
		}
		cout << "#" << t << " " << ans << endl;
		ans = 1e9;
		memset(arr, 0, sizeof(arr));
	}

}