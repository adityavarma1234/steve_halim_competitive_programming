#include<bits/stdc++.h>
using namespace std;
vector<string> largersquare, smallersquare, smallersquare90, smallersquare180, smallersquare270;
int N,n,p,q,r,s;
string tmp;
bool rotate(vector<string> &init, vector<string> &fin)
{
  fin.clear();
  for(int j=0;j<init[0].size();j++)
  {
    tmp = "";
    for(int i=init.size()-1;i>=0;i--)
    {
      tmp.push_back(init[i][j]);
    }
    fin.push_back(tmp);
  }
}
void printsquare(vector<string> a)
{
  for(int i=0;i<a.size();i++)
  {
    for(int j=0;j<a[i].size();j++)
    {
      cout << a[i][j] ;
    }
    cout << endl;
  }
}
void comparecount(vector<string> sqrcmp, int &cnt)
{
  int R,C,r,c;
  R = largersquare.size();
  C = largersquare[0].size();
  r = sqrcmp.size();
  c = sqrcmp[0].size();
  bool f = true;
  for(int i=0;i<R;i++)
  {
    for(int j=0;j<C;j++)
    {
      if(R-i>=r && C-j>=c)
      {
        for(int k=0;k<r;k++)
        {
          f = true;
          for(int l=0;l<c;l++)
          {
            if(sqrcmp[k][l] != largersquare[i+k][j+l])
            {
              f = false;
              break;
            }
          }
          if(!f) break;
        }
        if(f) cnt++;
      }
    }
  }
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  while(cin >> N >> n && N+n !=0)
  {
    largersquare.clear();
    smallersquare.clear();
    for(int i=0;i<N;i++)
    {
      cin >> tmp;
      largersquare.push_back(tmp);
    }
    for(int i=0;i<n;i++)
    {
      cin >> tmp;
      smallersquare.push_back(tmp);
    }
    rotate(smallersquare, smallersquare90);
    rotate(smallersquare90, smallersquare180);
    rotate(smallersquare180, smallersquare270);
    p=0;q=0;r=0;s=0;
    comparecount(smallersquare, p);
    comparecount(smallersquare90, q);
    comparecount(smallersquare180, r);
    comparecount(smallersquare270, s);
    cout << p << " " << q << " " << r << " " << s << endl;
  }
  return 0;    
}
