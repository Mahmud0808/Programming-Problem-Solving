#include <iostream>
using namespace std;

#define ll long long int

int main()
{
    string str;
    char Ch;
    ll num, mod=131071;
    while (cin >> Ch)
    {
        if (Ch=='#')
        {
            num=0;
            for (ll i=str.size()-1, j=1; i>=0; i--, j<<=1)
            {
                j %= mod;
                if (str[i]=='1')
                {
                    num+=j;
                    num %= mod;
                }
            }
            if (!num)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            str.clear();
        }
        else if (Ch=='0' || Ch=='1')
        {
            str+=Ch;
        }
    }
}
