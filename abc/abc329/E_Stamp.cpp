#include <bits/stdc++.h>
using namespace std;

int n,m;
bitset<200005> used;

bool valid(int p){
    return p>=0 && p<n-m+1 && !used[p];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    string s,t;
    cin>>s>>t;

    queue<int> q;

    for(int i=0; i<n-m+1; i++){
        if(s.substr(i,m) == t){
            q.push(i);
            used[i] = true;
        }
    }

    while(q.size()){
        //cout<<s<<'\n';
        int p = q.front();
        q.pop();

        for(int i=p; i<p+m; i++){
            s[i] = '#';
        }

        for(int i=p-m+1; i<=p+m; i++){
            if(!valid(i)) continue;

            bool ok = true;
            for(int j=0; j<m; j++){
                if(s[i+j] != '#' && s[i+j] != t[j]) ok = false;
            }

            if(ok){
                //cout<<i<<' ';
                q.push(i);
                used[i] = true;
            }
        }
    }
    //cout<<s<<'\n';

    bool ans = true;
    for(int i=0; i<n; i++){
        if(s[i] != '#') ans = false;
    }

    cout<<(ans ? "Yes\n" : "No\n");
}