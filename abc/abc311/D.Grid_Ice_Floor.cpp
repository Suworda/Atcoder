#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};
int n,m;
char a[205][205];
bool vis[205][205][4];
bool passed[205][205];

void dfs(int r, int c, int dir){
    if(vis[r][c][dir] || a[r][c] == '#') return;
    vis[r][c][dir] = 1;
    passed[r][c] = 1;

    int nr = r + dr[dir];
    int nc = c + dc[dir];
    if(a[nr][nc] == '.') dfs(nr, nc, dir);
    else{
        int nr2 = r+dr[(dir+1)%4];
        int nc2 = c+dc[(dir+1)%4];
        int nr3 = r+dr[(dir+3)%4];
        int nc3 = c+dc[(dir+3)%4];
        if(a[nr2][nc2] == '.') dfs(nr2, nc2, (dir+1)%4);
        if(a[nr3][nc3] == '.') dfs(nr3, nc3, (dir+3)%4);
    }

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>a[i][j];
        }
    }

    for(int i=0; i<4; i++) dfs(2,2,i);
    
    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            ans += passed[i][j];
        }
    }

    cout<<ans<<'\n';
}
