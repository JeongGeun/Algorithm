#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<string>
#include<cmath>
using namespace std;

int T;
string A;
string B;
bool isPrime[30001];
int ans1,ans2,ans = 0;
vector<char>a;
vector<char>b;
int visit[10];

void aback(int size,int cnt)
{
	int k = 0;
	int kc = 0;
	for (int i = 0; i < size; i++)
	{
		if (visit[i])
			kc++;
	}
	int rsize = size - kc-1;
	for (int i = 0; i < size; i++)
	{
		if (!visit[i])
		{
			k += (a[i] - '0')*pow(10, rsize);
			rsize--;
		}
	}
	if (isPrime[k])
	{
		for (int i = 0; i < A.size(); i++)
		{
			if (!visit[i])
			{
				visit[i]++;
				aback(size,cnt+1);
				visit[i]--;
			}
		}
	}
	else
	{
		ans1 = max(ans1, cnt);
		return;
	}
}

void bback(int size,int cnt)
{
	int k = 0;
	int kc = 0;
	for (int i = 0; i < size; i++)
	{
		if (visit[i])
			kc++;
	}
	int rsize = size - kc - 1;
	for (int i = 0; i < size; i++)
	{
		if (!visit[i])
		{
			k += (b[i] - '0')*pow(10, rsize);
			rsize--;
		}
	}
	if (isPrime[k])
	{
		for (int i = 0; i < size; i++)
		{
			if (!visit[i])
			{
				visit[i]++;
				bback(size, cnt + 1);
				visit[i]--;
			}
		}
	}
	else
	{
		ans2 = max(ans2, cnt);
		return;
	}
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	fill(isPrime + 2, isPrime + 30000+1, true);
	for (int i = 4; i <= 30000; i += 2)
		isPrime[i] = false;
	for (int i = 3; i <= 30000; i++) {
		//if (isPrime[i]) prime.push_back(i);
		for (int j = i * i; j <= 30000; j += i * 2)
			isPrime[j] = false;
	}
	cin >> T;
	for (int t = 1; t <= T; t++)
	{

		cin >> A >> B;
		for (int i = 0; i < A.size(); i++)
		{
			a.push_back(A[i]);
		}
		for (int i = 0; i < B.size(); i++)
		{
			b.push_back(B[i]);
		}
		aback(A.size(),0);
		memset(visit,0,sizeof(visit));
		bback(B.size(), 0);
		if (ans1 > ans2)
			ans = 1;
		else if (ans1 < ans2)
			ans = 2;
		else
			ans = 3;

		cout << "Case #" << t << "\n";
		cout << ans << "\n";
		ans = 0;
		ans1 = 0;
		ans2 = 0;
		a.clear();
		b.clear();
	}



}