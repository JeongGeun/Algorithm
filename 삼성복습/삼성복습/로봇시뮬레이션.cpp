#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#include<utility>
using namespace std;

int A, B, N,M;
int dx[] = { 0,1,0,-1 };
int dy[] = {1,0,-1,0};
int arr[102][102];

struct robot {
	int x;
	int y;
	int dir;

};
deque<robot>q;

int main()
{
	cin >> A >> B;
	cin >> N >> M;
	
	for (int i = 1; i <=N; i++)
	{
		robot r;
		char tmp[2];
		cin >> r.x >> r.y >>tmp;
		if (tmp[0] == 'N') r.dir = 0;
		else if (tmp[0] == 'W') r.dir = 3;
		else if (tmp[0] == 'S') r.dir = 2;
		else if (tmp[0] == 'E') r.dir = 1;
		q.push_back(r);
		arr[r.y][r.x] = i;
	}
	for (int i = 0; i < M; i++)
	{
		int idx, ccnt;
		char com[2];
		cin >> idx >> com >> ccnt;
		idx--;
		for (int m = 0; m < ccnt; m++)
		{

			if (com[0] == 'L')
			{
				q[idx].dir = (q[idx].dir + 3) % 4;
			}
			else if (com[0] == 'R')
			{
				q[idx].dir = (q[idx].dir + 1) % 4;
			}
			else
			{
				int xx = q[idx].x;
				int yy = q[idx].y;
				q[idx].x += dx[q[idx].dir];
				q[idx].y += dy[q[idx].dir];
				if (q[idx].x <=0 || q[idx].x >A  || q[idx].y <=0 || q[idx].y > B)
				{
					cout << "Robot " << idx + 1 << " crashes into the wall" << endl;
					return 0;
				}
				else if (arr[q[idx].y][q[idx].x])
				{
					cout << "Robot " << idx + 1 << " crashes into robot " << arr[q[idx].y][q[idx].x] <<endl;
					return 0;
				}
				else {
					arr[q[idx].y][q[idx].x] = idx + 1;
					arr[yy][xx] = 0;
				}
			}
		}
	}
	cout << "OK" << endl;

}