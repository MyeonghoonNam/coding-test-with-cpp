#include <bits/stdc++.h>

using namespace std;

// 오름차순
priority_queue<int, vector<int>, greater<int>> pq;

// 내림차순
priority_queue<int, vector<int>, less<int>> pq2;

int main() {
  for (int i = 5; i >= 1; i--) {
    pq.push(i);
    pq2.push(i);
  }

  while (pq.size()) {
    cout << pq.top() << " : " << pq2.top() << "\n";
    pq.pop();
    pq2.pop();
  }

  return 0;
}