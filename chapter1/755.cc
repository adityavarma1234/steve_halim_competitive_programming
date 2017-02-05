#include<bits/stdc++.h>
using namespace std;
map<string,int>m;
map<string,int>::iterator it;
string intstring(char a)
{
    if(a == 'A' || a == 'B' || a == 'C')
        return "2";
    if(a=='D' || a == 'E' || a == 'F')
        return "3";
    if(a == 'G' || a == 'H' || a == 'I')
        return "4";
    if(a=='J' || a ==  'K' || a == 'L')
        return "5";
    if(a == 'M' || a == 'N' || a == 'O')
        return "6";
    if(a == 'P' || a == 'R' || a == 'S')
        return "7";
    if(a == 'T' || a == 'U' || a == 'V')
        return "8";
    if(a == 'W' || a == 'X' || a == 'Y')
        return "9";

}
string getstandard(string a)
{
    string res = "";
    for(int i=0;i<a.size();i++)
    {
        if(a[i] == '-')
            continue;
        if(a[i]>='A' && a[i]<='Z')
            res += intstring(a[i]);
        else
            res += a[i];
    }
    res = res.substr(0,3) + "-" + res.substr(3,4);
    return res;
}
int main()
{
    int t;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        m.clear();
        string in;
        for(int i=0;i<n;i++)
        {
            cin >> in;
            in = getstandard(in);
            if(m.find(in) != m.end())
            {
                m[in] += 1;
            }
            else
            {
                m[in] = 1;
            }
        }
        if(m.size() == n)
            cout << "No duplicates.\n";
        else
        {
            for(it = m.begin(); it!=m.end();it++)
            {
                if(it->second > 1)
                {
                    cout << it->first << " " << it->second << endl;
                 }
            }
        }
        if(t) cout << endl;
    }
    return 0;
}
