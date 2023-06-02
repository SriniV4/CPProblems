/*
  Time: 15:00
  Num Submissions: 2
  Learnt: USE LL
  Time Complexity : O(N)
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

void solve(){
	int n;
	cin >> n;
	vector<ll> arr(n);
	map<int , ll> cnt;
	for(int i =0 ; i<n;i++){
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	vector<ll > cost(n+1 , -1);
	stack<ll> extra;
	ll numZero = cnt[0];
	if(numZero)
		cost[0] = 0;
	else {
		cout << 0 << " ";
		for(int i =1 ;i<=n;i++)
			cout << -1 << " ";
		cout << "\n";
		return;
	}
	numZero--;
	while(numZero)
	{
		extra.push(0);
		numZero--;
	}
	for(int i = 1 ; i<=n;i++){
		int num = cnt[i];
		if(num){
			cost[i] = cost[i-1];
			for(int j = 1;j<num;j++)
				extra.push(i);
		} else {
			if(extra.size()){
				int temp = extra.top();
				extra.pop();
				cost[i] = cost[i-1] + i-temp;
			} else {
				break;
			}
		}
	}
	cout << cost[0]+cnt[0] << " ";
	for(int i =1 ; i<=n;i++){
		if(cost[i-1]==-1)
			cout<< -1 << " ";
		else
			cout << cost[i-1] + cnt[i] << " ";
	}
	cout << "\n";

}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
