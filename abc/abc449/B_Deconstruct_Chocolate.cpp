#include <bits/stdc++.h>
using namespace std;

int h,w,q;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>h>>w>>q;
    while(q--){
        int ty;
        cin>>ty;
        if(ty == 1){
            int r;
            cin>>r;
            cout<<w*r<<'\n';
            h -= r;

        }else{
            int c;
            cin>>c;
            cout<<h*c<<'\n';
            w -= c;
        }
    }
    
}
