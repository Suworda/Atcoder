#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
vector<pair<int,char>> Snxt[105], Tnxt[105];
bool vis[105][105];
int dis[105][105];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    queue<pair<int,int>> q;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i != j) dis[i][j] = 2e9;
        }
        vis[i][i] = 1;
        q.push({i,i});
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            char c;
            cin>>c;
            if(c != '-'){
                Snxt[j].push_back({i,c});
                Tnxt[i].push_back({j,c});
                if(i != j){
                    dis[i][j] = 1;
                    vis[i][j] = 1;
                    q.push({i,j});
                }
            }
        }
    }

    while(q.size()){
        auto [s,t] = q.front();
        q.pop();
        for(auto [v1,c1]: Snxt[s]){
            for(auto [v2,c2]: Tnxt[t]){
                if(c1 == c2){
                    if(!vis[v1][v2]){
                        dis[v1][v2] = dis[s][t] + 2;
                        vis[v1][v2] = 1;
                        q.push({v1,v2});
                    }
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dis[i][j] == 2e9) cout<<-1<<' ';
            else cout<<dis[i][j]<<' ';
        }
        cout<<'\n';
    }
    
}
