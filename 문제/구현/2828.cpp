#include <bits/stdc++.h>
using namespace std;

int N, M, J;
int ret;
int pos;
int l = 1, r = 1;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> J;

  for (int i = 0; i < J; i++) {
    cin >> pos;

    r = l + M - 1;

    if (l <= pos && pos <= r) continue;

    if (pos < l) {
      ret += l - pos;
      l = pos;
    } else {
      // r < pos
      ret += pos - r;
      l += pos - r;
    }
  }

  cout << ret;

  return 0;
}