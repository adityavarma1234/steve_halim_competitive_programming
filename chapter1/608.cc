#include<bits/stdc++.h>
using namespace std;
string in[3][3];
string coins = "ABCDEFGHIJKL";
bool left_present(int x, char a)
{
  bool f = false;
  for(int i=0;i<in[x][0].size();i++)
  {
    if(in[x][0][i] == a)
    {
      return true;
    }
  }
  return false;
}
bool right_present(int x, char a)
{
  bool f = false;
  for(int i=0;i<in[x][1].size();i++)
  {
    if(in[x][1][i] == a)
    {
      return true;
    }
  }
  return false;
}
bool present_or_not(int x, char a)
{
  if(left_present(x,a) || right_present(x,a))
    return true;
  return false;
}
string even_light_weight_not_present(int x, char a)
{
  if(in[x][2] == "even")
    return "even"; 
  if(in[x][2] == "up")
  {
    if(left_present(x,a))
      return "heavy";
    else if(right_present(x,a))
      return "light";
  }
  if(in[x][2] == "down")
  {
    if(left_present(x,a))
      return "light";
    else if(right_present(x,a))
      return "heavy";
  }
}
void printans()
{
  string res = "";
  string tmp= "";
  int i;
  for(i=0;i<coins.size();i++)
  {
    res = "";
    tmp = "";
    bool f = false;
    for(int j=0;j<3;j++)
    {
      if(present_or_not(j, coins[i]))
      {
        if(res == "")
        {
          res = even_light_weight_not_present(j,coins[i]);
          if(res == "even")
          {
            f = true;
            break;
          }
        }
        else
        {
          tmp = even_light_weight_not_present(j,coins[i]);
          if(tmp == "even" || tmp != res)
          {
            f = true;
            break;
          }
        }
      }
    }
    if(!f && res != "") break;
  }
  cout << coins[i] << " is the counterfeit coin and it is " << res << "." << endl;
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  while(t--)
  {
    for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
      {
        cin >> in[i][j];
      }
    }
    printans();
  }
  return 0;    
}
