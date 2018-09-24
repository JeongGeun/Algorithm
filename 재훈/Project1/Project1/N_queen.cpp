#include<iostream>
using namespace std;

int N,col[15],cnt;

bool promising(int k)
{
	for (int i = 0; i < k; i++)
	{
		if (col[i] == col[k] || abs(col[i] - col[k] == (i - k)))
			return false;

	}
	return true;
}

void back(int num)
{
	if (num == N)
		cnt++;
	else
	{
		for (int i = 0; i < N; i++)
		{
			col[num] = i;
			if (promising(num))
				back(num + 1);
		}
	}

}
	
int main()
{
	cin >> N;
	back(0);
	cout << cnt << endl;


}