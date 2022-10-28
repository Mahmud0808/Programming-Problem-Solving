#include <iostream>
#include <cmath>
#include <map>
using namespace std;

#define ll long long int

ll squareSum(ll N)
{
	ll result = 0;
	while (N)
	{
		result += pow((N % 10), 2);
		N /= 10;
	}
	return result;
}

bool isHappy(ll N)
{
	map < ll, bool > used;
	bool happy = false;
	while (!used[N])
	{
		used[N] = true;
		N = squareSum(N);
		if (N == 1)
		{
			happy = true;
			break;
		}
	}
	return happy;
}

int main()
{
	int t, cs = 1;
	ll n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (isHappy(n))
			cout << "Case #" << cs++ << ": " << n << " is a Happy number." << endl;
		else
			cout << "Case #" << cs++ << ": " << n << " is an Unhappy number." << endl;
	}
}
