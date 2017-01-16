#include <bits/stdc++.h>

using namespace std;

long double arr[104];

int main()
{
    int a, b;
    long double c, d;
    while(1)
    {
        cin >> a >> c >> d >> b;
        if(a<0)
            break;
        for(int i=0;i<104;i++)
        {
            arr[i] = 0.0;
        }
        for(int i=0;i<b;i++)
        {
            int j ;
            cin >> j;
            cin >> arr[j];
//            cout << j <<  " " << arr[j] << endl;
        }
        int i=0;
        long double value = c + d;
        long double owed = d;
        long double prev_dep;
        while(i <= a)
        {
            if(arr[i] != 0.0)
              prev_dep = arr[i];
            value = value * (1.0 - prev_dep);
            cout << "owed " << owed << " value " << value << endl;
            if(owed < value)
            {
                break;
            }
            owed = owed - c;
            i++;
        }
        if(i==0)
        {
          cout << "1 month" << endl;
        }
        else
        {
          cout << i << " months" << endl;
        }
    }
    return 0;
}
