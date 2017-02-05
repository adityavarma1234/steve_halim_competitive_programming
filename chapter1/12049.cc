#include<bits/stdc++.h>
using namespace std;
multiset<int>a,b;
vector<int> result;
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int m,n,tmp;
        cin >> n >> m;
        a.clear();b.clear();result.clear();
        for(int i=0;i<n;i++)
        {
            cin >> tmp;
            a.insert(tmp);
        }
        for(int i=0;i<m;i++)
        {
            cin >> tmp;
            b.insert(tmp);
        }
        set_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(result));
        set_difference(b.begin(), b.end(), a.begin(), a.end(), back_inserter(result));
        cout << result.size() << endl;
    }
    return 0;
}
