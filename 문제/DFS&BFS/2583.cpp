#include <bits/stdc++.h>
using namespace std;

int M, N, K;

int area[104][104];
int visited[104][104];

int y, x;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

vector<int> ret;

int bfs(int startY, int startX) {
  int result = 1;

  queue<pair<int, int>> q;
  q.push({startY, startX});
  visited[startY][startX] = 1;

  while (q.size() != 0) {
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= M || nx >= N) continue;

      if (area[ny][nx] == 0 && !visited[ny][nx]) {
        q.push({ny, nx});
        visited[ny][nx] = 1;
        result += 1;
      }
    }
  }

  return result;
}

/**
 * 직사각형 좌표 맵에 표시
 * 전체 맵에서 연결 컴포넌트들의 넓이 합 (bfs)
 */
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> M >> N >> K;

  for (int i = 0; i < K; i++) {
    int x1, y1, x2, y2 = 0;

    cin >> x1 >> y1 >> x2 >> y2;

    for (int y = y1; y < y2; y++) {
      for (int x = x1; x < x2; x++) {
        area[y][x] = 1;
      }
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (area[i][j] == 0 && !visited[i][j]) {
        ret.push_back(bfs(i, j));
      }
    }
  }

  sort(ret.begin(), ret.end());

  cout << ret.size() << "\n";
  for (int a : ret) cout << a << " ";

  return 0;
}