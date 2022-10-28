#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct agency
{
	string aname;
	int cost;
} a;

bool cmp(agency a, agency b)
{
	if (a.cost < b.cost)
		return true;
	else if (a.cost == b.cost && a.aname < b.aname)
		return true;
	else
		return false;
}

int main()
{
	int T, N, M, L, A, B, cs = 1;
	string name;
	cin >> T;
	while (T--)
	{
		cin >> N >> M >> L;
		vector < agency > res;
		while (L--)
		{
			name.clear();
			char tmpC;
			while (true)
			{
				cin >> tmpC;
				if (tmpC == ':')
					break;
				else
					name += tmpC;
			}
			cin >> A;
			cin.ignore();
			cin >> B;
			int tmp, costB, costA, totalcost = 0, tmpN = N;
			while (tmpN > M)
			{
				tmp = (tmpN / 2);
				costB = totalcost + B;
				if (tmpN - tmp <= M)
					costA = totalcost + A * (tmpN - M);
				else
					costA = totalcost + A * (tmpN - tmp);
				if (tmp < M)
				{
					tmpN -= (tmpN - M);
					totalcost = costA;
				}
				else if (costB < costA)
				{
					tmpN /= 2;
					totalcost = costB;
				}
				else
				{
					tmpN -= (tmpN - tmp);
					totalcost = costA;
				}
			}
			a.aname = name;
			a.cost = totalcost;
			res.push_back(a);
		}
		sort(res.begin(), res.end(), cmp);
		int sz = res.size();
		cout << "Case " << cs++ << endl;
		for (int i = 0; i < sz; i++)
		{
			cout << res[i].aname << ' ' << res[i].cost << endl;
		}
	}
}
