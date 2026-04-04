#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
int a[405][405];

bool valid(int r, int c){
    return r>=1 && r<=n && c>=1 && c<=n && a[r][c] == -1;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    memset(a, -1, sizeof(a));

    queue<tuple<int,int,int>> q;
    q.push({1,1,0});
    a[1][1] = 0;

    while(q.size()){
        auto [r,c,step] = q.front();
        q.pop();

        for(int i=1; i<=n; i++){
            int x = r - i;
            int y_y = m - x*x;
            int y = sqrt(y_y);
            if(y*y == y_y){
                if(valid(i,c+y)){
                    a[i][c+y] = step+1;
                    q.push({i,c+y, step+1});
                }
                if(valid(i,c-y)){
                    a[i][c-y] = step+1;
                    q.push({i,c-y, step+1});
                }
            }
                
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }




    
}
