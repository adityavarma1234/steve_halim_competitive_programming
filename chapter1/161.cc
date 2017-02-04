#include<bits/stdc++.h>
using namespace std;
vector<int> sc;
int sig[5*60*60 + 5];

void printans(int i)
{
    int hours,mins,secs;
    hours = i/3600;
    i = i%3600;
    mins = i/60;
    i = i%60;
    secs = i;
    printf("%.2d:%.2d:%.2d\n",hours,mins,secs);
}

void findans()
{
    for(int i=0; i<18001; i++)
        sig[i] = 0;
    int i;
    for(i=0; i<sc.size(); i++)
    {
        int curr = sc[i];
        for(int j=0; j<18002; )
        {
            int green,red,orange;
            green = curr-5;
            red = curr;
            orange = 5;
            while(j<18002 && green--)
            {
                if(sig[j] == 0)
                    sig[j] = 1;
                j++;
            }
            while(j<18002 && orange--)
            {
                sig[j] = 2;
                j++;
            }
            while(j<18002 && red--)
            {
                sig[j] = 3;
                j++;
            }
        }
    }
    for(i=0; i<18002; i++)
    {
        if(sig[i] == 2)
            break;
    }
    for(; i<18001; i++)
    {
        if(sig[i] == 1)
        {
            printans(i);
            return;
        }
    }
    printf("Signals fail to synchronise in 5 hours\n");
    return ;
}

int main()
{
    string in;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(getline(cin, in))
    {
        string tmp;
        istringstream ss(in);
//        cout << "in " << in << endl;
        bool f = false;
        while(getline(ss, tmp, ' '))
        {
//            cout << "tmp " << tmp << endl;
//            if(tmp == " ") cout << "space here" << endl;
            if(tmp == "") continue;
            int a = atoi(tmp.c_str());
            if(a == 0 && sc.size() >= 2)
                {
                    f = true;
                    break;
//                    cout << "break here" << endl;
                }
            sc.push_back(a);
        }
        if(sc.size() > 1 && sc[0] == 0 && sc[1] == 0)
            break;
//        cout << "sc inside "<<endl;
//        for(int i=0; i<sc.size(); i++)
//        {
//            cout << sc[i] << " ";
//        }
//        cout << endl;
        if(f && sc.size()>=2)
        {
            findans();
            sc.clear();
        }
    }
    return 0;
}
