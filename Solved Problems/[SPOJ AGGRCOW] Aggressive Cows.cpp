#include <iostream>
#include <algorithm>
using namespace std;

long long int X[100005], N, C;

bool stalls(long long int mid)
{
	long long int cows=1, temp=X[0];
	for (int i=1; i<N; i++)
	{
		if (X[i]-temp>=mid)
		{
			cows++;
			temp=X[i];
		}
		if (cows==C)
			return true;
	}
	return false;
}

int main()
{
	long long int t;
	cin >> t;
	while (t--)
	{
		cin >> N >> C;
		for (int i=0; i<N; i++)
			cin >> X[i];
		sort(X, X+N);
		long long int low=1, mid, high=1000000000;
		for (int i=0; i<500; i++)
		{
			mid=(low+high)/2;
			if (stalls(mid))
				low=mid;
			else
				high=mid;
		}
		cout << low << endl;
	}
}
