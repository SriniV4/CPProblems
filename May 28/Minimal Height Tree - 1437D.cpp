//https://codeforces.com/contest/1437/problem/D
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

void solve(){
	queue<int> q;
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int& d : arr)
		cin >> d;
	int curr = 1;
	q.push(0);
	int answer = 0;
	while(curr<n){
		int x = q.front();
		q.pop();
		q.push(x+1);
		answer = max(answer ,  x+1);
		curr++;
		while(curr<n && arr[curr]>arr[curr-1])
		{
			q.push(x+1);
			curr++;
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
