/*
  Time: 60:23
  Num Submissions: 1
  Learnt: 
    Try and use geometry -> Rewrite conditions
  Time Complexity : O(N)
  Editorial : Same
  Rating: 1700
*/
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
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ;i<n;i++)
        cin >> arr[i];
    ll ans = n + n-1;
    for(int i = 0 ;i<n-2;i++){
        if(!(arr[i]<=arr[i+1] && arr[i+1] <=arr[i+2] || arr[i]>=arr[i+1] && arr[i+1]>=arr[i+2])){
            ans++;
        }
    }
    //cout << ans << " ";
    for(int i= 0 ; i<n-3;i++){
        int valid = 0;
        if(!(arr[i]<=arr[i+1] && arr[i+1]<=arr[i+2]  || 
            arr[i+1]<=arr[i+2] && arr[i+2]<=arr[i+3] || 
             arr[i]<=arr[i+2] && arr[i+2]<=arr[i+3] ||
              arr[i]<=arr[i+1] && arr[i+1]<=arr[i+3])){
                valid++;
        } 
        if(!(arr[i]>=arr[i+1] && arr[i+1]>=arr[i+2]  || 
            arr[i+1]>=arr[i+2] && arr[i+2]>=arr[i+3] || 
             arr[i]>=arr[i+2] && arr[i+2]>=arr[i+3] || 
             arr[i]>=arr[i+1] && arr[i+1]>=arr[i+3])){
                valid++;
             }

             if(valid==2)
             ans++;
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
