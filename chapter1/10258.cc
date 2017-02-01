#include<bits/stdc++.h>
using namespace std;

int contestants[101][10];
int solvecontestants[101], acontestants[101];
int correctsolution[101][10];
pair<pair<int, int>, int> p;
vector<pair<pair<int, int>, int> > v;
bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    if(a.first.second > b.first.second)
        return true;
    if(a.first.second < b.first.second)
        return false;
    if(a.first.second == b.first.second)
    {
        if(a.second > b.second)
            return false;
        if(a.second < b.second )
            return true;
        if(a.second == b.second)
        {
            if(a.first.first > b.first.first)
            {
                return false;
            }
            else
                return true;
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string a;
    int t;
    cin >> t;
//    cout << t << endl;
    getline(cin, a);
    getline(cin, a);
    while(t--)
    {
        v.clear();
        int contest, problem, time;
        for(int i=0; i<101; i++)
            for(int j=0; j<10; j++)
                {
                    contestants[i][j] = 0;
                    correctsolution[i][j]=0;
                }
        for(int i=0; i<101; i++)
            {
                solvecontestants[i] = 0;
                 acontestants[i]=0;
            }

        string l;
        while(getline(cin, a) && a!="")
        {
//            cout << a << "here"<< endl;
            istringstream ss(a);
            int cnt = 0;
            while(1)
            {
                if(cnt == 0)
                    ss >> contest;
                if(cnt == 1)
                    ss >> problem;
                if(cnt == 2)
                    ss >> time;
                if(cnt == 3)
                    ss >> l;
                cnt++;
                if(cnt>=4) break;
            }
//            cout << contest << " " <<  problem << " " << time << " " << l << "there" <<endl;
            if(l == "C" && correctsolution[contest][problem] == 0)
            {
//                cout << "inside corect" << contest << " " <<  problem << " " << time << " " << l << "there" <<endl;

                correctsolution[contest][problem] = 1;
                contestants[contest][problem] += time;
                solvecontestants[contest]++;
            }
            else if(l == "I" && correctsolution[contest][problem] == 0)
            {
                contestants[contest][problem] += 20;
                acontestants[contest] = -1;
            }
            else
            {
                acontestants[contest] = -1;
            }
        }
        for(int i=0;i<101;i++)
        {
            if(solvecontestants[i])
            {
                p.first.first = i;
                int cnt = 0;
                p.first.second = solvecontestants[i];
                p.second = 0;
                for(int j=0;j<10;j++)
                {
                    if(contestants[i][j] && correctsolution[i][j])
                        {
                            p.second += contestants[i][j];
                        }
                }
                v.push_back(p);
            }
            else if(acontestants[i] == -1)
            {
                p.first.first = i;
                p.first.second = 0;
                p.second = 0;
                v.push_back(p);
            }
        }
        sort(v.begin(), v.end(),compare);
        for(int i=0;i<v.size();i++)
        {
            cout << v[i].first.first << " " << v[i].first.second << " " << v[i].second << endl;
        }
        v.clear();
        if(t) cout << endl;
    }
    return 0;
}
