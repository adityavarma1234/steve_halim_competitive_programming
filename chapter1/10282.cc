#include<bits/stdc++.h>
using namespace std;
map<string, string> m;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string a, b,tmp;
    while(getline(cin, tmp) && tmp != "")
    {
        istringstream ss(tmp);
        ss >> a;
        ss >> b;
//        cout << a << " is " << b << endl;
        m[b] = a;
    }
    while(cin >> a)
    {
//        cout << a << "inside" << endl;
        if(m.find(a) != m.end())
        cout << m[a] << endl;
        else
            cout << "eh" << endl;
    }
    return 0;
}
