#include <iostream>
#include <queue>
using namespace std;
int n,q;
int x,y;

struct PC{
    int ver,cnt;

    bool operator< (const PC &b) const{
        return ver > b.ver;
    }
};
priority_queue<PC> pq;

int d;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        pq.push({i,1});
    }

    while(q--){
        cin>>x>>y;
        d=0;
        while(pq.top().ver<=x){
            d+=pq.top().cnt;
            pq.pop();
        }

        pq.push({y,d});
        //cout<<'\n';
        cout<<d<<'\n';
    }



}
