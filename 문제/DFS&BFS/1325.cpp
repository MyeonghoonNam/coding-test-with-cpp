#include <bits/stdc++.h>
using namespace std;

int N, M;
int to, from;
int maxCount;

vector<pair<int, int>> ret;
vector<int> adj[10004];
vector<int> visited(10004);
int dp[10004];

int dfs(int here) {
  visited[here] = 1;
  int ret = 1;

  for (int there : adj[here]) {
    if (visited[there]) continue;
    visited[there] = 1;
    ret += dfs(there);
  }

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    cin >> to >> from;
    adj[from].push_back(to);
  }

  for (int i = 1; i <= N; i++) {
    fill(visited.begin(), visited.end(), 0);
    dp[i] = dfs(i);
    maxCount = max(dp[i], maxCount);
  }

  for (int i = 1; i <= N; i++) {
    if (maxCount == dp[i]) cout << i << " ";
  }

  return 0;
}