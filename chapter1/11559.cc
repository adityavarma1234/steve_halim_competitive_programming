#include<bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long int n,b,h,w;
    while(scanf("%lld %lld %lld %lld", &n, &b, &h, &w)!=EOF)
    {
//        cout << n << b << h << w << endl;
        unsigned long long int min_val = b;
//        cout << min_val << endl;
        bool flag = false;
        for(int i=0; i<h; i++)
        {
            unsigned long long int cost;
            cin >> cost;
            for(int j=0; j<w; j++)
            {
                unsigned long long int beds;
                cin >> beds;
                if(beds >= n && beds*cost <= b)
                {
                    min_val = min(min_val , n*cost);
                    flag = true;
                }
            }
        }
        if(flag) cout << min_val << endl;
        else cout << "stay home" << endl;
    }
    return 0;
}
