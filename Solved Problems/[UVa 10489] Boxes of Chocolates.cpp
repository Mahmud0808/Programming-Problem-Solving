#include <iostream>
using namespace std;

int main()
{
    int T, N, B, K, a, total, ans;
    cin >> T;
    while (T--)
    {
        cin >> N >> B;
        ans = 0;
        while (B--)
        {
            cin >> K;
            total = 1;
            while (K--)
            {
                cin >> a;
                total *= a;
                total %= N;
            }
            ans += total;
            ans %= N;
        }
        cout << ans << endl;
    }
}
