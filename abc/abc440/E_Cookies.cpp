#include <bits/stdc++.h>
using namespace std;

#define int long long

struct State{
    long long val; 
    int last=-1, len=-1;

    bool operator< (const State &other) const{
        return val > other.val;
    }
};

int n,k,x;
int a[51];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k>>x;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a,a+n,greater<>());

    long long maxv = a[0]*k;
    cout<<maxv<<'\n';
    x--;

    priority_queue<State> pq;
    pq.push({a[0]-a[1], 1, 1});
    while(pq.size() && x--){
        auto [val, last, len] = pq.top();
        // cout<<val<<' '<<last<<' '<<len<<'\n';
        pq.pop();
        cout<<maxv - val<<'\n';
        if(len != k){
            pq.push({val+(a[0]-a[last]), last, len+1});
            // cout<<"(1) "<<val+(a[0]-a[last])<<' '<<last<<' '<<len+1<<'\n';
        }
        if(last != n-1){
            pq.push({val+(a[last]-a[last+1]), last+1, len});
            // cout<<"(2) "<<val+(a[last]-a[last+1])<<' '<<last+1<<' '<<len<<'\n';
        }
    }

}
