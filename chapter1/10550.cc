#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int start,first,second,third,result;
    while(1)
    {
        cin >> start >> first >> second >> third;
        if((start + first + second + third) == 0)
        {
            break;
        }

        int a = start - first;

        if(a < 0)
        {
            a += 40;
        }

        int b = second - first;

        if(b < 0)
        {
            b += 40;
        }

        int c = second - third;

        if(c < 0)
        {
            c += 40;
        }

        result = (a + b + c) * 9;

        result += 1080;
        cout << result << endl;
    }
}
