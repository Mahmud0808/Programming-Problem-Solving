#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int size[100005];

struct socks
{
	long long int sock1, sock2, diff;
	bool operator<(const socks &x) const
	{
		if (diff > x.diff)
			return true;
		else if (diff == x.diff && sock1 > x.sock1)
			return true;
		else if (diff == x.diff && sock1 == x.sock1 && sock2 > x.sock2)
			return true;
		else
			return false;
	}
} s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int n, k;
	while (cin >> n >> k && n && k)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> size[i];
		}
		sort(size, size + n);
		priority_queue<socks> sock;
		for (int i = 1; i < n; i++)
		{
			sock.push({i - 1, i, size[i] - size[i - 1]});
		}
		int day = 1;
		while (true)
		{
			socks current = sock.top();
			if (day == k)
			{
				cout << size[current.sock1] << ' ' << size[current.sock2] << endl;
				break;
			}
			sock.pop();
			day++;
			if (current.sock2 + 1 < n)
			{
				sock.push({current.sock1, current.sock2 + 1, size[current.sock2 + 1] - size[current.sock1]});
			}
		}
		while (!sock.empty())
		{
			sock.pop();
		}
	}
}
