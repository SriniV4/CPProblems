//https://codeforces.com/contest/1661/problem/C
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define PI 3.14159265358979323846
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
vector<int> arr;
bool valid(ll k , int max){
	ll sum = 0;
	ll t = k/2;
	for(int d : arr){
		ll  diff = max-d;
		ll num = min(t , diff/2);
		diff-=num*2;
		sum+=diff;
		t-=num;
	}
	return sum<=((k+1)/2);
}
void solve(){
	int n;
	cin >> n;
	rsz(arr , n);
	for(int i = 0 ;i<n;i++)
		cin >> arr[i];
	sort(arr.begin() , arr.end());
	ll left = 0 , right = 1e18 , ans = -1;;
	while(left<=right){
		ll mid = left+(right-left)/2;
		if(valid(mid , arr[n-1]) || valid(mid , arr[n-1]+1))
		{
			ans = mid;
			right = mid -1;
		} else
			left = mid+1;
	}
	cout << ans << "\n";
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
