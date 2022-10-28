#include <bits/stdc++.h>
using namespace std;

struct link
{
	string name;
	int dis;
} p[21];

bool cmp(link a, link b)
{
	if (a.dis == b.dis)
	{
		if (a.name < b.name)
			return true;
		else
			return false;
	}
	else
	{
		if (a.dis > b.dis)
			return true;
		else
			return false;
	}
}

int main()
{
	string str;
	vector < string > permute;
	while (cin >> str)
	{
		int n = 0;
		string str2 = str;
		while (prev_permutation(str2.begin(), str2.end()))
		{
			permute.push_back(str2);
			n++;
			if (n == 10)
				break;
		}
		reverse(permute.begin(), permute.end());
		permute.push_back(str);
		n = 0;
		str2 = str;
		while (next_permutation(str2.begin(), str2.end()))
		{
			permute.push_back(str2);
			n++;
			if (n == 10)
				break;
		}
		int min_distance, distance;
		for (int i = 0; i < permute.size(); i++)
		{
			min_distance = INT_MAX;
			for (int j = 0; j < str.size() - 1; j++)
			{
				distance = abs(permute[i][j] - permute[i][j + 1]);
				if (distance < min_distance)
				{
					min_distance = distance;
				}
			}
			p[i].name = permute[i];
			p[i].dis = min_distance;
		}
		sort(p, p + 21, cmp);
		cout << p[0].name << p[0].dis << endl;
		permute.clear();
	}
}
