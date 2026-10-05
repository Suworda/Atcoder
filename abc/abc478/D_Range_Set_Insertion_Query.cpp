#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,Q;
int a[200005];
int cnt[200005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>Q;

    vector<pair<int,int>> q;
    for(int i=1; i<=Q; i++){
        int l, r, x;
        cin>>l>>r>>x;
        q.push_back({l,+x});
        q.push_back({r+1,-x});
    }

    sort(q.begin(), q.end());

    // for(auto [p,x]: q) cerr << p << ' ' << x << '\n';
    
    int id = 0;
    int ans = 0;
    for(int i=1; i<=n; i++){
        while(id < 2*Q && i == q[id].first){
            int x = q[id].second;
            if(x > 0){
                if(cnt[x] == 0) ans++;
                cnt[x]++;
            }
            else{
                x = -x;
                cnt[x]--;
                if(cnt[x] == 0) ans--;
            }
            id++;
        }
        cout << ans << ' ';
    }
} 