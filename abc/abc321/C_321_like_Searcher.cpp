#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

vector<ll> ans;

void dfs(int x, string &s){
    s += to_string(x);
    ans.push_back(stoll(s));
    for(int i=0; i<x; i++) dfs(i, s);
    s.pop_back();
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    string s;
    for(int i=1; i<=9; i++) dfs(i, s);

    sort(ans.begin(), ans.end());
    
    cout << ans[n-1] << '\n';
} 