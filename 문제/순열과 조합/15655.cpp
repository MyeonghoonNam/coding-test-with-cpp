#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 8

int N, M;
vector<int> numbers(MAX_SIZE);
vector<bool> visited(MAX_SIZE, false);
vector<int> selected;

void print() {
  for (int i = 0; i < M; i++) {
    cout << selected[i] << " ";
  }

  cout << "\n";
}

void combi(int start, int cnt) {
  if (cnt == M) {
    print();
    return;
  }

  for (int i = start; i < N; i++) {
    if (visited[i] == true) continue;

    selected.push_back(numbers[i]);
    visited[i] = true;
    combi(i + 1, cnt + 1);
    visited[i] = false;
    selected.pop_back();
  }
}

int main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> numbers[i];
  }

  sort(numbers.begin(), numbers.begin() + N);
  combi(0, 0);

  return 0;
}