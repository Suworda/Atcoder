#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct Point{
	int x; int y;
	
};
Point p[2005];


struct Slope{
	int dx; int dy;
	
	bool operator<(const Slope &b) const{
		return (double)dy/dx < (double)b.dy/b.dx;
	}
};

map<Slope,vector<pair<int,int>>> cnt1;

int n;

double get_slope(int a, int b){
	return double(p[a].y-p[b].y) / (p[a].x-p[b].x);
}

bool para(int a, int b, int c, int d){
	return get_slope(a,b) == get_slope(c,d);
}

bool para2(int a, int b, int c, int d){
	return para(a,c,b,d) || para(a,d,b,c);
	
}


int main() {
	int ans=0;
	cin>>n;
	
	for(int i=0; i<n; i++){
		cin>>p[i].x>>p[i].y;
	}
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int dx=p[i].x-p[j].x;
			int dy=p[i].y-p[j].y;
			if(dy<0){
				dx=-dx;
				dy=-dy;
			}
			int g=__gcd(dx,dy);
			cnt1[{dx/g,dy/g}].push_back({i,j});
			
		}
	}
	int re=0;
	for(auto x:cnt1){
		ans+=x.second.size()*(x.second.size()-1)/2;
//		cout<<x.first.dx<<' '<<x.first.dy<<' '<<x.second.size()*(x.second.size()-1)/2<<'\n';
		for(int i=0; i<x.second.size(); i++){
			for(int j=i+1; j<x.second.size(); j++){
				re+=(para2(x.second[i].first , x.second[i].second , x.second[j].first , x.second[j].second));
			}
		}
	}
	ans-=re/2;
	
	cout<<ans<<'\n';
}
