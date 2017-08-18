#include<bits/stdc++.h>
using namespace std;

int g[3][3], buffer[3][3];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
string a;
int ans;

void readinput(){
  getline(cin, a);
  for(int i=0; i<3; i++)
  {
    cin >> a;
    for(int j=0; j<3; j++)
    {
      g[i][j] = a[j] - '0'; 
    }
  }
}

void solve(){
  ans = 0;
  while(true)
  {
    int allzeros = true;
    for(int i=0; i<3; i++)
    {
      for(int j=0; j<3; j++)    
      {
        if(g[i][j]!=0)
        {
          allzeros = false; 
        }
        if(!allzeros) break;
      }
      if(!allzeros) break;
    }
    if(allzeros) break;
    ans++;
    for(int i=0; i<3; i++)
    {
      for(int j=0;j<3;j++)
      {
        buffer[i][j]=0;
         for(int k=0;k<4;k++)
         {
            if(0 <= i + dx[k] && i + dx[k] < 3 && 0 <= j + dy[k] && j + dy[k] < 3)
            {
              buffer[i][j] ^= g[i+dx[k]][j+dy[k]];
            }
         }
      }
    }
    for(int i=0; i<3; i++)
    {
      for(int j=0; j<3; j++)
      {
        g[i][j] = buffer[i][j]; 
      }
    }
  }
}
void printans()
{
  printf("%d\n", ans-1);
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  while(t--)
  {
    readinput();
    solve();
    printans();
  }
  return 0;    
}
