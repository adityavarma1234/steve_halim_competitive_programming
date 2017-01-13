#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        v.clear();
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        if(n==1) {
            cout << 0 << endl;
        }
        else{
            cout << (v[n-1] - v[0])* 2 << endl;
        }
    }
    return 0;
}
