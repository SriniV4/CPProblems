//https://codeforces.com/contest/1833/problem/F
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
ll expo(ll a , ll b , ll m){//(a^b)%m
    ll ans = 1 , curr = a%m;    
    while(b){
        if(b&1){
            ans*=curr;
            ans%=m;
        }
        curr = (curr%m) * (curr%m)%m;
        b>>=1;
    }
    return ans%m;
}
int n ,m , MOD = (int)1e9+7;
void solve(){
	cin >> n >> m;
	vector<int> arr(n);
	vector<int> u;
	unordered_map<int ,ll> seen;
	for(int i = 0 ; i<n;i++){
		cin >> arr[i]; 
		if(!seen[arr[i]])
			u.push_back(arr[i]);
		seen[arr[i]]++;
	}
	sort(u.begin() , u.end());
	vector<ll> prefix(u.size()+1);
	prefix[0] = 1;
	for(int i = 1 ; i<=u.size();i++){
		prefix[i]=prefix[i-1]*seen[u[i-1]]%MOD;
		//cout << prefix[i] << " ";
	}
	ll answer = 0;
	if(u.size()<m){
		cout << "0\n";
		return;
    }
	for(int i = 0 ; i<=u.size()-m;i++){
		if(u[i]+m-1==u[i+m-1]){
		    ll val = prefix[i+m]*(expo(prefix[i] , MOD-2 , MOD))%MOD;
		   // cout << val << " ";
			answer+=val;
			//cout << answer << " ";
			answer%=MOD;
		}
	}
	cout << answer << "\n";
	
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
