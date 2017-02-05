#include<bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    string in;
    set<string> out;
    while(getline(cin,in))
    {
        string tmp = "";
        for(int i=0; i<in.size(); i++)
        {
            if(in[i] >= 'a' && in[i] <= 'z')
            {
                tmp += string(1, in[i]);
            }
            else if(in[i]>='A' && in[i] <='Z')
            {
                tmp += string(1, in[i]);
            }
            else if(tmp != "")
            {
                transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
                out.insert(tmp);
                tmp = "";
            }
        }
    }
    set<string>::iterator it;
    for(it =out.begin(); it!=out.end(); it++)
        cout << *it << endl;
    return 0;
}
