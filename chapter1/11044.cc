#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    int t;
    cin >> t;
    while(t--){
        int ans = 0;
        cin >> a >> b;
        ans = (b-2)/3 + (((b-2))%3 !=0 ? 1 : 0);
        ans *= (a-2)/3 + (((a-2))%3!=0 ? 1 : 0);
        cout << ans << endl;
    }
    return 0;
}
