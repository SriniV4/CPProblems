//https://codeforces.com/contest/1151/problem/B
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
	int n , m;
	cin >> n >> m;
	vector<vector<int>> arr(n , vector<int>(m));
	for(int i =0;i<n;i++)
		for(int j= 0 ;j<m;j++)
			cin >> arr[i][j];
	for(int i = 0; i<10;i++){
		int no = 0 , y = 0;
		vector<int> temp(n);
		for(int j= 0 ; j<n;j++){
			int yy = 0, nn = 0;
			for(int k= 0 ; k<m;k++){
				if(arr[j][k]&(1<<i))
					yy++;
				else
					nn++;
			}
			if(yy==0){
				no++;
				temp[j] = 2;
			}
			else if(nn==0){
				y++;
				temp[j] =  1;
			} else
				temp[j] = 0;

		}
		if(no==n || (y==n && n%2==0) || (y+no==n && y%2==0))
			continue;

		cout << "TAK\n";
		for(int j = 0 ;j<n;j++){
			if(temp[j])
				cout << 1 << " ";
			else {
				for(int k = 0 ;k<m;k++){
					if(arr[j][k] & (1<<i)){
						if(y%2==0)
						{
							cout << k+1 << " ";
							y++;
							break;
						}
					} else if(y%2){
						cout << k+1 << " ";
						break;
					}
				}
			}
		}	
		return;
	}
		cout << "NIE";
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
