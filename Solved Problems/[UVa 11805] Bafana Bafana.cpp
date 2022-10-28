#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int T, N, K, P, cs = 1;
	cin >> T;
	while (T--)
	{
		cin >> N >> K >> P;
		int tmpN = N, pass = 0;
		while (pass < P)
		{
			pass++;
			K++;
			if (K > N)
				K = 1;
		}
		cout << "Case " << cs++ << ": " << K << endl;
	}
}
