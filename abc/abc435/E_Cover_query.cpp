#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    int n,q;
    cin>>n>>q;

    int l,r;
    vector<pair<int,int>> v;
    for(int i=1; i<=q; i++){
        cin>>l>>r;
        v.push_back({l,i});
        v.push_back({r+1,-i});
    }
    sort(v.begin(), v.end());
    v.push_back({-1,0});
    
    vector<int> d(200005,0);
    set<int> st;

    int pre;
    for(int i=0; i<v.size()-1; i++){
        if(i != 0){
            if(!st.empty()){
                //cout<<v[i].first<<' '<<v[i].second<<'\n';
                d[*(st.begin())] -= v[i].first - pre;
            }
        }

        i--;
        do{
            i++;
            if(v[i].second > 0){
                st.insert(v[i].second);
            }else{
                st.erase(-v[i].second);
            }
            pre = v[i].first;
        } while(v[i].first == v[i+1].first);

    }
    
    int cur=0;
    for(int i=1; i<=q; i++){
        cur -= d[i];
        cout<< n - cur <<'\n';
    }
}