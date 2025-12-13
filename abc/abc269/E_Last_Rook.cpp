#include <bits/stdc++.h>
using namespace std;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n;
    cin>>n;
    int ans_r, ans_c;
    int l=1, r=n;
    while(l <= r){
        int mid = (l+r)/2;
        cout << "? " <<l<<' '<<mid<<' '<<1<<' '<<n<<'\n';
        cout.flush();

        int rst;
        cin>>rst;

        if(rst != mid - l +1){
            ans_r = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }

    l=1, r=n;
    while(l <= r){
        int mid = (l+r)/2;
        cout << "? " <<1<<' '<<n<<' '<<l<<' '<<mid<<'\n';
        cout.flush();

        int rst;
        cin>>rst;

        if(rst != mid - l +1){
            ans_c = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }

    cout << "! " << ans_r << ' ' << ans_c << '\n';

}