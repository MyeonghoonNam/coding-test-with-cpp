#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> numbers(10);
vector<int> selected(10);
vector<bool> visited(10, false);

void permutation(int cnt) {
  if (cnt == M) {
    for (int i = 0; i < M; i++) cout << selected[i] << " ";
    cout << "\n";

    return;
  }

  for (int i = 0; i < N; i++) {
    if (visited[i] == true) continue;

    selected[cnt] = numbers[i];
    visited[i] = true;
    permutation(cnt + 1);
    visited[i] = false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    numbers[i] = i + 1;
  }

  permutation(0);

  return 0;
}