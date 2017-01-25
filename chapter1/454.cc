#include<bits/stdc++.h>

using namespace std;
vector<string> v,ans;

string isanagram(string a, string b)
{
    istringstream sa(a);
    istringstream sb(b);
    string x="", y="", tmp;
    while(getline(sa, tmp, ' '))
    {
        x += tmp;
    }
    while(getline(sb, tmp, ' '))
    {
        y += tmp;
    }
//    transform(x.begin(), x.end(), x.begin(), ::tolower);
//    transform(y.begin(), y.end(), y.begin(), ::tolower);
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    if(x == y)
    {
        if(a < b)
            return a + " = " + b;
        return b + " = " + a;
    }
    return "";
}
map<string, int> m;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    string tmp;
    cin >> t;
    getline(cin, tmp);
    getline(cin, tmp);
    while(t--)
    {
        v.clear();
        ans.clear();
        while(1)
        {
            getline(cin, tmp);
            if(tmp == "")
                break;
            v.push_back(tmp);
        }
        for(int i=0; i<v.size(); i++)
        {
            for(int j=i+1; j<v.size(); j++)
            {
                tmp = isanagram(v[i], v[j]);
                if(tmp != "")
                {
//                    cout << tmp << " " << m.size() << endl;
                    {
                        ans.push_back(tmp);
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        for(int i=0; i<ans.size(); i++)
        {
            cout << ans[i] << endl;
        }
        if(t!=0)cout << endl;
    }
    return 0;

}
