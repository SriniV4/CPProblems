/*
	Date: 06.06.2023
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
#define trav(a , b) for(auto&b : a)
#define f first
#define s second
#define clr(x) x.clear()
#define all(a) a.begin() , a.end()
#define pi pair<int , int>
#define vi vector<int>
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
		string line;
		cin >> line;
		string ans = "";
		char letter = line[0];
		int pointer = 1;
		while(pointer < n){
					ans+=letter;
				while(line[pointer]!=letter)
					pointer++;
				pointer++;
				if(pointer<n)
					letter = line[pointer++];
		}
		cout << ans << "\n";
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
