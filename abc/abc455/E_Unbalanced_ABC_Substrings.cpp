#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

ll ans, tot;
ll ans_ab;
ll ans_bc;
ll ans_ac;
ll ans_abc;

int n;
string s;
int A = 0;
int B = 0;
int C = 0;

ll calc(char c1, char c2){
    ll rst = 0;
    unordered_map<int,int> d{{0,1}};
    int cur1 = 0, cur2 = 0;
    for(int i=1; i<=n; i++){
        cur1 += s[i] == c1;
        cur2 += s[i] == c2;
        rst += d[cur1 - cur2];
        d[cur1 - cur2]++;
    }

    return rst;
}

ll calcABC(){
    ll rst = 0;
    map<pair<int,int>,int> d{{{0,0},1}};
    int cur1 = 0, cur2 = 0, cur3 = 0;
    for(int i=1; i<=n; i++){
        cur1 += s[i] == 'A';
        cur2 += s[i] == 'B';
        cur3 += s[i] == 'C';
        rst += d[{cur1 - cur2, cur2 - cur3}];
        d[{cur1 - cur2, cur2 - cur3}]++;
    }

    return rst;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>s;
    s = ' ' + s;
    tot = n*(n+1)/2;

    ans = tot - calc('A','B') - calc('A','C') - calc('B','C') + 2*calcABC();
    
    cout<<ans<<'\n';
}
