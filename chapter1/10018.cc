#include<bits/stdc++.h>
using namespace std;
long long int rever(long long int a)
{
    long long int rev=0,rem;
    while(a!=0)
    {
        rem = a%10;
        rev = rev*10 + rem;
        a = a/10;
    }
    return rev;
}
bool palin(long long int a)
{
    if(a == rever(a))
        return true;
    return false;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    while(n--)
    {
        long long int a;
        cin >> a;
        int cnt = 0;
        while(!palin(a))
        {
            cnt++;
            a = a + rever(a);
        }
        cout << cnt << " " << a << endl;
    }

    return 0;
}
