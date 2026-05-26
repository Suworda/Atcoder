#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,q;
int cnt[600005];
int cnt2[600005];
int d;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>q;
    while(q--){
        int ty,x,y;
        cin>>ty;
        if(ty == 1){
            cin>>x;
            cnt[x]++;
            cnt2[cnt[x]]++;
            if(cnt2[cnt[x]] == n) d+=1;

        }else{
            cin>>y;

            cout<<cnt2[y+d]<<'\n';

        }

        
        // cout<<d<<'\n';
    }
}
