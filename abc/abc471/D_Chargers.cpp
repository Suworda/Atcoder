#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int q,v;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>q>>v;
    priority_queue<pair<int,int>> pq;
    while(q--){
        int ty;
        cin>>ty;
        if(ty == 1){
            int t,w;
            cin>>t>>w;
            pq.push({w-t, t});
        }
        else{
            int t;
            cin>>t;
            if(pq.empty()){
                cout << -1 << '\n';
                continue;
            }
            auto [x,y] = pq.top(); pq.pop();

            cout << min(v,x+y+(t-y)) << '\n';
        }
    }
    
} 