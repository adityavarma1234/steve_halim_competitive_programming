#include<bits/stdc++.h>
using namespace std;
set<int>a,b,c,ab,bc,ca;
vector<int>da,db,dc;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for(int T=1;T<=t;T++)
    {
        a.clear();
        b.clear();
        c.clear();
        ab.clear();
        bc.clear();
        ca.clear();
        da.clear();
        db.clear();
        dc.clear();
        int n,tmp;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin>> tmp;
            a.insert(tmp);
            ab.insert(tmp);
            ca.insert(tmp);
        }
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> tmp;
            b.insert(tmp);
            ab.insert(tmp);
            bc.insert(tmp);
        }
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> tmp;
            c.insert(tmp);
            ca.insert(tmp);
            bc.insert(tmp);
        }
        set_difference(a.begin(), a.end(), bc.begin(), bc.end(), back_inserter(da));
        set_difference(b.begin(), b.end(), ca.begin(), ca.end(), back_inserter(db));
        set_difference(c.begin(), c.end(), ab.begin(), ab.end(), back_inserter(dc));
        int ans = max(da.size(), max(db.size(), dc.size()));
        printf("Case #%d:\n", T);
        if(ans == da.size())
        {
            cout << 1 << " " << da.size();
            for(int i=0;i<da.size();i++)
            {
                cout << " " << da[i];
            }
            cout << endl;
        }
        if(ans == db.size())
        {
            cout << 2 << " " << db.size();
            for(int i=0;i<db.size();i++)
            {
                cout << " " << db[i];
            }
            cout << endl;
        }
        if(ans == dc.size())
        {
            cout << 3 << " " << dc.size() ;
            for(int i=0;i<dc.size();i++)
            {
                cout << " " << dc[i];
            }
            cout << endl;
        }
    }
    return 0;
}
