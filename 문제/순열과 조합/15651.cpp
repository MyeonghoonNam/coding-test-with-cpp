#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> numbers;
vector<int> selected;

void print() {
  for (int i = 0; i < M; i++) cout << selected[i] << " ";
  cout << "\n";

  return;
}

void permutation(int cnt) {
  if (cnt == M) {
    print();
    return;
  }

  for (int i = 0; i < N; i++) {
    selected.push_back(numbers[i]);
    permutation(cnt + 1);
    selected.pop_back();
  }

  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) numbers.push_back(i);

  permutation(0);

  return 0;
}