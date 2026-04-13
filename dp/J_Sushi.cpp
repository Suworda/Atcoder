#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
double dp[301][301][301];

double dfs(int a, int b, int c){
    if(dp[a][b][c]) return dp[a][b][c];
    if(a == 0 && b == 0 && c == 0) return 0;

    double rst = 0;
    if(a) rst += dfs(a-1,b,c)*a;
    if(b) rst += dfs(a+1,b-1,c)*b;
    if(c) rst += dfs(a,b+1,c-1)*c;
    
    rst += n;
    rst /= (a+b+c);

    return dp[a][b][c] = rst;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    vector<int> v(4);
    for(int i=0; i<n; i++){
        int cnt;
        cin>>cnt;
        v[cnt]++;
    }

    cout << fixed << setprecision(15) << dfs(v[1], v[2], v[3]) << '\n';
    
}