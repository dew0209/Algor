#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int kMaxN = 2e5 + 100, L = 18, mod = 1e9 + 7;

int q, op, t, c;
priority_queue<ll> Q;
ll s;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> op;
    if (op == 1) {
      Q.push(-s);
    } else if (op == 2) {
      cin >> t, s += t;
    } else {
      for (cin >> t, c = 0; Q.size() && Q.top() + s >= t; c++, Q.pop()) {
      }
      cout << c << '\n';
    }
  }
  return 0;
}
