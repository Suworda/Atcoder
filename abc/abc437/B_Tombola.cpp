#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int h,w,n;
    cin>>h>>w>>n;
    int a[h][w];
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>a[i][j];
        }
    }

    int apr[100]={};
    while(n--){
        int x;
        cin>>x;
        apr[x]=1;
    }

    int ans=0;
    for(int i=0; i<h; i++){
        int cur=0;
        for(int j=0; j<w; j++){
            cur+=apr[a[i][j]];
        }
        ans = max(ans,cur);
    }

    cout<<ans<<'\n';

}