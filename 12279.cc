#include<bits/stdc++.h>

using namespace std;

int main()
{
    int b = 0;
    while(1)
    {
        b++;
        int n;
        cin >> n;
        if(n == 0)
            break;
        int c = 0;
        int a;
        while(n--)
        {
            cin >> a;
            if(a>0) c++;
            else c--;
        }
        printf("Case %d: %d\n",b, c);
    }
    return 0;
}
