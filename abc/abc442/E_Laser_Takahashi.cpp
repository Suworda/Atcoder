#include <bits/stdc++.h>
using namespace std;

#define double long double

int n,q;
int x[200005];
int y[200005];
int sum[200005];
int id[200005];
int ty[200005];
int pre[200005];

bool same(int a, int b){
    if(ty[a] != ty[b]) return false;
    
    int g = gcd(x[a], y[a]);
    x[a]/=g; y[a]/=g;
    
    g = gcd(x[b], y[b]);
    x[b]/=g; y[b]/=g;

    return (x[a] == x[b] && y[a] == y[b]);
}

bool cmp(int a, int b){
    if(ty[a] < ty[b]) return true;
    if(ty[a] > ty[b]) return false;

    if(same(a,b)) return false;

    if(ty[a] == 1){
        double m1 = (double)y[a]/x[a];
        double m2 = (double)y[b]/x[b];
        return m1 > m2;

    }else if(ty[a] == 2){
        if(x[a] == 0) return true;
        if(x[b] == 0) return false;
        double m1 = (double)y[a]/x[a];
        double m2 = (double)y[b]/x[b];
        return m1 > m2;

    }else if(ty[a] == 3){
        double m1 = (double)y[a]/x[a];
        double m2 = (double)y[b]/x[b];
        return m1 > m2;
    
    }else if(ty[a] == 4){
        if(x[a] == 0) return true;
        if(x[b] == 0) return false;
        double m1 = (double)y[a]/x[a];
        double m2 = (double)y[b]/x[b];
        return m1 > m2;

    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>q;
    iota(id+1, id+n+1, 1);
    for(int i=1; i<=n; i++){
        cin>>x[i]>>y[i];
        if(x[i] < 0 && y[i] >= 0) ty[i] = 1;
        if(x[i] >= 0 && y[i] > 0) ty[i] = 2;
        if(x[i] > 0 && y[i] <= 0) ty[i] = 3;
        if(x[i] <= 0 && y[i] < 0) ty[i] = 4;
    }

    sort(id+1, id+n+1, cmp);

    int cur=0;
    for(int i=1; i<=n; i++){
        if(!same(id[i], id[i-1])){
            cur = id[i-1];
        } 
        else sum[id[i]] = sum[id[i-1]];
        sum[id[i]] = i;
        pre[id[i]] = cur;
    }
    for(int i=n-1; i>=1; i--){
        if(same(id[i], id[i+1])) sum[id[i]] = sum[id[i+1]];
    }

    while(q--){
        int a,b;
        cin>>a>>b;
        if(sum[a] > sum[b]) cout<<sum[b]+n - sum[pre[a]]<<'\n';
        else cout<<sum[b] - sum[pre[a]]<<'\n';
    }
    
}
