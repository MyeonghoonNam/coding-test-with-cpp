#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 10

int N, M;
vector<int> numbers;
vector<int> selected(MAX_SIZE);

void print() {
  for (int i = 0; i < M; i++) cout << selected[i] << " ";
  cout << "\n";

  return;
}

void combi(int start, int cnt) {
  if (cnt == M) {
    print();
    return;
  }

  for (int i = start; i < N; i++) {
    selected[cnt] = numbers[i];
    combi(i, cnt + 1);
  }

  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) numbers.push_back(i);

  combi(0, 0);

  return 0;
}