#include <bits/stdc++.h>
using namespace std;

int n;
int ans[101][101];

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>n;
    int r=0, c=(n-1)/2;
    ans[r][c]=1;
    int k = 2;
    while(k <= n*n){
        //cout<<r<<' '<<c<<'\n';
        if(ans[((r-1)%n+n)%n][(c+1)%n] == 0){
            ans[((r-1)%n+n)%n][(c+1)%n]=k;
            r = ((r-1)%n+n)%n;
            c = (c+1)%n;

        }else{
            ans[(r+1)%n][c]=k;
            r = (r+1)%n;
        }
        k++;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }
}