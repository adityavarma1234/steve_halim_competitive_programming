#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >v;
pair<int,int> p;
int in[1003],out[1003];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,a,b;
    while(cin >> n && n)
    {
        for(int i=0;i<1003;i++) out[i] = -1;
        v.clear();
        for(int i=0;i<n;i++)
        {
            cin >> a >> b;
            p.first = a;
            p.second = b;
            v.push_back(p);
        }
        bool f=true;
        for(int i=0;i<v.size();i++)
        {
            a = i+1;
            b = v[i].second;
            if(a + b >= 1 && a + b <= n && out[a+b] == -1)
            {
                out[a+b] = v[i].first;
            }
            else
            {
//                cout << a+b << " " << out[a+b] << " " << v[i].first << endl;
                f = false;
                break;
            }
        }
        if(f)
        {
            for(int i=1;i<=n;i++)
            {
                if(i==1)
                cout << out[i];
                else cout << " " << out[i];
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
