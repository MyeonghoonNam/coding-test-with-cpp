#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;

int N, K;
int visited[MAX + 4];
long long cnt[MAX + 4];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;

  if (N == K) {
    cout << "0" << "\n";
    cout << "1" << "\n";
    return 0;
  }

  queue<int> q;
  q.push(N);
  visited[N] = 1;
  cnt[N] = 1;

  while (!q.empty()) {
    int now = q.front();
    q.pop();

    for (int next : {now - 1, now + 1, now * 2}) {
      if (0 <= next && next <= MAX) {
        if (!visited[next]) {
          q.push(next);
          visited[next] = visited[now] + 1;
          cnt[next] += cnt[now];
        } else if (visited[next] == visited[now] + 1) {
          cnt[next] += cnt[now];
        }
      }
    }
  }

  cout << visited[K] - 1 << "\n";
  cout << cnt[K] << "\n";

  return 0;
}
