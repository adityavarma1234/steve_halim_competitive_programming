#include<bits/stdc++.h>
using namespace std;
string in,tmp;
deque<string> d;
deque<string>::iterator it;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(getline(cin, in))
    {
        bool f = true;
        d.clear();
        tmp = "";
        for(int i=0;i<in.size();i++)
        {
            if(in[i] == '[')
            {
                if(f) d.push_back(tmp);
                else d.push_front(tmp);
                f = 0;
                tmp = "";
            }
            else if(in[i] == ']')
            {
                if(f) d.push_back(tmp);
                else d.push_front(tmp);
                f = true;
                tmp = "";
            }
            else
            {
                tmp += string(1,in[i]);
            }
        }
        if(f) d.push_back(tmp);
        else d.push_front(tmp);
        it = d.begin();
        while(it!=d.end())
        {
            cout << *it++;
        }
        cout << endl;
    }
    return 0;
}
