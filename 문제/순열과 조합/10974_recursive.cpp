#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> numbers;
vector<int> selected;
vector<bool> visited(N + 1, false);

void print() {
  for (int v : selected) cout << v << " ";
  cout << "\n";
}

void permutation(int cnt) {
  if (cnt == N) {
    print();
    return;
  }

  for (int i = 0; i < N; i++) {
    if (visited[i] == true) continue;

    selected.push_back(numbers[i]);
    visited[i] = true;
    permutation(cnt + 1);
    visited[i] = false;
    selected.pop_back();
  }
}

int main() {
  cin >> N;

  for (int i = 1; i <= N; i++) numbers.push_back(i);
  permutation(0);

  return 0;
}