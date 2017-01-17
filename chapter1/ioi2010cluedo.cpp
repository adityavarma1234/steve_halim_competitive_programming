#include<bits/stdc++.h>

using namespace std;

void Solve(){
  bool murderer[7], location[11], weapon[7];
  int mur=1, loc=1, wea = 1;
  int ans = Theory(mur, loc, wea);
  while(ans != 0)
  {
      if(ans == 1)
      {
          murderer[mur] = true;
          mur++;
      }
      else if(ans == 2)
      {
          location[loc] = true;
          loc++;
      }
      else
      {
          weapon[wea] = true;
          wea++;
      }
      ans = Theory(mur, loc, wea);
  }
  return;
}
