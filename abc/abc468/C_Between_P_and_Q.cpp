#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
vector<int> p,q;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        p.push_back(x);
    }
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        q.push_back(x);
    }

    if(p >= q){
        cout << 0 << '\n';
        return 0;
    }

    int ans = 0;
    while(p != q){
        ans++;
        next_permutation(p.begin(), p.end());
    }

    cout << ans-1 << '\n';

    
} 