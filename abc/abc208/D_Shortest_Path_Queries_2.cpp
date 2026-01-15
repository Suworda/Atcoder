#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
long long dis[405][405];
int n,m;

void init(){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i != j) dis[i][j] = INF;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    init();
    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        dis[a][b] = c;
    }

    long long ans=0;
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

                if(dis[i][j] < INF){
                    ans += dis[i][j];
                }
            }
        }
    }

    cout<<ans<<'\n';
    
}
