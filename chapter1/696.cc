#include<bits/stdc++.h>

using namespace std;

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int t;
    while(1)
    {
        int n, m;
        cin >>  n >> m;
        if(n ==0 && m==0)
            break;
        if(n == 0 || m == 0)
        {
            printf("0 knights may be placed on a %d row %d column board.\n", n,m);
        }
        else if(n==1 || m==1)
        {
            printf("%d knights may be placed on a %d row %d column board.\n",max(n,m), n,m);
        }
        else if(n == 2 || m == 2)
        {
            int ans= 4*(max(n,m)/4);
            if(max(n,m)%4 == 1)
                ans += 2;
            else if(max(n,m)%4 == 2 || max(n,m)%4 == 3)
                ans += 4;
            printf("%d knights may be placed on a %d row %d column board.\n",ans, n,m);
        }
        else
        {
            int ans = (n/2 + (n%2 ? 1 : 0))*(m/2 + (m%2 ? 1 : 0)) + (n/2)*(m/2) ;
            printf("%d knights may be placed on a %d row %d column board.\n",ans, n,m) ;
        }
    }
    return 0;
}

