#include <iostream>
#include <vector>
#include <bitset>
#include <map>
using namespace std;

#define maxN 46350
#define ll long long int

vector < ll > prime;
bitset < maxN > isPrime;
map < int, int >_m;

void sieve()
{
	isPrime.set();
	isPrime[0] = isPrime[1] = false;
	for (ll i = 4; i < maxN; i += 2)
		isPrime[i] = false;
	for (ll i = 3; i * i < maxN; i += 2)
		if (isPrime[i])
			for (ll j = i * i; j < maxN; j += 2 * i)
				isPrime[j] = false;
	prime.push_back(2);
	for (ll i = 3; i < maxN; i += 2)
		if (isPrime[i])
			prime.push_back(i);
}

ll get_powers(ll n, ll p)
{
	ll power = 0, num = p;
	while (num <= n)
	{
		power += n / num;
		num *= p;
	}
	return power;
}

void primeFactor(ll m)
{
	int sz = prime.size();
	for (int i = 0; i < sz && prime[i] <= m; i++)
	{
		if (m % prime[i] == 0)
		{
			while (m % prime[i] == 0)
			{
				m /= prime[i];
				_m[prime[i]]++;
			}
		}
	}
	if (m != 1)
		_m[m]++;
}

bool check(ll n)
{
	int tmp;
  for (auto it:_m)
	{
		tmp = get_powers(n, it.first);
		if (it.second > tmp)
			return false;
	}
	return true;
}

int main()
{
	sieve();
	ll n, m;
	while (cin >> n >> m)
	{
		if (m == 0 || m == 1)
		{
			cout << m << " divides " << n << '!' << endl;
			continue;
		}
		else if (n == 0)
		{
			cout << m << " does not divide " << n << '!' << endl;
			continue;
		}
		primeFactor(m);
		if (check(n))
			cout << m << " divides " << n << '!' << endl;
		else
			cout << m << " does not divide " << n << '!' << endl;
		_m.clear();
	}
}
