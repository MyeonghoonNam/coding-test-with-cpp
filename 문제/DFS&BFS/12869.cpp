#include <bits/stdc++.h>
using namespace std;

int N;
int hp[3];
int visited[64][64][64];
int combi[6][3] = {{9, 3, 1}, {9, 1, 3}, {3, 9, 1},
                   {3, 1, 9}, {1, 9, 3}, {1, 3, 9}};

struct value {
  int a, b, c;
};

int attack() {
  queue<value> q;
  q.push({hp[0], hp[1], hp[2]});

  while (q.size()) {
    int a = q.front().a;
    int b = q.front().b;
    int c = q.front().c;

    q.pop();

    if (visited[0][0][0]) break;

    for (int i = 0; i < 6; i++) {
      int na = max(0, a - combi[i][0]);
      int nb = max(0, b - combi[i][1]);
      int nc = max(0, c - combi[i][2]);

      if (!visited[na][nb][nc]) {
        q.push({na, nb, nc});
        visited[na][nb][nc] = visited[a][b][c] + 1;
      }
    }
  }

  return visited[0][0][0];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> hp[i];
  }

  cout << attack();

  return 0;
}