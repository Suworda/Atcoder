#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,L,R;
string s;
vector<int> v[30];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>L>>R>>s;
    
    for(int i=0; i<s.size(); i++){
        v[s[i]-'a'].push_back(i);
    }

    int ans=0;
    for(int i=0; i<30; i++){
        for(int &x: v[i]){
            auto it1 = lower_bound(v[i].begin(), v[i].end(), x+L);
            auto it2 = upper_bound(v[i].begin(), v[i].end(), x+R);
            ans += it2 - it1;
        }
    }
    cout<<ans<<'\n';


}
