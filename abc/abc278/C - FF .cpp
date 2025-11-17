#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,q;
    cin>>n>>q;
    set<pair<int,int>> st;

    int ty,x,y;
    for(int i=0; i<q; i++){
        cin>>ty>>x>>y;

        if(ty==1){
            st.insert({x,y});

        }else if(ty==2){
            st.erase({x,y});

        }else{
            cout << (st.count({x,y}) && st.count({y,x}) ? "Yes\n" : "No\n");
        }
    }

}
