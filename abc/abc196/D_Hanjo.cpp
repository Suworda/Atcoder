#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int h,w,a,b;
bool used[20][20];
int ans = 0;

void dfs(int r, int c){
    if(r == h+1){
        ans++;
        return;
    }
    if(c == w+1){
        dfs(r+1,1);
        return;
    }
    if(used[r][c]){
        dfs(r, c+1);
        return;
    }
    

    if(b){
        b--;
        dfs(r,c+1);
        b++;
    }

    if(a){
        a--;
        if(c+1 <= w){
            dfs(r,c+2);

        }

        if(r+1 <= h){
            used[r+1][c] = 1;
            dfs(r,c+1);
            used[r+1][c] = 0;
        }
        a++;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>h>>w>>a>>b;
    dfs(1,1);
    
    cout<<ans<<'\n';
}
