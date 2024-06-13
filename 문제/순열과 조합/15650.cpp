#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> numbers;
vector<int> selected(10);

void combi(int start, int cnt) {
  if (cnt == M) {
    for (int i = 0; i < M; i++) cout << selected[i] << " ";
    cout << "\n";

    return;
  }

  for (int i = start; i < N; i++) {
    selected[cnt] = numbers[i];
    combi(i + 1, cnt + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    numbers.push_back(i);
  }

  combi(0, 0);

  return 0;
}