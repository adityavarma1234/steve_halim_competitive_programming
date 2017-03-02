#include<bits/stdc++.h>
using namespace std;
long long int N, x;
pair<long long int, long long int> getrange(long long int mid)
{
  pair<long long int, long long int> p;
  long long int y = 2*(mid-1) + 1; 
  long long int sizesq = 2*y + 2*(y-2) - 1;
  long long int startelem = (mid-1)*(mid-1) + 1;
  long long int endelem = startelem + sizesq;
  p.first = startelem ;
  p.second = endelem;
  return p;
}
long long int findsquarenum()
{
  long long int maxsquares = (N-1)/2 + 1;
  long long int start = 2, end = maxsquares, mid;
  mid = (start + end) / 2;
  while(start < end)
  {
    pair<long long int,long long int>p = getrange(mid);
    if(x >= p.first && x <= p.second)
    {
      return mid;
    }
    else if(x < p.first)
    {
      end = mid - 1;
    }
    else 
    {
      start = mid + 1;
    }
  }
}
void findsquare()
{
  long long int sq = findsquarenum(); 
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  pair<long long int,long long int> p = getrange(3);
  cout << p.first << " " << p.second << endl;
  //while(cin >> N >> x && N + x != 0)
  //{
    //findsquare();
  //}
  return 0;    
}
