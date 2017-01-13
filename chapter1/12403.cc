#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int ans = 0;
    while(t--)
    {
        string a;
        int b;
        cin >> a;
        if(a[0]=='d')
        {
            cin >> b;
            ans += b;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}
