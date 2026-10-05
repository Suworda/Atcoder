#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,Q;
string ans, t;
vector<pair<int,int>> q;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>Q;
    for(int i=0; i<n; i++){
        t += '.';
        ans += '.';
    }

    for(int i=0; i<Q; i++){
        int ty, x;
        char c;
        cin>>ty;

        if(ty == 1){
            cin>>x;
            x--;
            q.push_back({ty,x});
            t[x] = (t[x] == '.' ? '#' : '.');
        }
        else{
            cin>>c;
            q.push_back({ty,c});
        }
    }

    set<int> st;
    for(int i=0; i<n; i++){
        if(t[i] == '.') st.insert(i);
    }

    for(int i=Q-1; i>=0; i--){
        auto [ty,x] = q[i];

        if(ty == 1){
            if(ans[x] == '.'){
                if(t[x] == '.'){ //->#
                    st.erase(x);
                    
                }
                else{ //->.
                    st.insert(x);
                    
                }
            }
            t[x] = (t[x]  == '.' ? '#' : '.');
        }
        else{
            for(int y: st){
                ans[y] = char(x);
            }
            st.clear();
        }
    }

    for(int i=0; i<n; i++) if(ans[i] == '.') ans[i] = 'a';
    cout << ans << '\n';
}
