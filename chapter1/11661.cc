#include<bits/stdc++.h>
using namespace std;
string a;
int main()
{
    while(1)
    {
        int n;
        cin >> n;
        if(n==0) break;
        cin >> a;
        int prev_d = n + 1;
        int prev_r = n + 1;
        int ans = n + 1;
        for(int i=0;i<n;i++)
        {
            if(a[i] == 'Z')
            {
                ans = 0;
                break;
            }
            else if(a[i] == 'R')
            {
                if(prev_d != n+1)
                {
                    ans = min(ans, i - prev_d);
                }
                prev_r = i;
            }
            else if(a[i] == 'D')
            {
                if(prev_r != n+1)
                {
                    ans = min(ans, i - prev_r);
                }
                prev_d = i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
