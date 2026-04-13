#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

string s,t;
int n,m;
int nxt[200005][30];
ll ans;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>s>>t;
    n = s.size();
    m = t.size();
    t += ' ';
    for(int i=0; i<n; i++) ans += i+1;

    for(int j=0; j<26; j++) nxt[n][j] = nxt[n+1][j]= n;
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<26; j++){
            nxt[i][j] = nxt[i+1][j];
            nxt[i][s[i]-'a'] = i;
        }
    }

    // for(int i=0; i<n; i++) cout<<i<<':'<<nxt[i][0]<<' '<<nxt[i][1]<<'\n';

    set<pair<int,int>> st;
    for(int l=0; l<n; l++){
        vector<int> v;
        int x = l;
        for(int i=0; i<m; i++){
            x = nxt[x][t[i]-'a'];
            v.push_back(nxt[x][t[i]-'a']);
            x++;
        }
        int a = v.front();
        int b = v.back();
        if(a == n || b == n) break;
        st.insert({a,b});
    }

    int last = 0;
    for(auto [a,b]: st){
        // cout<<a<<' '<<b<<'\n';
        ans -= (a-last+1) * (n-b);
        last = a+1;
    }

    cout<<ans<<'\n';
    
}
