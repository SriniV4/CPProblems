//https://codeforces.com/problemset/problem/1775/A1
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
	string line;
	cin >> line;
	int index = -1;
	for(int i = 1 ;i<line.length()-1;i++)
		if(line[i]=='a'){
			index = i;
			break;
		}
	if(index==-1){
		cout << line[0] << " " << line.substr(1 , line.length()-2) << " " << line[line.length()-1] << "\n";
	} else {
		cout << line.substr(0 , index) << " " << 'a' << " " << line.substr(index+1 , line.length()-1-index) << "\n";
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

