#include <bits/stdc++.h>
using namespace std;

map<int,int> cnt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    int ans=0;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        cnt[x] = cnt[x-1]+1;
        ans = max(ans, cnt[x]);
    }

    cout<<ans<<'\n';
    
}
