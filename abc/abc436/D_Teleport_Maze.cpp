#include <bits/stdc++.h>
using namespace std;

int h,w;       
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
char s[1005][1005];
int dis[1005][1005];
bool tried[128];

vector<pair<int,int>> edge[128];

bool valid(int x, int y){
    return x>=1 && x<=h && y>=1 && y<=w && s[x][y] != '#';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i=0; i<=1000; i++){
        for(int j=0; j<=1000; j++){
            dis[i][j]=-1;
        }
    }
    
    cin>>h>>w;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin>>s[i][j];
            char c = s[i][j];
            if('a' <= c && c <= 'z'){
                edge[c].push_back({i,j});
            }
        }
    }
    
    queue<pair<int,int>> que;
    que.push({1,1});
    dis[1][1]=0;
    
    while(!que.empty()){
        auto [x,y] = que.front();
        que.pop();
        //cout<<x<<' '<<y<<'\n';
        
        if(x == h && y == w){
            cout<<dis[x][y]<<'\n';
            return 0;
        }
        
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(valid(nx,ny) && dis[nx][ny] == -1){
                que.push({nx,ny});
                dis[nx][ny] = dis[x][y]+1;
            }
        }

        char c = s[x][y];
        if('a' <= c && c <= 'z' && !tried[c]){
            for(auto next: edge[c]){
                auto [nx,ny] = next;
                if(dis[nx][ny] == -1){
                    que.push({nx,ny});
                    dis[nx][ny] = dis[x][y]+1;
                }
            }
            tried[c] = true;
        }

        
    }

    cout<<-1<<'\n';

}