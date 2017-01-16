#include<bits/stdc++.h>

using namespace std;

int main()
{
    string a[16] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};
    int n;
    cin >> n;
    int i=0;
    string in[101];
    int c=0;
    for(i=0;i<n;i++)
    {
        cin >> in[i];
//        cout << in[i] << endl;
    }
    for(i=0;i<n;i++)
    {
        cout << in[i] << ": " << a[c%16] << endl;
//        cout << c << endl;
        c++;
    }
    while(c%16)
    {
        for(i=0;i<n;i++)
        {
            if(c%16 == 0)
            {
                break;
            }
            cout << in[i] << ": "<< a[c%16] << endl;
//            cout << c << endl;
            c++;
        }
    }
    return 0;
}
