#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int n,q;
int h[MAXN];
int l[MAXN], r[MAXN];
int ans[MAXN];
int stk[MAXN];
int top = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>h[i];
    }

    for(int i=1; i<=q; i++){
        cin>>l[i]>>r[i];
    }

    int id[q+5];
    iota(id, id+q+1, 0);
    sort(id+1, id+q+1, [](int x, int y){
        return l[x] > l[y];
    });

    int x = 1;
    int cur = id[1];
    for(int i=n; i>=1; i--){
        while(x <= q && i == l[cur]){
            auto it = lower_bound(stk+1, stk+top+1, r[cur], greater<>());
            ans[cur] = (it - (stk+1));
            cur = id[++x];
        }

        while(top && h[i] >= h[stk[top]]){
            top--;
        }

        stk[++top] = i;
    }

    for(int i=1; i<=q; i++) cout<<ans[i]<<'\n';

}