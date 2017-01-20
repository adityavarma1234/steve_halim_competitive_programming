#include<bits/stdc++.h>

using namespace std;

int acards[100002], bcards[100002];
int da, db, rc;

int main()
{
  while(1)
  {
    int a, b;
    cin >> a >> b;
    int tmp;
    if(a==0 && b==0)
      break;
    for(int i=0;i<100002;i++) acards[i] = bcards[i] = 0;
    for(int i=0;i<a;i++)
    {
      cin >> tmp;
      acards[tmp]++;
    }
    for(int i=0;i<b;i++)
    {
      cin >> tmp;
      bcards[tmp]++;
    }
    da = db = rc = 0;
    for(int i=0;i<100002;i++)
    {
      if(acards[i])
        da++;
      if(bcards[i])
        db++;
      if(acards[i] && bcards[i])
        rc++;
    }
    cout << min(da-rc, db-rc) << endl;
  }
  return 0;
}
