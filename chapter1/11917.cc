#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for(int i=1;i<=T;i++)
    {
        int n,b;
        m.clear();
        cin >> n;
        string a;
        for(int j=0;j<n;j++)
        {
            cin >> a >> b;
            m[a] = b;
        }
        int d;
        cin >> d;
        cin >> a;
        if(m.find(a) == m.end() || m[a] > d+5)
        {
            printf("Case %d: Do your own homework!\n",i);
        }
        else if(m[a] > d)
        {
            printf("Case %d: Late\n",i);
        }
        else
        {
            printf("Case %d: Yesss\n",i);
        }
    }
    return 0;
}
