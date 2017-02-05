#include<bits/stdc++.h>
using namespace std;
string in,tmp;
set<string> out;
set<string>::iterator it;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    tmp = "";
    while(getline(cin, in))
    {
        int len = in.size();
        for(int i=0;i<len;i++)
        {
            if(in[i] == '-' && i == len-1)
                continue;
            else if(in[i] == '-')
                tmp += string(1, in[i]);
            else if(in[i] >= 'a' && in[i]<='z')
            {
                tmp += string(1,in[i]);
            }
            else if(in[i]>= 'A' && in[i] <= 'Z')
            {
                tmp += string(1, in[i]);
            }
            else if(tmp != "")
            {
                transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
                out.insert(tmp);
                tmp = "";
            }
            if(i==len- 1 && in[i] != '-' && tmp != "")
            {
                transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
                out.insert(tmp);
                tmp = "";
            }
        }
    }
    for(it = out.begin(); it != out.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}
