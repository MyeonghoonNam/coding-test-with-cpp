#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 104;
const int MAX_Y = 104;

int N, M, y, x;
int maze[MAX_N][MAX_Y], visited[MAX_N][MAX_Y];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void bfs() {
  queue<pair<int, int>> q;

  q.push({0, 0});
  visited[0][0] = 1;

  while (q.size()) {
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

      if (visited[ny][nx] == 0 && maze[ny][nx] == 1) {
        q.push({ny, nx});
        visited[ny][nx] = visited[y][x] + 1;
      }
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%1d", &maze[i][j]);
    }
  }

  bfs();

  printf("%d", visited[N - 1][M - 1]);

  return 0;
}