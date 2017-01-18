#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d\n",&t);
    string a;
    while(t--)
    {
        getline(cin, a);
        int c=0;
        int sm=0, em=0, sf=0, ef=0;
        for(int i=0; i<a.size(); i++)
        {
            while(a[i]==' ') i++;
//            cout << i << endl;
            if(i>=a.size()) break;
//            cout << i << " i" << endl;
            if(a[i]=='M' && a[i+1] == 'M')
            {
                sm++;
                em++;
                c++;
            }
            else if(a[i]=='M' && a[i+1] == 'F')
            {
                sm++;
                ef++;
                c++;
            }
            else if(a[i]=='F' && a[i+1] =='M')
            {
                sf++;
                em++;
                c++;
            }
            else
            {
                sf++;
                ef++;
                c++;
            }
            i++;
        }
//        cout << a << endl;
//        cout << sm << " " << em << " " << sf << " " << ef << endl;
        if(c>1 && sm==ef && sf == em)
        {
            cout << "LOOP" << endl;
        }
        else
        {
            cout << "NO LOOP" << endl;
        }
    }
    return 0;
}
