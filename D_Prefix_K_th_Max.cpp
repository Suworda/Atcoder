#include <bits/stdc++.h>
using namespace std;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n,k;
    cin>>n>>k;
    priority_queue<int , vector<int> , greater<>> pq;
    int x;
    for(int i=0; i<n; i++){
        cin>>x;
        pq.push(x);
        if(pq.size() == k) cout<<pq.top()<<'\n';
        if(pq.size() > k){
            pq.pop();
            cout<<pq.top()<<'\n';
        }
    }

}