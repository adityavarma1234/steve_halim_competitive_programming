#include<bits/stdc++.h>

using namespace std;
bool pass,fail;
int h[26];
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int n,cnt=0;
    string ans,gue;
    while(1)
    {
        cin >> n;
        cnt++;
        pass=false;
        fail = false;
        for(int i=0; i<26; i++) h[i] = 0;
        if(n==-1)
            break;
        cin >> ans;
        for(int i=0; i<ans.size(); i++)
        {
            h[ans[i]-'a']++;
        }
        cin >> gue;
        int f = 0;
        int solved = 0;
        for(int i=0; i<gue.size(); i++)
        {
            if(h[gue[i]-'a'] == 0)
            {
                f++;
                h[gue[i]-'a'] = -1;
            }
            else
            {
                if(h[gue[i]-'a'] != -1)
                solved += h[gue[i]-'a'];
                h[gue[i]-'a'] = -1;
            }
            if(ans.size() == solved)
            {
                pass = true;
                break;
            }
            if(f == 7)
            {
                fail = true;
                break;
            }
        }
        cout << "Round " << n << endl;
        if(fail) cout << "You lose." << endl;
        else if(pass) cout << "You win." << endl;
        else cout << "You chickened out." << endl;
    }
    return 0;
}
