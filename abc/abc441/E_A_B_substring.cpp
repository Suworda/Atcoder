#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
string s;
vector<int> v;
int B[1100005];

void update(int x){
    while(x <= 1100000){
        B[x]++;
        x += x & (-x);
    }
}

long long query(int x){
    long long rst=0;
    while(x){
        rst+=B[x];
        x -= x & (-x);
    }
    return rst;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>s;

    int x = 500001;
    long long ans = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'A'){
            x--;
            update(x+1);

        }else if(s[i] == 'B'){
            x++;
            update(x-1);

        }else{
            update(x);
        }
        ans += query(n+500001) - query(x);
    }

    cout<<ans<<'\n';
}
