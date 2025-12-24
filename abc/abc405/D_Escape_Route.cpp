#include <bits/stdc++.h>
using namespace std;


int dr[]={+1,-1,0,0};
int dc[]={0,0,+1,-1};
int n,m;
char a[1005][1005];

bool valid(int r, int c){
    return r>=0 && r<n && c>=0 && c<m && a[r][c]=='.';
}

void draw(int r, int c, int dir){
    if(dir == 0) a[r][c] = '^';
    if(dir == 1) a[r][c] = 'v';
    if(dir == 2) a[r][c] = '<';
    if(dir == 3) a[r][c] = '>';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
            if(a[i][j] == 'E') {
                q.push({i,j});
            }
        }
    }

    while(q.size()){
        auto [r,c] = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(valid(nr,nc)){
                draw(nr,nc,i);
                q.push({nr,nc});
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