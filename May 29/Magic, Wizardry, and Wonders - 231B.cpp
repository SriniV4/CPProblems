//https://codeforces.com/contest/231/problem/B
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
	int n , d , l;
	cin >> n >> d >> l;
	int pos = (n+1)/2;
	int neg = n- pos;
	int max = pos*l - neg;
	int min = pos-neg*l;
	if(max<d || min>d)
		cout << -1;
	else {
		if(d>=0){
			vector<int> p(pos , l) , ne(neg , 1);
			int curr = max;
			int diff = curr - d;
			int pointer = 0;// deal with n%2 , d= 0 case
			if(d==0 && n%2){
				cout << "1 2 ";
				for(int i = 3;i<=n;i++)
					cout << 1 << " ";
				return;
			}	
			while(diff){
				int temp =std::min(l-1 , diff);
				diff-=temp;
				p[pointer++]-=temp;
			}
			for(int i =0 ;i<std::min(pos,neg);i++)
				cout << p[i]  << " " << ne[i] << " ";
			if(n%2)
				cout << p[pos-1] << " ";
		} else {
			vector<int> p(pos , 1) , ne(neg , l);
			int curr = min;
			int diff = curr-d;
			int pointer  =0;
			while(diff){
				int temp =std:: min(abs(diff) , l-1);
				p[pointer++]+=temp;
				diff+=temp;
			}
			for(int i =0 ;i<std::min(pos,neg);i++)
				cout << p[i]  << " " << ne[i] << " ";
			if(n%2)
				cout << p[pos-1] << " ";

		}

	}
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
