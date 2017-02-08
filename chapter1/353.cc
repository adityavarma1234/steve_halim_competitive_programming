#include<bits/stdc++.h>
using namespace std;
set<string> s;

bool ispalin(string s)
{
    string a = s;
    reverse(a.begin(), a.end());
    if(a == s)
        return true;
    return false;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string res;
    while(getline(cin,res))
    {
        int len = res.size();
        s.clear();
        for(int i=0;i<len+1;i++)
        {
            for(int j=0;j<len;j++)
            {
//                                        cout << res.substr(j,i) << " comp" << endl;
                if(res.substr(j,i) != "" && ispalin(res.substr(j,i)))
                {
//                        cout << res.substr(j,i) << " sf" << endl;
                    s.insert(res.substr(j,i));
                }
            }
        }
        cout << "The string '" << res << "' contains " << s.size() << " palindromes."<< endl;
    }
    return 0;
}
