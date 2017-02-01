#include<bits/stdc++.h>
using namespace std;
vector<long long int> v;
int median()
{
  size_t n = v.size() / 2;
  nth_element(v.begin(), v.begin()+n, v.end());
  int vn = v[n];
  if(v.size()%2 == 1)
  {
    return vn;
  }else
  {
    std::nth_element(v.begin(), v.begin()+n-1, v.end());
    return (vn+v[n-1])/2;
  }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a;
    string b;
    while(getline(cin, b))
    {
        a = std::atoi(b.c_str());
//        cout << a  << "val "<< endl;
        v.push_back(a);
        cout << median() << endl;
    }
    return 0;
}
