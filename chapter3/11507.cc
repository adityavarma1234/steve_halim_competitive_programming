#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  int flag=0;
  while(cin >> t){
    v.clear();
    // if(flag) cout << endl;
    flag = 1;
    int n = t;
    // cout << t << endl;
    for(int i=0; i<n ;i++){
      int tmp;
      cin >> tmp;
      // cout << tmp << endl;
      v.push_back(tmp);
    }
    int val; 
    cin >> val;
    // cout << val << endl;
    sort(v.begin(), v.end());
    int start = 0, end = n-1, i = 0, j=0;
    while(start < end){
      if(v[start] + v[end] == val){
        i = start;
        j = end;
        start++;
        end--;
      }
      else if(v[start] + v[end] > val){
        end--; 
      }
      else{
        start++;
      }
    }
    cout << "Peter should buy books whose prices are " << v[i] <<  " and " << v[j] << "." << endl;
    cout << endl;
  }
  return 0;    
}
