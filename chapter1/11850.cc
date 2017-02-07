#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    v.clear();
    int n;
    while(cin >> n && n)
    {
        v.clear();
        int tmp;
        for(int i=0;i<n;i++)
        {
            cin >> tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());
        bool f = true;
        for(int i=0;i<n-1;i++)
        {
            if(v[i+1] - v[i] > 200)
            {
//                cout << i << endl;
                f = false;
                break;
            }
        }
        int lastcharge = 1422 - v[n-1];
        if(2*lastcharge > 200)
        {
//            cout << lastcharge << " " << v[n-1] << endl;
            f = false;
        }
        if(f) cout << "POSSIBLE" << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
