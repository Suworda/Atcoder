#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int a[8005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,s,L;
    cin>>n>>s>>L;
    a[1] = 0;
    for(int i=2; i<=n; i++){
        cin>>a[i];
        a[i] += a[i-1];
    }

    int ans = 0;

    // left right
    for(int l = 1; l<=s; l++){
        int r = s;
        if(a[s] - a[l] <= L){
            ans = max(ans, s-l+1);
            int x = L - (a[s] - a[l]);
            for(int i=s+1; i<=n; i++){
                if(a[i] - a[l] <= x){
                    ans = max(ans, i-l+1);
                }
                else break;
            }
        }
    }

     for(int r = s; r<=n; r++){
        int l = s;
        if(a[r] - a[s] <= L){
            ans = max(ans, r-s+1);
            int x = L - (a[r] - a[s]);
            for(int i=s-1; i>=1; i--){
                if(a[r] - a[i] <= x){
                    ans = max(ans, r-i+1);
                }
                else break;
            }
        }
    }

    cout << ans << '\n';
    
} 