//https://codeforces.com/contest/1553/problem/D
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
   string a , b;
   getline(cin ,a);
   getline(cin , b);
  
   int pA = a.length()-1 ,pB = b.length()-1;
   while(pA>=0 && pB>=0){
       if(a[pA]==b[pB]){
           pA--;
           pB--;
       } else 
        pA-=2;
   }
   //cout << a << "b << ' '  << pB << ' ';
   cout << (pB==-1?"YES":"NO") << "\n";
}
int main() {
      setIO();
      int t = 1;
      cin >> t;
      string a;
      getline(cin , a);
      while (t--) {
        solve();
      }
    }


