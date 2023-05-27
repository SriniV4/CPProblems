//https://codeforces.com/contest/1810/problem/C
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
	ll n , c , d;
	cin >> n >> c >> d;
	vector<int> arr;
	ll extra = 0;
	unordered_map<int , int> count;
	for(int i = 0;i<n;i++){
		int a;
		cin >> a;
		if(!count[a])
			arr.push_back(a);
		else
			extra++;
		count[a]++;
	}
	sort(arr.begin() , arr.end());
	ll ans = c*extra;
	ll curr =1 ;
	ans+=(arr[0]==1?0:d);
	ll missing = 0;
	ll size = arr.size();
	ll temp = c*(arr[0]==1?arr.size()-1:arr.size());
	
	for(int i = (arr[0]==1?1:0);i<arr.size();i++){
		missing+=(i==0?arr[i]-2:arr[i]-arr[i-1]-1);
		temp = min(temp , missing*d+c*(size-i-1));
		
	}
	cout << ans+temp << "\n";
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
