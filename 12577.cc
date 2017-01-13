#include<bits/stdc++.h>

using namespace std;

int main()
{
    string a = "Hajj-e-Akbar";
    string b = "Hajj-e-Asghar";
    int c = 0;
    while(1)
    {
        c++;
        string d;
        cin >> d;
        if(d[0] == '*')
            break;
        if (d[0] == 'H')
        {
            printf("Case %d: %s\n", c, a.c_str());
        }
        else
        {
            printf("Case %d: %s\n", c, b.c_str());
        }

    }
    return 0;
}
