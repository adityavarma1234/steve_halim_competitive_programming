#include<bits/stdc++.h>
using namespace std;
bool compare(char a, char b)
{
    int x,y;
    if(a >= 'a' && a <= 'z')
        x = a - 'a';
    else
        x = a - 'A';
    if(b>= 'a' && b <= 's')
        y = b - 'a';
    else y = b - 'A';
    if(x>y)
        return false;
    else if(x==y)
    return a<b;
    return a > b;
}
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
    sort(a.begin(), a.end(), compare);
    do
    {
      cout << a << endl;
    }while(next_permutation(a.begin(), a.end()));
  }
  return 0;
}
