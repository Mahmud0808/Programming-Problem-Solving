#include <iostream>
#include <algorithm>
using namespace std;

struct player
{
	string name;
	int attack, defend;
} argentina[10];

bool compare(player a, player b)
{
	if (a.attack > b.attack)
		return true;
	else if (a.attack == b.attack && a.defend < b.defend)
		return true;
	else if (a.attack == b.attack && a.defend == b.defend && a.name < b.name)
		return true;
	else
		return false;
}

bool name(player a, player b)
{
	if (a.name < b.name)
		return true;
	else
		return false;
}

int main()
{
	int n, cs = 1;
	cin >> n;
	while (n--)
	{
		for (int i = 0; i < 10; i++)
		{
			cin >> argentina[i].name >> argentina[i].attack >> argentina[i].defend;
		}
		sort(argentina, argentina + 10, compare);
		sort(argentina, argentina + 5, name);
		sort(argentina + 5, argentina + 10, name);
		cout << "Case " << cs++ << ":" << endl;
		for (int i = 0; i < 5; i++)
		{
			if (i == 0)
				cout << '(';
			else
				cout << ", ";
			cout << argentina[i].name;
			if (i == 4)
				cout << ')' << endl;
		}
		for (int i = 5; i < 10; i++)
		{
			if (i == 5)
				cout << '(';
			else
				cout << ", ";
			cout << argentina[i].name;
			if (i == 9)
				cout << ')' << endl;
		}
	}
}
