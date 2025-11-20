#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<string,int> cnt;
    int n;
    cin>>n;
    string s;
    for(int i=0; i<n; i++){
        cin>>s;
        cnt[s]++;

        if(cnt[s]==1) cout<<s<<'\n';
        else cout<<s<<'('<<cnt[s]-1<<')'<<'\n';
    }
}
