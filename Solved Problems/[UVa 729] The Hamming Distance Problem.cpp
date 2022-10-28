#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int T, N, H;
	string str;
	cin >> T;
	bool endline = false;
	while (T--)
	{
		cin >> N >> H;
		for (int i = 1; i <= H; i++)
			str += '1';
		for (int i = 1; i <= N - H; i++)
			str += '0';
		sort(str.begin(), str.end());
		if (endline)
			cout << endl;
		cout << str << endl;
		while (next_permutation(str.begin(), str.end()))
		{
			cout << str << endl;
		}
		endline = true;
		str.clear();
	}
}
