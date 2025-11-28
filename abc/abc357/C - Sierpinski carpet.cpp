#include <bits/stdc++.h>
using namespace std;

int pow3[]={1, 3, 9, 27, 81, 243, 729, 2187};

char mat[2200][2200];

void init(){
    for(int i=0; i<2200; i++){
        for(int j=0; j<2200; j++){
            mat[i][j]='#';
        }
    }
}

void op(int n, int x, int y){
    if(n==0) return;

    for(int i=x; i<x+3*pow3[n-1]; i+=pow3[n-1]){
        for(int j=y; j<y+3*pow3[n-1]; j+=pow3[n-1]){
            op(n-1, i,j);
        }
    }

    for(int i=x+pow3[n-1]; i<x+2*pow3[n-1]; i++){
        for(int j=y+pow3[n-1]; j<y+2*pow3[n-1]; j++){
            mat[i][j]='.';
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie();

    init();
    int n;
    cin>>n;
    op(n,0,0);

    for(int i=0; i<pow3[n]; i++){
        for(int j=0; j<pow3[n]; j++){
            cout<<mat[i][j];
        }
        cout<<'\n';
    }
}
