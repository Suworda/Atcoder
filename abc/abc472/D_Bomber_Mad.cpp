#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};
int h,w,k;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>h>>w>>k;
    vector<vector<char>> a(h+2, vector<char>(w+2,0));
    bitset<500005> safe_r;
    bitset<500005> safe_c;
    safe_r.set();
    safe_c.set();

    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin>>a[i][j];
            if(a[i][j] == '#'){
                safe_r[i] = 0;
                safe_c[j] = 0;
            }
        }
    }

    
    queue<tuple<int,int,int>> q;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            if(safe_r[i] && safe_c[j]){
                a[i][j] = 'O';
                q.push({i,j,0});
            }
        }   
    }
    
    int ans = 0;
    while(q.size()){
        auto [r,c,step] = q.front(); q.pop();
        ans++;
        for(int i=0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(step+1 <= k && a[nr][nc] == '.'){
                q.push({nr,nc,step+1});
                a[nr][nc] = 'O';
            }
        }
        
    }

    cout << ans << '\n';



    
} 