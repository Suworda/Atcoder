#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,h,w;
int a[10], b[10];
bool A[15][15];
bitset<10> used;

bool in(int r, int c){
    return r>=1 && r<=h && c>=1 && c<=w;
}

bool valid(int r, int c, int id, int ty){
    bool rst = 1;
    if(ty == 1){
        for(int i=r; i<r+a[id]; i++){
            for(int j=c; j<c+b[id]; j++){
                if(!in(i,j) || A[i][j]) rst = 0;
            }
        }

    }else{
        for(int i=r; i<r+b[id]; i++){
            for(int j=c; j<c+a[id]; j++){
                if(!in(i,j) || A[i][j]) rst = 0;
            }
        }
    }

    return rst;
}

void place(int r, int c, int id, int ty){
    if(ty == 1){
        for(int i=r; i<r+a[id]; i++){
            for(int j=c; j<c+b[id]; j++){
                A[i][j] = 1;
            }
        }

    }else{
        for(int i=r; i<r+b[id]; i++){
            for(int j=c; j<c+a[id]; j++){
                A[i][j] = 1;
            }
        }
    }
}

void rm(int r, int c, int id, int ty){
    if(ty == 1){
        for(int i=r; i<r+a[id]; i++){
            for(int j=c; j<c+b[id]; j++){
                A[i][j] = 0;
            }
        }

    }else{
        for(int i=r; i<r+b[id]; i++){
            for(int j=c; j<c+a[id]; j++){
                A[i][j] = 0;
            }
        }
    }
}

void check(){
    bool rst = 1;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            if(!A[i][j]) rst = 0;
        }
    }

    if(rst){
        cout<<"Yes\n";
        exit(0);
    }
}

void dfs(int r, int c){
    // cerr<<r<<' '<<c<<'\n';
    if(r > h){
        check();
        return;
    }
    if(c > w){
        dfs(r+1, 1);
        return;
    }
    if(A[r][c]){
        dfs(r, c+1);
        return;
    }

    // for(int i=1; i<=h; i++){
    //     for(int j=1; j<=w; j++){
    //         cerr<<A[i][j]<<' ';
    //     }
    //     cerr<<'\n';
    // }
    // cerr<<'\n';

    for(int i=1; i<=n; i++){
        if(!used[i] && valid(r,c,i,1)){
            used[i] = 1;
            place(r,c,i,1);
            dfs(r, c+1);
            rm(r,c,i,1);
            used[i] = 0;
        }
        if(!used[i] && valid(r,c,i,2)){
            used[i] = 1;
            place(r,c,i,2);
            dfs(r, c+1);
            rm(r,c,i,2);
            used[i] = 0;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>h>>w;
    for(int i=1; i<=n; i++){
        cin>>a[i]>>b[i];
    }

    dfs(1,1);

    cout<<"No\n";

}