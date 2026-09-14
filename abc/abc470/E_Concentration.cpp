#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,L;
double a[205];
double dp[205][205][205]; //life, c0, c1
bool vis[205][205][205];

double f(int hp, int c0, int c1){
    if(vis[hp][c0][c1]) return dp[hp][c0][c1];
    if(hp == 0 || c0 + c1 == 0) return 0;

    double rst = 0;
    int r = 2*c0 + c1;

    double a = c1;
    double b = c0;

    double p1 = 1.0 * a/(2*b + a);
    double p2 = 1.0 * (2*b * a) / ((2*b + a) * (2*b + a - 1));
    double p3 = 1.0 * (2*b) / ((2*b + a) * (2*b + a - 1));
    double p4 = 1.0 * ((2*b) * (2*b-2)) / ((2*b + a) * (2*b + a - 1));

    if(c1-1 >= 0) rst += p1 * (f(hp, c0, c1-1) + 1);
    if(hp > 1 && c0-1 >= 0) rst += p2 * (f(hp-1, c0-1, c1) + 1);
    if(c0-1 >= 0) rst += p3 * (f(hp, c0-1, c1) + 1);
    if(c0 > 1) rst += p4 * (f(hp-1, c0-2, c1+2));

    vis[hp][c0][c1] = 1;
    return dp[hp][c0][c1] = rst;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>L;
    double tot = 0;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        tot += a[i];
    }
    
    cout << fixed << setprecision(10) << tot / n * f(L, n, 0) << '\n';
    
} 