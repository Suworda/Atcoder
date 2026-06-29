#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int cnt[128];

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    string s;
    cin>>s;
    for(char c: s) cnt[c]++;

    int mx = 0;
    for(int i=0; i<128; i++){
        mx = max(mx, cnt[i]);
    }
    for(int i=0; i<128; i++){
        if(cnt[i] == mx){
            if(i == 'W') cout<<"West"<<'\n';
            else cout<<"East\n";
        }
    }
    
}