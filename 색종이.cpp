#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int T, N,K;
int arr[10001];
int idx[10001];
int scount[10001];
int ans;


int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N>>K;
		memset(idx, -1, sizeof(idx));
		memset(arr, 0, sizeof(arr));
		memset(scount, 0, sizeof(scount));

		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
			if(idx[arr[i]]==-1)
			idx[arr[i]] = i;
			scount[arr[i]]++;
		}
		if (scount[0] == N)
		{
			ans = N - K + 1;
	
		}
		else
		{
			for (int i = 1; i <= K; i++)
			{
				if (idx[i] != -1)
				{
					int cnt = 1;
					int num = idx[i];
					while (num>0)
					{
						if (arr[num - 1] == 0 || arr[num - 1] == i)
						{
							cnt++;
							num--;
						}
						else
							break;
					}
					int j = i-1;
					while (j>=0)
					{
						if (idx[j] == -1)
						{
							cnt--;
							j--;
						}
						else
							break;
					}
					num = idx[i];
					while (num < N-1)
					{
						if (arr[num + 1] == 0 || arr[num + 1] == i)
						{
							cnt++;
							num++;
						}
						else
							break;
					}
					j = i + 1;
					while (j <=K)
					{
						if (idx[j] == -1)
						{
							cnt--;
							j++;
						}
						else
							break;
					}
					ans = max(ans, cnt);
				}
			}
		}

		cout << "#" << t << " "<< ans<<"\n";
		ans = 0;
	}


}