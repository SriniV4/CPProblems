//https://codeforces.com/contest/753/problem/A
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
	int n;
	cin >> n;
	int count = 1;
	int counter = 2;
	while(count+counter<=n){
		count+=counter;
		counter++;
	}
	if(n==1)
	{
		cout << "1\n1\n";
		return;
	}
	cout << counter-1 << "\n";
	for(int i = 0;i<counter-2;i++){
		cout << i+1 << " ";
		n-=i+1;
	}
	if(n>0)
		cout << n << " ";
	cout << "\n";
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
