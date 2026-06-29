#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<pair<int,int>> q;
multiset<int> mst;
unordered_map<int,vector<int>> mp;
vector<int> v2;
int ans[300005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=0; i<n; i++){
        int h,l;
        cin>>h>>l;
        mst.insert(h);
        v2.push_back(l);
        mp[l].push_back(h);
    }
    sort(v2.begin(), v2.end());
    
    int Q;
    cin>>Q;
    for(int i=0; i<Q; i++){
        int t;
        cin>>t;
        q.push_back({t,i});
    }

    sort(q.begin(), q.end());
    int pos = 0;
    int last = 0;
    for(int i=0; i<Q; i++){
        auto [t,x] = q[i];
        while(pos < v2.size() && v2[pos] <= t){
            if(v2[pos] == last){
                pos++;
                continue;
            }

            for(int y: mp[v2[pos]]){
                mst.erase(mst.find(y));
                
            }
            last = v2[pos];
            pos++;
        }

        ans[x] = (*(prev(mst.end())));

    }

    for(int i=0; i<Q; i++) cout<<ans[i]<<'\n';


}