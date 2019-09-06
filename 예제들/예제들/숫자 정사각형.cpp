#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n, m;
int arr[51][51];
int dx[] = {1,1,0};
int dy[] = {0,1,1};
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = s[j] - '0';
		}
	}

	int k = min(m, n);
	int ans = 1;
	for (int r = k - 1; r >= 1; r--)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int cnt = 0;
				for (int a = 0; a < 3; a++)
				{
					int nx = i + dx[a]*r;
					int ny = j + dy[a]*r;
					if (nx >= 0 && nx < n&&ny >= 0 && ny < m)
					{
						if (arr[i][j] == arr[nx][ny])cnt++;
					}
				}
				if (cnt == 3)
				{
					ans = (r + 1)*(r + 1);
					cout << ans << endl;
					return 0;
				}
			}
		}
	}
	cout << ans << endl;
}