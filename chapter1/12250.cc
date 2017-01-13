#include<bits/stdc++.h>

using namespace std;

int main()
{
    string words[6] = {"HELLO", "HOLA", "HALLO", "BONJOUR", "CIAO", "ZDRAVSTVUJTE"};
    string languages[6] = {"ENGLISH", "SPANISH", "GERMAN", "FRENCH", "ITALIAN", "RUSSIAN"};
    int c = 0;
    while(1)
    {
        c++;
        string a;
        cin >> a;
        if(a[0]=='#')
            break;
        bool flag = true;
        for(int i=0;i<6;i++)
        {
            if(words[i] == a)
            {
                flag = false;
                printf("Case %d: %s\n", c, languages[i].c_str());
                break;
            }
        }
        if(flag)
        {
            printf("Case %d: UNKNOWN\n", c);
        }
    }
    return 0;
}
