#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int R, N, ans, cs = 1;
	while (cin >> R >> N && (R && N))
	{
		R -= N;
		ans = ceil((float)R / N);
		if (ans <= 26)
			cout << "Case " << cs++ << ": " << ans << endl;
		else
			cout << "Case " << cs++ << ": impossible" << endl;
	}
}
