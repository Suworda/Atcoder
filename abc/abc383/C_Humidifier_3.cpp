#include <bits/stdc++.h>
using namespace std;

int h,w,d;
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};
char G[1005][1005];
int dis[1005][1005];

bool valid(int r, int c){
    return r>=0 && r<h && c>=0 && c<w && G[r][c]=='.'; 
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    cin>>h>>w>>d;
    int ans=0;
    queue<pair<int,int>> que;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>G[i][j];
            if(G[i][j] == 'H'){
                ans++;
                que.push({i,j});
            }
        }
    }

    while(!que.empty()){
        auto [r,c] = que.front();
        que.pop();
        if(dis[r][c]==d) continue;

        for(int i=0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(valid(nr,nc)){
                que.push({nr,nc});
                G[nr][nc] = '#';
                ans++;
                dis[nr][nc] = dis[r][c]+1;
            }
        }
    }

    // for(int i=0; i<h; i++){
    //     for(int j=0; j<w; j++){
    //         cout<<G[i][j];
    //     }
    //     cout<<'\n';
    // }
    cout<<ans<<'\n';

    
}