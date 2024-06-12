#include <bits/stdc++.h>
using namespace std;

int N, M, ret = 0;
int numbers[15001];
vector<int> selected;

void combi(int start, int cnt) {
  if (cnt == 2) {
    int sum = 0;

    for (int v : selected) {
      sum += v;
    }

    if (sum == M) {
      ret += 1;
    }

    return;
  }

  for (int i = start; i < N; i++) {
    selected.push_back(numbers[i]);
    combi(i + 1, cnt + 1);
    selected.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> numbers[i];
  }

  combi(0, 0);

  cout << ret;

  return 0;
}