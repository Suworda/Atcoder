#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int M = 998244353;
int first = 0;
string s{'1'}, t{'1'};
int rst[10][600005];

void mod(){
    if(s.size() < 9) return;

    ll x = stoll(s);
    x += M;
    x %= M;
    s = to_string(x);
}

void deduct(){
    ll x = stoll(s);
    x -= rst[t[first]-'0'][t.size()-first-1];
    x += M;
    x %= M;
    s = to_string(x);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i=0; i<10; i++){
        int x = i;
        for(int j=0; j<600005; j++){
            rst[i][j] = x;
            x *= 10;
            x %= M;
        }
    }
    int q;
    cin>>q;
    while(q--){
        int ty;
        cin>>ty;
        if(ty == 1){
            char c;
            cin>>c;
            s += c;
            t += c;
            mod();
        }else if(ty == 2){
            deduct();
            first++;
        }else{
            cout<<s<<'\n';
        }
    }
    
}
