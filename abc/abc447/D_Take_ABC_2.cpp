#include <bits/stdc++.h>
using namespace std;

string s;
set<int> pa;
set<int> pb;
int ans=0;

void check(){
    if(pb.empty() || pa.empty()) return;

    int x = *prev(pb.end());
    auto it = pa.lower_bound(x);
    if(it != pa.begin()){
        ans++;
        it--;
        pa.erase(it);
        pb.erase(x);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>s;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'A') pa.insert(i);
        if(s[i] == 'B') pb.insert(i);
        if(s[i] == 'C'){
            check();
        }
    }

    cout<<ans<<'\n';
    
}
