#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void primeGen(vector < int >&prime)
{
    vector < bool > isPrime(46348, true);
    for (int i = 2; i <= 46348; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= 46348; j += i)
            {
                isPrime[j] = false;
            }
            prime.push_back(i);
        }
    }
}

int main()
{
    vector < int >prime;
    primeGen(prime);
    long long int N, tmp;
    vector < long long int >res;
    while (cin >> N && N)
    {
        tmp = N;
        if (tmp < 0)
        {
            res.push_back(-1);
            tmp = abs(tmp);
        }
        for (int i = 0; tmp != 1; i++)
        {
            if (tmp % prime[i] == 0)
            {
                while (tmp % prime[i] == 0)
                {
                    res.push_back(prime[i]);
                    tmp /= prime[i];
                }
            }
            if (i >= 4791 && tmp != 1)
            {
                res.push_back(tmp);
                tmp /= tmp;
            }
        }

        cout << N << " = ";
        int sz = res.size();
        for (int i = 0; i < sz; i++)
        {
            if (i != sz - 1)
                cout << res[i] << " x ";
            else
                cout << res[i];
        }
        if (sz == 1 && res[0] == -1)
            cout << " x ";
        cout << endl;
        res.clear();
    }
}
