#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

int main()
{
	int k;
	bool endline = false;
	while (cin >> k && k)
	{
		int set[k];
		deque < int >res;
		for (int i = 0; i < k; i++)
			cin >> set[i];
		int mask = 1 << k, parity = 0;
		for (int i = 1; i < mask; i++)
		{
			for (int j = 0; j < k; j++)
			{
				if (i & (1 << j))
				{
					parity++;
				}
			}
			if (parity == 6)
				res.push_back(i);
			parity = 0;
		}
		vector < int >line;
		vector < vector < int >>lex;
		bool space = false;
		for (int i = 1; i < mask; i++)
		{
			space = false;
			if (i == res.front())
			{
				for (int j = 0; j < k; j++)
				{
					if (i & (1 << j))
					{
						line.push_back(set[j]);
					}
				}
				lex.push_back(line);
				res.pop_front();
				line.clear();
			}
		}
		sort(lex.begin(), lex.end());
		int s = lex.size();
		if (endline)
			cout << endl;
		for (int i = 0; i < s; i++)
		{
			int s2 = lex[i].size();
			for (int j = 0; j < s2; j++)
			{
				if (j)
					cout << ' ';
				cout << lex[i][j];
			}
			cout << endl;
		}
		lex.clear();
		res.clear();
		endline = true;
	}
}
