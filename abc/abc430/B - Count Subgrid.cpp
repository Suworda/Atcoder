#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m,n;
    cin>>n>>m;
    char a[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }

    set<vector<string>> shape;
    for(int i=0; i<=n-m; i++){
        for(int j=0; j<=n-m; j++){
            vector<string> cur;
            for(int r=i; r<i+m; r++){
                string s;
                for(int c=j; c<j+m; c++){
                    s+=(a[r][c]);
                }
                cur.push_back(s);
            }
            shape.insert(cur);
        }
    }

    cout<<shape.size()<<'\n';

}
