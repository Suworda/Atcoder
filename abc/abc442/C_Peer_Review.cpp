#include <bits/stdc++.h>
using namespace std;

int n,m;
int cnt[200005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    fill(cnt, cnt+n+1, n-1);
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        cnt[a]--;
        cnt[b]--;
    }

    for(int i=1; i<=n; i++){
        long long x = cnt[i];
        cout<<x*(x-1)*(x-2)/6<<' ';
    }
}
