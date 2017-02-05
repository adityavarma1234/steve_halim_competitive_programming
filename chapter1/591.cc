#include<bits/stdc++.h>
using namespace std;
vector<int> in;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt",  "w", stdout);
    int n;
    int cnt = 0;
    while(cin >> n && n)
    {
        cnt++;
        int tmp;
        in.clear();
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            cin >> tmp;
            sum += tmp;
            in.push_back(tmp);
        }
        int x = sum/n, ans=0;
        for(int i=0;i<n;i++)
        {
            if(in[i] > x)
            {
                ans += in[i] - x;
            }
        }
        printf("Set #%d\n", cnt);
        printf("The minimum number of moves is %d.\n", ans);
        cout << endl;
    }
    return 0;
}
