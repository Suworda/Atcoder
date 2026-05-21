#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
vector<pair<int,int>> nxt[1005];
bool vis[1005][1005];
int ans1 = 2e9;
int ans2 = 2e9;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a,b;
        char c;
        cin>>a>>b>>c;
        nxt[a].push_back({b,c});
        nxt[b].push_back({a,c});
    }

    queue<tuple<int,int,int>> q;
    q.push({1,n,0});
    // int test = 100;
    while(q.size()){
        auto [s,t,step] = q.front();
        q.pop();

        if(s == t) ans1 = min(ans1, step*2);

        // cout<<s<<' '<<t<<' '<<step<<'\n';

        for(auto &[v1,c1]: nxt[s]){
            for(auto &[v2,c2]: nxt[t]){
                if(c1 == c2){
                    if(v1 == t || v2 == s) ans2 = min(ans2, step*2+1);
                    
                    if(!vis[v1][v2]){
                        vis[v1][v2] = 1;
                        q.push({v1,v2,step+1});
                    } 

                }
            }
        }
    }

    int ans = min(ans1, ans2);
    cout << (ans != 2e9 ? ans : -1) << '\n';
    // cout<<ans1<<'\n';
    // cout<<ans2<<'\n';

    
}
