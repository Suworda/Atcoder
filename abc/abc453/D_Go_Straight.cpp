#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long 

int dr[] = {1,0,-1,0};
int dc[] = {0,-1,0,1};
int h,w;
pair<int,int> S,G;
char a[1005][1005];
int vis[1005][1005][4];
int dp[1005][1005][4];
tuple<int,int,int> pre[1005][1005][4];
string change = "DLUR";

void print(int r, int c, int ty, int th){
    cout<<"Yes\n";
    string ans;

    while(make_pair(r,c) != S){
        ans += change[ty];
        tie(r,c,ty) = pre[r][c][ty];
    }

    reverse(ans.begin(), ans.end());
    cout<<ans<<'\n';

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>h>>w;

    for(int i=0; i<=h+1; i++){
        for(int j=0; j<4; j++){
            vis[i][0][j] = 1;
            vis[i][w+1][j] = 1;
        }
    }
    for(int i=0; i<=w+1; i++){
        for(int j=0; j<4; j++){
            vis[0][i][j] = 1;
            vis[h+1][i][j] = 1;
        }
    }

    memset(vis, -1, sizeof(vis));
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin>>a[i][j];
            if(a[i][j] == 'S'){
                S = {i,j};
                a[i][j] = '.';
            }

            if(a[i][j] == 'G'){
                G = {i,j};
                a[i][j] = '.';
            }

            if(a[i][j] != '#') for(int k=0; k<4; k++) vis[i][j][k] = 0;
        }
    }

    queue<tuple<int,int,int,int>> q;
    q.push({S.first, S.second, 0, 1});

    while(q.size()){
        auto [r,c,ty,th] = q.front();
        q.pop();

        if(make_pair(r,c) == G){
            print(r,c,ty,th);
            return 0;
            break;
        }

        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(a[r][c] == 'o' && i != ty) continue;
            if(a[r][c] == 'x' && i == ty) continue;

            // if(a[nr][nc] == '.'){
            //     if(!vis[nr][nc][0]){
            //         q.push({nr,nc,0,th+1});
            //         pre[nr][nc][0] = {r,c,0};
            //         // dp[nr][nc][i] = th+1;
            //         vis[nr][nc][0] = 1;
            //     }

            // }else 
            if(a[nr][nc] != '#'){
                if(!vis[nr][nc][i]){
                    q.push({nr,nc,i,th+1});
                    pre[nr][nc][i] = {r,c,ty};
                    // dp[nr][nc][i] = th+1;
                    vis[nr][nc][i] = 1;
                }
            }
        }
    }

    cout<<"No\n";
}
