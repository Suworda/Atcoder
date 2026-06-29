#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int dr[]={1,1,1,0,0,-1,-1,-1};
int dc[]={1,0,-1,1,-1,1,0,-1};
int n,m;
set<pair<int,int>> vis;
vector<string> a;

bool in(int r, int c){
    return r>=0 && r<n && c>=0 && c<m;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        a.push_back(s);
    }
    
    queue<tuple<int,int,int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == '#'){
                a[i][j] = '.';
                vis.insert({i,j});
                q.push({i,j,2});
            }
            else{
                a[i][j] = '#';
            }
        }
    }

    while(q.size()){
        auto [r,c,ty] = q.front();
        q.pop();

        if(ty == 1){
            for(int i=0; i<8; i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(in(nr,nc) && !vis.count({nr,nc})){
                    a[nr][nc] = '.';
                    vis.insert({nr,nc});
                    q.push({nr,nc,2});
                }
            }

        }else{
            for(int i=0; i<8; i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(in(nr,nc) && !vis.count({nr,nc})){
                    a[nr][nc] = '#';
                    vis.insert({nr,nc});
                    q.push({nr,nc,1});
                }
            }

        }
    }
    vis.clear();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == '#'){
                a[i][j] = '.';
                vis.insert({i,j});
                q.push({i,j,2});
            }
        }
    }

    while(q.size()){
        auto [r,c,ty] = q.front();
        q.pop();

        if(ty == 1){
            for(int i=0; i<8; i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(in(nr,nc) && !vis.count({nr,nc})){
                    a[nr][nc] = '.';
                    vis.insert({nr,nc});
                    q.push({nr,nc,2});
                }
            }

        }else{
            for(int i=0; i<8; i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(in(nr,nc) && !vis.count({nr,nc})){
                    a[nr][nc] = '#';
                    vis.insert({nr,nc});
                    q.push({nr,nc,1});
                }
            }

        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<a[i][j];
        }
        cout<<'\n';
    }

}
