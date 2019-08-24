#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#include<utility>
using namespace std;


int N, L;
int arr[101][101];

int row(int num)
{
	int old = arr[num][0];
	int cur = 0;
	int val = 0;

	for (int i = 0; i < N; i++)
	{
		cur = arr[num][i];
		if (cur == old)
		{
			val++;
		}
		else if (cur > old)
		{
			if (cur > old + 1 || val<L) return 0;
			val = 1;
		}
		else {
			if (cur+1< old || val < 0) return 0;
			val = 1-L;
		}
		old = cur;
	}
	if (val >= 0) return 1;
	else return 0;
}
int col(int num)
{
	int old = arr[0][num];
	int cur = 0;
	int val = 0;

	for (int i = 0; i < N; i++)
	{
		cur = arr[i][num];
		if (cur == old)
		{
			val++;
		}
		else if (cur > old)
		{
			if (cur > old + 1 || val < L) return 0;
			val = 1;
		}
		else {
			if (cur + 1 < old || val < 0) return 0;
			val = 1 - L;
		}
		old = cur;
	}
	if (val >= 0) return 1;
	else return 0;

}



int main()
{
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans += (row(i)+col(i));
	}
	cout << ans << endl;
}