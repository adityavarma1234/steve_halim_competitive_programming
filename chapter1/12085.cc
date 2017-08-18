#include<bits/stdc++.h>
using namespace std;
long long int n,tmp,x;
string in,intmp,prev1,sta;
deque< pair<string, string> >q;
deque< pair<string, string> >::iterator it;
pair<string,string> p;
string calculate(string a, string b)
{
  string res = "";
  int i,j;
  for(i=0;i<a.size();i++)
  {
    if(a[i] == b[i])
    {
      res += a[i];
    }
    else
    {
      break;
    }
  }
  j = i;
  for(;j<a.size();j++)
  {
    res += a[j];
  }
  res += "-";
  j = i;
  for(;j<b.size();j++)
    res += b[j];
  return res;
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int cnt = 1;
  while(cin >> n && n)
  {
    while(!q.empty()) q.pop_back();
    while(n--)
    {
      cin >> in;
      tmp = atol(in.c_str());
      p.first = in;
      p.second = in;
      if(q.empty())
      {
        prev1 = in;
        sta = in;
        q.push_back(p);    
      }
      else
      {
        intmp = prev1;
        x = atol(intmp.c_str());
        if(x+1 == tmp)
        {
          q.back().second = calculate(sta, in); 
          prev1 = in;
        }
        else
        {
          sta = in;
          prev1 = in;
          q.push_back(p);
        }
      }
    }
    cout << "Case " << cnt << ":" << endl;
    cnt++;
    it = q.begin();
    while(it != q.end())
    {
      cout << it->second << endl; 
      it++;
    }
    cout << endl;
  }
  return 0;
}
