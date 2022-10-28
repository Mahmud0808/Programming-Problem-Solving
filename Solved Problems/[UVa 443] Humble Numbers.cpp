#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define ll long long int

int prime[4] = { 2, 3, 5, 7 };

void preCalc(vector < ll > &humble)
{
	set < ll > temp;
	temp.insert(1);
	set < ll >::iterator idx = temp.begin();
	while (true)
	{
		for (int i = 0; i < 4; i++)
			temp.insert(*idx * prime[i]);
		idx++;
		if (temp.size() >= 8000)
			break;
	}
  for (auto it:temp)
		humble.push_back(it);
}

int main()
{
	vector < ll > humble;
	preCalc(humble);
	int n;
	while (cin >> n && n)
	{
		string s;
		if (n % 10 == 1 && n % 100 != 11)
			s = "st";
		else if (n % 10 == 2 && n % 100 != 12)
			s = "nd";
		else if (n % 10 == 3 && n % 100 != 13)
			s = "rd";
		else
			s = "th";
		cout << "The " << n << s << " humble number is " << humble[n - 1] << '.' << endl;
	}
}
