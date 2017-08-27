#include<bits/stdc++.h>
using namespace std;
map<int, int>m;
map<int, int>::iterator it;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
      // cout << "test " << t << endl;
        int n;
        cin >> n;
        m.clear();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int tmp;
            cin >> tmp;
            // cout << tmp << endl;
            if(m.find(tmp) == m.end()){
              m[tmp] = i;
            }
            else{
              int x = m[tmp];
              it = m.begin();
              ans = max(ans, int(m.size()));
              while(it != m.end()){
                if(it -> second  <= x){
                  it = m.erase(it);
                }
                else{
                  it++;
                }
              }
              m[tmp] = i;
            }
        }

        ans = max(ans, int(m.size()));
        cout << ans << endl;
    }
    return 0;
}
