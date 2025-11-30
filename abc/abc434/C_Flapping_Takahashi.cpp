#include <bits/stdc++.h>
using namespace std;

void sol(){
    int n,h;
    cin>>n>>h;
    int t[n],l[n],u[n];

    for(int i=0; i<n; i++){
        cin>>t[i]>>l[i]>>u[i];
    }

    int cur_t=0,dt;
    int h1=h, h2=h; //h1<=h2
    for(int i=0; i<n; i++){
        dt=t[i]-cur_t;
        h1=max(h1-dt , l[i]);
        h2=min(h2+dt , u[i]);

        if(h2 < l[i] || h1 > u[i]){
            cout<<"No\n";
            return;
        }

        cur_t=t[i];
        // if(i==n-1) break;

        // if(l[i+1] >= u[i]){
        //     h = min(h+dt , l[i+1]);
        // }else if(u[i+1] <= l[i]){
        //     h = max(h-dt , u[i+1]);
        // }
    }

    cout<<"Yes\n";

}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) sol();

}