#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    while(cin >> n && n)
    {
        string in;
        cin >> in;
        int times = in.size()/n;
        for(int i=0;i<n;i++)
        {
            reverse(in.begin()+i*times , in.begin()+(i+1)*times);
        }
        cout << in << endl;
    }
    return 0;
}
