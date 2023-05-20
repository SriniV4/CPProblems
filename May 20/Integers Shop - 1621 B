//https://codeforces.com/contest/1621/problem/B
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define PI 3.14159265358979323846
using namespace std;

size_t hF(pair<int , int> a){
	return (a.first + a.second)*(a.first + a.second + 1)/2 + a.second;
}
void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

void solve(){
	int n;
	cin >> n;
	ll minNum = INT_MAX , maxNum = INT_MIN , minCost = INT_MAX , maxCost = INT_MAX , fullCost = 0;
	for(int i = 0; i<n;i++){
		ll l , r , c;
		cin >> l >> r >> c;
		if(l<minNum && r>maxNum){
			minNum = l;
			maxNum = r;
			minCost = c;
			maxCost = c;
			fullCost = c;
		} else if(l<minNum && r==maxNum || r>maxNum && l==minNum){
			fullCost = c;
			if(r==maxNum){
				minCost = c;
				maxCost = min(maxCost , c);
			} else
				maxCost = c;
				minCost = min(minCost , c);
		} else if(l==minNum && r==maxNum){
			fullCost = min(fullCost , c);
			minCost = min(minCost , c);
			maxCost = min(maxCost , c);
		} else if(r==maxNum){
			maxCost = min(maxCost , c);
		} else if(l==minNum){
			minCost = min(minCost , c);
		} else if(l<minNum){
			minNum = l;
			minCost = c;
			fullCost = INT64_MAX;
		}
		 else if(r>maxNum){
			maxNum = r;
			maxCost = c;
			fullCost = INT64_MAX;
		}
		minNum = min(minNum , l);
		maxNum = max(maxNum , r);
		//cout << minNum << " " << maxNum << " " << min(fullCost , maxCost + minCost) << "\n";
		cout << min(fullCost , maxCost + minCost) <<"\n";
	}
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
