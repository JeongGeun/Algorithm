#include<iostream>
#include<set>
using namespace std;

int N, M;
set<int>A;
set<int>B;
int diff;
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int m;
		cin >> m;
		A.insert(m);
	}
	for (int i = 0; i < M; i++)
	{
		int m;
		int asize = A.size();
		cin >> m;
		A.insert(m);
		if (A.size() == asize)
		{
			diff++;
		}
	}
	N -= diff;
	M -= diff;
	cout << N + M << "\n";
}