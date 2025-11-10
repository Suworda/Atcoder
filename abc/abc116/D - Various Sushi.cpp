#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Sushi{
    int t,d;
    bool operator> (const Sushi &b) const{
        return d > b.d;
    }
};

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    vector<Sushi> v(n);
    vector<pair<int,int>> ma(n+5);
    int cnt[n+5]={};
    bool found[n+5]={};
    int totkind=0;

    for(int i=0; i<n; i++){
        cin>>v[i].t>>v[i].d;
        if(!found[v[i].t]){
            totkind++;
            found[v[i].t]=true;
        }
        ma[v[i].t].second=v[i].t;
        ma[v[i].t].first = max(ma[v[i].t].first,v[i].d);
    }
    sort(v.begin(), v.end(),greater<Sushi>());
    sort(ma.begin(), ma.end(),greater<pair<int,int>>());

    long long ans=0;
    int x=0;
    for(int i=0; i<k; i++){
        if(cnt[v[i].t]==0){
            x++;
        }
        ans+=v[i].d;
        cnt[v[i].t]++;
    }
    ans+=x*x;

    long long cur=ans-x*x;

    int th=0;
    for(int i=k-1; i>=0; i--){
        if(cnt[v[i].t]>=2){
            while(th<totkind && cnt[ma[th].second]!=0){
                th++;
            }
            if(th>=totkind) break;
            cur-=v[i].d;
            x++;
            cur+=ma[th].first;
            cnt[v[i].t]--;
            cnt[ma[th].second]++;
            //cout<<cur<<'\n';
        }
        ans=max(ans,cur+x*x);
    }



    cout<<ans<<'\n';

}
/*
7 4
4 1
4 1
4 1
4 6
4 5
4 5
4 5
*/
