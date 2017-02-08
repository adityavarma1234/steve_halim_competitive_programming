#include<bits/stdc++.h>
using namespace std;
int findc(char a)
{
    switch(a){
    case 'a':
        return 1;
    case 'b':
        return 2;
    case 'c':
        return 3;
    case 'd':
        return 1;
    case 'e':
        return 2;
    case 'f':
        return 3;
    case 'g':
        return 1;
    case 'h':
        return 2;
    case 'i':
        return 3;
    case 'j':
        return 1;
    case 'k':
        return 2;
    case 'l':
        return 3;
    case 'm':
        return 1;
    case 'n':
        return 2;
    case 'o':
        return 3;
    case 'p':
        return 1;
    case 'q':
        return 2;
    case 'r':
        return 3;
    case 's':
        return 4;
    case 't':
        return 1;
    case 'u':
        return 2;
    case 'v':
        return 3;
    case 'w':
        return 1;
    case 'x':
        return 2;
    case 'y':
        return 3;
    case 'z':
        return 4;
    case ' ':
        return 1;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    string tmp;
    getline(cin, tmp);
    for(int i=1;i<=t;i++)
    {
        string a;
        getline(cin, a);
        int ans = 0;
        for(int i=0;i<a.size();i++)
        {
            ans += findc(a[i]);
        }
        printf("Case #%d: %d\n", i, ans);
    }
    return 0;
}
