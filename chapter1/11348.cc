#include<bits/stdc++.h>
using namespace std;
map<int,int> seen;
set<int> ig;
vector<set<int> >v;
vector<int> ans,tmp;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
//    cout << t << "test " << endl;
    for(int T=1;T<=t;T++)
    {
        int n; cin >> n;
//        cout << n << " total n" << endl;
        seen.clear();ig.clear();v.clear();ans.clear();tmp.clear();
        for(int i=0;i<n;i++)
        {
            int m;cin >> m;
//            cout << m << " indi count" << endl;
            v.push_back(set<int> ());
            for(int j=0;j<m;j++)
            {
                int x;
                cin >> x;
//                cout << x << " indi" << endl;
                if(seen.find(x) != seen.end() && seen[x] != i)
                {
//                    cout << x << " already sen " << seen[x] << endl;
                    ig.insert(x);
                }
                else if(seen.find(x) == seen.end())
                {
                    seen[x] = i;
//                    cout << x << " first time seen " << seen[x] << endl;
                }
                v[v.size()-1].insert(x);
            }
        }
        int sum = 0;
        for(int i=0;i<v.size();i++)
        {
            tmp.clear();
            set_difference(v[i].begin(), v[i].end(), ig.begin(), ig.end(), back_inserter(tmp));
//            cout << i << " set diff " << tmp.size() << endl;
            ans.push_back(tmp.size());
            sum += tmp.size();
        }
        printf("Case %d:",T);
        for(int i=0;i<ans.size();i++)
        {
            printf(" %.6f%%%",100*((double)ans[i]/sum));
        }
        cout << endl;
    }
    return 0;
}
