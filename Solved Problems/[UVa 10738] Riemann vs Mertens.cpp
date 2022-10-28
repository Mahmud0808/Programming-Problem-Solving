#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#define maxN 1000005

int mu[maxN], M[maxN], factor[maxN];
bool squareFree[maxN];

void mobius()
{
	memset(squareFree, true, sizeof(squareFree));
	factor[1] = 1;
	for (int i = 2; i < maxN; i++)
	{
		if (factor[i] == 0)
		{
			factor[i]++;
			for (int j = i + i; j < maxN; j += i)
			{
				factor[j]++;
				if (j % (i * i) == 0)
				{
					squareFree[j] = false;
				}
			}
		}
	}
}

void preCalc()
{
	mu[1] = M[1] = 1;
	int sum = 1;
	for (int i = 2; i < maxN; i++)
	{
		if (!squareFree[i])
		{
			mu[i] = 0;
		}
		else
		{
			if (factor[i] % 2)
			{
				mu[i] = -1;
			}
			else
			{
				mu[i] = 1;
			}
		}
		sum += mu[i];
		M[i] = sum;
	}
}

int main()
{
	mobius();
	preCalc();
	int N;
	while (cin >> N && N)
	{
		cout << setw(8) << N << setw(8) << mu[N] << setw(8) << M[N] << endl;
	}
}
