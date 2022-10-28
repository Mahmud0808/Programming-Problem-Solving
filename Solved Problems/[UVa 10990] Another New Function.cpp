#include <iostream>
using namespace std;

int phi[2000005], res[2000005];

int EulerPhi(int n)
{
	int count = n, p = 2, temp = n;
	while (p * p <= temp)
	{
		if (temp % p == 0)
		{
			while (temp % p == 0)
			{
				temp /= p;
			}
			count *= (1.0 - (1.0 / p));
		}
		p++;
	}
	if (temp != 1)
		count *= (1.0 - (1.0 / temp));
	return count;
}

int SODF(int n)
{
	int tmp = n, cnt = 0;
	while (tmp!=1)
	{
		tmp = phi[tmp];
		cnt++;
	}
	return cnt;
}

void preCalc()
{
	int i = 1;
	while (i <= 2000000)
	{
		phi[i] = EulerPhi(i);
		i++;
	}
	i = 1;
	while (i <= 2000000)
	{
		res[i] = res[i - 1] + SODF(i);
		i++;
	}
}

int main()
{
	preCalc();
	int N, m, n;
	cin >> N;
	while (N--)
	{
		cin >> m >> n;
		cout << (res[n] - res[m - 1]) << endl;
	}
}
