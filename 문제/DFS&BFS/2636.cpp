#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[104][104];
int visited[104][104];
int meltTime;
int cheeseCount;

int y, x;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int melt() {
  // 1. 녹일 치즈 찾기
  // 2. 동시에 치즈 녹이기
  // 3. 남은 치즈있다면 치즈값 갱신
  vector<pair<int, int>> v;
  queue<pair<int, int>> q;

  int meltCheeseCount = 0;

  q.push({0, 0});
  visited[0][0] = 1;

  while (!q.empty()) {
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;

      if (a[ny][nx] == 0) {
        q.push({ny, nx});
      } else if (a[ny][nx] == 1) {
        v.push_back({ny, nx});
      }

      visited[ny][nx] = 1;
    }
  }

  for (auto it : v) {
    a[it.first][it.second] = 0;
    meltCheeseCount++;
  }

  return meltCheeseCount;
}

/**
 * 녹일 치즈가 있다면 치즈를 녹인다.
 * 녹일 치즈가 없다면 종료하고 치즈가 모두 녹기 1시간전의 치즈 수를 반환
 */
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];
      if (a[i][j] == 1) cheeseCount++;
    }
  }

  while (true) {
    memset(visited, 0, sizeof(visited));
    int meltCheeseCount = melt();

    meltTime++;
    cheeseCount -= meltCheeseCount;

    if (cheeseCount == 0) {
      cout << meltTime << "\n";
      cout << meltCheeseCount;
      break;
    }
  }

  return 0;
}