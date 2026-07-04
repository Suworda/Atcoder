#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int dp[2][10];
int n;
string s;

void upd(int id){
    int cur_id = id%2;
    int last_id = (id-1)%2;

    // ty == 0:
    dp[cur_id][0] = dp[last_id][0] + (s[id] == '1'); // 0
    dp[cur_id][3] = dp[last_id][0] + (s[id] == '0'); // 1

    //ty == 1:
    dp[cur_id][1] = dp[last_id][1] + (s[id] == '1'); // 0

    // ty == 2:
    dp[cur_id][2] = dp[last_id][2] + (s[id] == '1'); // 0

    // ty == 3:
    dp[cur_id][2] =  min(dp[cur_id][2], dp[last_id][3] + (s[id] == '1')); // 0
    dp[cur_id][3] =  min(dp[cur_id][3], dp[last_id][3] + (s[id] == '0')); // 1

    // ty == 4:
    dp[cur_id][4] = dp[last_id][4] + (s[id] == '1'); // 0

    // ty == 5:
    dp[cur_id][2] =  min(dp[cur_id][2], dp[last_id][5] + (s[id] == '1')); // 0
    dp[cur_id][5] = dp[last_id][5] + (s[id] == '0'); // 1

    // ty == 6:
    dp[cur_id][4] =  min(dp[cur_id][4], dp[last_id][6] + (s[id] == '1')); // 0
    dp[cur_id][6] = dp[last_id][6] + (s[id] == '0'); // 1
}

void sol(){
    cin>>n>>s;

    // for(int i=0; i<7; i++) dp[0][i] = 0;

    // s = ' ' + s;
    // for(int i=1; i<=n; i++){
    //     upd(i);
    // }

    // int ans = 2e9;
    // for(int i=0; i<7; i++){
    //     ans = min(ans, dp[n%2][i]);
    // }

    // cout<<ans<<'\n';


    
    //簡單的做法:
    int ty0 = 0, ty01 = 0, ty010 = 0;
    for(int i=0; i<n; i++){
        tie(ty0, ty01, ty010) = make_tuple(
            ty0 + (s[i] == '1'),
            min(ty0, ty01) + (s[i] == '0'),
            min(ty01, ty010) + (s[i] == '1')
        );
    }

    cout<<min({ty0, ty01, ty010})<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) sol();
    
}