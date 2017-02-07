#include<bits/stdc++.h>
using namespace std;
struct team{
    string name;
    int gamesplayed, totalpoints, wins, ties, losses, goalsscored, goalsagainst,goaldiff;
};
vector<team> v;
map<string, int> ma;
bool compare(team a, team b)
{
    if(a.totalpoints > b.totalpoints)
        return true;
    if(a.totalpoints < b.totalpoints)
        return false;
    if(a.wins > b.wins)
        return true;
    if(a.wins < b.wins)
        return false;
    if(a.goaldiff > b.goaldiff)
        return true;
    if(a.goaldiff < b.goaldiff)
        return false;
    if(a.goalsscored > b.goalsscored)
        return true;
    if(a.goalsscored < b.goalsscored)
        return false;
    if(a.gamesplayed > b.gamesplayed)
        return false;
    if(a.gamesplayed < b.gamesplayed)
        return true;
    string ta,tb;
    ta = a.name;tb= b.name;
    transform(ta.begin(),ta.end(), ta.begin(),::tolower );
    transform(tb.begin(),tb.end(), tb.begin(),::tolower );
    if(ta > tb)
        return false;
    return true;
}
bool similar(team a, team b)
{
    if(a.totalpoints == b.totalpoints && a.wins == b.wins && a.goaldiff == b.goaldiff && a.goalsscored == b.goalsscored && a.gamesplayed == b.gamesplayed )
        return true;
    return false;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
//    cout << t << endl;
    string asdf;
    getline(cin, asdf);
    while(t--)
    {
        v.clear();
        ma.clear();
        team f;
        string tournament,tmp;
        getline(cin, tournament);
//        cout << "tournament " << tournament << endl;
        int n;
        cin >> n;
        getline(cin,asdf);
//        cout << "n " << n << endl;
        for(int i=0;i<n;i++)
        {
            getline(cin, tmp);
//            cout << "team " << tmp << endl;
            ma[tmp] = i;
            f.name = tmp;
            f.gamesplayed = 0;
            f.totalpoints = 0;
            f.wins = 0;
            f.ties = 0;
            f.losses = 0;
            f.goalsscored = 0;
            f.goalsagainst = 0;
            f.goaldiff = 0;
            v.push_back(f);
        }
        int m;
        cin >> m;
        getline(cin, asdf);
//        cout << "games "<< m << endl;
        for(int i=0;i<m;i++)
        {
            getline(cin, tmp);
//            cout << tmp << endl;
            istringstream ss(tmp);
            string token;int cnt = 0;
            string team1, team2, goals;
            int goal1, goal2;
            while(getline(ss, token, '#'))
            {
                if(cnt == 0)
                {
                    team1 = token;
                }
                if(cnt == 1)
                {
                    goals = token;
                    istringstream sa(token);
                    string goal;
                    int cnt1 =0;
                    while(getline(sa, goal, '@'))
                    {
                        if(cnt1 == 0)
                        {
                            goal1 = atoi(goal.c_str());
                        }
                        if(cnt1 == 1)
                        {
                            goal2 = atoi(goal.c_str());
                        }
                        cnt1++;
                    }
                }
                if(cnt == 2)
                {
                    team2 = token;
                }
                cnt++;
            }
//            cout << team1 << " " << goal1 << " " << team2 << " " << goal2 << endl;
            int team1ind = ma[team1];
            int team2ind = ma[team2];
            v[team1ind].goalsagainst += goal2;
            v[team2ind].goalsagainst += goal1;
            v[team1ind].gamesplayed++;
            v[team2ind].gamesplayed++;
            v[team1ind].goalsscored += goal1;
            v[team2ind].goalsscored += goal2;
            v[team1ind].goaldiff = v[team1ind].goalsscored - v[team1ind].goalsagainst;
            v[team2ind].goaldiff = v[team2ind].goalsscored - v[team2ind].goalsagainst;
            if(goal1 > goal2)
            {
                v[team1ind].wins++;
                v[team2ind].losses++;
                v[team1ind].totalpoints += 3;
            }
            if(goal2 > goal1)
            {
                v[team2ind].wins++;
                v[team1ind].losses++;
                v[team2ind].totalpoints += 3;
            }
            if(goal1 == goal2)
            {
                v[team1ind].ties++;
                v[team2ind].ties++;
                v[team1ind].totalpoints += 1;
                v[team2ind].totalpoints += 1;
            }
        }
        sort(v.begin(),v.end(),compare);
        int ranking=1,c=0;
        team prev= v[0];
        cout << tournament << endl;
        for(int i=0;i<v.size();i++)
        {
//            if(similar(prev, v[i]))
//            {
//                c++;
//            }
//            else
//            {
//                ranking+= c;
//                c = 1;
//            }
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", i+1, v[i].name.c_str(), v[i].totalpoints, v[i].gamesplayed, v[i].wins, v[i].ties, v[i].losses, v[i].goaldiff, v[i].goalsscored, v[i].goalsagainst);
            prev = v[i];
        }
        if(t) cout << endl;
    }
    return 0;
}
