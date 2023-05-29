//https://codeforces.com/contest/1296/problem/D
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
	int n , a , b ,k;
	cin >> n >> a >> b >> k;
	vector<int> arr(n);
	for(int& d : arr){
		cin >> d;
		d%=(a+b);
		if(d==0)
			d = (a+b);
	}
	sort(arr.begin() , arr.end());
	int answer = 0;
	for(int d : arr){
		if(d<=a)
			answer++;
		else{
			if(k>=(ceil(d/(ld)a)-1)){
				answer++;
				k-=(ceil(d/(ld)a)-1);
			}
		}
	}
	cout << answer;
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
