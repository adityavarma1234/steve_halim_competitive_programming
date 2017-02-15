#include<bits/stdc++.h>
using namespace std;
stack<int> s;
vector<int> v;
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n,m;
  while(cin >> n && n)
  {
    cin >> m;
    while(!s.empty()) s.pop();
    v.clear();
    for(int i=0;i<m;i++)
    {
      int tmp;
      cin >> tmp;
      v.push_back(tmp);
    }
    s.push(n);
    int ans = 0;
    for(int i=0;i<v.size();i++)
    {
      if(s.empty())
      {
        s.push(v[i]);
        continue;
      }
      else if(s.top() > v[i])
      {
        ans += s.top() - v[i];
        s.pop();
        s.push(v[i]);
      }
      else if(s.top() < v[i])
      {
        s.pop();
        s.push(v[i]);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
