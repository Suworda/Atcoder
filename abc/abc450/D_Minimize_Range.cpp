#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,k;
int a[200005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k;

    for(int i=0; i<n; i++){
        cin>>a[i];
        a[i]%=k;
    }

    sort(a,a+n);
    deque<int> dq;
    for(int i=0; i<n; i++) dq.push_back(a[i]);
    int ans = dq.back() - dq.front();
    for(int i=0; i<n; i++){
        dq.push_front(dq.back()-k);
        dq.pop_back();
        ans = min(ans, dq.back() - dq.front());
    }

    cout<<ans<<'\n';
    


}
