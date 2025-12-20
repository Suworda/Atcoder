#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 500005;
int n;
int p[MAXN];
int b[MAXN];

int query(int x){
    int rst = 0;
    while(x){
        rst += b[x];
        x -= (x & -x);
    }
    return rst;
}

void update(int x){
    while(x<=n){
        b[x]++;
        x +=(x & -x);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        p[x] = i;
    }

    long long ans=0;
    for(int i=1; i<=n; i++){
        int rst = query(p[i]);
        ans += (ll)(rst+1) * (i - rst); 
        update(p[i]);
    }

    cout<<ans<<'\n';



}