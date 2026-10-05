#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define double long double

const double EPS = 9e-18L;
const double  INF = 9e18;

struct Point{
    int id,x,y;
    bool operator== (const Point &b) const{
        return x == b.x && y == b.y;
    }
};
Point p[305];
bool used[305][305];
int n,k;

int check(Point a, Point b){
    if(used[a.id][b.id]) return 0;
    double m = 1.0L*(a.y - b.y) / (a.x - b.x);
    if((a.x - b.x) == 0) m = INF;
    
    used[a.id][b.id] = 1;
    used[b.id][a.id] = 1;

    int cnt = 0;
    vector<Point> v1;

    for(int i=1; i<=n; i++){
        Point c = p[i];
        if(p[i] == a || p[i] == b){
            v1.push_back(c);
            cnt++;
            continue;
        }
        
        double m1 = 1.0L*(a.y - c.y) / (a.x - c.x);
        if((a.x - c.x) == 0) m1 = INF;
        if(abs(m - m1) < EPS){
            v1.push_back(c);
            cnt++;
        }
    }

    if(cnt >= k){
        for(int i=0; i<v1.size(); i++){
            for(int j=i+1; j<v1.size(); j++){
                used[v1[i].id][v1[j].id] = 1;
                used[v1[j].id][v1[i].id] = 1;
            }
        }
        return 1;
    }

    return 0;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k;
    if(k == 1){
        cout << "Infinity\n";
        return 0;
    }

    for(int i=1; i<=n; i++){
        cin >> p[i].x >> p[i].y;
        p[i].id = i;
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            ans += check(p[i],p[j]);
        }
    }

    cout << ans << '\n';
}