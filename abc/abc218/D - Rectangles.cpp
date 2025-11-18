#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x,y;
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    set<pair<int,int>> st;
    Point p[n];

    for(int i=0; i<n; i++){
        cin>>p[i].x>>p[i].y;
        st.insert({p[i].x, p[i].y});

    }

    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(p[i].x != p[j].x && p[i].y != p[j].y){
                ans+=(st.count({p[i].x , p[j].y}) && st.count({p[j].x , p[i].y}));
            }
        }
    }

    cout<<ans/2<<'\n';
}

