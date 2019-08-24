#include<queue>
#include<iostream>
using namespace std;


priority_queue<int>pq;
int N;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x = 0;
		cin >> x;
		if (x == 0)
		{
			if (pq.empty())
			{
				cout << "0" << "\n";
				continue;
			}
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
		{
			pq.push(x);
		}
	}

}