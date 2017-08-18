#include<bits/stdc++.h>
using namespace std;
class comparef{
    public:
bool operator()(pair<int,int> a, pair<int, int> b)
{
  if(a.first < b.first) return false;
  if(a.first > b.first) return true;
  if(a.second < b.second) return false;
  if(a.second > b.second) return true;
}
};
priority_queue<pair<int,int>, vector<pair<int,int> >, comparef> pq;
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  string in;
  pair<int,int> p;
  map<int,int>m;
  while(getline(cin, in) && in!= "#")
  {
    istringstream ss(in);
    string tmp;
    int cnt = 0;
    while(ss >> tmp)
    {
      cnt++;
      if(cnt == 2)
      {
        p.second = atoi(tmp.c_str());
      }
      if(cnt == 3)
      {
        p.first = atoi(tmp.c_str());
      }
    }
    m[p.second] = p.first;
    pq.push(p);
  }
  int k;
  cin >> k;
  while(k--)
  {
    p = pq.top();
    cout << pq.top().second << endl;
    pq.pop();
    p.first += m[p.second];
    pq.push(p);
  }
  return 0;
}
