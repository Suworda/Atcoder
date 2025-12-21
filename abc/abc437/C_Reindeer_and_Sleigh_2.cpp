#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
int w[300005];
int p[300005];

void sol(){
    cin>>n;
    ll targ = 0;
    priority_queue<int> pq;
    for(int i=0; i<n; i++){
        cin>>w[i]>>p[i];
        targ += w[i];
        pq.push(w[i]+p[i]);
    }

    int ans=n;
    ll cur=0;
    while(cur < targ){
        ans--;
        cur+=pq.top();
        pq.pop();
    }

    cout<<ans<<'\n';

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) sol();

}