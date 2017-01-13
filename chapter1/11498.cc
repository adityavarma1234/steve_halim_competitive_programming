#include<bits/stdc++.h>


using namespace std;

string region(int x, int y, int X, int Y)
{
    int a = X-x;
    int b = Y-y;
    if(a > 0 && b > 0)
        return "NE";
    if(a > 0 && b < 0)
        return "SE";
    if(a < 0 && b > 0 )
        return "NO";
    if(a < 0 && b < 0)
        return "SO";
    return "divisa";
}

int main()
{
    int k;
    while(1)
    {
        cin >> k;
        if (k==0) break;
        int x,y;
        cin >> x >> y;
        while(k--)
        {
            int X,Y;
            cin >> X >> Y;
            cout << region(x, y, X, Y) << endl;
        }
    }
    return 0;
}
