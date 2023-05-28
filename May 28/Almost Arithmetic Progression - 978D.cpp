//https://codeforces.com/contest/978/problem/D
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
	vector<int> arr(n);
	for(int i = 0 ; i<n;i++)
		cin >> arr[i];
	int ans = INT_MAX;
	if(n==2)
		cout << 0 << "\n";
	else {
	for(int i = -1;i<=1;i++){
		for(int j = -1;j<=1;j++){
			int moves = 0 , a1 = arr[0]+i , d = arr[1]+j-a1;
			bool val = true;
			for(int k = 2 ; k<n;k++){
				int ak = a1+d*k;
				if(abs(ak-arr[k])>1){
					val = false;
					break;
				} else
					moves+=abs(ak-arr[k]);
			}
			if(i!=0)
				moves++;
			if(j!=0)
				moves++;
			if(val)
				ans= min(moves , ans);
		}
	}
	cout << (ans==INT_MAX?-1:ans) << "\n";
	}
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
