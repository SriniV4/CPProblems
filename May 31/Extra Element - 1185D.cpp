//https://codeforces.com/contest/1185/problem/D
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

int n;
vector<array<int , 2>> arr;
bool val(int ind){
    int d = arr[2][0] - (ind?arr[0][0]:arr[1][0]);
    ll next = arr[2][0]+d;
    for(int i = 3;i<n;i++){
        if(arr[i][0]!=next)
            return false;
        next+=d;
    }
    return true;
}
void solve(){
    cin >> n;
    rsz(arr , n);
    for(int i =0 ; i<n;i++)
    {
        cin >> arr[i][0];
        arr[i][1] = i+1;
    }
    if(n==2){
        cout << 1;
        return;
    }
    sort(arr.begin() , arr.end());
    if(val(0)){
        cout << arr[0][1];
    } else if(val(1)){
        cout << arr[1][1];
    } else {
        int d = arr[1][0] - arr[0][0];
        //cout << d << ' ';
        int ele = -1;
        int next = arr[1][0] + d;
        for(int i = 2 ; i<n;i++){
            if(arr[i][0]!=next){
                if(ele==-1){
                    ele = arr[i][1];
                } else
                {
                    cout << -1;
                    return;
                }
            } else {
                next+=d;   
            }
        }
        cout << ele << "\n";
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
