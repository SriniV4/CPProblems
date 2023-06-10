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
string a , b;
int q  , t;
vector<ll> tree;
void update(int index , int newNum , int n){
	index+=n;
	tree[index] = newNum;
	while(index!=1){
		index/=2;
		tree[index] = tree[index*2] + tree[index*2+1];
	}
}
void solve(){
	cin >> a ;
	cin >> b;
	cin >> t >> q;
	set<int> matters;
	int n = a.length();
	for(int i = 0;i<n;i++)
		if(a[i]!=b[i])
			matters.insert(i);
	int temp = n;
	while(bits(temp)!=1)
		temp++;
	rsz(tree , 2*temp);
	queue<pi> blocked;
	for(int i = 0;i<q;i++){
			int num;
			//cout << a << " " << b;
			cin >> num;
			if(blocked.size() && blocked.front().s==i){
				//cout << "YEasdfS\n";
					update(blocked.front().f , 0 , temp);
					blocked.pop();
			}
			if(num==1){
					int pos;
					cin >> pos;
					if(matters.count(pos-1)){
							blocked.push({pos-1 , i+t});
							update(pos-1 , 1 , temp);
					}
			} else 
			if(num==3){
					cout << (tree[1] >= (ll)matters.size()?"YES\n":"NO\n");
					cout.flush();
			} else {
					int s1 , p1 , s2 , p2;
					cin >> s1 >> p1 >> s2 >> p2;
					p1--;
					p2--;
						if(matters.count(p1)){
								matters.erase(p1);
						}	
						if(matters.count(p2))
							matters.erase(p2);
					if(s1==s2){

						if(s1==1){
								char temp = a[p1];
								a[p1] = a[p2];
								a[p2] = temp;

						} else {
														char temp = b[p1];
								b[p1] = b[p2];
								b[p2] = temp;	
						}

					} else {
							if(s1==1)
							{
								char temp = a[p1];
								a[p1] = b[p2];
								b[p2] = temp;
							} else {
														char temp = b[p1];
								b[p1] = a[p2];
								a[p2] = temp;									
							}
					}
							if(a[p1]!=b[p1])
								matters.insert(p1);
							if(a[p2]!=b[p2])
								matters.insert(p2);
			}
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
