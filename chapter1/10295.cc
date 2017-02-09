#include<bits/stdc++.h>
using namespace std;

map<string,int> mm;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        string a;
        int x;
        cin >> a >> x;
        mm[a] = x;
    }
    string b,a;
    getline(cin ,a );
    long int ans = 0;
    for(int i=0;i<m;i++)
    {
        ans = 0;
        while(getline(cin, b) && b!= ".")
        {
            istringstream ss(b);
            while(getline(ss, a, ' '))
            {
                if(mm.find(a) != mm.end())
                {
                    ans += mm[a];
                }
            }
        }
                    cout << ans << endl;

    }
    return 0;
}
