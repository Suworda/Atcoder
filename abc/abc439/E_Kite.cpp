#include <bits/stdc++.h>
using namespace std;

pair<int,int> line[300005];
vector<int> v;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>line[i].first>>line[i].second;
    }

    sort(line, line+n, [&](auto p1, auto p2){
        if(p1.first != p2.first) return p1.first < p2.first;
        return p1.second > p2.second;
    });
    
    v.push_back(line[0].second);
    for(int i=1; i<n; i++){
        int b = line[i].second;
        if(b > v.back()){
            v.push_back(b);
        }else{
            auto it = lower_bound(v.begin(), v.end(), b);
            int idx = it - v.begin();
            v[idx] = b;
        }
    }

    cout<<v.size()<<'\n';

}