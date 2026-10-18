#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
string s[105];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<string, int> cnt;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>s[i];
        string x = s[i];
        cnt[x] = 0;
    }

    while(m--){
        string t;
        cin>>t;
        int cur_cnt = 0;
        if(cnt.find(t) != cnt.end()){
            cnt[t]++;
            continue;
        }

        string y;
        for(int i=0; i<t.size(); i++){
            string x = t;
            for(int j='a'; j<='z'; j++){
                x[i] = char(j);
                cur_cnt += (cnt.find(x) != cnt.end());
                if(cnt.find(x) != cnt.end()) y = x;
                // cerr << x << '\n';
            }
        }
        
        // cout << cur_cnt << ' ' << y << '\n';
        // if(y == "takahashi") cout << "?";
        if(cur_cnt == 1) cnt[y]++;
    }

    
    for(int i=0; i<n; i++){
        cout << cnt[s[i]] << '\n';
    }
    // cout << "return 0";

} 