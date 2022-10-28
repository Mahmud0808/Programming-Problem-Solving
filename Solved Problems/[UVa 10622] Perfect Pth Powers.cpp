#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll power(ll N)
{
    ll tmp=abs(N), sq=sqrt(tmp)+1, pwr, n, max=1;
    for (int i=-sq; i<=sq; i++)
    {
        if (i==-1 || i==0 || i==1)
            continue;
        n=1, pwr=i;
        while (pwr<tmp && pwr>-tmp)
        {
            pwr*=i;
            n++;
        }
        if (pwr==N && n>max)
            max=n;
    }
    return max;
}

int main()
{
    ll x;
    while (cin >> x && x)
    {
        cout << power(x) << endl;
    }
}
