#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n,m;
bool compare(int a, int b)
{
    int am= a%m;
    int bm = b%m;
    if(am < bm)
        return true;
    if(am > bm)
        return false;
    if(a%2 && b%2==0)
    {
        return true;
    }
    if(a%2==0 && b%2)
    {
        return false;
    }
    if(a%2 && b%2)
    {
        if(a>b)
            return true;
        return false;
    }
    if(a<b)
        return true;
    return false;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(cin >> n >> m && n+m)
    {
        v.clear();
        for(int i=0;i<n;i++)
        {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end(), compare);
        cout << n << " " << m << endl;
        for(int i=0;i<n;i++)
            cout << v[i] << endl;
    }
    cout << n << " " << m << endl;
    return 0;
}
