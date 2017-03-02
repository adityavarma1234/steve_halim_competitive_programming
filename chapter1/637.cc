#include<bits/stdc++.h>
using namespace std;
pair<string, string> p[100];
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  while(cin>> n && n!=0)
  {
    cout << "Printing order for " << n << " pages:" << endl;
    if(n==1)
    {
      cout << "Sheet 1, front: Blank, 1" << endl;
      continue;
    }
    int x = n/4;
    if(n%4) x++;
    for(int i=0;i<2*x;i++)
    {
      p[i].first = "Blank";
      p[i].second = "Blank";
    }
    bool f = false;
    int y = 1;
    for(int i=0;i<2*x;i++)
    {
      if(f)
      {
        p[i].first = to_string(y);
      }
      else
      {
        p[i].second = to_string(y);
      }
      y++; f = !f;
//      cout << y << " " << f <<  " " << i << endl;
    }

    for(int i=2*x-1;i>=0;i--)
    {
        if(y>n) break;
      if(f)
      {
        p[i].first = to_string(y);
      }
      else
      {
        p[i].second = to_string(y);
      }
      y++; f = !f;
//      cout << y << " " << f << " " << i << endl;
    }
    int j=0;
    for(int i=1;i<=x;i++)
    {
      printf("Sheet %d, front: %s, %s\n", i, p[j].first.c_str(), p[j].second.c_str());
      j++;
      printf("Sheet %d, back : %s, %s\n", i, p[j].first.c_str(), p[j].second.c_str());
      j++;
    }
  }
  return 0;
}
