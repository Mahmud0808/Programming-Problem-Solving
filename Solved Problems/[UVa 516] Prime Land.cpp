#include <iostream>
#include <bitset>
#include <vector>
#include <sstream>
#include <cmath>
#include <map>
using namespace std;

bitset < 32770 > prm;
vector < int >prime;

void sieve()
{
	prm.set();
	for (int i = 2; i <= 32770; i++)
	{
		if (prm[i])
		{
			for (int j = i * i; j <= 32770; j += i)
			{
				prm[j] = false;
			}
			prime.push_back(i);
		}
	}
}

int main()
{
	string line;
	sieve();
	map < int, int >res;
	while (getline(cin, line) && line != "0")
	{
		stringstream ln(line);
		int p, e, x = 1;
		while (ln >> p >> e)
		{
			x *= pow(p, e);
		}
		x--;
		int mx = sqrt(x);
		for (int i = 0; prime[i] <= mx; i++)
		{
			if (x % prime[i] == 0)
			{
				while (x % prime[i] == 0)
				{
					x /= prime[i];
					res[prime[i]]++;
				}
			}
		}
		if (x != 1)
		{
			res[x]++;
		}
		bool space = false;
		for (auto it = res.rbegin(); it != res.rend(); it++)
		{
			if (space)
				cout << ' ';
			cout << it->first << ' ' << it->second;
			if (!space)
				space = true;
		}
		cout << endl;
		res.clear();
	}
}
