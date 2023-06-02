/*
  Time: 50:00
  Num Submissions: 2
  Learnt: 
  	a) KnapSack DP
    b) Check where you initalize variables!
  Time Complexity : O(N*X + N*(min(log(a(1...n)))
  Editorial : Same
  Rating: 1700
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define PI 3.14159265358979323846
#define bits(x) __builtin_popcount(x)
#define pb push_back
#define f first
#define s second
#define clr(x) x.clear()
#define rsz(x ,n) x.resize(0); x.resize(n);
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
int n;
void solve(){
	cin >> n;
	vector<pair<int , int>> arr(n);
	ll sum = 0;
	for(int i = 0 ;i<n;i++){
		cin >> arr[i].f;
		sum+=arr[i].f;
		arr[i].s = i;
	}
	if(sum%2)
		cout << "0\n";
	else {
		sum/=2;
		sort(arr.begin() , arr.end());
		vector<ll> dp(sum+1);
		for(int i = 0 ; i<n;i++){
			auto d = arr[i];
			if(d.f<=sum)
				dp[d.f] = i+1;
		}
		for(int i =0 ; i<n;i++){
			for(int j = 1;j<=sum-arr[i].f;j++){
				if(dp[j] && dp[j]!=i+1 && dp[j+arr[i].f]==0)
					dp[j+arr[i].f] = i+1;
			}
		}
		if(dp[sum]/* possible way to partion array */){
		   ll MOD = 2;
		    while(true){
			for(int i =0 ;i<n;i++){
				if(arr[i].f%MOD)
				{
					cout << "1\n";
					cout << arr[i].s+1 << "\n";
					return;
				}
			}
			MOD*=2;
		    }
		} else{
			cout << "0\n";
		}
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
