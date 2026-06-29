#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,q;
int b[3][300005];
bitset<300005> apr;
int ans = 0;
int last1[300005], last2[300005];

void upd(int k, int val, int ty){
    while(k <= 300000){
        b[ty][k] += val;
        k += (k & -k);
    }
}

int query(int k, int ty){
    int rst = 0;
    while(k){
        rst += b[ty][k];
        k -= (k & -k);        
    }
    return rst;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>q;
    for(int i=1; i<=q; i++){
        int ty,x;
        cin>>ty>>x;

        if(ty == 1){
            if(!apr[x]){
                ans += n;
                apr[x] = 1;
                
            }else{
                ans += query(i, 2) - query(last1[x], 2);
            }
            if(last1[x]) upd(last1[x], -1, 1);
            upd(i, 1, 1);
            last1[x] = i;
            
        }else{ //2
            ans -= query(i, 1) - query(last2[x], 1);
            if(last2[x]) upd(last2[x], -1, 2);
            upd(i, 1, 2);
            last2[x] = i;
            
        }
        cout<<ans<<'\n';
    }
    
}
