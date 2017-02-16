#include<bits/stdc++.h>
using namespace std;
vector<int> v;
set<int> s;
set<int>::iterator it;
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n,b,cnt=0;
  while(cin >> n >> b && n + b != 0)
  {
      cnt++;
    v.clear();s.clear();
    for(int i=0;i<b;i++)
    {
      int tmp;
      cin >> tmp;
      v.push_back(tmp);
    }
    for(int i=0;i<b-1;i++)
    {
      for(int j=i+1;j<b;j++)
      {
        s.insert(abs(v[i]-v[j]));
      }
    }
//    if(cnt==16)
//    {
//        cout << n << " " << b << endl;
//        for(int i=0;i<v.size();i++)
//            cout << v[i] << " " ;
//        cout << endl;
//    }
    if(v.size()>1)
    s.insert(0);
    int cnt = 0;
    bool f=true;

    if(v.size() == 1) f = false;
    for(it = s.begin(); it != s.end() ; it++)
    {
      if(*it != cnt)
      {
        f = false;
        break;
      }
      cnt++;
    }
    if(cnt!=n+1) f = false;
    if(f) cout << "Y" << endl;
    else cout << "N" << endl;
  }

  return 0;
}
