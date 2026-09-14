#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
string s;
vector<int> v;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>s;
    for(int i=0; i<n; i++){
        if(s[i] == 'x') v.push_back(i);
    }

    for(int i=0; i<n; i++){
        if(i < v.size()) cout << v[i]+1 << '\n';
        else cout << n << '\n';
    }
    
} 