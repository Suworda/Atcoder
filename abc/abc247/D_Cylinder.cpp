#include <bits/stdc++.h>
using namespace std;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    queue<pair<int,int>> que;
    int q;
    cin>>q;
    while(q--){
        int ty;
        cin>>ty;
        if(ty==1){
            int x,c;
            cin>>x>>c;
            que.push({x,c});
        }else{
            long long ans=0;
            int c;
            cin>>c;
            while(c){
                auto [x,cnt] = que.front();
                ans += 1LL*x * min(c,cnt);
                if(c < cnt){
                    que.front().second -= c;
                    c=0;
                }else{
                    c -= cnt;
                    que.pop();
                }
            }
            cout<<ans<<'\n';
        }
    }

}