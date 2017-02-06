#include<bits/stdc++.h>
using namespace std;
struct records
{
    int team;
    int time;
    int solved;
};
struct record
{
    int team;
    char status;
    int time;
    char problem;
};
vector<records> v;
vector<record> in;
int teamscore[26][7];
int solvedproblems[26][7];
int attemptteams[26];
bool compare(records a, records b)
{
    if(a.solved > b.solved)
        return true;
    if(a.solved < b.solved)
        return false;
    if(a.time > b.time)
        return false;
    if(a.time < b.time)
        return true;
    if(a.team < b.team)
        return true;
    return false;

}
bool c(record a, record b)
{
    if(a.time > b.time)
        return false;
    return true;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string tmp;
    int t;
    cin >> t;
    getline(cin, tmp);
    getline(cin, tmp);
    while(t--)
    {
        v.clear();
        in.clear();
        for(int i=0; i<26; i++)
        {
            for(int j=0; j<7; j++)
            {
                teamscore[i][j] = 0;
                solvedproblems[i][j] = 0;
            }
            attemptteams[i] = 0;
        }

        int cnt,team,time, hour,minutes;
        char problemsolved,status;
        int n = 0;
        while(getline(cin, tmp) && tmp!="")
        {
//        cout << "in "<< tmp << endl;
            istringstream ss(tmp);
            cnt = 0;
            while(getline(ss, tmp, ' '))
            {
                if(cnt == 0)
                {
                    team = atoi(tmp.c_str());
                    n = max(n, team);
//                cout << "team " << team << endl;
                }
                if(cnt == 1)
                {
                    problemsolved = tmp[0];
//                cout << "attempmt " << problemsolved << endl;
                }
                if(cnt == 2)
                {
                    string asdf;
                    asdf = tmp;
                    istringstream sa(asdf);
                    string x;
                    int icnt = 0;
                    while(getline(sa, x, ':'))
                    {
                        if(icnt == 0)
                            hour = atoi(x.c_str());
                        if(icnt == 1)
                            minutes= atoi(x.c_str());
                        icnt++;
                    }
                    time = hour*60 + minutes;
//                cout << "time " << time << endl;
                }
                if(cnt == 3)
                {
                    status = tmp[0];
//                cout << "status " << status << endl;
                }
                cnt++;
            }
            record rr;
            rr.time = time;
            rr.problem = problemsolved;
            rr.status = status;
            rr.team = team;
            in.push_back(rr);
        }
        sort(in.begin(), in.end(), c);
        for(int i=0; i<in.size(); i++)
        {
            problemsolved = in[i].problem;
            team = in[i].team;
            status = in[i].status;
            time = in[i].time;
            if(status=='Y' && solvedproblems[team][problemsolved-'A'] == 0)
            {
//            cout << "solved " << team << " " << problemsolved-'A' << " " << teamscore[team][problemsolved-'A'] + time << endl;
                attemptteams[team] = 1;
                teamscore[team][problemsolved-'A'] += time;
                solvedproblems[team][problemsolved-'A'] = 1;
            }
            else if(status == 'N' && solvedproblems[team][problemsolved-'A'] == 0)
            {
//            cout << "not solved " << team << " " <<  problemsolved-'A' << " " << teamscore[team][problemsolved-'A'] + 20 << endl;
                attemptteams[team] = 1;
                teamscore[team][problemsolved-'A'] += 20;
            }
        }
        records r;
        for(int i=1; i<n+1; i++)
        {
//            if(attemptteams[i])
            {
                r.team = i;
                r.time = 0;
                r.solved = 0;
                int cnt = 0;
                for(int j=0; j<7; j++)
                {
                    if(solvedproblems[i][j])
                    {
//                        cout << "team " << i << " solved" << j << endl;
                        cnt++;
                        r.time += teamscore[i][j];
                    }
                }
                r.solved = cnt;
                v.push_back(r);
            }
        }
        sort(v.begin(), v.end(), compare);
        int ranking = 1;
        cnt = 0;
        r = v[0];
        cout << "RANK" << " TEAM" << " PRO/SOLVED" << " TIME" << endl;
        for(int i=0; i<v.size(); i++)
        {
            if(r.solved == v[i].solved && r.time == v[i].time)
            {
                cnt++;
            }
            else
            {
                ranking += cnt;
                cnt = 1;
            }
            if(v[i].solved)
                printf("%4d %4d %4d%11d\n", ranking, v[i].team, v[i].solved, v[i].time);
            else
                printf("%4d %4d\n",ranking, v[i].team);
            r = v[i];
        }
            if(t) cout << endl;
    }
}

