#include<bits/stdc++.h>
using namespace std;
set<int> s;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        s.clear();
        for(int i=0;i<n;i++)
        {
            int tmp;
            cin >> tmp;
            s.insert(tmp);
        }
        cout << s.size() << endl;
    }
    return 0;
}
