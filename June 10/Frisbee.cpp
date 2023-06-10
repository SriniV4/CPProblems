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
#define sz(i) i.size()
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
int n;
vi arr;
void solve(){
	cin >> n;
	rsz(arr , n , 0);
	trav(a , arr)
		cin >> a;
	ll ans = n-1;
	ans*=2;
	vi left(n) , right(n);
	stack<int> s;
	for(int i = 0;i<n;i++){
			while(s.size() && arr[i]>arr[s.top()])
				s.pop();
			left[i] = s.size()?s.top():i;
			s.push(i);
	}
	while(s.size())
		s.pop();
	for(int i = n-1;i>=0;i--){
			while(s.size() && arr[i]>arr[s.top()])
				s.pop();
			right[i] = s.size()?s.top():i;
			s.push(i);
	}
	//trav(d , right)
		//cout << d << " ";
	//cout << "\n";
	for(int i = 0;i<n;i++){
		int r = right[i] , l = left[i];
		if(r>i+1)
			ans+=r-i+1;
		if(l<i-1)
			ans+=i-l+1;
		//cout << ans << " ";?
		//cout.flush();
	}
	cout << ans << "\n";
	cout.flush();
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
