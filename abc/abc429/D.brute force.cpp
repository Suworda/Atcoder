#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long

signed main(){
    int n;
    long long m;
    int c;
    cin>>n>>m>>c;
    int cnt[m]={};
    int x;
    for(int i=0; i<n; i++){
        cin>>x;
        cnt[x]++;
    }

    int ans=0;
    int cur=0;
    int r=0;
    for(int l=0; l<m; l++){
        cur=0;
        r=l;
        while(cur<c){
            cur+=cnt[r];
            r++;
            if(r==m) r=0;
        }
        cout<<l<<' '<<cur<<'\n';
        ans+=cur;
    }

    cout<<ans<<'\n';


}

/*
10 60 3
1 1 2 8 15 15 15 15 46 55
*/
