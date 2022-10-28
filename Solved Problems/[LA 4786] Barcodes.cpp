#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cctype>
#include <cmath>
using namespace std;

int m;
vector<double> input;

char decode(string code)
{
	if (code == "00001")
		return '0';
	if (code == "10001")
		return '1';
	if (code == "01001")
		return '2';
	if (code == "11000")
		return '3';
	if (code == "00101")
		return '4';
	if (code == "10100")
		return '5';
	if (code == "01100")
		return '6';
	if (code == "00011")
		return '7';
	if (code == "10010")
		return '8';
	if (code == "10000")
		return '9';
	if (code == "00100")
		return '-';
	if (code == "00110")
		return 's';
	return 'x';
}

int weight(char ch)
{
	if (isdigit(ch))
		return ch - '0';
	else
		return 10;
}

string solve()
{
	if ((m + 1) % 6 != 0)
		return "bad code";
	char code[m];
	for (int i = 0; i < m; i++)
	{
		if (input[i] <= input[0] * 1.5)
			code[i] = '0';
		else
			code[i] = '1';
	}
	double low = 300.0, high = 0.0;
	for (int i = 0; i < m; i++)
	{
		if (code[i] == '1')
		{
			low = min(low, input[i]);
			high = max(high, input[i]);
		}
		else
		{
			low = min(low, 2.0 * input[i]);
			high = max(high, 2.0 * input[i]);
		}
	}
	if (low * 1.05 / 0.95 < high)
		return "bad code";
	if (code[1] == '1')
		reverse(code, code + m);
	string line, start1, start2;
	for (int i = 0; i < 5; i++)
		start1 += code[i];
	for (int i = m - 5; i < m; i++)
		start2 += code[i];
	if (decode(start1) == 's' && decode(start2) == 's')
	{
		for (int i = 6; i <= m - 7; i++)
		{
			line += code[i];
		}
	}
	else
		return "bad code";
	string res, tmp;
	for (int i = 0; i < line.size(); i += 6)
	{
		if (i && line[i - 1] == '1')
			return "bad code";
		int j = i;
		tmp.clear();
		while (j < i + 5)
		{
			tmp += line[j];
			j++;
		}
		tmp = decode(tmp);
		if (tmp == "x" || tmp == "s")
			return "bad code";
		res += tmp;
	}
	if (6 * res.size() - 1 != m - 6 * 2)
		return "bad code";
	int n = res.size() - 2;
	int C = res[n] - '0';
	if (C < 0 || C > 10)
		C = 10;
	int K = res[n + 1] - '0';
	if (K < 0 || K > 10)
		K = 10;
	int Cn = 0, Kn = 0;
	for (int i = 1; i <= n; i++)
	{
		Cn += ((n - i) % 10 + 1) * weight(res[i - 1]);
		Cn %= 11;
	}
	if (Cn != C)
		return "bad C";
	for (int i = 1; i <= n + 1; i++)
	{
		Kn += ((n - i + 1) % 9 + 1) * weight(res[i - 1]);
		Kn %= 11;
	}
	if (Kn != K)
		return "bad K";
	res = res.substr(0, n);
	return res;
}

int main()
{
	int cs = 1;
	while (cin >> m && m)
	{
		double in;
		bool bc = false;
		for (int i = 0; i < m; i++)
		{
			cin >> in;
			if (in < 1 || in > 221)
				bc = true;
			input.push_back(in);
		}
		if (m < 29 || (m - 24) % 6 != 5)
			bc = true;
		if (bc)
		{
			cout << "Case " << cs++ << ": bad code" << endl;
			input.clear();
			continue;
		}
		string result = solve();
		cout << "Case " << cs++ << ": " << result << endl;
		input.clear();
	}
}
