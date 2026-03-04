#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long

int n;
ll a[405];
ll dp[405][405];
ll sum[405];

ll tot(int l, int r){
    return sum[r] - sum[l-1];
}

ll ans(int l, int r){
    if(dp[l][r]) return dp[l][r];
    if(l == r) return 0;
    ll mi=9e18;
    int m=0;
    for(int i=l; i<=r-1; i++){
        ll L = ans(l,i), R = ans(i+1,r);
        if(L + R < mi){
            m = i;
            mi = L + R;
        }
    }

    return dp[l][r] = mi + tot(l,r);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        sum[i] = sum[i-1] + a[i];
    }

    //解釋
    // for (int len = 2; len <= n; len++) {
    //     for (int l = 1; l <= n - len + 1; l++) {
    //         int r = l + len - 1;
    //         dp[l][r] = 1e18;
    //         int best_k = -1; // 用來紀錄是哪一個 k 讓代價最小

    //         for (int k = l; k <= r - 1; k++) {
    //             int current_val = dp[l][k] + dp[k+1][r] + (sum[r] - sum[l-1]);
    //             if (current_val < dp[l][r]) {
    //                 dp[l][r] = current_val;
    //                 best_k = k; // 抓到目前最好的切法
    //             }
    //         }
            
    //         // --- 放在這裡！ ---
    //         // 這裡會顯示：這個區間最後決定在哪裡切開最划算
    //         cout << "區間 [" << l << ", " << r << "] 最優切點 k=" << best_k 
    //             << "，最小代價=" << dp[l][r] << endl;
    //     }
    //     cout << "-----------------------------------" << endl; // 分隔不同長度的決策
    // }

    //answer
    cout << ans(1,n);


    
}
