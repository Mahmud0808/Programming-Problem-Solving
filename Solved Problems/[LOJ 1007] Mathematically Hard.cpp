#include <iostream>
using namespace std;

#define ll long long unsigned int
#define maxN 5000005

ll cache[maxN];

void preCalc()
{
    int i = 2;
	while (i < maxN)
    {
        if (cache[i] == 0)
        {
            cache[i] = i - 1;
            int j = 2 * i;
			while (j < maxN)
            {
                if (cache[j] == 0)
                    cache[j] = j;
                cache[j] -= (cache[j] / i);
				j += i;
            }
        }
		i++;
    }
    i = 2;
	while (i < maxN)
    {
        cache[i] = cache[i - 1] + cache[i] * cache[i];
		i++;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    preCalc();
    int T, a, b, cs = 1;
    cin >> T;
    while (T--)
    {
        cin >> a >> b;
        printf("Case %d: %llu\n", cs++, (cache[b] - cache[a - 1]));
    }
}
