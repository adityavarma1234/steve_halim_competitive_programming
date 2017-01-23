#include<bits/stdc++.h>

using namespace std;

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        char a;
        int n, m;
        cin >> a >> n >> m;
        int tmp ;
        tmp = max(n,m);
        m = min(n, m);
        n = tmp;
        if(a == 'r')
            cout << m << endl;
        else if(a=='k')
        {
            cout << (n/2 + (n%2 ? 1 : 0))*(m/2 + (m%2 ? 1 : 0)) + (n/2)*(m/2) << endl;
        }
        else if(a == 'Q')
        {
            cout << m << endl;
        }
        else
        {
            cout << (m/2 + m%2)*(n%2 + n/2) << endl;
        }
    }
    return 0;
}
