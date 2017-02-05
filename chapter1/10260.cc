#include<bits/stdc++.h>
using namespace std;
string findint(char a)
{
    if(a == 'B' || a == 'F' || a == 'P' || a== 'V')
        return "1";
    if(a == 'C' || a== 'G' || a == 'J' || a == 'K' || a == 'Q' || a== 'S' || a == 'X' || a == 'Z')
        return "2";
    if(a == 'D' || a == 'T')
        return "3";
    if(a=='L')
        return "4";
    if(a == 'M' || a=='N')
        return "5";
    if(a == 'R')
        return "6";
    return "0";
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string in,res = "";
    while(getline(cin, in))
    {
        res = "";
        bool f = true;
        for(int i=0;i<in.size();i++)
        {
            string ans = findint(in[i]);
            if(ans != "0" && (ans[0] != res[res.size()-1] || f))
                {
                    res += ans;
                    f = false;
                }
                else if(ans == "0")
                {
                    f = true;
                }
        }
        cout << res << endl;
    }
    return 0;
}
