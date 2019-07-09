#include<iostream>
#include<queue>
#include<string.h>
#include<vector>
#include<utility>
using namespace std;

int N, M,K;
int arr[1001][1001];
vector<pair<int, int>> v[11];

void calc(int x,int y)
{


}


int main()
{
	int T = 0;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> N >> M >> K;

		for (int i = 500; i < 500 + N; i++)
		{
			for (int j = 500; j < 500 + M; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j])
					v[arr[i][j]].push_back(make_pair(i, j));
			}
		}
		



	}







}
