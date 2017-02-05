#include<bits/stdc++.h>
using namespace std;
vector<string> v;
bool compare(string a, string b)
{
    if(a+b>b+a) return true;
    return false;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    while(cin >> n && n)
    {
        string tmp;
        v.clear();
        for(int i=0;i<n;i++)
        {
            cin >> tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end(), compare);
        for(int i=0;i<v.size();i++)
        {
            cout << v[i] ;
        }
        cout << endl;
    }
    return 0;
}
