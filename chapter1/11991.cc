#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > g(1000002);
int main()
{
    int n,m;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(cin >> n >> m)
    {
        for(int i=0;i<1000002;i++) g[i].clear();
        for(int i=0;i<n;i++)
        {
            int tmp;
            cin >> tmp;
            g[tmp].push_back(i+1);
        }
        for(int i=0;i<m;i++)
        {
            int k,v;
            cin >> k >> v;
            if(g[v].size() < k)
                cout << 0 << endl;
            else
                cout << g[v][k-1] << endl;
        }
    }
    return 0;
}
