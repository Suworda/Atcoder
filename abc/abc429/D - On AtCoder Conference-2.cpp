#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long

signed main(){
    vector<int> v;
    vector<pair<long long, int>> p;
    int n;
    long long m;
    int c;
    cin>>n>>m>>c;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.push_back(-1);

    int cnt=1;
    for(int i=1; i<=n; i++){
        if(v[i]==v[i-1]) cnt++;
        else{
            p.push_back({v[i-1] , cnt});
            cnt=1;
        }

    }

    int cur=0;
    int r=0;
    for(auto [x,cnt]: p){
        cur+=cnt;
        //cout<<x<<' '<<cnt<<'\n';
        if(cur>=c) break;
        r++;
    }
    int sz=p.size();
    long long ans=(long long)cur*(p[0].first+m - p[sz-1].first);
    //cout<<ans<<'\n';
    for(int l=1; l<p.size(); l++){
        cur-=p[l-1].second;
        while(cur<c){
            r++;
            if(r==sz){
                r=0;
            }
            cur+=p[r].second;
        }
        //cout<<l<<' '<<r<<' '<<cur<<'\n';
        ans+=(long long)cur*(p[l].first - p[l-1].first);
    }

    cout<<ans<<'\n';


}
