#include <bits/stdc++.h>

using namespace std;

deque<int> dq;

int main() {
  // for (int i = 1; i <= 10; i++) dq.push_front(i);
  for (int i = 1; i <= 10; i++) dq.push_back(i);

  cout << dq.front() << " ";
  cout << dq.back() << " ";

  return 0;
}