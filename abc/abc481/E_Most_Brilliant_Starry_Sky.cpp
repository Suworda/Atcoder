#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct Point{
    ll x, y;
    bool is_L;
    Point(int _x, int _y): x(_x), y(_y){
        if(x < 0) is_L = 1;
        else if(x > 0) is_L = 0;
        else is_L = (y > 0);
    }

    bool operator< (const Point &b) const{
        
        // return y/x < b.y/b.x;
        if((x == 0) != (b.x == 0)) return (x==0);
        if((x > 0) + (b.x > 0) != 1){
            return b.x*y < x*b.y;
        }
        else{
            return b.x*y > x*b.y;    
        }
    }
};

void sol(){
    int n;
    cin>>n;
    vector<Point> v;
    for(int i=1; i<=n; i++){
        ll a, b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());

    int L = 0;
    int R = 0;
    for(auto &p: v){
        R += !(p.is_L);
        // cout << p.x << ' ' << p.y << ' ' << 1.0*p.y/p.x << ' ' << p.is_L << '\n';
    }
    
    
    int ans = max(R, n-R);
    int cur = R;
    for(auto &p: v){
        if(p.is_L){
            cur++;
        }
        else{
            cur--;
        }
        ans = max({ans, cur, n-cur});
    }

    // cout << L << ' ' << R << '\n';

    cout << ans << '\n';
    // cout << "return\n";

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--) sol();
    
} 