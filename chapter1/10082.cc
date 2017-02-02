#include<bits/stdc++.h>
using namespace std;
string in,res;
string getprev(char a)
{
    string ac = "WERTYUIOP[]SDFGHJKL;,'XCVBNM,./1234567890-=";
    string re = "QWERTYUIOP[ASDFGHJKLM;ZXCVBNM,.`1234567890-";
    for(int i=0;i<ac.size();i++)
    {
        if(ac[i] == a)
        {
            return string(1, re[i]);
        }
    }
    return "";
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(getline(cin, in))
    {
        res.clear();
//        cout << in << endl;
        for(int i=0;i<in.size();i++)
        {
//            cout << in[i] << " " << getprev(in[i]) << endl;
            if(in[i] == '\\')
            res += "]";
            else if(in[i]==' ')
                {
                    res += " ";
                }
            else
            {
                res += getprev(in[i]);
            }
        }
        cout << res << endl;
    }
    return 0;
}
