#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

#define maxN 5000005

bitset <maxN> isPrime;
vector <int> prime;
int counter[maxN], sz;

void sieve()
{
    isPrime.set();
    isPrime[0] = isPrime[1] = false;
    for (int i=4; i<maxN; i+=2)
        isPrime[i]=false;
    for (int i=3; i*i<maxN; i+=2)
        if (isPrime[i])
            for (int j=i*i; j<maxN; j+=2*i)
                isPrime[j]=false;
    prime.push_back(2);
    for (int i=3; i<12000; i+=2)
        if (isPrime[i])
            prime.push_back(i);
}

bool primeFactor(int n)
{
    int sum=0;
    for (int i=0; i<sz && prime[i]*prime[i]<=n; i++)
    {
        if (n%prime[i]==0)
        {
            while (n%prime[i]==0)
            {
                n/=prime[i];
            }
            sum+=prime[i];
        }
    }
    if (n!=1)
        sum+=n;
    return isPrime[sum];
}

void preCalc()
{
    for (int i=2; i<maxN; i++)
    {
        if (isPrime[i] || primeFactor(i))
            counter[i]++;
        counter[i]+=counter[i-1];
    }
}

int main()
{
    sieve();
    sz=prime.size();
    preCalc();
    int a, b;
    while (cin >> a && a)
    {
        cin >> b;
        if (a)
            a--;
        cout << counter[b]-counter[a] << endl;
    }
}
