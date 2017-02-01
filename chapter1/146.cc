#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string a;
    while(getline(cin, a) && a != "#")
    {
        if(next_permutation(a.begin(), a.end()))
            cout << a << endl;
        else
            cout << "No Successor" << endl;
    }
    return 0;
}
