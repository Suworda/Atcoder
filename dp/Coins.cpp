#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int N = 3005;
double p[N];
double dp[N][N];
bool vis[N][N];

double f(int n, int head){
    if(vis[n][head]) return dp[n][head];
    if(head == -1 || n < head) return 0;
    if(n == 0) return 1;
    
    double rst = p[n] * f(n-1, head-1) + (1-p[n]) * f(n-1, head);
    vis[n][head] = 1;
    return dp[n][head] = rst;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>p[i];
    }
    
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=n; j++){
    //         cout<<i<<' '<<j<<" : "<<f(i,j)<<'\n';
    //     }
    // }

    double ans = 0;
    for(int i=n/2+1; i<=n; i++){
        ans += f(n,i);
        // cout<<n<<' '<<i<<' '<<f(n,i)<<'\n';
    }


    cout<<fixed<<setprecision(15)<<ans<<'\n';
    
}