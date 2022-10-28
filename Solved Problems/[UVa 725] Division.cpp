#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	int N, newline = false;
	while (cin >> N && N)
	{
		if (newline)
			cout << endl;
		bool no_solution = true;
		for (int i = 1234; i <= 99999; i++)
		{
			if (i * N > 99999)
				break;
			bool solution = true;
			int freq[10] = { 0 };
			string num;
			if (i < 10000)
			{
				num += '0';
			}
			num += to_string(i);
			for (int j = 0; j < num.size(); j++)
			{
				freq[(int)num[j] - 48]++;
			}
			num.clear();
			if (i * N < 10000)
			{
				num += '0';
			}
			num += to_string(i * N);
			for (int j = 0; j < num.size(); j++)
			{
				freq[(int)num[j] - 48]++;
			}
			num.clear();
			for (int i = 0; i < 10; i++)
			{
				if (freq[i] != 1)
					solution = false;
			}
			if (solution)
			{
				printf("%05d / %05d = %d\n", i * N, i, N);
				no_solution = false;
			}
		}
		if (no_solution)
		{
			printf("There are no solutions for %d.\n", N);
		}
		newline = true;
	}
}
