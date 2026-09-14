#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
string s;
vector<int> v;
int change[129];
bool used[129];
string x;
int ans = -1;

bitset<10000005> is_p;

void init_p(){
    is_p.set();
    is_p[0] = is_p[1] = 0;
    for(int i=2; i<=10000005; i++){
        if(is_p[i]){
            for(int j = i*2; j<=10000005; j+=i){
                is_p[j] = 0;
            }
        }
    }
}

bool is_prime(string x){
    return is_p[stoi(x)];
}

void dfs(int id){
    // cerr << x << ' ';
    if(id == n){
        // cerr << x << '\n';
        if(is_prime(x) && x[0] != '0') ans = stoi(x);
        return;
    }

    if(!change[v[id+1]]){
        for(int i='1'; i<='9'; i++){
            if(!used[i]){
                used[i] = 1;
                change[v[id+1]] = i;
                x.push_back(i);
                dfs(id+1);
                change[v[id+1]] = 0;
                x.pop_back();
                used[i] = 0;
            }
        }
    }
    else{
        x.push_back(change[v[id+1]]);
        dfs(id+1);
        x.pop_back();
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    init_p();

    cin>>s;
    n = s.size();
    int t = 0;
    s = ' ' + s;
    v.push_back(0);
    for(int i=1; i<=n; i++){
        if(change[s[i]]){
            v.push_back(change[s[i]]);
        }
        else{
            change[s[i]] = ++t;
            v.push_back(change[s[i]]);
        }
    }

    dfs(0);

    cout << ans << '\n';
    
} 