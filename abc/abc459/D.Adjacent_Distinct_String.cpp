#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

string s;
int cnt[26];

void init(){
    for(int i=0; i<26; i++) cnt[i] = 0;
}

void sol(){
    init();

    priority_queue<pair<int,char>> pq;
    cin>>s;
    for(int i=0; i<s.size(); i++){
        cnt[s[i]-'a']++;
    }

    for(int i=0; i<26; i++) if(cnt[i]) pq.push({cnt[i],i});

    int ln = -1, lc = -1;
    string ans;
    while(pq.size()){
        auto [n,c] = pq.top();
        // cout<<n<<' '<<(char)(c+'a')<<'\n';
        pq.pop();
        if(c == lc){
            if(pq.empty()){
                cout<<"No\n";
                return;
            }

            auto [n2,c2] = pq.top();
            pq.pop();
            ans += c2 + 'a';

            n2--;
            if(n2) pq.push({n2,c2});

        }
        ans += c + 'a';

        ln = n;
        lc = c;

        n--;
        if(n) pq.push({n,c});
            

    }

    cout<<"Yes\n";
    cout<<ans<<'\n';




}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int t;
    cin>>t;
    while(t--) sol();
    
}
