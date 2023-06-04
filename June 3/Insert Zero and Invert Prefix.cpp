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
	vector<int> arr(n);
	for(int i=  0;i<n;i++)
		cin >> arr[i];
	if(arr[n-1]==1){
		cout << "NO\n";
	} else {
		cout << "YES\n";
		int pointer =n-1;
		while(pointer>=0){
		while(pointer-1>=0 && arr[pointer-1]!=1)
		{
			cout << 0 << " ";
			pointer--;
		}
		int numOnes = 0;
		if(pointer==0){
			cout << "0 \n";
			return;
		}
		pointer--;
		while(pointer>=0 && arr[pointer]==1)
		{
			numOnes++;
			pointer--;
		}
		for(int i = 0 ;i<numOnes;i++)
			cout << 0 << " ";
		cout << numOnes << " ";
		}
		cout << "\n";
	}
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
