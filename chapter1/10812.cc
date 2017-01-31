#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        long long int a,b;
        cin >> a >> b;
        long long int x,y;
        x = (a+b)/2;
        y = (a-b)/2;
        if(x<0 || y < 0 )
            cout << "impossible" << endl;
        else if(x+y == a && x-y == b)
            cout << x << " " << y << endl;
        else
            cout << "impossible" << endl;
    }
    return 0;
}
