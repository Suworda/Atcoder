#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long



signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;

    vector<int> pa(n+1), pb(n+1), pc(n+1);

    for(int i=1; i<=n; i++){
        if(s[i] == 'A') pa.push_back(i);
        if(s[i] == 'B') pb.push_back(i);
        if(s[i] == 'C') pc.push_back(i);
    }

    int r = 0;
    set<char> st;
    for(int i=n; i>=1; i--){
        st.insert(s[i]);
        if(st.size() == 3){
            r = i;
            break;
        }
    }

    int L = 0;
    st.clear();
    for(int i=1; i<=n; i++){
        st.insert(s[i]);
        if(st.size() == 3){
            L = i;
            break;
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        auto it1 = upper_bound(pa.begin(), pa.end(), i);
        auto it2 = upper_bound(pb.begin(), pb.end(), i);
        auto it3 = upper_bound(pc.begin(), pc.end(), i);

        if(it1 == pa.end()) break;
        if(it2 == pb.end()) break;
        if(it3 == pc.end()) break;

        int l = max({*it1, *it2, *it3});
        if(L <= i) ans += max(0LL, r - l);
    }

    cout << ans << '\n';
    
}