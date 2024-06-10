#include <bits/stdc++.h>
using namespace std;

#define N 9

int person[N];
int r = 7;

vector<int> selected;
vector<int> visited(N + 4, false);

void getCombi(int start, int cnt) {
  if (cnt == r) {
    int sum = 0;

    for (int v : selected) {
      sum += v;
    }

    if (sum == 100) {
      sort(selected.begin(), selected.end());
      for (int v : selected) cout << v << "\n";
      exit(0);
    }

    return;
  }

  for (int i = start; i < N; i++) {
    if (visited[i] == false) {
      selected.push_back(person[i]);
      visited[i] = true;
      getCombi(i + 1, cnt + 1);
      visited[i] = false;
      selected.pop_back();
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < N; i++) {
    cin >> person[i];
  }

  getCombi(0, 0);

  return 0;
}