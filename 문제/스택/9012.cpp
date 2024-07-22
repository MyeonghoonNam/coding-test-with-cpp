#include <bits/stdc++.h>
using namespace std;

int T;
string ps;
char c;

bool check(string s) {
  stack<char> stk;

  for (int i = 0; i < (int)ps.size(); i++) {
    c = ps[i];

    if (c == '(') {
      stk.push(c);
    } else {
      if (stk.empty()) {
        return false;
      }

      stk.pop();
    }
  }

  return stk.empty();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;

  while (T--) {
    cin >> ps;

    if (check(ps)) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }

  return 0;
}