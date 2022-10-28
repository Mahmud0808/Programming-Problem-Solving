#include <iostream>
#include <algorithm>
using namespace std;

string fibo[5005];

string sum(string num1, string num2)
{
    int sz1 = num1.size(), sz2 = num2.size();
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    string sum;
    char carry = '0';
    for (int i = 0; i < min(sz1, sz2); i++)
    {
        sum += (char)((((num1[i] - '0') + (num2[i] - '0') + (carry - '0')) % 10) + '0');
        carry = (char)((((num1[i] - '0') + (num2[i] - '0') + (carry - '0')) / 10) + '0');
    }
    if (sz1 > sz2)
    {
        for (int i = sz2; i < sz1; i++)
        {
            sum += (char)((((num1[i] - '0') + (carry - '0')) % 10) + '0');
            carry = (char)((((num1[i] - '0') + (carry - '0')) / 10) + '0');
            if (carry == '0')
                break;
        }
    }
    else if (sz2 > sz1)
    {
        for (int i = sz1; i < sz2; i++)
        {
            sum += (char)((((num2[i] - '0') + (carry - '0')) % 10) + '0');
            carry = (char)((((num2[i] - '0') + (carry - '0')) / 10) + '0');
            if (carry == '0')
                break;
        }
    }
    if (carry != '0')
        sum += carry;
    reverse(sum.begin(), sum.end());
    return sum;
}

void preCalc()
{
    fibo[1] = "1";
    fibo[2] = "2";
    for (int i = 3; i <= 500; i++)
    {
        fibo[i] = sum(fibo[i - 1], fibo[i - 2]);
    }
}

bool compare(string A, string B)
{
    if (A.size()<B.size())
        return false;
    else if (A.size()>B.size())
        return true;
    else
    {
        for(int i = 0; i < A.size(); i++)
        {
            if ((A[i] - '0') < (B[i] - '0'))
            {
                return false;
            }
            else if ((A[i] - '0') > (B[i] - '0'))
            {
                return true;
            }
        }
    }
    return true;
}

int main()
{
    preCalc();
    string a, b;
    while (cin >> a >> b && (a!="0" || b!="0"))
    {
        int idx=1;
        while (!compare(fibo[idx], a))
        {
            idx++;
        }
        if (fibo[idx-1]==a)
            idx--;
        int count=0;
        for (int i=idx; i<=500; i++)
        {
            if (fibo[i]==b)
                count++;
            if (compare(fibo[i], b))
                break;
            else
                count++;
        }
        cout << count << endl;
    }
}
