#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAX_N=500000;
int n,q;
int a[MAX_N+5];
int b_cnt[MAX_N+5];
int b_sum[MAX_N+5];

void update_sum(int x, int d){
    if(x==0) return;
    while(x<=MAX_N){
        b_sum[x] += d;
        x += x & (-x);
    }
}

int query_sum(int x){
    int ans=0;
    if(x==-1) return 0;

    while(x){
        ans+=b_sum[x];
        x -= x & (-x);
    }
    return ans;
}

void update_cnt(int x, int d){
    if(x==0){
        b_cnt[0]+=d;
        return;
    }

    while(x<=MAX_N){
        b_cnt[x]+=d;
        x += x & (-x);
    }

}

int query_cnt(int x){
    if(x==-1) return 0;

    int ans=0;
    while(x){
        ans+=b_cnt[x];
        x -= x & (-x);
    }

    return ans + b_cnt[0];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        update_cnt(a[i], +1);
        update_sum(a[i], +a[i]);
    }

//    for(auto x:mset) cout<<x<<' ';

    int ty,x,y,l,r,ans;
    while(q--){
//    for(int i=1; i<=10; i++) cout<<i<<':'<<b[i]<<'\n';
        cin>>ty;
        if(ty==1){
            cin>>x>>y;
            update_cnt(a[x],-1);
            update_sum(a[x], -a[x]);
            a[x]=y;

            update_cnt(y, +1);
            update_sum(y, +y);

        }else{
            cin>>l>>r;
            if(l<r){

                ans=query_sum(r)-query_sum(l-1);

                ans+=query_cnt(l-1)*l + (query_cnt(MAX_N) - query_cnt(r))*r;

                cout<<ans<<'\n';

            }else{
                cout<<l*n<<'\n';
            }
        }
    }
}
/*
3 4
4 3 2
2 3 5
*/

