#include <iostream>
#include <vector>
using namespace std;
int n,m;
int x[200005];
long long d[200005]={};


void range_add(int a, int b, int val){
    d[a]+=val;
    d[b+1]-=val;
}

void process(int a, int b){
    if(a > b) swap(a,b);

    int dis1=b-a;
    int dis2=n-dis1;

    range_add(a, b-1, dis2);
    range_add(1, a-1, dis1);
    range_add(b, n, dis1);
}
int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    cin>>n>>m;
    cin>>x[0];
    for(int i=1; i<m; i++){
        cin>>x[i];
        //cout<<1;
        process(x[i], x[i-1]);
    }

    long long ans=9e18;
    long long cur=0;
    for(int i=1; i<=n; i++){
        cur+=d[i];
        ans=min(ans, cur);
    }

    cout<<ans<<'\n';


}
