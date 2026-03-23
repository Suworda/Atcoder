#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int q;
multiset<int> l;
queue<int> r;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>q;
    while(q--){
        int ty;
        cin>>ty;
        if(ty == 1){
            int x;
            cin>>x;
            r.push(x);

        }else if(ty == 2){
            if(l.empty()){
                cout<<r.front()<<'\n';
                r.pop();
            }else{
                cout<<*(l.begin())<<'\n';
                l.erase(l.begin());
            }
            
        }else{
            while(r.size()){
                l.insert(r.front());
                r.pop();
            }

        }
    }

}