#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a;
        cin >> a;
        cout << abs((((((a*567)/9 + 7492)*235)/47)-498)%100)/10 << endl;
    }
    return 0;
}
