#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,q;
int nxt[100005], pre[100005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>q;
    for(int i=0; i<=n; i++){
        nxt[i] = pre[i] = -1;
    }
    while(q--){
        int ty,x,y;
        cin>>ty;
        if(ty == 1){
            cin>>x>>y;
            nxt[y] = x;
            pre[x] = y;

        }else if(ty == 2){
            cin>>x>>y;
            pre[x] = -1;
            nxt[y] = -1;

        }else{
            cin>>x;
            while(nxt[x] != -1) x = nxt[x];

            vector<int> v;
            while(x != -1){
                v.push_back(x);
                x = pre[x];
            } 

            cout<<v.size()<<' ';
            for(int j: v) cout<<j<<' ';
            cout<<'\n';
        }
    }
    
}
