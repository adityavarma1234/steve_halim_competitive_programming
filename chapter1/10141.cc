#include<bits/stdc++.h>

using namespace std;
int main()
{
    int n, p;
    int c=0;
    while(1)
    {
        c++;
        cin >> n >> p;
//        cout << n << p << endl;
        string tmp,ans, rm_line;
        if(n==0 && p==0) break;
        long double curr_compliance, max_price = 0.0;
        int max_compliance=0;
        getline(cin, rm_line);
        for(int i=0;i<n;i++)
        {
            getline(cin, tmp);
//            cout << tmp << endl;
        }
        for(int i=0; i<p;i++)
        {
            getline(cin, tmp);
//            cout << tmp << endl;
            long double price;
            int sat_req;
            cin >> price >> sat_req;
            getline(cin, rm_line);
//            cout << price <<" "<< sat_req << " "<< max_compliance<<endl;
            if(sat_req >= max_compliance)
            {
                if(max_price == 0)
                {
                    max_price = price;
                    ans = tmp;
                }
                if(max_price > price || sat_req > max_compliance)
                {
                    ans = tmp;
//                    cout << ans << "-----" << endl;
                    max_price = price;
                }
                max_compliance = sat_req;
            }
            for(int j=0;j<sat_req;j++)
            {
                getline(cin, tmp);
//                cout << tmp << endl;
            }
        }
        if(c!=1) cout << endl;
        printf("RFP #%d\n",c);
        cout << ans << endl;
    }
    return 0;
}
