#include<bits/stdc++.h>
using namespace std;

map<string,string> m;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    string tmp;
    getline(cin, tmp);
    for(int i=0;i<n;i++)
    {
        string a,b;
        getline(cin, a);
        getline(cin, b);
        m[a] = b;
    }
    int mm;
    cin >> mm;
    getline(cin, tmp);
    for(int i=0;i<mm;i++)
    {
        getline(cin, tmp);
        cout << m[tmp] << endl;
    }
    return 0;
}
