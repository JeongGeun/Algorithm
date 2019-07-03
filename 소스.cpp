


vector<int> solution(int N, vector<int> &A) {
	int k = 0;
	int lk = 0;
	vector<int>ret;
	for (int i = 0; i < N; i++)
	{
		ret.push_back(0);
	}
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] > N)
		{
			m = i;
			lk = k;
		}
		else
		{
			if (ret[A[i] - 1] < lk)
			{
				ret[A[i] - 1] = lk;
				ret[A[i] - 1]++;
			}
			else
			{
				ret[A[i] - 1]++;
			}
			if (ret[A[i] - 1] > k)
				k = ret[A[i] - 1];
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (ret[i] < lk)
			ret[i] = lk;
	}
	return ret;
}