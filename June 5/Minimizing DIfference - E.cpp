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
	ll n, k;
	cin >>n >> k;
	vector<ll> arr(n);
	for(int i = 0;i<n;i++)
		cin >> arr[i];
	sort(arr.begin() , arr.end());
	ll left =0 , multR = 1 , right = n-1 , multL = 1 ,mn = arr[0]  , mx = arr[n-1];
	while(k && left<right){
			while(left+1<right && arr[left+1]==mn){
				left++;
				multL++;
			}
			while(right-1>left && arr[right-1]==mx)
				{
						multR++;
					right--;
}			if(left>=right)
				continue;
			if(multR>multL){
					ll cost = multL * (arr[left+1]-mn);
					if(cost>k)
					{
							cout << mx - mn - k/multL;
							return;
					}
					k-=cost;
					mn = arr[++left];
					multL++;
			} else {
									ll cost = multR * (mx-arr[right-1]);
					if(cost>k)
					{
							cout << mx - mn - k/multR;
							return;
					}
					k-=cost;
					mx = arr[--right];
					multR++;
			}
	}
	cout << mx - mn << "\n";
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
