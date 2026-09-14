#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
int a[300005];
set<int> st;

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
        st.insert(a[i]);
    }

    auto it = st.insert(0).first;
    int ans = 0;
    while(st.size() > 1){
        auto it2 = it;
        auto it3 = it;
        if(it == st.begin()){
            it2++;
            ans += (*it2) - (*it);
            st.erase(it); 
            it = it2;
        }
        else if(next(it) == st.end()){
            it2--;
            ans += abs((*it2) - (*it));
            st.erase(it); 
            it = it2;
        }
        else{
            it2--;
            it3++;
            int x = abs((*it3) - (*it));
            int y = abs((*it2) - (*it));
            st.erase(it);
            if(x < y){
                ans += x;
                it = it3;
            }
            else if(x>y){
                ans += y;
                it = it2;
            }
            else{
                ans += x;
                if((*it2) < (*it3)){
                    it = it2;
                }
                else{
                    it = it3;
                }
            }
        }
    }

    cout << ans << '\n';
} 