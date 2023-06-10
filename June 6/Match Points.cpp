/*
	Date: 
	Time:
	Learnt: Read over impl -> look for LL mistakes
	Rating: 2000
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define PI 3.14159265358979323846
#define bits(x) __builtin_popcount(x)
#define pb push_back
#define trav(ds , name) for(auto&name : ds)
#define f first
#define s second
#define clr(x) x.clear()
#define all(a) a.begin() , a.end()
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
	ll n,  z;
	cin >> n >> z;
	vll arr(n);

	for(int i = 0 , a;i<n;i++)
		{
				cin >> arr[i];
		}
	int answer = 0;
	int l = 0 ,r = n/2;
	sort(all(arr));
	while(l<n/2 && r<n){
			if(arr[l]+z<=arr[r]){
					l++;
					r++;
					answer++;
			} else
				r++;
	}
	cout << answer << "\n";
	
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
