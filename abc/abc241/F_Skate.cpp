#include <bits/stdc++.h>
using namespace std;

#define int long long

map<int, set<int>> row, col;
map<pair<int,int>, int> cnt;
int ans = 2e9;
set<pair<int,int>> vis;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h,w,n;
    cin>>h>>w>>n;

    int sx,sy,gx,gy;
    cin>>sx>>sy>>gx>>gy;

    int X,Y;
    for(int i=0; i<n; i++){
        cin>>X>>Y;
        row[X].insert(Y);
        col[Y].insert(X);
    }

    queue<pair<int,int>> que;
    que.push({sx,sy});
    vis.insert({sx,sy});
    while(!que.empty()){
        auto [x,y] = que.front();
        que.pop();
        //cout<<x<<' '<<y<<'\n';

        if(x == gx && y == gy){
            ans = cnt[{x,y}];
            break;
        }

        auto it = row[x].upper_bound(y);
        if(it != row[x].end()){
            int ny = *it-1;
            if(!vis.count({x,ny})){
                que.push({x, ny});
                cnt[{x,ny}] = cnt[{x,y}]+1;
                vis.insert({x,ny});
            }

        }
        if(it != row[x].begin()){
            int ny = *prev(it)+1;
            if(!vis.count({x,ny})){
                que.push({x, ny});
                cnt[{x,ny}] = cnt[{x,y}]+1;
                vis.insert({x,ny});
            }
        }

        it = col[y].upper_bound(x);
        if(it != col[y].end()){
            int nx = *it-1;
            if(!vis.count({nx,y})){
                que.push({nx, y});
                cnt[{nx,y}] = cnt[{x,y}]+1;
                row[y].insert(nx);
                vis.insert({nx,y});
            }

        }
        if(it != col[y].begin()){
            int nx = *prev(it)+1;
            if(!vis.count({nx,y})){
                que.push({nx, y});
                cnt[{nx,y}] = cnt[{x,y}]+1;
                row[y].insert(nx);
                vis.insert({nx,y});
            }
        }
        
    }
    
    if(ans == 2e9) cout<<-1<<'\n';
    else cout<<ans<<'\n';
}