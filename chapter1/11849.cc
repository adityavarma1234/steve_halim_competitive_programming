#include<bits/stdc++.h>
using namespace std;
vector<int>a,b,ans;
int main()
{
    int n,m;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(1)
    {
        cin >> n >> m;
        if(n+m == 0)
            break;
        int tmp;
        a.clear();
        b.clear();
        for(int i=0;i<n;i++)
        {
            cin >> tmp;
            a.push_back(tmp);
        }
        sort(a.begin(),a.end());
        for(int i=0;i<m;i++)
        {
            cin >> tmp;
            b.push_back(tmp);
        }
        sort(b.begin(), b.end());
        set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(ans));
        cout << ans.size() << endl;
    }
    return 0;
}
