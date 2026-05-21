#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
set<pair<int,int>> apr;
vector<int> r[200005], l[200005];
multiset<int> mst;
int idx = 0;
bool ans[200005];

void try1(int s, int t, bool &rst){
    if(!apr.count(make_pair(s,t))) return;
    for(int i=idx; i<s; i++){
        for(auto x: r[i]){
            // cout<<x<<'\n';
            mst.erase(mst.find(x));
            
        }
    }
    idx = s;
    if(mst.size() < 2) return;
    auto it = mst.begin();
    it++;
    if(*it <= t) rst = true;
}

void try2(int s, int t, bool &rst){
    auto id1 = lower_bound(l[t].begin(), l[t].end(), s);
    if(id1 == l[t].end()) return;
    
    auto id2 = lower_bound(r[s].begin(), r[s].end(), t);
    if(id2 == r[s].begin()) return;
    id2--;
    
    int minL=(*id1), maxR=(*id2);
    // cerr<<*id1<<' '<<*id2<<'\n';
    if(minL <= maxR+1) rst = true;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0; i<m; i++){
        int L, R;
        cin>>L>>R;
        mst.insert(R);
        apr.insert({L,R});
        r[L].push_back(R);
        l[R].push_back(L);
    }

    for(int i=0; i<=n; i++){
        sort(r[i].begin(), r[i].end());
        sort(l[i].begin(), l[i].end());
    }

    int Q;
    cin>>Q;
    vector<tuple<int,int,int>> q;
    for(int i=0; i<Q; i++){
        int s, t;
        cin>>s>>t;
        q.push_back({s,t,i});
    }

    sort(q.begin(), q.end());
    // for(auto [a,b,c]: q) cout<<a<<' '<<b<<' '<<c<<'\n';

    for(int i=0; i<Q; i++){
        auto [s,t,id] = q[i];
        bool rst = false;
        try1(s,t,rst);
        try2(s,t,rst);

        ans[id] = rst;
    }

    for(int i=0; i<Q; i++) cout << (ans[i] ? "Yes" : "No") <<'\n';
    
}
