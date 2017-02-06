#include<bits/stdc++.h>
using namespace std;
int a[8];
char grade(int score)
{
    if(score>=90)
        return 'A';
    if(score>=80)
        return 'B';
    if(score>=70)
        return 'C';
    if(score>=60)
        return 'D';
    return 'F';
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for(int t=1;t<=T;t++)
    {
        for(int i=0;i<7;i++)
        {
            cin >> a[i];
//            cout << a[i] << " ";
        }
//        cout << endl;
        sort(a+4, a+7);
//        for(int i=0;i<7;i++)
//            cout << a[i] << " ";
//        cout << endl;
        int sum=0;
        for(int i=0;i<4;i++)
            sum += a[i];
        sum += (a[6] + a[5])/2;
        printf("Case %d: %c\n", t, grade(sum));
    }
    return 0;
}
