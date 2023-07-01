/*
	Date: 29th
	Time:
	Learnt: Notice how to solve the problem can be spli into two cases, solving for right and left side.
	Rating: 1800
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define PI 3.14159265358979323846
#define sbits(x) __builtin_popcount(x)
#define tbits(total_size , num) total_size - __builtin_clz(num)
#define pb push_back
#define f first
#define s second
#define clr(ds) ds.clear()
#define all(ds) ds.begin() , ds.end()
#define pi pair<ll , ll>
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pi>
#define sz(i) (int)i.size()
#define rsz(ds ,size , val) ds.assign(size , val);
int xP[] = {0,0,1,-1,1,1,-1,-1} , yP[] = {1,-1,0,0,1,-1,-1,1};
using namespace std;
uint64_t time() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}
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
	vpi arr(n);
	for(auto& [x,y] : arr)
		cin >> x >> y , y+=x;
	vll left(n) , right(n);
	left[0] = arr[0].s;
	right[n-1] = arr[n-1].s;
	for(int i =1 ; i<n;i++){
			left[i] = min(left[i-1] +1 , arr[i].s);
			right[n-1-i] = min(right[n-i] +1 , arr[n-1-i].s);
			//cerr << right[i] << " ";
	}
	vi ans(n);
	for(int i =0;i<n;i++)
		ans[i] = min(left[i] , right[i]);
	bool good = 1;
	for(int i =0;i<n;i++){
		if(!(ans[i]>=arr[i].f && ans[i]<=arr[i].s))
			good = 0;
	}
	if(good)
	{
		ll total = 0;
		for(int i =0;i<n;i++)
			total+=ans[i] - arr[i].f;
		cout << total << "\n";
		for(int& a : ans)
			cout << a <<  " ";
	} else
		cout << -1 << '\n';
	
}

int main(){
	setIO();
	int t = 1;
// 	cin >> t;
	while(t--){
		solve();
	}	
}

