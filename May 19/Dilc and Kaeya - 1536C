//https://codeforces.com/contest/1536/problem/C
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;

size_t hF(pair < int, int > a) {
  return (a.first + a.second) * (a.first + a.second + 1) / 2 + a.second;
}
void setIO(string name = "") {
  cin.tie(0) -> sync_with_stdio(0);
  if (name.size()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

void solve() {
   int n;
   unordered_map<pair<int , int> , int , function<size_t(pair<int , int>) > > counts(2 , hF);
   cin >> n;
   string line;
   cin >> line;
   int k = 0 , d = 0;
   for(int i = 0;i<n;i++){
        
       (line[i]=='K'?k:d)++;
       int tk = k , td = d;
       if(d==0 || k==0){
           counts[{0,0}]++;
       } else {
          
           int c = gcd(tk , td);
           tk/=c;
           td/=c;
           counts[{tk,td}]++;
       }
       cout << (k==0||d==0?counts[{0,0}]:counts[{tk,td}]) << " ";
   }
   cout << '\n';
}
int main() {
      setIO();
      int t = 1;
      cin >> t;
      while (t--) {
        solve();
      }
    }


