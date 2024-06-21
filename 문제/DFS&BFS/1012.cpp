#include <bits/stdc++.h>
using namespace std;

int T, M, N, K, X, Y, x, y;
int farm[54][54], visited[54][54];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void bfs(int startY, int startX) {
  queue<pair<int, int>> q;
  q.push({startY, startX});
  visited[startY][startX] = 1;

  while (q.size() != 0) {
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

      if (visited[ny][nx] == 0 && farm[ny][nx] == 1) {
        q.push({ny, nx});
        visited[ny][nx] = 1;
      }
    }
  }

  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;

  while (T--) {
    cin >> M >> N >> K;

    int ret = 0;

    memset(farm, 0, sizeof(farm));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < K; i++) {
      cin >> X >> Y;
      farm[Y][X] = 1;
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (visited[i][j] == 0 && farm[i][j] == 1) {
          bfs(i, j);
          ret += 1;
        }
      }
    }

    cout << ret << "\n";
  }

  return 0;
}