#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t,a,b,c,d,p,q,r,s,w,x,y,z;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        bool f = true;
        scanf("%d:%d %d:%d",&a,&b,&c,&d);
        scanf("%d:%d %d:%d",&p,&q,&r,&s);
        w = a*60 + b;
        x = c*60 + d;
        y = p*60 + q;
        z = r*60 + s;
        if(y>=w && y<=x ) f = false;
        if(z>=w && z<=x) f = false;
        if(w>=y && w<=z ) f = false;
        if(x>=y && x<=z) f = false;
        if(f)
        {
            printf("Case %d: Hits Meeting\n", i);
        }
        else
        {
            printf("Case %d: Mrs Meeting\n", i);
        }
    }
    return 0;
}
