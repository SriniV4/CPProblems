//https://codeforces.com/contest/1409/problem/D
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
	string num;
	int sum;
	cin >> num >> sum;
	int curr = 0;
	int pointer = 0;
	while(pointer < num.length() && curr+num[pointer]-48<=sum)
	{
		curr+=num[pointer]-48;
		pointer++;
	}
	if(pointer==num.length()){
		cout << "0\n";
		return;
	}
	if(sum==curr)
		pointer--;

	while(num[pointer]=='0')
		pointer--;
		ll temp = 1 , val = stoll(num.substr(pointer , num.length() - pointer));
		while(temp < val)
			temp*=10;
		cout << temp - val << "\n";
	}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
