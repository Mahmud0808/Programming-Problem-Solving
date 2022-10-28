#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int n, k, solution, num[26];
bool visited[26], taken[10];
char letter[26];
string word[10];

bool solved()
{
    for (int i=0; i<n; i++)
        if (num[word[i][0]-'A']==0)
            return false;
    int total=0;
    for (int i=0; i<n-1; i++)
    {
        int sz=word[i].size(), sum=0;
        for (int j=0; j<sz; j++)
        {
            sum=(sum*10)+(num[word[i][j]-'A']);
        }
        total+=sum;
    }
    int sum=0, sz=word[n-1].size();
    for (int i=0; i<sz; i++)
    {
        sum=(sum*10)+(num[word[n-1][i]-'A']);
    }
    if (total==sum)
        return true;
    return false;
}

void solve(int idx)
{
    if (idx>=k)
    {
        if (solved())
            solution++;
        return;
    }
    else
    {
        for (int i=0; i<10; i++)
        {
            if (!taken[i])
            {
                taken[i]=true;
                num[letter[idx]-'A']=i;
                solve(idx+1);
                taken[i]=false;
            }
        }
    }
}

int main()
{
    while (cin >> n)
    {
        k=0;
        for (int i=0; i<n; i++)
        {
            cin >> word[i];
            for (int j=0; j<word[i].size(); j++)
            {
                if (!visited[word[i][j]-'A'])
                {
                    visited[word[i][j]-'A']=true;
                    letter[k++]=word[i][j];
                }
            }
        }
        solution=0;
        solve(0);
        cout << solution << endl;
        memset(visited, false, sizeof(visited));
    }
}
