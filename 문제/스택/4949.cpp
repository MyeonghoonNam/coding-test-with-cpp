#include <bits/stdc++.h>
using namespace std;

string s;

bool check(string s) {
  stack<char> stk;

  for (int i = 0; i < (int)s.length(); i++) {
    char c = s[i];

    if (c == '(' || c == '[') {
      stk.push(c);
    } else if (c == ')') {
      if (stk.size() != 0 && stk.top() == '(') {
        stk.pop();
      } else {
        return false;
      }
    } else if (c == ']') {
      if (stk.size() != 0 && stk.top() == '[') {
        stk.pop();
      } else {
        return false;
      }
    }
  }

  return stk.empty();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true) {
    getline(cin, s);

    if (s == ".") break;

    if (check(s)) {
      cout << "yes" << "\n";
    } else {
      cout << "no" << "\n";
    }
  }

  return 0;
}
