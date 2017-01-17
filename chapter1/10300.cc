#include<bits/stdc++.h>


using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        long long int sum = 0;
        while(n--)
        {
            long long int a, b, c;
            cin >> a >> b >> c;
            sum+= a*c;
        }
        cout << sum << endl;
    }
    return 0;
}
