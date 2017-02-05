#include<bits/stdc++.h>
using namespace std;
int hartals[3655];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        for(int i=0;i<3655;i++) hartals[i] = 0;
        cin >> n;
//        cout << "n " << n << endl;
        int cnt;
        cin >> cnt;
//        cout << "hartals " << cnt << endl;
        for(int i=0;i<cnt;i++)
        {
            int tmp;
            cin >> tmp;
//            cout << "polit " << tmp << endl;
            int val=tmp;
            while(val <= n)
            {
                hartals[val] = 1;
                val += tmp;
//                cout << "polit " << val << endl;
            }
        }
        int ans = 0;
        int f=6;
        for(int i=1;i<=n;i++)
        {
            if(i>f+1) f += 7;
            if(i == f || i == f +1)
            {
//                cout << f << " friday " << f+1 << "satruday" << endl;
                continue;
            }
            if(hartals[i]) {
                ans++;
//                cout << i << " hartal cpunt" << endl;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
