#include<bits/stdc++.h>
using namespace std;
bool compare (char a, char b)
{
    bool minisculaA = true, minisculaB = true;
    if (a >= 'A' && a <= 'Z')
        minisculaA = false;
    if (b >= 'A' && b <= 'Z')
        minisculaB = false;

    //Both are upper or lower case
    if (minisculaA && minisculaB)
        return a < b;
    if (!minisculaA && !minisculaB)
        return a < b;

    //a it's a lowercase
    if (minisculaA)
    {
        a -= ('a'-'A');
        return a < b;
    }
    else
    {
        b -= ('a'-'A');
        return a <= b;
    }
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
    }while(next_permutation(a.begin(), a.end(), compare));
  }
  return 0;
}
