#include <bits/stdc++.h>
using namespace std;

#define y1 aa
#define x1 bb

int N, M;
char a[304][304];
int visited[304][304];
int x1, y1, x2, y2, x, y;
int turn;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

queue<pair<int, int>> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  cin >> y1 >> x1 >> y2 >> x2;

  y1--, x1--, y2--, x2--;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];
    }
  }
  q.push({y1, x1});
  visited[y1][x1] = 1;

  while (a[y2][x2] != '0') {
    turn++;

    queue<pair<int, int>> temp;

    while (q.size()) {
      tie(y, x) = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;

        if (a[ny][nx] != '0') {
          temp.push({ny, nx});
          a[ny][nx] = '0';
        } else {
          q.push({ny, nx});
        }

        visited[ny][nx] = turn;
      }
    }

    q = temp;
  }

  cout << visited[y2][x2];

  return 0;
}