#include <bits/stdc++.h>
using namespace std;

int N, L, R;
int a[54][54];
int visited[54][54];
int ret;
int sum;

vector<pair<int, int>> v;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x) {
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) continue;

    int dist = abs(a[y][x] - a[ny][nx]);

    if (L <= dist && dist <= R) {
      v.push_back({ny, nx});
      visited[ny][nx] = 1;
      sum += a[ny][nx];
      dfs(ny, nx);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> L >> R;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];
    }
  }

  while (true) {
    bool flag = false;
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (!visited[i][j]) {
          v.clear();
          v.push_back({i, j});
          visited[i][j] = 1;
          sum = a[i][j];
          dfs(i, j);

          if (v.size() == 1) continue;

          for (pair<int, int> pos : v) {
            a[pos.first][pos.second] = sum / v.size();
            flag = true;
          }
        }
      }
    }

    if (!flag) break;
    ret++;
  }

  cout << ret;

  return 0;
}