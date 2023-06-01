//https://codeforces.com/contest/1798/problem/D
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
	int nn;
	cin >>nn;
	vector<int> p , n;
	for(int i =0 ; i<nn;i++)
	{
		int a;
		cin >> a;
		if(a>0)
			p.push_back(a);
		else if(a<0)
			n.push_back(a);
	}
	sort(p.begin() , p.end() , greater<int>());
	sort(n.begin() , n.end());
	if(p.size()&&n.size()){
		int pE =0 , nE=0;
		int sum = 0;
		cout << "YES\n";
		while(pE<p.size() && nE<n.size())
		{
			if(sum>0)
			{
				sum+=n[nE];
				cout << n[nE++] << " ";
			} else
			{
				sum+=p[pE];
				cout << p[pE++] << " ";
			}
		}
		while(pE<p.size())
			cout << p[pE++] << " " ;
		while(nE<n.size())
			cout << n[nE++] << " ";
		for(int i =0 ; i<nn-(p.size()+n.size());i++)
			cout << 0 << " ";
		cout << "\n";
	} else 
		cout << "NO\n";
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
