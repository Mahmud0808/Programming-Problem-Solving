#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct point
{
	int left, right;
};

vector < point > line, res;

bool compare(point a, point b)
{
	if (a.left < b.left)
		return true;
	else if (a.left == b.left && a.right > b.right)
		return true;
	else
		return false;
}

int main()
{
	int N, M, L, R;
	cin >> N;
	bool newl = false;
	while (N--)
	{
		cin >> M;
		point tmp;
		while (cin >> L >> R && (L || R))
		{
			if ((L <= M && R >= M) || (L <= 0 && R >= 0) || (L >= 0 && R <= M))
			{
				tmp.left = L;
				tmp.right = R;
				line.push_back(tmp);
			}
		}
		sort(line.begin(), line.end(), compare);
		point best;
		int sz = line.size(), left = 0, right = 0, reach = 0, brk, idx = 0;
		while (reach < M)
		{
			brk = -1;
			while (line[idx].left <= left)
			{
				if (line[idx].right > right)
				{
					best = line[idx];
					right = line[idx].right;
					brk = idx;
				}
				idx++;
				if (idx == sz)
					break;
			}
			if (brk == -1)
				break;
			res.push_back(best);
			left = right;
			reach = right;
		}
		sz = res.size();
		if (newl)
			cout << endl;
		newl = true;
		if (reach < M)
		{
			cout << 0 << endl;
			line.clear(), res.clear();
			continue;
		}
		cout << sz << endl;
		for (int i = 0; i < sz; i++)
		{
			cout << res[i].left << ' ' << res[i].right << endl;
		}
		line.clear(), res.clear();
	}
}
