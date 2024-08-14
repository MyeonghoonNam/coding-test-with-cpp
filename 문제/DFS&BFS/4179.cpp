/**
 * 문제분석
 * 매 분마다 지훈이는 상,하,좌,우 중 1칸으로 위치 이동
 * 매 분마다 불은 상,하,좌,우 중 4칸 모두 위치 확산
 * 매 분마다 동시에 지훈이와 불의 움직임 검증 필요
 *  - 즉, 두번의 bfs()를 통해 불의 최단거리와 지훈이의 최단거리가 비교 가능해야
 * 한다. 지훈이와 불은 벽이 있는 공간은 통과하지 못한다. 최단 거리로 지훈이의
 * 2차원 좌표(y, x)가 미로의 가장 자리에 도달하면 문제 해결
 *  - 미로의 가장 자리는 2차원 배열의 (행길이 - 1) or (열길이 - 1)의 좌표들
 *
 */

#include <bits/stdc++.h>
using namespace std;

int R, C;
char maze[1004][1004];
int fire[1004][1004], jihoon[1004][1004];
int sy, sx;
int fy, fx, jy, jx;
int ret;

vector<pair<int, int>> firePos;

queue<pair<int, int>> q;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};

bool isValidPos(int y, int x) {
  if (y < 0 || y >= R || x < 0 || x >= C) return false;
  return true;
}

bool isPosMazeEnd(int y, int x) {
  if (y == 0 || y == R - 1 || x == 0 || x == C - 1) return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> R >> C;
  fill(&fire[0][0], &fire[0][0] + 1004 * 1004, INT_MAX);

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> maze[i][j];

      if (maze[i][j] == 'J') {
        sy = i;
        sx = j;
      } else if (maze[i][j] == 'F') {
        fire[i][j] = 1;
        q.push({i, j});
      }
    }
  }

  while (!q.empty()) {
    tie(fy, fx) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = fy + dy[i];
      int nx = fx + dx[i];

      if (!isValidPos(ny, nx)) continue;
      if (fire[ny][nx] != INT_MAX) continue;

      if (maze[ny][nx] == '.') {
        q.push({ny, nx});
        fire[ny][nx] = fire[fy][fx] + 1;
      }
    }
  }

  q.push({sy, sx});
  jihoon[sy][sx] = 1;

  while (!q.empty()) {
    tie(jy, jx) = q.front();
    q.pop();

    if (isPosMazeEnd(jy, jx)) {
      ret = jihoon[jy][jx];
      break;
    }

    for (int i = 0; i < 4; i++) {
      int ny = jy + dy[i];
      int nx = jx + dx[i];

      if (!isValidPos(ny, nx)) continue;
      if (jihoon[ny][nx] || maze[ny][nx] == '#') continue;

      if (jihoon[jy][jx] + 1 < fire[ny][nx]) {
        q.push({ny, nx});
        jihoon[ny][nx] = jihoon[jy][jx] + 1;
      }
    }
  }

  if (ret != 0) {
    cout << ret;
  } else {
    cout << "IMPOSSIBLE";
  }

  return 0;
}