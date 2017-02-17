#include<bits/stdc++.h>
using namespace std;
int dicerolls[1002], ladchut[102], noofplayers,turn[102],players[7],missturn[7];
int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
  int cnt = 0, tmp;
  while(1)
  {
    cin >> tmp;
//    cout << tmp << " ";
    if(tmp==0) break;
    dicerolls[cnt++] = tmp;
  }
//  cout << endl;
  while(cin >> noofplayers && noofplayers)
  {
//      cout << "no of players " << noofplayers << endl;
    int a,b;
    for(int i=0;i<102;i++) ladchut[i] = 0;
    for(int i=0;i<102;i++) turn[i] = 0;
    for(int i=0;i<7;i++) players[i] = 0;
    for(int i=0;i<7;i++) missturn[i] = 0;
    while(cin >> a >> b && a+b != 0)
    {
//        cout << "lad chut " << a << " " << b << endl;
      ladchut[a] = b;
    }
    while(cin >> a  && a )
    {
//        cout << "extr turn " << a << endl;
      if(a>0)
        turn[a] = 1;
      else
        turn[abs(a)] = -1;
    }
    int x = 0, dicerollcnt =0,y;
    while(1)
    {
      x = x % noofplayers;
      y = players[x] + dicerolls[dicerollcnt];
//      cout << "turn player " << x << " dice roll cnt " << dicerollcnt << "  dice roll " << dicerolls[dicerollcnt] << " before " << players[x] << " ";
      if(missturn[x])
      {
//          cout << "turn  miss" << endl;
        missturn[x] = 0;
        x++;
        dicerollcnt++;
      }
      else if(y>100)
      {
//          cout << " > 100 " << endl;
        x++; dicerollcnt++;
      }
      else if(ladchut[y])
      {
        players[x] = ladchut[y];
//        cout << " lad chut after " << ladchut[y] << endl;
        x++;
        dicerollcnt++;
      }
      else if(turn[y] > 0)
      {
        players[x] = y;
//        cout << " extra turn " << y << endl;
        dicerollcnt++;
      }
      else if(turn[y] < 0)
      {
        players[x] = y;
//        cout << "loose turn " << y << endl;
        dicerollcnt++;
        missturn[x] = 1;
        x++;
      }
      else
      {
        players[x] = y;
//        cout << "simple add "  << y << endl;
        if(y==100) break;
        x++;
        dicerollcnt++;
      }
    }
    cout << x + 1 << endl;
  }
  return 0;
}
