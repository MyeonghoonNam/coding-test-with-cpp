#include <bits/stdc++.h>
#define prev aaa
#define next aaaa

using namespace std;

const int MAX = 200004;

int N, K;
int ret;
int visited[MAX];
int prev[MAX];
vector<int> path;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;

  if (N == K) {
    cout << "0" << "\n";
    cout << N << "\n";

    return 0;
  }

  queue<int> q;
  q.push(N);
  visited[N] = 1;

  while (q.size()) {
    int now = q.front();
    q.pop();

    if (now == K) {
      ret = visited[now] - 1;
      break;
    }

    for (int next : {now - 1, now + 1, now * 2}) {
      if (next < 0 || next >= MAX) continue;

      if (!visited[next]) {
        q.push(next);
        visited[next] = visited[now] + 1;
        prev[next] = now;
      }
    }
  }

  for (int i = K; i != N; i = prev[i]) {
    path.push_back(i);
  }

  path.push_back(N);

  cout << ret << "\n";
  reverse(path.begin(), path.end());

  for (int v : path) cout << v << " ";

  return 0;
}