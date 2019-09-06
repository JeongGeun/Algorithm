#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

struct water {
	int a;
	int b;
	int c;
};
int arr[201][201][201];
int visit[201][201][201];
deque<water>q;
int A, B, C;

int main()
{
	cin >> A >> B >> C;
	q.push_back({0,0,C});
	visit[0][0][C]++;
	vector<int>ans;
	while (!q.empty())
	{
		int na = q.front().a;
		int nb = q.front().b;
		int nc = q.front().c;
		q.pop_front();
		if (na == 0)ans.push_back(nc);
		if (na != 0)
		{
			if (na + nb >= B)
			{
				if (!visit[na+nb-B][B][nc])
				{
					visit[na + nb - B][B][nc]++;
					q.push_back({ na + nb - B,B,nc });
				}
			}
			else {
				if (!visit[0][na+nb][nc]) 
				{
					visit[0][na+nb][nc]++;
					q.push_back({ 0,nb + na,nc });
				}
			}

			if (na + nc >= C)
			{
				if (!visit[na+nc-C][nb][C])
				{
					visit[na + nc - C][nb][C]++;
					q.push_back({ na+nc-C,nb,C });
				}
			}
			else {
				if (!visit[0][nb][na+nc])
				{
					visit[0][nb][na+nc]++;
					q.push_back({ 0,nb,na+nc });
				}
			}
		}

		if (nb != 0)
		{
			if (na + nb >= A)
			{
				if (!visit[A][na + nb - A][nc])
				{
					visit[A][na + nb - A][nc]++;
					q.push_back({ A,na+nb-A,nc });
				}
			}
			else {
				if (!visit[na+nb][0][nc])
				{
					visit[na+nb][0][nc]++;
					q.push_back({ nb + na,0,nc });
				}
			}

			if (nb + nc >= C)
			{
				if (!visit[na][nb+nc-C][C])
				{
					visit[na][nb + nc - C][C]++;
					q.push_back({ na,nb + nc - C,C });
				}
			}
			else {
				if (!visit[na][0][nb + nc])
				{
					visit[na][0][nb + nc]++;
					q.push_back({ na,0,nb + nc });
				}
			}
		}
	
		if (nc != 0)
		{
			if (na + nc >= A)
			{
				if (!visit[A][nb][na+nc-A])
				{
					visit[A][nb][na + nc - A]++;
					q.push_back({ A,nb,na+nc-A });
				}
			}
			else {
				if (!visit[na + nc][nb][0])
				{
					visit[na + nc][nb][0]++;
					q.push_back({ nc + na,nb,0 });
				}
			}

			if (nb + nc >= B)
			{
				if (!visit[na][B][nb+nc-B])
				{
					visit[na][B][nb+nc-B]++;
					q.push_back({ na,B,nb+nc-B });
				}
			}
			else {
				if (!visit[na][nb+nc][0])
				{
					visit[na][nb+nc][0]++;
					q.push_back({ na,nb+nc,0 });
				}
			}
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";


}