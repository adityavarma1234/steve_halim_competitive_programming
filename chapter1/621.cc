#include<bits/stdc++.h>

using namespace std;

string printans(string a)
{
    if(a.size() == 1 || a.size() == 2)
    {
        return "+";
    }

    if(a[a.size()-2] == '3' && a[a.size()-1] == '5')
    {
        return "-";
    }
    if(a[0] == '9' && a[a.size()-1] == '4' )
    {
        return "*";
    }
    return "?";
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string a;
        cin >> a;
        cout << printans(a) << endl;
    }
    return 0;
}
