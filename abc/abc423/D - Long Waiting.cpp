#include <iostream>
#include <queue>
using namespace std;

#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    int n,k;
    cin>>n>>k;
    int a,b,c;
    int cur=0;
    int cur_t=0;
    while(n--){
        cin>>a>>b>>c;
        cur_t=max(cur_t, a);
        while(cur+c>k){
            auto [t,x] = pq.top();
            pq.pop();
            cur-=x;
            cur_t=max(cur_t,t);
        }

        cur+=c;
        pq.push({cur_t+b, c});
        cout<<cur_t<<'\n';
    }

}
/*
4 10
30 300 3
90 45 4
90 45 3
240 45 2
*/


