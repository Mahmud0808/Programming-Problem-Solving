#include <iostream>
using namespace std;

int main()
{
	int T, N, tmp, cs = 1;
	cin >> T;
	while (T--)
	{
		cin >> N;
		bool Qinghuai = true;
		while (N--)
		{
			cin >> tmp;
			if (tmp % 3 != 0)
				Qinghuai = false;
		}
		cout << "Case #" << cs++ << ": ";
		(Qinghuai) ? cout << "Yes" << endl : cout << "No" << endl;
	}
}
