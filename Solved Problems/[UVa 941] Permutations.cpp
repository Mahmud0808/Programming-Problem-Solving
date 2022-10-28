#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long int

ll factorial[20];

void factorialCalc()
{
    factorial[0] = factorial[1] = 1;
    for (int i = 2; i < 20; i++)
        factorial[i] = factorial[i-1]*i;
}

int main()
{
    factorialCalc();
    int t;
    ll N;
    string S;
    cin >> t;
    while (t--)
    {
        cin >> S >> N;
        string res;
        sort(S.begin(), S.end());
        while (!S.empty())
        {
            ll tmp = factorial[S.size()-1], idx = N/tmp;
            res += S[idx];
            S.erase(S.begin()+idx);
            N %= tmp;
        }
        cout << res << endl;
        res.clear();
    }
}
