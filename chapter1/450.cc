#include<bits/stdc++.h>
using namespace std;
struct records
{
    string title, firstname, lastname, address, homephone, workphone,campusmailbox,department;
};
bool compare(records a, records b)
{
    if(a.lastname < b.lastname )
        return true;
    return false;
}
vector<records> v;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    string tmp;
    getline(cin,tmp);
    while(n--)
    {
        getline(cin, tmp);
//        cout << "department " << tmp << endl;
        string dtitle = tmp;
        records vv;
        while(getline(cin, tmp) && tmp!="")
        {
//            cout << "records "<< tmp << endl;
            istringstream ss(tmp);
            int cnt=0;
            while(getline(ss, tmp, ','))
            {
                if(cnt == 0)
                {
                    vv.title = tmp;
                }
                if(cnt == 1)
                {
                    vv.firstname = tmp;
                }
                if(cnt == 2)
                {
                    vv.lastname = tmp;
                }
                if(cnt == 3)
                {
                    vv.address = tmp;
                }
                if(cnt == 4)
                {
                    vv.homephone = tmp;
                }
                if(cnt == 5)
                {
                    vv.workphone = tmp;
                }
                if(cnt == 6)
                {
                    vv.campusmailbox = tmp;
                }
                cnt++;
            }
            vv.department = dtitle;
            v.push_back(vv);
        }
    }
    sort(v.begin(), v.end(), compare);
    for(int i=0; i<v.size(); i++)
    {
        cout << "----------------------------------------" << endl;
        cout << v[i].title << " " << v[i].firstname << " "<< v[i].lastname << endl;
        cout << v[i].address << endl;
        cout << "Department: " << v[i].department << endl;
        cout << "Home Phone: " << v[i].homephone << endl;
        cout << "Work Phone: " << v[i].workphone << endl;
        cout << "Campus Box: " << v[i].campusmailbox << endl;
    }
    return 0;
}
