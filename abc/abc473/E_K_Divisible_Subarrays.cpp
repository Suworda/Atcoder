#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,k;
int a[200005];
ll sum[200005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        sum[i] = sum[i-1] + a[i];
    }

    int ans = 0;
    set<int> st{0};
    for(int i=1; i<=n; i++){
        if(a[i] == 0 || st.count(sum[i]%k)){
            ans++;
            st.clear();
        }
        st.insert(sum[i]%k);
    }

    cout << ans << '\n';
} 