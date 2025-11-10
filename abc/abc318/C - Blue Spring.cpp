#include <bits/stdc++.h>>
using namespace std;

#define int long long

signed main(){
    int n,d,p;
    cin>>n>>d>>p;
    int f[n];

    int ans=0;
    for(int i=0; i<n; i++){
        cin>>f[i];
        ans+=f[i];
    }
    sort(f, f+n, greater<int>());

    for(int i=0; i<n; i+=d){
        int cur=0;
        for(int j=i; j<min(i+d,n); j++){
            //cout<<j<<' ';
            cur+=f[j];
        }

        if(p<cur){
            ans-=(cur-p);
        }
        //cout<<'\n';
    }

    cout<<ans<<'\n';

}

/*
3
7 1 3
8 6 4 4 4 1 7
*/
