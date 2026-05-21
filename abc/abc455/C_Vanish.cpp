#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,k;
int a[300005];
map<int,int> cnt;
int cur = 0;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        cur+=a[i];
        cnt[a[i]]++;
    }

    priority_queue<ll> pq;
    for(auto [a, b]: cnt){
        pq.push(a*b);
    }


    while(k-- && pq.size()){
        cur -= pq.top();
        pq.pop();
    }

    cout<<cur<<'\n';
    
}
