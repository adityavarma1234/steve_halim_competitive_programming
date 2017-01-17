#include <bits/stdc++.h>

using namespace std;

long double arr[104];

int main()
{
    int months, month_deps;
    long double down_payment, loan_amount;
    while(1)
    {
        cin >> months >> down_payment >> loan_amount >> month_deps;
        if(months<0)
            break;
        for(int i=0;i<104;i++)
        {
            arr[i] = 0.0;
        }
        for(int i=0;i < month_deps;i++)
        {
            int j ;
            cin >> j;
            cin >> arr[j];
        }
        int i=0;
        long double curr_value = down_payment + loan_amount;
        long double owed = loan_amount;
        long double prev_dep;
        long double month_paid_amount = (loan_amount)/(long double)(months);
        while(i <= months)
        {
            if(arr[i] != 0.0)
              prev_dep = arr[i];
            curr_value = curr_value * ((long double)1.0 - prev_dep);
            if(owed < curr_value)
            {
                break;
            }
            owed = owed - month_paid_amount;
            i++;
        }
        if(i==1)
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
