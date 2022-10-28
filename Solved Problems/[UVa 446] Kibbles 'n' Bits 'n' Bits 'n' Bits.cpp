#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    string num1, operation, num2;
    cin >> n;
    while (n--)
    {
        cin >> num1 >> operation >> num2;
        int res, n1, n2;
        stringstream(num1) >> hex >> n1;
        stringstream(num2) >> hex >> n2;
        string bin1, bin2;
        int tmp1=n1, tmp2=n2;
        while (tmp1)
        {
            bin1+=to_string(tmp1%2);
            tmp1/=2;
        }
        while (bin1.size()<13)
        {
            bin1+='0';
        }
        while (tmp2)
        {
            bin2+=to_string(tmp2%2);
            tmp2/=2;
        }
        while (bin2.size()<13)
        {
            bin2+='0';
        }
        reverse(bin1.begin(), bin1.end());
        reverse(bin2.begin(), bin2.end());
        if (operation=="+")
            res=n1+n2;
        else
            res=n1-n2;
        cout << bin1 << ' ' << operation << ' ' << bin2 << " = " << dec << res << endl;
        bin1.clear();
        bin2.clear();
    }
}
