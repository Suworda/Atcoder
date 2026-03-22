#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int dr[]={1, -1, 0, 0};
int dc[]={0, 0, 1, -1};
int h,w;
char a[1005][1005];
bool vis[1005][1005];

bool in(int r, int c){
    return r >=1 && r<=h && c >= 1 && c <= w;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>h>>w;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin>>a[i][j];
        }
    }

    int ans=0;

    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            bool ok=0;
            queue<pair<int,int>> q;
            if(a[i][j] == '.' && !vis[i][j]){
                ok = 1;
                vis[i][j] = 1;
                q.push({i,j});
            }

            while(q.size()){
                auto [r,c] = q.front();
                q.pop();
                for(int k=0; k<4; k++){
                    int nr = r+dr[k];
                    int nc = c+dc[k];
                    if(!in(nr, nc)) ok = 0;
                    else{
                        if(a[nr][nc] == '.' && !vis[nr][nc]){
                            vis[nr][nc] = 1;
                            q.push({nr,nc});
                        }
                    }
                }

            }
            ans += ok;
        }

    }

    cout<<ans<<'\n';


}
