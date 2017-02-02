#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        float c, f,ans;
        cin >> c >> f;
        ans = (9*c)/5 + 32 + f;
//        cout << ans << endl;
        ans = ((ans - 32)*5)/9;
        printf("Case %d: %.2f\n", i, ans);
//        cout << ans << endl;
    }
    return 0;
}
