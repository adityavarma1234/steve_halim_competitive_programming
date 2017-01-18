#include<bits/stdc++.h>

using namespace std;
string a, b;

int sum_digits(int a)
{
    if(a==0) return 0;
    int sum=0;
    sum += a%10 + sum_digits(a/10);
    return sum;
}

int sum_helper(int a)
{
    int sum=sum_digits(a);
    while(sum/10)
    {
        sum = sum_digits(sum);
    }
    return sum;
}

int main()
{
    while(getline(cin,a))
    {
        getline(cin,b);
        int len = a.size();
        int sum1 = 0;
        int cnt=0;
        for(int i=0;i<len;i++)
        {
            if(a[i] <= 'z' && a[i] >= 'a')
            {
                cnt = a[i] - 'a';
                cnt++;
                sum1 += cnt;
            }
            if(a[i] <= 'Z' && a[i] >= 'A')
            {
                cnt = a[i] - 'A';
                cnt++;
                sum1 += cnt;
            }
        }
        sum1 = sum_helper(sum1);
        int sum2 = 0;
        len = b.size();
        for(int i=0;i<len;i++)
        {
            if(b[i] <= 'z' && b[i] >= 'a')
            {
                cnt = b[i] - 'a';
                cnt++;
                sum2 += cnt;
            }
            if(b[i] <= 'Z' && b[i] >= 'A')
            {
                cnt = b[i] - 'A';
                cnt++;
                sum2 += cnt;
            }
        }
        sum2 = sum_helper(sum2);
        int tmp;
        tmp = max(sum1, sum2);
        sum1 = min(sum1, sum2);
        sum2 = tmp;
        float num, den;
        num = sum1;
        den = sum2;
        float ans = 0;
        if(den != 0 ) ans = num/den;
        printf("%.2f %\n", ans*100);
    }
    return 0;
}
