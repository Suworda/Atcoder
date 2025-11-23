#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Point{
    int x,y;
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int w,h;
    cin>>w>>h;
    int n;
    cin>>n;
    Point p[n];
    for(int i=0; i<n; i++){
        cin>>p[i].x>>p[i].y;
    }

    vector<int> X,Y;
    X.push_back(0);
    Y.push_back(0);

    int A,a;
    cin>>A;
    for(int i=0; i<A; i++){
        cin>>a;
        X.push_back(a);
    }
    sort(X.begin(), X.end());

    int B,b;
    cin>>B;
    for(int i=0; i<B; i++){
        cin>>b;
        Y.push_back(b);
    }
    sort(Y.begin(), Y.end());

    map< pair<int,int> , int > cnt;

    for(int i=0; i<n; i++){
        auto it_x = lower_bound(X.begin(), X.end(), p[i].x);
        auto it_y = lower_bound(Y.begin(), Y.end(), p[i].y);
        cnt[{*it_x, *it_y}]++;
    }

    int ans1=2e9 , ans2=0;
    for(auto &d: cnt){
        ans1=min(ans1, d.second);
        ans2=max(ans2, d.second);
    }

    if(cnt.size() == (A+1)*(B+1)) cout<<ans1<<' ';
    else cout<<0<<' ';

    cout<<ans2<<'\n';
}
