#include <iostream>
using namespace std;

long long int fibo[45];

void preCalc()
{
	fibo[0]=1;
	for (int i=0; i<=40; i++)
	{
		fibo[i+1]+=fibo[i];
		fibo[i+2]+=4*fibo[i];
		fibo[i+3]+=2*fibo[i];
	}
}

int main()
{
	preCalc();
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << fibo[n] << endl;
	}
}
