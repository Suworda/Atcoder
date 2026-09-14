#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,q;
int a[500005];
set<int> st;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>q;
    int ans = 0;
    while(q--){
        int ty;
        cin>>ty;
        if(ty == 1){
            int x;
            cin>>x;
            ans ^= a[x];
            a[x]++;
            ans ^= a[x];
            st.insert(x);
        }
        else{
            for(auto it = st.begin(); it != st.end();){
                ans ^= a[*it];
                a[*it]--;
                ans ^= a[*it];
                if(a[*it] == 0){
                    it = st.erase(it);
                }
                else{
                    it++;
                } 
            }
        }

        cout << ans << '\n';
    }
    
} 