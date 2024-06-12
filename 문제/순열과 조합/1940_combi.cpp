#include <bits/stdc++.h>
using namespace std;

int N, M, ret = 0;
int numbers[15001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> numbers[i];
  }

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (numbers[i] + numbers[j] == M) {
        ret += 1;
      }
    }
  }

  cout << ret;

  return 0;
}