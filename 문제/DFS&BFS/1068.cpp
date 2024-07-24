#include <bits/stdc++.h>
using namespace std;

int N, R;
int to;
int root;
vector<int> adj[54];

int dfs(int here) {
  int ret = 0;
  int child = 0;

  for (int there : adj[here]) {
    if (there == R) continue;
    ret += dfs(there);
    child++;
  }

  if (child == 0) return 1;

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> to;

    if (to == -1) {
      root = i;
    } else {
      adj[to].push_back(i);
    }
  }

  cin >> R;

  if (R == root) {
    cout << 0;
  } else {
    cout << dfs(root);
  }

  return 0;
}