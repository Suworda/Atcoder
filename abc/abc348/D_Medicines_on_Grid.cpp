#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int h,w;
int n;
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};
char G[205][205];
int a[205][205];
bool vis[205][205];
pair<int,int> s;

bool valid(int r, int c){
    return r>=1 && r<=h && c>=1 && c<=w && G[r][c] != '#';
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>h>>w;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin>>G[i][j];
            if(G[i][j] == 'S') s = {i,j};
        }
    }
    
    // memset(a, -1, sizeof(a));
    cin>>n;
    while(n--){
        int r, c, e;
        cin>>r>>c>>e;
        a[r][c] = e;
    }
    
    
    queue<tuple<int,int,int>> q;
    auto [x,y] = s;
    q.push({x, y, a[x][y]});
    while(q.size()){
        auto [r,c,e] = q.front();
        q.pop();

        if(G[r][c] == 'T'){
            cout<<"Yes\n";
            return 0;
        }

        if(e <= 0) continue;

        for(int i=0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(valid(nr,nc) && ((!vis[nr][nc] && a[nr][nc] != -1) || e-1 > a[nr][nc])){
                a[nr][nc] = max(a[nr][nc], e-1);
                q.push({nr,nc,a[nr][nc]});
                vis[nr][nc] = 1;
            }
        }
    }

    cout<<"No\n";


    

}