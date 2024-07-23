#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[10][10];
int c[10][10];
int visited[10][10];
int wall;
int y, x;
int area;
int ret;

queue<pair<int, int>> q;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int getAreaCount() {
  int ret = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (c[i][j] == 0) ret++;
    }
  }

  return ret;
}

void virus(int startY, int startX) {
  for (int i = 0; i < 4; i++) {
    int ny = startY + dy[i];
    int nx = startX + dx[i];

    if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

    if (c[ny][nx] == 0 && !visited[ny][nx]) {
      c[ny][nx] = 2;
      visited[ny][nx] = 1;
      virus(ny, nx);
    }
  }
}

void build(int count) {
  if (count == 3) {
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        c[i][j] = a[i][j];
      }
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (c[i][j] == 2 && !visited[i][j]) {
          virus(i, j);
        }
      }
    }

    ret = max(ret, getAreaCount());

    return;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (a[i][j] == 0) {
        a[i][j] = 1;
        wall++;
        build(wall);
        wall--;
        a[i][j] = 0;
      }
    }
  }
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

  build(0);

  cout << ret;

  return 0;
}