#include <iostream>
#include <sstream>
using namespace std;

string note[12] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
bool major[12] = { true, false, true, false, true, true, false, true, false, true, false, true };

int index(string s)
{
	for (int i=0; i<12; i++)
		if (note[i]==s)
			return i;
	return -1;
}

int main()
{
	string line, key;
	while (getline(cin, line) && line != "END")
	{
		bool found[12] = { false };
		stringstream keys(line);
		while (keys >> key)
			found[index(key)] = true;
		bool space = false;
		for (int i=0; i<12; i++)
		{
			bool composed = true;
			for (int j=0; j<12; j++)
			{
				if (found[(i+j)%12])
				{
					if (!major[j])
					{
						composed = false;
						break;
					}
				}
			}
			if (composed)
			{
				if (space)
					cout << ' ';
				else
					space = true;
				cout << note[i];
			}
		}
		cout << endl;
	}
}
