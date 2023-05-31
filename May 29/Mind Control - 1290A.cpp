//https://codeforces.com/contest/1290/problem/A
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

void solve(){
	int n , m ,k;
	cin >> n >> m>>k;
	vector<int> arr(n);
	for(int i = 0;i<n;i++)
		cin >> arr[i];
	int answer = 0;
	k= min(k , m-1);
	for(int x = 0 ; x<=k;x++){
		int left = x , right = n-1-k+x;
		int remainingPeople = m-1-k;
		int temp = INT_MAX;
		for(int i = 0 ;i<=remainingPeople;i++){
			int newLeft = left + i , newRight = right-(remainingPeople-i);
			temp = min(max(arr[newLeft] , arr[newRight]) , temp);
		}
		answer = max(answer , temp);
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
