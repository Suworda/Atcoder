#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;

signed main(){
    
    cin>>n;
    int ans = 0;
    int l = 1, r = 2;
    while(1){
        if(r > n) break;
        cout << "? " << l << ' ' << r << '\n';
        cout.flush();
        string rst;
        cin>>rst;

        if(rst == "Yes"){
            ans += (r-l);
            r++;
        }else{
            l++;
        }
        
        if(l == r) r++;

    }
    
    cout<<"! "<<ans<<'\n';
}