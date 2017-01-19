#include<bits/stdc++.h>
using namespace std;
int dp[2001][2001];
int zeros[2001];
vector<pair<pair<int, int>, int> > v(2001);

bool compare(  pair<pair<int,int>, int> a,   pair<pair<int,int>, int> b)
{
  if(a.first.first > b.first.first)
    return true;
  if(a.first.first < b.first.first)
    return false;
  if(a.first.second > b.first.second)
    return true;
  if(a.first.second < b.first.second)
    return false;
  if(a.second > b.second)
    return false;
  return true;
}

int main()
{
  int n,t,p;
  cin >> n >> t >> p;
  cout << n << t << p << endl;
  pair<pair<int,int>, int> pp;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<t;j++)
    {
        cin >> dp[i][j];
        if(dp[i][j] == 0) zeros[j]++;
    }
  }
  for(int i=0;i<n;i++)
  {
    int pp_second = i;
    int pp_first_first = 0;
    int pp_first_second = 0;
    for(int j=0;j<t;j++)
    {
      if(dp[i][j])
      {
        pp_first_first += zeros[j];
        pp_first_second += 1;
      }
    }
    pp.second = pp_second;
    pp.first.first = pp_first_first;
    pp.first.second = pp_first_second;
    v[i] = pp;
//    v.push_back(pp);
//    cout << v[v.size()-1].first.first << v[v.size()-1].first.second << v[v.size()-1].second << endl;
  }
//  sort(v.begin(), v.end(), compare);
//  for(int i=0;i<n;i++)
//  {
//      cout << v[i].first.first << v[i].first.second << v[i].second << endl;
//  }
  for(int i=0;i<n;i++)
  {
//      cout << v[i].second << endl;
    if(v[i].second == p-1)
    {
      cout << v[i].first.first << " " << v[i].first.second << endl;
    }
  }
  return 0;
}
