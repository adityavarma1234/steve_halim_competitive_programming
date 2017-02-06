#include<bits/stdc++.h>
using namespace std;
struct record{
    string name;
    int dd;
    int mm;
    int yy;
};
vector<record> v;
bool compare(record a, record b)
{
    if(a.yy > b.yy)
        return false;
    if(a.yy < b.yy)
        return true;
    if(a.mm > b.mm)
        return false;
    if(a.mm < b.mm)
        return true;
    if(a.dd > b.dd)
        return false;
    if(a.dd < b.dd)
        return true;
    return true;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    record r;
    string name;
    int dd,mm,yy;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> name >> dd >> mm >> yy;
        r.name = name;
        r.dd = dd;
        r.mm = mm;
        r.yy = yy;
        v.push_back(r);
    }
    sort(v.begin(), v.end(), compare);
    cout << v[v.size()-1].name << endl;
        cout << v[0].name << endl;

    return 0;
}
