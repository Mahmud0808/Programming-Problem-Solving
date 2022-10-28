#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
	long long int taka, cs = 1;
	int kuti, lakh, hajar, shata, rest, shata2, hajar2, lakh2, kuti2;
	while (cin >> taka)
	{
		cout << setw(4) << cs++ << ".";
		if (taka == 0)
		{
			cout << ' ' << taka << endl;
			continue;
		}
		rest = taka % 100;
		taka /= 100;
		shata = taka % 10;
		taka /= 10;
		hajar = taka % 100;
		taka /= 100;
		lakh = taka % 100;
		taka /= 100;
		kuti = taka % 100;
		taka /= 100;
		shata2 = taka % 10;
		taka /= 10;
		hajar2 = taka % 100;
		taka /= 100;
		lakh2 = taka % 100;
		taka /= 100;
		kuti2 = taka % 100;
		taka /= 100;
		if (kuti2)
			cout << ' ' << kuti2 << " kuti";
		if (lakh2)
			cout << ' ' << lakh2 << " lakh";
		if (hajar2)
			cout << ' ' << hajar2 << " hajar";
		if (shata2)
			cout << ' ' << shata2 << " shata";
		if (kuti)
			cout << ' ' << kuti << " kuti";
		else if (kuti2 || lakh2 || hajar2 || shata2)
			cout << " kuti";
		if (lakh)
			cout << ' ' << lakh << " lakh";
		if (hajar)
			cout << ' ' << hajar << " hajar";
		if (shata)
			cout << ' ' << shata << " shata";
		if (rest)
			cout << ' ' << rest;
		cout << endl;
	}
}
