#include<bits/stdc++.h>
using namespace std;
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  string a;
  while(t--)
  {
    cin >> a;
    sort(a.begin(), a.end());
    do
    {
      cout << a << endl;
    }while(next_permutation(a.begin(), a.end()));
    cout << endl;
  }
  return 0;
}

