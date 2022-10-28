#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	string name[99999], soundex[99999];
	int k=0, idx;
	while (cin >> name[k])
	{
		soundex[k]+=name[k][0];
		for (int i=1; i<name[k].size(); i++)
		{
			int x=i;
			if (soundex[k].size()==1)
			{
				if (name[k][i]=='B' || name[k][i]=='P' || name[k][i]=='F' || name[k][i]=='V')
				{
					if ((soundex[k][soundex[k].size()-1]!='B' && soundex[k][soundex[k].size()-1]!='P' && soundex[k][soundex[k].size()-1]!='F' && soundex[k][soundex[k].size()-1]!='V') || (name[k][x-1]=='A' || name[k][x-1]=='E' || name[k][x-1]=='I' || name[k][x-1]=='O' || name[k][x-1]=='U' || name[k][x-1]=='W' || name[k][x-1]=='H' || name[k][x-1]=='Y'))
						soundex[k]+='1';
				}
				else if (name[k][i]=='C' || name[k][i]=='S' || name[k][i]=='K' || name[k][i]=='G' || name[k][i]=='J' || name[k][i]=='Q' || name[k][i]=='X' || name[k][i]=='Z')
				{
					if ((soundex[k][soundex[k].size()-1]!='C' && soundex[k][soundex[k].size()-1]!='S' && soundex[k][soundex[k].size()-1]!='K' && soundex[k][soundex[k].size()-1]!='G' && soundex[k][soundex[k].size()-1]!='J' && soundex[k][soundex[k].size()-1]!='Q' && soundex[k][soundex[k].size()-1]!='X' && soundex[k][soundex[k].size()-1]!='Z') || (name[k][x-1]=='A' || name[k][x-1]=='E' || name[k][x-1]=='I' || name[k][x-1]=='O' || name[k][x-1]=='U' || name[k][x-1]=='W' || name[k][x-1]=='H' || name[k][x-1]=='Y'))
						soundex[k]+='2';
				}
				else if (name[k][i]=='D' || name[k][i]=='T')
				{
					if ((soundex[k][soundex[k].size()-1]!='D' && soundex[k][soundex[k].size()-1]!='T') || (name[k][x-1]=='A' || name[k][x-1]=='E' || name[k][x-1]=='I' || name[k][x-1]=='O' || name[k][x-1]=='U' || name[k][x-1]=='W' || name[k][x-1]=='H' || name[k][x-1]=='Y'))
						soundex[k]+='3';
				}
				else if (name[k][i]=='L')
				{
					if ((soundex[k][soundex[k].size()-1]!='L') || (name[k][x-1]=='A' || name[k][x-1]=='E' || name[k][x-1]=='I' || name[k][x-1]=='O' || name[k][x-1]=='U' || name[k][x-1]=='W' || name[k][x-1]=='H' || name[k][x-1]=='Y'))
						soundex[k]+='4';
				}
				else if (name[k][i]=='M' || name[k][i]=='N')
				{
					if ((soundex[k][soundex[k].size()-1]!='M' && soundex[k][soundex[k].size()-1]!='N') || (name[k][x-1]=='A' || name[k][x-1]=='E' || name[k][x-1]=='I' || name[k][x-1]=='O' || name[k][x-1]=='U' || name[k][x-1]=='W' || name[k][x-1]=='H' || name[k][x-1]=='Y'))
						soundex[k]+='5';
				}
				else if (name[k][i]=='R')
				{
					if ((soundex[k][soundex[k].size()-1]!='R') || (name[k][x-1]=='A' || name[k][x-1]=='E' || name[k][x-1]=='I' || name[k][x-1]=='O' || name[k][x-1]=='U' || name[k][x-1]=='W' || name[k][x-1]=='H' || name[k][x-1]=='Y'))
						soundex[k]+='6';
				}
			}
			else
			{
				if (name[k][i]=='B' || name[k][i]=='P' || name[k][i]=='F' || name[k][i]=='V')
				{
					if ((soundex[k][soundex[k].size()-1]!='1') || (name[k][x-1]=='A' || name[k][x-1]=='E' || name[k][x-1]=='I' || name[k][x-1]=='O' || name[k][x-1]=='U' || name[k][x-1]=='W' || name[k][x-1]=='H' || name[k][x-1]=='Y'))
						soundex[k]+='1';
				}
				else if (name[k][i]=='C' || name[k][i]=='S' || name[k][i]=='K' || name[k][i]=='G' || name[k][i]=='J' || name[k][i]=='Q' || name[k][i]=='X' || name[k][i]=='Z')
				{
					if ((soundex[k][soundex[k].size()-1]!='2') || (name[k][x-1]=='A' || name[k][x-1]=='E' || name[k][x-1]=='I' || name[k][x-1]=='O' || name[k][x-1]=='U' || name[k][x-1]=='W' || name[k][x-1]=='H' || name[k][x-1]=='Y'))
						soundex[k]+='2';
				}
				else if (name[k][i]=='D' || name[k][i]=='T')
				{
					if ((soundex[k][soundex[k].size()-1]!='3') || (name[k][x-1]=='A' || name[k][x-1]=='E' || name[k][x-1]=='I' || name[k][x-1]=='O' || name[k][x-1]=='U' || name[k][x-1]=='W' || name[k][x-1]=='H' || name[k][x-1]=='Y'))
						soundex[k]+='3';
				}
				else if (name[k][i]=='L')
				{
					if ((soundex[k][soundex[k].size()-1]!='4') || (name[k][x-1]=='A' || name[k][x-1]=='E' || name[k][x-1]=='I' || name[k][x-1]=='O' || name[k][x-1]=='U' || name[k][x-1]=='W' || name[k][x-1]=='H' || name[k][x-1]=='Y'))
						soundex[k]+='4';
				}
				else if (name[k][i]=='M' || name[k][i]=='N')
				{
					if ((soundex[k][soundex[k].size()-1]!='5') || (name[k][x-1]=='A' || name[k][x-1]=='E' || name[k][x-1]=='I' || name[k][x-1]=='O' || name[k][x-1]=='U' || name[k][x-1]=='W' || name[k][x-1]=='H' || name[k][x-1]=='Y'))
						soundex[k]+='5';
				}
				else if (name[k][i]=='R')
				{
					if ((soundex[k][soundex[k].size()-1]!='6') || (name[k][x-1]=='A' || name[k][x-1]=='E' || name[k][x-1]=='I' || name[k][x-1]=='O' || name[k][x-1]=='U' || name[k][x-1]=='W' || name[k][x-1]=='H' || name[k][x-1]=='Y'))
						soundex[k]+='6';
				}
			}
		}
		if (soundex[k].size()>4)
		{
			soundex[k].erase(soundex[k].begin()+4, soundex[k].end());
		}
		else
		{
			for (int j=soundex[k].size(); j<4; j++)
				soundex[k]+='0';
		}
		k++;
	}
	for (int i=1; i<=10; i++)
	{
		if (i!=10)
			cout << ' ';
		else
			cout << "NAME";
	}
	for (int i=14; i<=35; i++)
	{
		if (i!=35)
			cout << ' ';
		else
			cout << "SOUNDEX CODE" << endl;
	}
	for (int i=0; i<k; i++)
	{
		for (int space=1; space<=10; space++)
		{
			if (space!=10)
				cout << ' ';
			else
				cout << name[i];
		}
		for (int space=10+name[i].size(); space<=35; space++)
		{
			if (space!=35)
				cout << ' ';
			else
				cout << soundex[i];
		}
		cout << endl;
	}
	for (int i=1; i<=20; i++)
	{
		if (i!=20)
			cout << ' ';
		else
			cout << "END OF OUTPUT" << endl;
	}
}