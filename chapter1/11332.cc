#include<bits/stdc++.h>
using namespace std;
int sum(unsigned long long int a)
{
    int return_sum = 0;
    if(a==0) return 0;
    return_sum += a%10 + sum(a/10);
    return return_sum;
}

int sum1(unsigned long long int a)
{
    int ans=sum(a);
    while(ans/10)
    {
        ans = sum(ans);
    }
    return ans;
}
int main()
{
    unsigned long long int n;
    while(1)
    {
        cin >> n;
        if(n==0) break;
        cout << sum1(n) << endl;
    }
    return 0;
}
