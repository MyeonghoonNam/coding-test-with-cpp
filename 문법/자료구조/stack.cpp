#include <bits/stdc++.h>

using namespace std;

int main() {
  stack<string> stk;

  stk.push("s");
  stk.push("t");
  stk.push("a");
  stk.push("c");
  stk.push("k");

  while (stk.size() != 0) {
    cout << stk.top() << "\n";
    stk.pop();
  }

  return 0;
}