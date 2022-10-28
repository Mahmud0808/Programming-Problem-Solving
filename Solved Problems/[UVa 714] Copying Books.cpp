#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define ll long long int

vector < ll > p;
bool slash[501];

int bs(ll mid)
{
	int sz = p.size() - 1, count = 0;
	memset(slash, false, sizeof(slash));
	ll sum = 0;
	for (int i = sz; i >= 0;)
	{
		sum = 0;
		while (i >= 0 && sum + p[i] <= mid)
		{
			sum += p[i];
			i--;
		}
		if (sum == 0)
			return 1e5;
		count++;
		if (i != -1)
			slash[i] = true;
	}
	return count;
}

void print(ll avg, int k)
{
	int sz = p.size();
	for (int i = 0; i < sz; i++)
	{
		if (i)
			cout << ' ' << p[i];
		else
			cout << p[i];
		if (slash[i])
			cout << " /";
	}
	cout << endl;
}

int main()
{
	int N, m, k;
	cin >> N;
	while (N--)
	{
		cin >> m >> k;
		ll sum = 0, tmp, lo = 1e7;
		for (int i = 0; i < m; i++)
		{
			cin >> tmp;
			p.push_back(tmp);
			sum += tmp;
			lo = min(lo, tmp);
		}
		ll low = lo, mid, high = sum;
		while (low < high)
		{
			mid = (low + high) / 2;
			if (bs(mid) > k)
				low = mid + 1;
			else
				high = mid;
		}
		int cnt = bs(high), idx = 0;
		while (idx < m - 1 && cnt < k)
		{
			if (!slash[idx])
				slash[idx] = true, cnt++;
			idx++;
		}
		print(high, k);
		p.clear();
	}
}
