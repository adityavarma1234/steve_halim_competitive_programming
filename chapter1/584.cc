#include<bits/stdc++.h>

using namespace std;
vector<string> scores;
string inscore;

int vscore(string a)
{
    char b = a[0];
    if(b >= '0' && b<='9')
        return b-'0';
    if(b=='/')
        return 9;
    return 10;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while(1)
    {
        getline(cin, inscore);
        if(inscore[0] == 'G')
        {
            break;
        }
        istringstream iss(inscore);
        string token;
        scores.clear();
        while (getline(iss, token, ' '))
        {
            scores.push_back(token);
        }
        int frames = 0, ans = 0;
        for(int i =0;i<scores.size(); i++)
        {
            if(frames == 10) break;
            if(scores[i] == "X")
            {
                if(scores[i+2] != "/")
                    ans += 10 + vscore(scores[i+1]) + vscore(scores[i+2]);
                else
                    ans += 20;
                frames++;
            }
            else if(scores[i+1] == "/")
            {
                ans += 10 + vscore(scores[i+2]);
                frames++;
                i++;
            }
            else
            {
                ans += vscore(scores[i]) + vscore(scores[i+1]);
                frames++;
                i++;
            }
        }
//        for(int i=0;i<scores.size(); i++)
//            cout << scores[i] << " " ;
//        cout << endl;
        cout << ans << endl;
    }
    return 0;
}
