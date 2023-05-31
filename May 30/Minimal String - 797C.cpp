//https://codeforces.com/contest/797/problem/C
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
	string line;
	cin >> line;
	vector<char> suffix(1+line.length());
	suffix[line.length()] = line[line.length()-1];
	for(int i = line.length()-1;i>=1;--i)
		suffix[i] = min(suffix[i+1] , line[i-1]);
	string ans = "";
	suffix[0] = 0;
	stack<char> temp;
	int pointer = 0;
	while(pointer<line.length()){
			char let = suffix[pointer+1];
			while(line[pointer] != let){
				temp.push(line[pointer++]);
			}
			ans+=let;
			pointer++;
		if(pointer==line.length())
			break;
		while(temp.size() && temp.top()<=suffix[pointer+1]){
			ans+=temp.top();
			temp.pop();
		}
	}
	while(temp.size())
	{
		ans+=temp.top();
		temp.pop();
	}
	cout << ans << " ";

}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
