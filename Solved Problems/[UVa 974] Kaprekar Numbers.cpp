#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool isKaprekar(int n)
{
	long long int sq = pow(n, 2), left, right, power;
	int digit = floor(log10(sq) + 1);
	if (pow(10, digit - 1) == sq)
		return false;
	for (int i = 1; i <= digit; i++)
	{
		power = pow(10, i);
		left = sq / power;
		right = sq % power;
		if (left + right == n)
			return true;
	}
	return false;
}

vector < int >kaprekar;

void preCalc()
{
	for (int i = 2; i <= 40000; i++)
	{
		if (isKaprekar(i))
			kaprekar.push_back(i);
	}
}

int main()
{
	preCalc();
	int N, L, R, cs = 1;
	bool newl = false;
	cin >> N;
	while (N--)
	{
		cin >> L >> R;
		int left = lower_bound(kaprekar.begin(), kaprekar.end(), L) - kaprekar.begin();
		int right = lower_bound(kaprekar.begin(), kaprekar.end(), R) - kaprekar.begin();
		if (kaprekar[right] > R)
			right--;
		if (right == 19)
			right--;
		bool found = right - left + 1 > 0 ? true : false;
		if (newl)
			cout << endl;
		else
			newl = true;
		cout << "case #" << cs++ << endl;
		if (!found)
			cout << "no kaprekar numbers" << endl;
		else
			for (int i = left; i <= right; i++)
				cout << kaprekar[i] << endl;
	}
}
