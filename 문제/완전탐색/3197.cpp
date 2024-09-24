#include <bits/stdc++.h>
using namespace std;

int R, C;
int swanY, swanX;
int y, x;
int day;
char lake[1504][1504];
int visitedWater[1504][1504];
int visitedSwan[1504][1504];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

queue<pair<int, int>> swanQueue;
queue<pair<int, int>> swanTempQueue;
queue<pair<int, int>> waterQueue;
queue<pair<int, int>> waterTempQueue;

bool moveSwan() {
  while (swanQueue.size()) {
    tie(y, x) = swanQueue.front();
    swanQueue.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
      if (visitedSwan[ny][nx]) continue;

      visitedSwan[ny][nx] = 1;

      if (lake[ny][nx] == '.') {
        swanQueue.push({ny, nx});
      } else if (lake[ny][nx] == 'X') {
        swanTempQueue.push({ny, nx});
      } else if (lake[ny][nx] == 'L') {
        return true;
      }
    }
  }

  swanQueue = swanTempQueue;
  swanTempQueue = queue<pair<int, int>>();

  return false;
}

void meltIce() {
  while (waterQueue.size()) {
    tie(y, x) = waterQueue.front();
    waterQueue.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
      if (visitedWater[ny][nx]) continue;

      if (lake[ny][nx] == 'X') {
        lake[ny][nx] = '.';
        waterTempQueue.push({ny, nx});
        visitedWater[ny][nx] = 1;
      }
    }
  }

  waterQueue = waterTempQueue;
  waterTempQueue = queue<pair<int, int>>();
}

int main() {
  cin >> R >> C;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      char input;
      cin >> input;

      lake[i][j] = input;

      if (input == 'L') {
        swanY = i;
        swanX = j;
      }

      if (input == '.' || input == 'L') {
        waterQueue.push({i, j});
        visitedWater[i][j] = 1;
      }
    }
  }

  swanQueue.push({swanY, swanX});
  visitedSwan[swanY][swanX] = 1;

  while (true) {
    if (moveSwan()) break;
    meltIce();
    day++;
  }

  cout << day;

  return 0;
}