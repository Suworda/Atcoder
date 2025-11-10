#include <iostream>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int x;
    set<int> p;
    unordered_map<int,int> cost;
    p.insert(0);
    p.insert(2e9); cost[2e9]=0;
    long long cur=0;
    for(int i=0; i<n; i++){
        cin>>x;
        auto it1=(p.lower_bound(x));
        int b=*it1, a=*(--it1);

        if(i==0){
            cur=x*2;
            cost[0]=x;
            cost[x]=x;
        }else{
            cur+=min(abs(x-a) , abs(b-x));
            cur-=max(cost[a] - (x-a) , 0);
            cur-=max(cost[b] - (b-x) , 0);

            cost[a]=min(cost[a] , x-a);
            cost[b]=min(cost[b] , b-x);
            cost[x]=min(abs(x-a) , abs(b-x));
        }
        cout<<cur<<'\n';
        p.insert(x);


    }



}
