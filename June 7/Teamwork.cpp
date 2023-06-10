/*
	Date: 
	Time:
	Learnt:
	Rating:
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define PI 3.14159265358979323846
#define bits(x) __builtin_popcount(x)
#define pb push_back
#define trav(name , ds) for(auto&name : ds)
#define f first
#define s second
#define clr(ds) ds.clear()
#define all(ds) ds.begin() , ds.end()
#define pi pair<int , int>
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pi>
#define rsz(ds ,size , val) ds.assign(size , val);
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
	int n , k;
	cin >> n >> k;
	vi arr(n);
	for(int i =0;i<n;i++)
		cin >> arr[i];
	vi dp(n , -1);
	for(int i =0;i<n;i++){
		int score = arr[i];
		for(int j = i;j>i-k && ~j;--j){
					score = max(score , arr[j]);
					if(j)
						dp[i] = max(dp[i] , dp[j-1] + score*(i-j+1));
					else
						dp[i] =max(dp[i] , score*(i-j+1)+0);
		}
	}	
	cout << dp[n-1]  << '\n';
}
int main(){
	setIO("teamwork");
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
