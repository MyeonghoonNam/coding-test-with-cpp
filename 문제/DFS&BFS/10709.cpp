#include <bits/stdc++.h>
using namespace std;

int H, W;
char a[104][104];
int visited[104][104];
int ret[104][104] = {
    0,
};

void dfs(int y, int x, int time) {
  ret[y][x] = time;
  visited[y][x] = 1;

  int dy = 0;
  int dx = 1;
  int ny = y + dy;
  int nx = x + dx;

  if (ny < 0 || nx < 0 || ny >= H || nx >= W) return;

  if (a[ny][nx] != 'c' && !visited[ny][nx]) {
    dfs(ny, nx, time + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> H >> W;

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a[i][j];
    }
  };

  memset(ret, -1, sizeof(ret));

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (a[i][j] == 'c' && !visited[i][j]) {
        dfs(i, j, 0);
      }
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << ret[i][j] << " ";
    }

    cout << "\n";
  }

  return 0;
}