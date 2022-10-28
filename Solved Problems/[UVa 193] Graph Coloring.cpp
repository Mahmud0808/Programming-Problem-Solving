#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, k, _max, node[105][105], color[105];
vector <int> res;

bool isValid(int x)
{
    for (int i=1; i<=n; i++)
    {
        if (node[x][i])
        {
            if (color[x] && color[i])
                return false;
        }
    }
    return true;
}

void dfs(int idx)
{
    if (idx>n)
    {
        int count=0;
        for (int i=1; i<=n; i++)
        {
            if (color[i])
                count++;
        }
        if (count>_max)
        {
            _max=count;
            res.clear();
            for (int i=1; i<=n; i++)
            {
                if (color[i])
                    res.push_back(i);
            }
        }
    }
    else
    {
        for (int i=0; i<=1; i++)
        {
            color[idx]=i;
            if (isValid(idx))
                dfs(idx+1);
            color[idx]=0;
        }
    }
}

int main()
{
    int t, n1, n2;
    cin >> t;
    while (t--)
    {
        memset(node, 0, sizeof(node));
        cin >> n >> k;
        for (int i=0; i<k; i++)
        {
            cin >> n1 >> n2;
            node[n1][n2]=1;
            node[n2][n1]=1;
        }
        _max=0;
        dfs(1);
        cout << _max << endl;
        for (int i=0; i<res.size(); i++)
        {
            if (i)
                cout << ' ';
            cout << res[i];
        }
        cout << endl;
    }
}
