#include<bits/stdc++.h>
using namespace std;

map<string, int>m;
map<string, int>::iterator it;
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  while(cin >> t && t!=0){
    m.clear();
    int mostpopular=-1; 
    int a[5];
    while(t--){
      for(int i=0; i< 5;i++){
        cin >> a[i];
      }
      sort(a, a+5);
      string b="";
      for(int i=0; i< 5;i++){
        b += to_string(a[i]);
      }
      if(m.count(b)){
        m[b] += 1;
      }
      else{
        m[b] = 1;
      }
      mostpopular = max(mostpopular, m[b]);
    }
    int ans = 0;
    it = m.begin();
    while(it != m.end()){
      if(it -> second == mostpopular){
        ans++;
      }
      it++;
    }
    cout << mostpopular*ans << endl;
  }
  return 0;    
}
