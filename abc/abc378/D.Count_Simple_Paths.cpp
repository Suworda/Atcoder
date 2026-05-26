#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};
int h,w,k;
char a[12][12];
bool vis[12][12];
ll ans;

bool valid(int r, int c){
    return !vis[r][c]&& a[r][c] == '.';
}

void dfs(int r, int c, int step){
    if(!valid(r,c)) return;
    
    if(step == k){
        ans++;
        return;
    }

    vis[r][c] = 1;
    for(int i=0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        dfs(nr,nc,step+1);
    }
    vis[r][c] = 0;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>h>>w>>k;
    for(int i=0; i<=h+1; i++){
        for(int j=0; j<=w+1; j++) a[i][j] = '#';
    }
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin>>a[i][j];
        }
    }

    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            dfs(i,j,0);
        }
    }
    
    cout<<ans<<'\n';
}
