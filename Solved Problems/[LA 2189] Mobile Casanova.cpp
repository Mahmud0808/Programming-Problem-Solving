#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	int N, cs = 1;
	while (cin >> N && N)
	{
		string num[N], number;
		long long int numb[N];
		for (int i = 0; i < N; i++)
		{
			cin >> number;
			stringstream nume(number);
			num[i] = number;
			nume >> numb[i];
		}
		int last = 0, init;
		cout << "Case " << cs++ << ":" << endl;
		for (int i = 0; i < N; i++)
		{
			if (i != N && numb[i + 1] - numb[i] == 1)
			{
				cout << num[i] << '-';
				init = i;
				while (numb[i + 1] - numb[i] == 1)
				{
					i++;
					if (i == N - 1)
						break;
				}
				int x;
				for (int j = 0; j < num[init].size(); j++)
				{
					if (num[init][j] != num[i][j])
					{
						x = j;
						break;
					}
				}
				for (int k = x; k < num[i].size(); k++)
				{
					cout << num[i][k];
				}
				cout << endl;
			}
			else
				cout << num[i] << endl;
		}
		cout << endl;
	}
}