#include <bits/stdc++.h>
using namespace std;

int N;
int area[104][104];
int visited[104][104];
int result = 1;
int y, x;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void bfs(int startY, int startX, int h) {
  queue<pair<int, int>> q;
  q.push({startY, startX});
  visited[startY][startX] = 1;

  while (q.size() != 0) {
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

      if (area[ny][nx] > h && !visited[ny][nx]) {
        q.push({ny, nx});
        visited[ny][nx] = 1;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> area[i][j];
    }
  }

  for (int h = 1; h <= 100; h++) {
    fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);

    int count = 0;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (area[i][j] > h && !visited[i][j]) {
          bfs(i, j, h);
          count += 1;
        }
      }
    }

    result = max(result, count);
  }

  cout << result << "\n";

  return 0;
}
