#include <iostream>
#include <set>
using namespace std;

int main()
{
	int N, cs = 1;
	while (cin >> N)
	{
		int b[N];
		for (int i = 0; i < N; i++)
			cin >> b[i];
		set < long int >sum;
		bool sequence = true;
		for (int i = 0; i < N; i++)
		{
			for (int j = i; j < N; j++)
			{
				if (b[i] < 1 || b[j] < 1 || (i != j && b[i] >= b[j]))
				{
					sequence = false;
					break;
				}
				int tmp = sum.size();
				sum.insert(b[i] + b[j]);
				if (tmp == sum.size())
				{
					sequence = false;
					break;
				}
			}
			if (!sequence)
				break;
		}
		if (sequence)
			cout << "Case #" << cs++ << ": It is a B2-Sequence." << endl << endl;
		else
			cout << "Case #" << cs++ << ": It is not a B2-Sequence." << endl << endl;
	}
}
