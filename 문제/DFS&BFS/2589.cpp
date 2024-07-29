#include <bits/stdc++.h>
using namespace std;

int N, M;
char a[54][54];
int visited[54][54];
int ret;
int y, x, d;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int bfs(int startY, int startX) {
  queue<tuple<int, int, int>> q;
  q.push({startY, startX, 0});
  visited[startY][startX] = 1;

  int ret = 0;

  while (!q.empty()) {
    tie(y, x, d) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

      if (a[ny][nx] == 'L' && !visited[ny][nx]) {
        q.push({ny, nx, d + 1});
        visited[ny][nx] = 1;
        ret = d + 1;
      }
    }
  }

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (a[i][j] == 'L' && !visited[i][j]) {
        ret = max(ret, bfs(i, j));
        memset(visited, 0, sizeof(visited));
      }
    }
  }

  cout << ret;

  return 0;
}