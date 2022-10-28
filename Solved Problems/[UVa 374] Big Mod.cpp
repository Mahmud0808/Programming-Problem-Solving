#include <iostream>
using namespace std;

#define ll long long int

ll _pow(ll n, ll m, ll p)
{
    ll res = 1;
    n %= p;
    if (!n)
        return n;
    while (m)
    {
        if (m & 1)
            res = (res * n) % p;
        m >>= 1;
        n = (n * n) % p;
    }
    return res;
}

int main()
{
    ll B, P, M;
    while (cin >> B >> P >> M)
    {
        cout << _pow(B, P, M) << endl;
    }
}
