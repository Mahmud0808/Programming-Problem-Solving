#include <iostream>
using namespace std;

int convert(char c)
{
	if (c == 'r')
		return 0;
	else if (c == 'o')
		return 1;
	else if (c == 'y')
		return 2;
	else if (c == 'g')
		return 3;
	else if (c == 'b')
		return 4;
	else
		return -1;
}

int main()
{
	string str[1000];
	int n = 0, arr[1000][5] = { 0 };
	while (getline(cin, str[n]) && str[n][0] != '#')
	{
		if (str[n][0] != 'e')
		{
			for (int i = 0; i < 5; i++)
			{
				arr[n][convert(str[n][i * 4])] = str[n][i * 4 + 2] - 65;
			}
			n++;
		}
		else
		{
			int max = 0, res = 1;
			for (int i = 0; i < n; i++)
			{
				int match = 0;
				for (int j = 0; j < n; j++)
				{
					if (i != j)
					{
						for (int k = 0; k < 5; k++)
						{
							if (arr[i][k] == arr[j][k])
								match++;
						}
					}
				}
				if (match > max)
				{
					max = match;
					res = i + 1;
				}
			}
			cout << res << endl;
			n = 0;
			arr[1000][5] =
			{
			0};
		}
	}
}
