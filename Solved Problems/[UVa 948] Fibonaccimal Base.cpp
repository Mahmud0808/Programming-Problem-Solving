#include <iostream>
using namespace std;

long long int fibo[41];

void preCalc()
{
	fibo[0]=0, fibo[1]=1;
	for (int i=2; i<=40; i++)
		fibo[i]=fibo[i-1]+fibo[i-2];
}

int main()
{
	preCalc();
	int T, N;
	cin >> T;
	while (T--)
	{
		cin >> N;
		cout << N << " = ";
		bool first=true;
		for (int i=40; i>=2; i--)
		{
			if (N>=fibo[i])
			{
				N-=fibo[i];
				cout << 1;
				first=false;
			}
			else
			{
				if (!first)
					cout << 0;
			}
		}
		cout << " (fib)" << endl;
	}
}
