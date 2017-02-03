#include<bits/stdc++.h>
using namespace std;
multiset<int> pq;
multiset<int>::iterator it;
multiset<int>::reverse_iterator rit;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    while(cin >> n  && n!=0)
    {
        int ans = 0;
        pq.clear();
        while(n--)
        {
            int a;
            cin >> a;
            for(int i=0; i<a; i++)
            {
                int b;
                cin >> b;
                pq.insert(b);
            }
            rit = pq.rbegin();
            ans += *rit;
            it = pq.end();
            it--;
            pq.erase(it);
            it = pq.begin();
            ans -= *it;
            pq.erase(it);
        }
        cout << ans << endl;
    }
    cout << endl;
    return 0;
}
