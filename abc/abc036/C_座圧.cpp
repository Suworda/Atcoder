#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
vector<int> v;
vector<int> q(100005);

int get_rank(int x){
    auto it = lower_bound(v.begin(), v.end(), x);
    return it - v.begin();
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=0; i<n; i++) cin>>q[i];
    for(int i=0; i<n; i++) v.push_back(q[i]);

    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    for(int i=0; i<n; i++){
        cout << get_rank(q[i]) << '\n';
    }

    
} 