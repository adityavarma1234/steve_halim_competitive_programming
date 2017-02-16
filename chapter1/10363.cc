#include<bits/stdc++.h>
using namespace std;
char a[3][3];
bool startgame()
{
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      if(a[i][j]=='O' || a[i][j] == 'X')
      {
        return false;
      }
    }
  }
  return true;
}
bool endgame(char b)
{
  for(int i=0;i<3;i++)
  {
    if(a[i][0] == b && a[i][0] == a[i][1] && a[i][1] == a[i][2])
      return true;
    if(a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[0][i] == b)
      return true;
  }
  if(a[0][0] == b && a[0][0] == a[1][1] && a[1][1] == a[2][2])
    return true;
  if(a[2][0] == b && a[2][0] == a[1][1] && a[1][1] == a[0][2])
    return true;
  return false;
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  string tmp;
  int t;
  cin >> t;
  getline(cin, tmp);
  int cnt=0;
  while(t--)
  {
      cnt++;
    int cntx=0,cnto=0;
    for(int i=0;i<3;i++)
    {
      getline(cin,tmp);
//      if(cnt == 476)
//      cout << tmp << endl;
      for(int j=0;j<3;j++)
      {
        a[i][j] = tmp[j];
        if(tmp[j]=='O') cnto++;
        if(tmp[j]=='X') cntx++;
      }
    }
    if(t) getline(cin,tmp);
    if(cntx < cnto || cntx - cnto>1 || (endgame('X') && endgame('O')) || (endgame('O') && cntx != cnto) || (endgame('X') && cntx != cnto+1))
    {
      cout << "no" << endl;
    }
    else
    {
      cout << "yes" << endl;
    }
  }
  return 0;
}
