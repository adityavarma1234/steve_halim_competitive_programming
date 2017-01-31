#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int h,m;
    while(1)
    {
        scanf("%d:%d",&h,&m);
        if(h==0&&m==0) break;
        if(h==12) h = 0;
        if(m==60) m = 0;
        float ans,hangle, mangle;
        hangle = (h*60 + m)*0.5;
        mangle = m*6;
        ans = abs(hangle - mangle);
        ans = min(ans, abs(360-ans));
        printf("%.3f\n",ans);
    }
    return 0;
}
