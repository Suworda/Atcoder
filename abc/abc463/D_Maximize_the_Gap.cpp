#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int N = 200005;
int n,k;
vector<pair<int,int>> seg;

bool valid(int m){
    int s = -2e9;
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(seg[i].second >= s + m){
            cnt++;
            s = seg[i].first;
        }
    }

    return cnt >= k;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k;
    for(int i=0; i<n; i++){
        int l,r;
        cin>>l>>r;
        seg.push_back({r, l});
    }
    sort(seg.begin(), seg.end());

    // for(int i=0; i<n; i++) cout<<seg[i].second<<' '<<seg[i].first<<'\n';
    // return 0;
    
    int ans = -1, l=1, r=4e18;
    while(l<=r){
        int m = (l+r)/2;
        if(valid(m)){
            ans = m;
            l = m+1;
        }else{
            r = m-1;
        }
    }

    cout<<ans<<'\n';
}