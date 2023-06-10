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
bool Compare(pi a , pi b){
		return a.f==b.f?a.s>b.s:a.f>b.f;
}
void solve(){
	ll n , x , y;
	cin >> n >> x >> y;
	ll ans = 0;
	const int MOD = (int)1e9+7;
	priority_queue<pi , vector<pi> , function<bool(pi , pi)>> q(Compare);
	for(int i= 0;i<n;i++){
			int a , b;
			cin >> a >> b;
			q.push({a,b});
	}
	auto temp = q;
	vpi a;
	while(temp.size())
		{
				a.pb(temp.top());
				temp.pop();
		}
	//cout << "\n";
	//trav(item , a){
			//cout << item.f << " " << item.s << "\n";
	//}
	//cout << "\n";
	priority_queue<int , vi , greater<int>> going;
	priority_queue<int> finished;
	while(!q.empty()){
		//cout << ans << "\n";
		auto next = q.top();
		q.pop();
		while(going.size() && going.top()<next.f){
				finished.push(going.top());
				going.pop();
		}
		if(finished.size()==0){
				going.push(next.s);
				ans = (ans + x + y*(next.s-next.f))%MOD;
				continue;
		}
		
		ll latest = finished.top();
		if(y * (next.f-latest) < x){
				going.push(next.s);
				ans = (ans + y*(next.s-latest))%MOD;
				finished.pop();
		} else {
			going.push(next.s);
			ans = (ans + x + y*(next.s-next.f))%MOD;
		}
		
	}
	cout << ans << "\n";
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
